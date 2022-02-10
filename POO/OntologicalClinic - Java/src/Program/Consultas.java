package Program;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.text.DateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.Scanner;

public class Consultas {

    private String valor;
    private boolean pago;
    private String dataPagamento;

    // CONTRUTOR VAZIO
    public Consultas() {
    }

    public Consultas(String valor, boolean pago, String dataPagamento) {
        this.valor = valor;
        this.pago = pago;
        this.dataPagamento = dataPagamento;
    }

    /* GETTERS */
    // RETORNA O VALOR DA CONSULTA
    public String getValor() {
        return valor;
    }

    // RETORNA O STATUS DO PAGAMENTO
    public boolean getPago() {
        return pago;
    }

    // RETORNA A DATA DO PAGAMENTO
    public String getDataPagamento() {
        return dataPagamento;
    }

    // ALTERA O VALOR DO PAGAMENTO
    public void setValor(String valor) {
        this.valor = valor;
    }

    // ALTERA O STATUS DO PAGAMENTO
    protected void setPago(boolean pago) {
        this.pago = pago;
    }

    // ALTERA A DATA DO PAGAMENTO
    protected void setDataPagamento(String dataPagamento) {
        this.dataPagamento = dataPagamento;
    }

    // RECEBER CONSULTA
    public void receberConsulta(Cliente cliente) {
        Consultas consulta = new Consultas();
        Scanner input = new Scanner(System.in);

        System.out.print("Valor: ");
        consulta.valor = input.next();

        char opcao;
        System.out.print("Confirmar pagamento (S/N)? ");
        opcao = input.next().charAt(0);

        if (opcao == 'S') {
            consulta.setPago(true);
            System.out.println("\nPagamento confirmado.\n");

            //PEGA A DATA ATUAL DO SISTEMA
            Date hoje = new Date();
            String dataHoje = java.text.DateFormat.getDateInstance(DateFormat.DATE_FIELD).format(hoje);
            consulta.setDataPagamento(dataHoje);
        } else {
            System.out.println("A conta não foi paga");
            consulta.setPago(false);
            consulta.setDataPagamento(null);
        }
        jogaEmArquivo(consulta, cliente);
    }

