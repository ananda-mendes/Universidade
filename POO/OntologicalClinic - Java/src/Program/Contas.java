package Program;

import java.io.BufferedReader;
import java.text.DateFormat;
import java.util.Scanner;
import java.util.Date;
import java.text.SimpleDateFormat;
import java.text.ParseException;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.List;

public class Contas {

    String valor;
    String tipo;
    String dataVencimento;
    String dataPagamento;

    // CONTRUTOR VAZIO
    public Contas() {
    }

    public Contas(String valor, String dataVencimento, String dataPagamento, String tipo) {
        this.valor = valor;
        this.dataVencimento = dataVencimento;
        this.dataPagamento = dataPagamento;
        this.tipo = tipo;
    }

    /* GETTERS */
    // RETORNA O VALOR DA CONTA
    public String getValor() {
        return valor;
    }

    // RETORNA A DATA DO VENCIMENTO DA CONTA
    public String getDataVencimento() {
        return dataVencimento;
    }

    // RETORNA A DATA DO PAGAMENTO DA CONTA
    public String getDataPagamento() {
        return dataPagamento;
    }

    // RETORNA O TIPO DE CONTA
    public String getTipo() {
        return tipo;
    }

    /* SETTERS */
    // ALTERA O VALOR DA CONTA
    protected void setValor(String valor) {
        this.valor = valor;
    }

    // ALTERA A DATA DO VENCIMENTO DA CONTA
    protected void setDataVencimento(String dataVencimento) {
        this.dataVencimento = dataVencimento;
    }

    // ALTERA A DATA DO PAGAMENTO DA CONTA
    protected void setDataPagamento(String dataPagamento) {
        this.dataPagamento = dataPagamento;
    }

    // ALTERA O TIPO DE CONTA
    protected void setTipo(String tipo) {
        this.tipo = tipo;
    }

    public void lerContas(List<String> tipo, List<String> valor, 
            List<String> dataPagamento, List<String> dataVencimento) {
        try {
            FileReader arq = new FileReader("Contas.txt");
            BufferedReader lerArq = new BufferedReader(arq);

            //Lê A PRIMEIRA LINHA QUE NO CASO É O NOME DO DENTISTA
            String linha = lerArq.readLine();
            String tipoInput;
            String valorInput;
            String pagamentoInput;
            String vencimentoInput;
            while (linha != null) {
                //VERIFICA APENAS O NOME DO DENTISTA
                if (linha.contains("Tipo:\t")) {
                    tipoInput = linha.replace("Tipo:\t", "");
                    
                    linha = lerArq.readLine();
                    valorInput = linha.replace("Valor:\t", "");
                    
                    linha = lerArq.readLine();
                    pagamentoInput = linha.replace("Data de Pagamento:\t", "");
                    
                    linha = lerArq.readLine();
                    vencimentoInput = linha.replace("Data de Vencimento:\t", "");
                    
                    tipo.add(tipoInput);
                    valor.add(valorInput);
                    dataPagamento.add(pagamentoInput);
                    dataVencimento.add(vencimentoInput);
                }
                //LÊ DA SEGUNDA ATÉ A ÚLTIMA LINHA
                linha = lerArq.readLine();
            }

            arq.close();
        } catch (IOException e) {
            System.out.printf("Erro na abertura do arquivo: %s.\n", e.getMessage());
        }
    }
    
    public void jogaEmArquivo(String tipo, String valor, String dataPagamento, String dataVencimento) {
        //CRIA UM ARQUIVO PARA JOGAR OS DADOS DAS CONTAS PAGAS
        File arq = new File("Contas.txt");
        try {
            arq.createNewFile();

            //APONTA O PONTEIRO PARA A PRIMEIRA POSIÇÃO DO ARQUIVO
            //O 2º PARÂMETRO SENDO NEGATIVO, SOBREESCREVE O ARQUIVO COM O NOVO CONTEÚDO
            FileWriter fileWriter = new FileWriter(arq, true);

            //USANDO A CLASSE PrintWriter PARA ESCREVER NO ARQUIVO
            PrintWriter printWriter = new PrintWriter(fileWriter);
            printWriter.println("Tipo:\t"+tipo);
            printWriter.println("Valor:\t" + valor);
            printWriter.println("Data de Pagamento:\t" + dataPagamento);
            printWriter.println("Data de Vencimento:\t" + dataVencimento);
            printWriter.print("\n");

            //LIBERA A ESCRITA NO ARQUIVO
            printWriter.flush();

            //FECHA O ARQUIVO
            printWriter.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
