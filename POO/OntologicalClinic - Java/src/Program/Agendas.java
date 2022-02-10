package Program;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.List;
import java.util.Scanner;
import java.text.ParseException;
import java.util.Date;
import java.io.FileReader;

public class Agendas {

    String data;
    String horario;

    // CONSTRUTOR VAZIO
    public Agendas() {
    }

    public Agendas(String data, String horario) {
        this.data = data;
        this.horario = horario;
    }

    /* GETTERS */
    // RETORNA O DIA
    public String getData() {
        return data;
    }

    // RETORNA A HORA
    public String getHorario() {
        return horario;
    }

    /* SETTERS */
    // ALTERA O DIA
    protected void setData(String data) {
        this.data = data;
    }

    // ALTERA A HORA
    protected void setHorario(String horario) {
        this.horario = horario;
    }

    public void lerDentistas(List<String> dentistas) {
        try {
            FileReader arq = new FileReader("Dentistas.txt");
            BufferedReader lerArq = new BufferedReader(arq);

            //Lê A PRIMEIRA LINHA QUE NO CASO É O NOME DO DENTISTA
            String linha = lerArq.readLine();
            String dentista;
            while (linha != null) {
                //VERIFICA APENAS O NOME DO DENTISTA
                if (linha.contains("Dentista:\t")) {
                    dentista = linha.replace("Dentista:\t", "");
                    dentistas.add(dentista);
                    
//                    FileReader arq2 = new FileReader("Clientes.txt");
//                    BufferedReader lerArq2 = new BufferedReader(arq2);
//                    String linha2 = lerArq.readLine();
//                    String cliente = linha.replace("Cliente:\t", "");
//                    String horario = linha.replace("Horario:")
//                    clientes.add(cliente);
                }
                //LÊ DA SEGUNDA ATÉ A ÚLTIMA LINHA
                linha = lerArq.readLine();

            }

            arq.close();
        } catch (IOException e) {
            System.out.printf("Erro na abertura do arquivo: %s.\n", e.getMessage());
        }
    }

    // EDITA A AGENDA DE UM DETERMINADO DENTISTA    
    public void editarAgenda(List<Agendas> agenda) {
        Scanner input = new Scanner(System.in);
        Agendas aux = new Agendas();
        int comando;

        System.out.print("Digite um comando (1/2/3): ");
        comando = input.nextInt();

        /* TABELA DE COMANDOS AQUI */
        String data;
        String horario;
        boolean controle = false;
        if (comando == 1) {
            boolean agendar = true;

            System.out.println("\n*** AGENDAMENTO DE CONSULTA ***\n");
            do {
                System.out.print("Data (dd/mm/yy): ");
                data = input.next();

                //VERIFICA SE A DATA É VÁLIDA
                SimpleDateFormat formato = new SimpleDateFormat("dd/MM/yy");
                formato.setLenient(false);

                //PEGA A DATA ATUAL DO SISTEMA
                Date hoje = new Date();
                String dataHoje = java.text.DateFormat.getDateInstance(DateFormat.DATE_FIELD).format(hoje);

                try {
                    Date dat = formato.parse(data);
                    Date datHoje = formato.parse(dataHoje);
                    //COMPARA SE A DATA DESEJADA JÁ PASSOU
                    if (dat.after(datHoje) || dat.equals(datHoje)) {
                        controle = true;
                    } else {
                        System.err.println("Essa data já passou. Consultas a partir do dia de hoje: " + dataHoje);
                    }
                } catch (ParseException e) {
                    System.err.println("Data inválida, digite novamente...");
                    controle = false;
                }
            } while (controle != true);

            do {
                System.out.print("Horário (hh:mm): ");
                horario = input.next();

                //VERIFICA SE A HORA É VÁLIDA
                SimpleDateFormat hora = new SimpleDateFormat("HH:mm");
                hora.setLenient(false);

                try {
                    hora.parse(horario);
                    controle = true;
                } catch (ParseException e) {
                    System.err.println("Horário inválido, digite novemente...");
                    controle = false;
                }

            } while (controle != true);

            //VERIFICA SE ESSE HORÁRIO JÁ FOI RESERVADO
            for (int i = 0; i < agenda.size(); i++) {
                if (data.equals(agenda.get(i).getData())) {
                    System.err.println("Horário já reservado");
                    agendar = false;
                    break;
                }
            }

            //AGENDA ESSE HORÁRIO
            if (agendar != false) {
                aux.setData(data);
                aux.setHorario(horario);

                //ADICIONA NA AGENDA
                agenda.add(aux);
            }

        } else if (comando == 2) {
            do {
                System.out.println("*** DESAGENDAMENTO DE CONSULTA ***");
                System.out.print("Data (dd/mm/yy): ");
                data = input.next();
                System.out.print("Horário (hh:mm): ");
                horario = input.next();

                //VERIFICA SE A DATA E HORA SÃO VÁLIDAS
                SimpleDateFormat formato = new SimpleDateFormat("dd/MM/yy");
                formato.setLenient(false);

                SimpleDateFormat hora = new SimpleDateFormat("HH:mm");
                hora.setLenient(false);

                try {
                    Date dat = formato.parse(data);
                    hora.parse(horario);
                    controle = true;
                } catch (ParseException e) {
                    controle = false;
                }
            } while (controle != true);

            for (int i = 0; i < agenda.size(); i++) {
                //VERIFICA SE EXISTE ESSA CONSULTA NA AGENDA
                if (!data.equals(agenda.get(i).getData()) || !horario.equals(agenda.get(i).getHorario())) {
                    System.err.println("Consulta Inexistente");
                } else {
                    //REMOVE A CONSULTA
                    agenda.remove(i);
                    System.out.println("Consulta Desmarcada");
                    break;
                }
            }
        } else if (comando == 3) {
            System.out.println("Redirecionando para o menu");
            System.out.flush();
        }
    }