    public void jogaEmArquivo(Consultas consulta, Cliente cliente) {
        //CRIA UM ARQUIVO PARA JOGAR OS DADOS DAS CONSULTAS 
        File arq = new File("Consultas.txt");
        try {
            arq.createNewFile();

            //APONTA O PONTEIRO PARA A PRIMEIRA POSIÇÃO DO ARQUIVO
            //O 2º PARÂMETRO SENDO NEGATIVO, SOBREESCREVE O ARQUIVO COM O NOVO CONTEÚDO
            //SENDO TRUE ESCREVE DE ONDE PAROU
            FileWriter fileWriter = new FileWriter(arq, false);

            //USANDO A CLASSE PrintWriter PARA ESCREVER NO ARQUIVO
            PrintWriter printWriter = new PrintWriter(fileWriter);
            printWriter.printf("%-10s %-10s %-10s %-10s\n", "Cliente", "Valor", "Pago", "Data do pagamento");
            printWriter.printf("%-11s", cliente.getNome());
            printWriter.printf("%-11s", consulta.getValor());
            printWriter.printf("%-12s", consulta.getPago());
            printWriter.printf("%10s\n\n", consulta.getDataPagamento());

            //LIBERA A ESCRITA NO ARQUIVO
            printWriter.flush();

            //FECHA O ARQUIVO
            printWriter.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    
    public void lerClientes(List<String> clientes) {
        try {
            FileReader arq = new FileReader("Clientes.txt");
            BufferedReader lerArq = new BufferedReader(arq);

            //Lê A PRIMEIRA LINHA QUE NO CASO É O NOME DO CLIENTE
            String linha = lerArq.readLine();
            String cliente;
            while (linha != null) {
                //VERIFICA APENAS O NOME DO CLIENTE
                if (linha.contains("Cliente:\t")) {
                    cliente = linha.replace("Cliente:\t", "");
                    clientes.add(cliente);
                }
                //LÊ DA SEGUNDA ATÉ A ÚLTIMA LINHA
                linha = lerArq.readLine();

            }

            arq.close();
        } catch (IOException e) {
            System.out.printf("Erro na abertura do arquivo: %s.\n", e.getMessage());
        }
    }
    
    public void cadastraCliente(String nome, String sobrenome, String endereco, String email, 
            String cpf, String rg, String telefone, String idade) {
        
        Cliente cliente = new Cliente();
        cliente.setNome(nome);
        cliente.setSobrenome(sobrenome);
        cliente.setEndereco(endereco);
        cliente.setEmail(email);
        cliente.setCPF(cpf);
        cliente.setRG(rg);
        cliente.setTelefone(telefone);
        cliente.setIdade(idade);
        
        //CRIA UMA LISTA DE ADM'S E VAI JOGANDO EM UM ARQUIVO 
        List<Cliente> clientes = new ArrayList<>();
        clientes.add(cliente);
        
        //CRIA UM ARQUIVO PARA JOGAR OS DADOS DOS FUNCIONÁRIOS
        File arqClientes = new File("Clientes.txt");
        try {
            arqClientes.createNewFile();

            //APONTA O PONTEIRO PARA A PRIMEIRA POSIÇÃO DO ARQUIVO
            //O 2º PARÂMETRO SENDO FALSE, SOBREESCREVE O ARQUIVO COM O NOVO CONTEÚDO
            //SENDO TRUE ESCREVE DE ONDE PAROU
            FileWriter fileWriter = new FileWriter(arqClientes, true);

            //USANDO A CLASSE PrintWriter PARA ESCREVER NO ARQUIVO
            PrintWriter printWriter = new PrintWriter(fileWriter);
            for (int i = 0; i < clientes.size(); i++) {
                printWriter.println("Cliente:\t" + clientes.get(i).getNome()+ " " + clientes.get(i).getSobrenome());
                printWriter.println("Idade:\t"+clientes.get(i).getIdade());
                printWriter.println("Telefone:\t"+clientes.get(i).getTelefone());
                printWriter.println("E-mai:l\t"+clientes.get(i).getEmail());
                printWriter.println("Endereço:\t"+clientes.get(i).getEndereco());
                printWriter.println("RG:\t"+clientes.get(i).getRG());
                printWriter.println("CPF:\t"+clientes.get(i).getCPF());
                printWriter.print("\n");
            }

            //LIBERA A ESCRITA NO ARQUIVO
            printWriter.flush();

            //FECHA O ARQUIVO
            printWriter.close();

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    
    public void lerConsultas(List<String> cpf, List<String> valor, List<String> status) {
        try {
            FileReader arq = new FileReader("Agenda.txt");
            BufferedReader lerArq = new BufferedReader(arq);
            //Lê A PRIMEIRA LINHA QUE NO CASO É O NOME DO DENTISTA
            String linha = lerArq.readLine();
            while (linha != null) {
                //VERIFICA APENAS O NOME DO DENTISTA
                if (linha.contains("Dentista:\t")) {
                    linha = lerArq.readLine();
                    String cpfLido = linha.replace("CPF:\t", "");
                    linha = lerArq.readLine(); // pula o nome do cliente na hora de mostrar a 
                    linha = lerArq.readLine();
                    
                    String valorLido = linha.replace("Valor:\t", "");
                    
                    linha = lerArq.readLine();
                    String statusLido = linha.replace("Status:\t", "");
                    
                    cpf.add(cpfLido.substring(0, 5));
                    valor.add(valorLido);
                    status.add(statusLido);
                }
                //LÊ DA SEGUNDA ATÉ A ÚLTIMA LINHA
                linha = lerArq.readLine();
            }

            arq.close();
        } catch (IOException e) {
            System.out.printf("Erro na abertura do arquivo: %s.\n", e.getMessage());
        }
    }

}