    // ARMAZENA A AGENDA EM UM ARQUIVO
    public void gravaAgenda(String dentista, String cpf, String cliente, String data, String hora, String valor) {
        //CRIA UM ARQUIVO PARA JOGAR OS DADOS DA AGENDA
        File arq = new File("Agenda.txt");
        try {
            arq.createNewFile();

            //APONTA O PONTEIRO PARA A PRIMEIRA POSIÇÃO DO ARQUIVO
            //O 2º PARÂMETRO SENDO FALSE, SOBREESCREVE O ARQUIVO COM O NOVO CONTEÚDO
            //SENDO TRUE ESCREVE DE ONDE PAROU
            FileWriter fileWriter = new FileWriter(arq, true);

            //USANDO A CLASSE PrintWriter PARA ESCREVER NO ARQUIVO
            PrintWriter printWriter = new PrintWriter(fileWriter);
            printWriter.println("Dentista:\t" + dentista);
            printWriter.println("CPF:\t" + cpf);
            printWriter.println("Cliente:\t"+ cliente);
            printWriter.println("Valor:\t"+ valor);
            printWriter.println("Data:\t" + data);
            printWriter.println("Status:\t" + "pendente");
            printWriter.println("Horário:\t" + hora);
            printWriter.print("\n");

            //LIBERA A ESCRITA NO ARQUIVO
            printWriter.flush();

            //FECHA O ARQUIVO
            printWriter.close();

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    
    public void lerAgenda(String dentista, List<String> agendado) {
        try {
            FileReader arq = new FileReader("Agenda.txt");
            BufferedReader lerArq = new BufferedReader(arq);
            //Lê A PRIMEIRA LINHA QUE NO CASO É O NOME DO DENTISTA
            String linha = lerArq.readLine();
            while (linha != null) {
                //VERIFICA APENAS O NOME DO DENTISTA
                if (linha.contains("Dentista:\t"+dentista)) {
                    
                    linha = lerArq.readLine(); // Pula o CPF na hora de mostrar a agenda do dentista
                    linha = lerArq.readLine(); // Pula o nome
                    String nomeLido = linha.replace("Cliente:\t", "");

                    linha = lerArq.readLine(); // Pula o valor na consulta
                    linha = lerArq.readLine(); // pula o status do pagamento
                    
                    linha = lerArq.readLine();
                    String dataLida = linha.replace("Data:\t", "");
                    
                    linha = lerArq.readLine();
                    String horaLida = linha.replace("Horário:\t", "");
                    
                    String spaces = "";
                        for(int i = 0; i < 20; i++) {
                        spaces += " "; 
                    }
                    String lido = nomeLido + spaces + dataLida + spaces + horaLida;
                    agendado.add(lido);
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
