package Program;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.List;
import java.util.ArrayList;
import java.util.Date;
import java.util.Iterator;
import java.util.Scanner;

public class Administrador extends Funcionario {

    private String login;
    private String senha;

    // CONSTRUTOR 
    public Administrador() {
        login = "admin";
        senha = "admin";
    }

    public Administrador(
            String salario, String cargaHoraria, String cargo, String nome,
            String sobrenome, String endereco, String email, String CPF,
            String RG, String telefone, String idade, String login, String senha) {
        super(salario, cargaHoraria, cargo, nome, sobrenome, endereco, email,
                CPF, RG, telefone, idade);
        this.login = login;
        this.senha = senha;
    }

    /* GETTERS */
    // RETORNA O LOGIN DE UM ADMINISTRADOR OU ASSISTENTE ADMINISTRATIVO
    public String getLogin() {
        return login;
    }

    // RETORNA A SENHA DE UM ADMINISTRADOR OU ASSISTENTE ADMINISTRATIVO
    public String getSenha() {
        return senha;
    }

    /* SETTERS */
    // ALTERA O LOGIN DE UM ADMINISTRADOR OU ASSISTENTE ADMINISTRATIVO
    protected void setLogin(String login) {
        this.login = login;
    }

    // ALTERA A SENHA DE UM ADMINISTRADOR OU ASSISTENTE ADMINISTRATIVO
    protected void setSenha(String senha) {
        this.senha = senha;
    }
    
    // CADASTRA ADMINISTRADOR
    public void cadastraAdministrador(String nome, String sobrenome, String endereco, String email,
            String cpf, String rg, String telefone, String idade, String salario,
            String cargaHoraria, String cargo, String login, String senha) {

        Administrador admin = new Administrador();
        admin.setNome(nome);
        admin.setSobrenome(sobrenome);
        admin.setEndereco(endereco);
        admin.setEmail(email);
        admin.setCPF(cpf);
        admin.setRG(rg);
        admin.setTelefone(telefone);
        admin.setIdade(idade);
        admin.setSalario(salario);
        admin.setCargaHoraria(cargaHoraria);
        admin.setCargo(cargo);
        admin.setLogin(login);
        admin.setSenha(senha);
        //CRIA UMA LISTA DE ADM'S E VAI JOGANDO EM UM ARQUIVO 
        List<Administrador> administradores = new ArrayList<>();
        administradores.add(admin);
        //CRIA UM ARQUIVO PARA JOGAR OS DADOS DOS FUNCIONÁRIOS
        File arqAdm = new File("Administradores.txt");
        try {
            arqAdm.createNewFile();

            //APONTA O PONTEIRO PARA A PRIMEIRA POSIÇÃO DO ARQUIVO
            //O 2º PARÂMETRO SENDO FALSE, SOBREESCREVE O ARQUIVO COM O NOVO CONTEÚDO
            //SENDO TRUE ESCREVE DE ONDE PAROU
            FileWriter fileWriter = new FileWriter(arqAdm, true);

            //USANDO A CLASSE PrintWriter PARA ESCREVER NO ARQUIVO
            PrintWriter printWriter = new PrintWriter(fileWriter);
            for (int i = 0; i < administradores.size(); i++) {
                printWriter.println("Administrador:\t" + administradores.get(i).getNome() + " " + administradores.get(i).getSobrenome());
                printWriter.println("Idade:\t" + administradores.get(i).getIdade());
                printWriter.println("Cargo:\t" + administradores.get(i).getCargo());
                printWriter.println("Salario:\t" + administradores.get(i).getSalario());
                printWriter.println("Telefone:\t" + administradores.get(i).getTelefone());
                printWriter.println("E-mai:l\t" + administradores.get(i).getEmail());
                printWriter.println("Endereço:\t" + administradores.get(i).getEndereco());
                printWriter.println("Carga Horária:\t" + administradores.get(i).getCargaHoraria());
                printWriter.println("Login:\t" + administradores.get(i).getLogin());
                printWriter.println("Senha:\t" + administradores.get(i).getSenha());
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

    // CADASTRA UM ASSISTENTE ADMINISTRATIVO
    public void cadastraAssistenteAdm(String nome, String sobrenome, String endereco, String email,
            String cpf, String rg, String telefone, String idade, String salario,
            String cargaHoraria, String cargo, String login, String senha) {

        AssistenteAdministrativo assistente = new AssistenteAdministrativo();
        assistente.setNome(nome);
        assistente.setSobrenome(sobrenome);
        assistente.setEndereco(endereco);
        assistente.setEmail(email);
        assistente.setCPF(cpf);
        assistente.setRG(rg);
        assistente.setTelefone(telefone);
        assistente.setIdade(idade);
        assistente.setSalario(salario);
        assistente.setCargaHoraria(cargaHoraria);
        assistente.setCargo(cargo);
        assistente.setLogin(login);
        assistente.setSenha(senha);

        //CRIA UMA LISTA DE ASSISTENTES ADMINISTRATIVOS E VAI JOGANDO EM UM ARQUIVO 
        List<AssistenteAdministrativo> assistentes = new ArrayList<>();
        assistentes.add(assistente);

        //CRIA UM ARQUIVO PARA JOGAR OS DADOS DOS FUNCIONÁRIOS
        File arqAssAdm = new File("AssistentesAdm.txt");
        try {
            arqAssAdm.createNewFile();

            //APONTA O PONTEIRO PARA A PRIMEIRA POSIÇÃO DO ARQUIVO
            //O 2º PARÂMETRO SENDO FALSE, SOBREESCREVE O ARQUIVO COM O NOVO CONTEÚDO
            //SENDO TRUE ESCREVE DE ONDE PAROU
            FileWriter fileWriter = new FileWriter(arqAssAdm, true);

            //USANDO A CLASSE PrintWriter PARA ESCREVER NO ARQUIVO
            PrintWriter printWriter = new PrintWriter(fileWriter);
            for (int i = 0; i < assistentes.size(); i++) {
                printWriter.println("Ass.Adm:\t" + assistentes.get(i).getNome() + " " + assistentes.get(i).getSobrenome());
                printWriter.println("Idade:\t" + assistentes.get(i).getIdade());
                printWriter.println("Cargo:\t" + assistentes.get(i).getCargo());
                printWriter.println("Salario:\t" + assistentes.get(i).getSalario());
                printWriter.println("Telefone:\t" + assistentes.get(i).getTelefone());
                printWriter.println("E-mai:l\t" + assistentes.get(i).getEmail());
                printWriter.println("Endereço:\t" + assistentes.get(i).getEndereco());
                printWriter.println("Carga Horária:\t" + assistentes.get(i).getCargaHoraria());
                printWriter.println("Login:\t" + assistentes.get(i).getLogin());
                printWriter.println("Senha:\t" + assistentes.get(i).getSenha());
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

    // CADASTRA UM DENTISTA
    public void cadastraDentista(String nome, String sobrenome, String endereco, String email,
            String cpf, String rg, String telefone, String idade, String salario,
            String cargaHoraria, String cargo) {

        Dentista dentista = new Dentista();
        dentista.setNome(nome);
        dentista.setSobrenome(sobrenome);
        dentista.setEndereco(endereco);
        dentista.setEmail(email);
        dentista.setCPF(cpf);
        dentista.setRG(rg);
        dentista.setTelefone(telefone);
        dentista.setIdade(idade);
        dentista.setSalario(salario);
        dentista.setCargaHoraria(cargaHoraria);
        dentista.setCargo(cargo);

        //CRIA UMA LISTA DE ADM'S E VAI JOGANDO EM UM ARQUIVO 
        List<Dentista> dentistas = new ArrayList<>();
        dentistas.add(dentista);

        //CRIA UM ARQUIVO PARA JOGAR OS DADOS DOS FUNCIONÁRIOS
        File arqDentista = new File("Dentistas.txt");
        try {
            arqDentista.createNewFile();

            //APONTA O PONTEIRO PARA A PRIMEIRA POSIÇÃO DO ARQUIVO
            //O 2º PARÂMETRO SENDO FALSE, SOBREESCREVE O ARQUIVO COM O NOVO CONTEÚDO
            //SENDO TRUE ESCREVE DE ONDE PAROU
            FileWriter fileWriter = new FileWriter(arqDentista, true);

            //USANDO A CLASSE PrintWriter PARA ESCREVER NO ARQUIVO
            PrintWriter printWriter = new PrintWriter(fileWriter);
            for (int i = 0; i < dentistas.size(); i++) {
                printWriter.println("Dentista:\t" + dentistas.get(i).getNome() + " " + dentistas.get(i).getSobrenome());
                printWriter.println("Idade:\t" + dentistas.get(i).getIdade());
                printWriter.println("Cargo:\t" + dentistas.get(i).getCargo());
                printWriter.println("Salario:\t" + dentistas.get(i).getSalario());
                printWriter.println("Telefone:\t" + dentistas.get(i).getTelefone());
                printWriter.println("E-mai:l\t" + dentistas.get(i).getEmail());
                printWriter.println("Endereço:\t" + dentistas.get(i).getEndereco());
                printWriter.println("Carga Horária:\t" + dentistas.get(i).getCargaHoraria());
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

    // CADASTRA UM ASSISTENTE DE DENTISTA
    public void cadastraAssistenteDentista(String nome, String sobrenome, String endereco, String email,
            String cpf, String rg, String telefone, String idade, String salario,
            String cargaHoraria, String cargo) {

        AssistenteDentista assistenteDentista = new AssistenteDentista();
        assistenteDentista.setNome(nome);
        assistenteDentista.setSobrenome(sobrenome);
        assistenteDentista.setEndereco(endereco);
        assistenteDentista.setEmail(email);
        assistenteDentista.setCPF(cpf);
        assistenteDentista.setRG(rg);
        assistenteDentista.setTelefone(telefone);
        assistenteDentista.setIdade(idade);
        assistenteDentista.setSalario(salario);
        assistenteDentista.setCargaHoraria(cargaHoraria);
        assistenteDentista.setCargo(cargo);

        //CRIA UMA LISTA DE ADM'S E VAI JOGANDO EM UM ARQUIVO 
        List<AssistenteDentista> assDentista = new ArrayList<AssistenteDentista>();
        assDentista.add(assistenteDentista);

        //CRIA UM ARQUIVO PARA JOGAR OS DADOS DOS FUNCIONÁRIOS
        File arqAssDen = new File("AssistentesDeDentista.txt");
        try {
            arqAssDen.createNewFile();

            //APONTA O PONTEIRO PARA A PRIMEIRA POSIÇÃO DO ARQUIVO
            //O 2º PARÂMETRO SENDO FALSE, SOBREESCREVE O ARQUIVO COM O NOVO CONTEÚDO
            //SENDO TRUE ESCREVE DE ONDE PAROU
            FileWriter fileWriter = new FileWriter(arqAssDen, true);

            //USANDO A CLASSE PrintWriter PARA ESCREVER NO ARQUIVO
            PrintWriter printWriter = new PrintWriter(fileWriter);
            for (int i = 0; i < assDentista.size(); i++) {
                printWriter.println("Ass.Dentista:\t" + assDentista.get(i).getNome() + " " + assDentista.get(i).getSobrenome());
                printWriter.println("Idade:\t" + assDentista.get(i).getIdade());
                printWriter.println("Cargo:\t" + assDentista.get(i).getCargo());
                printWriter.println("Salario:\t" + assDentista.get(i).getSalario());
                printWriter.println("Telefone:\t" + assDentista.get(i).getTelefone());
                printWriter.println("E-mai:l\t" + assDentista.get(i).getEmail());
                printWriter.println("Endereço:\t" + assDentista.get(i).getEndereco());
                printWriter.println("Carga Horária:\t" + assDentista.get(i).getCargaHoraria());
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

    // CADASTRA UM RECEPCIONISTA
    public void cadastraRecepcionista(String nome, String sobrenome, String endereco, String email,
            String cpf, String rg, String telefone, String idade, String salario,
            String cargaHoraria, String cargo) {

        Recepcionista recepcionista = new Recepcionista();
        recepcionista.setNome(nome);
        recepcionista.setSobrenome(sobrenome);
        recepcionista.setEndereco(endereco);
        recepcionista.setEmail(email);
        recepcionista.setCPF(cpf);
        recepcionista.setRG(rg);
        recepcionista.setTelefone(telefone);
        recepcionista.setIdade(idade);
        recepcionista.setSalario(salario);
        recepcionista.setCargaHoraria(cargaHoraria);
        recepcionista.setCargo(cargo);
        //CRIA UMA LISTA DE ADM'S E VAI JOGANDO EM UM ARQUIVO 
        List<Recepcionista> recepcionistas = new ArrayList<>();
        recepcionistas.add(recepcionista);

        //CRIA UM ARQUIVO PARA JOGAR OS DADOS DOS FUNCIONÁRIOS
        File arqRecepcionistas = new File("Recepcionistas.txt");
        try {
            arqRecepcionistas.createNewFile();

            //APONTA O PONTEIRO PARA A PRIMEIRA POSIÇÃO DO ARQUIVO
            //O 2º PARÂMETRO SENDO FALSE, SOBREESCREVE O ARQUIVO COM O NOVO CONTEÚDO
            //SENDO TRUE ESCREVE DE ONDE PAROU
            FileWriter fileWriter = new FileWriter(arqRecepcionistas, true);

            //USANDO A CLASSE PrintWriter PARA ESCREVER NO ARQUIVO
            PrintWriter printWriter = new PrintWriter(fileWriter);
            for (int i = 0; i < recepcionistas.size(); i++) {
                printWriter.println("Recepcionista:\t" + recepcionistas.get(i).getNome() + " " + recepcionistas.get(i).getSobrenome());
                printWriter.println("Idade:\t" + recepcionistas.get(i).getIdade());
                printWriter.println("Cargo:\t" + recepcionistas.get(i).getCargo());
                printWriter.println("Salario:\t" + recepcionistas.get(i).getSalario());
                printWriter.println("Telefone:\t" + recepcionistas.get(i).getTelefone());
                printWriter.println("E-mai:l\t" + recepcionistas.get(i).getEmail());
                printWriter.println("Endereço:\t" + recepcionistas.get(i).getEndereco());
                printWriter.println("Carga Horária:\t" + recepcionistas.get(i).getCargaHoraria());
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
    
    //LÊ TODAS AS CONSULTAS PARA GERAR O RELATORIO
    public void lerConsultas (String dataInicio, String dataFim, List<String> valor, List<String> dataPagamento, List<String> clientes) {
        try {
            double ganhos = 0;
            FileReader arq = new FileReader("Consultas.txt");
            BufferedReader lerArq = new BufferedReader(arq);
         
            //Lê A PRIMEIRA LINHA QUE NO CASO É OS ÍNDICES
            String linha = lerArq.readLine();
            String teste;
            String data;

            while (linha != null) {
                //VERIFICA APENAS O VALOR DA CONSULTA
                if (linha.contains("Valor")) {
                    //LÊ A PRÓXIMA LINHA
                    linha = lerArq.readLine();

                    int comecoNome = linha.indexOf("");
                    int fimNome = linha.indexOf(" ");
                    String cliente = linha.substring(comecoNome, fimNome);
                    clientes.add(cliente);

                    //PEGA A DATA
                    int comecoData = linha.indexOf("/");
                    int fimData = linha.indexOf("/");
                    data = linha.substring(comecoData - 2, fimData + 6);

                    //VERIFICA SE A DATA É VÁLIDA
                    SimpleDateFormat formato = new SimpleDateFormat("dd/MM/yy");

                    try {
                        Date dataDesejadaInicio = formato.parse(dataInicio);
                        Date dataDesejadaFim = formato.parse(dataFim);
                        Date dataArquivo = formato.parse(data);
                        
                        //COMPARA SE A DATA DESEJADA JÁ PASSOU
                        if (dataArquivo.after(dataDesejadaInicio) && dataArquivo.before(dataDesejadaFim)) {
                            
                            //PARA PEGAR A SUBSTRING VALOR 
                            int comeco = linha.indexOf(" ");
                            int fim = linha.indexOf(".");
                            teste = linha.substring(comeco + 1, fim + 2);

                            //ADICIONANDO ESSES VALORES A UMA LISTA DE CONSULTA
                            String v = teste;
                            valor.add(v);
                            
                            String d = data;
                            dataPagamento.add(d);

                            //SOMA TODOS OS VALORES
                            ganhos += Double.parseDouble(teste);
                        }
                    } catch (ParseException e) {
                    }
                }
                //LÊ AS LINHAS QUE SÃO ÍNDICES
                linha = lerArq.readLine();
            }

            arq.close();
            //System.out.println(ganhos);
            geraRelatorioGanhos(clientes, valor, dataPagamento, ganhos);
        } catch (IOException e) {
            System.out.printf("Erro na abertura do arquivo: %s.\n", e.getMessage());
        }
        
    }
    
    // JOGA O RELATÓRIO DE GANHOS EM UM ARQUIVO 
    public void geraRelatorioGanhos (List<String> clientes, List<String> valor, List<String> dataPagamento, double ganhos) {
        //CRIA UM ARQUIVO PARA JOGAR OS DADOS DA AGENDA
        File arq = new File("RelatorioGanhos.txt");
        try {
            arq.createNewFile();

            //APONTA O PONTEIRO PARA A PRIMEIRA POSIÇÃO DO ARQUIVO
            //O 2º PARÂMETRO SENDO FALSE, SOBREESCREVE O ARQUIVO COM O NOVO CONTEÚDO
            //SENDO TRUE ESCREVE DE ONDE PAROU
            FileWriter fileWriter = new FileWriter(arq, false);

            //USANDO A CLASSE PrintWriter PARA ESCREVER NO ARQUIVO
            PrintWriter printWriter = new PrintWriter(fileWriter);
            for (int i = 0; i < clientes.size(); i++) {
                printWriter.print("Cliente \t\t Valor \t\t Data do pagamento\n");
                printWriter.print(clientes.get(i));
                printWriter.print("\t\t" + valor.get(i));
                printWriter.print("\t\t" + dataPagamento.get(i) + "\n\n");
            }
            printWriter.println("TOTAL: " + ganhos);

            //LIBERA A ESCRITA NO ARQUIVO
            printWriter.flush();

            //FECHA O ARQUIVO
            printWriter.close();

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    
    //LÊ TODOS OS GASTOS PARA GERAR O RELATORIO
    public void lerGastos(String dataInicio, String dataFim, List<String> contas, List<String> valor, List<String> dataPagamento) {
        try {
            double gastos = 0;
            FileReader arq = new FileReader("Contas.txt");
            BufferedReader lerArq = new BufferedReader(arq);

            //Lê A PRIMEIRA LINHA QUE NO CASO É OS ÍNDICES
            String linha = lerArq.readLine();
            String teste;
            String data;
            while (linha != null) {

                int comecoNome = linha.indexOf("");
                int fimNome = linha.indexOf(" ");
                String conta = linha.substring(comecoNome, fimNome+1);
                contas.add(conta);

                //PEGA A DATA
                int comecoData = linha.indexOf("/");
                int fimData = linha.indexOf("/");
                data = linha.substring(comecoData - 2, fimData + 6);

                //VERIFICA SE A DATA É VÁLIDA
                SimpleDateFormat formato = new SimpleDateFormat("dd/MM/yy");

                try {
                    Date dataDesejadaInicio = formato.parse(dataInicio);
                    Date dataDesejadaFim = formato.parse(dataFim);
                    Date dataArquivo = formato.parse(data);

                    //COMPARA SE A DATA DESEJADA JÁ PASSOU
                    if (dataArquivo.after(dataDesejadaInicio) && dataArquivo.before(dataDesejadaFim)) {
                        //PARA PEGAR A SUBSTRING VALOR 
                        int comeco = linha.indexOf("/");
                        int fim = linha.indexOf(".");
                        teste = linha.substring(comeco + 6, fim + 2);
                        
                        String v = teste;
                        valor.add(v);
                        
                        String d = data;
                        dataPagamento.add(d);

                        //SOMA TODOS OS VALORES
                        gastos += Double.parseDouble(teste);
                    }
                } catch (ParseException e) {
                }

                //LÊ AS LINHAS QUE SÃO ÍNDICES
                linha = lerArq.readLine();
            }

            arq.close();
            System.out.println(gastos);
            geraRelatorioGastos(contas, valor, dataPagamento, gastos);
        } catch (IOException e) {
            System.out.printf("Erro na abertura do arquivo: %s.\n", e.getMessage());
        }
        
    }
    
    // JOGA O RELATÓRIO DE GASTOS EM UM ARQUIVO
    public void geraRelatorioGastos (List<String> contas, List<String> valor, List<String> dataPagamento, double gastos) {
        //CRIA UM ARQUIVO PARA JOGAR OS DADOS DA AGENDA
        File arq = new File("RelatorioGanhos.txt");
        try {
            arq.createNewFile();

            //APONTA O PONTEIRO PARA A PRIMEIRA POSIÇÃO DO ARQUIVO
            //O 2º PARÂMETRO SENDO FALSE, SOBREESCREVE O ARQUIVO COM O NOVO CONTEÚDO
            //SENDO TRUE ESCREVE DE ONDE PAROU
            FileWriter fileWriter = new FileWriter(arq, false);

            //USANDO A CLASSE PrintWriter PARA ESCREVER NO ARQUIVO
            PrintWriter printWriter = new PrintWriter(fileWriter);
            for (int i = 0; i < contas.size(); i++) {
                printWriter.print("Cliente \t\t Valor \t\t Data do pagamento\n");
                printWriter.print(contas.get(i));
                printWriter.print("\t\t" + valor.get(i));
                printWriter.print("\t\t" + dataPagamento.get(i) + "\n\n");
            }
            printWriter.println("TOTAL: " + gastos);

            //LIBERA A ESCRITA NO ARQUIVO
            printWriter.flush();

            //FECHA O ARQUIVO
            printWriter.close();

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    
    //LÊ TODOS OS FUNCIONÁRIOS E JOGA EM UMA LISTA DE NOMES
    public void lerFuncionarios(String cargo, List<String> nomes) {
        switch (cargo) {
            //LÊ TODOS OS ADMINISTRADORES
            case "": {
                break;
            }
            case "Administrador": {
                try {
                    FileReader arq = new FileReader("Administradores.txt");
                    BufferedReader lerArq = new BufferedReader(arq);

                    //Lê A PRIMEIRA LINHA QUE NO CASO É O NOME DO DENTISTA
                    String linha = lerArq.readLine();
                    String nome;
                    while (linha != null) {
                        //VERIFICA APENAS O NOME DO ADM
                        if (linha.contains("Administrador:\t")) {
                            nome = linha.replace("Administrador:\t", "");
                            nomes.add(nome);
                        }
                        //LÊ DA SEGUNDA ATÉ A ÚLTIMA LINHA
                        linha = lerArq.readLine();
                    }

                    arq.close();
                } catch (IOException e) {
                    System.err.printf("Erro na abertura do arquivo: %s.\n", e.getMessage());
                }

                break;
            }
            // LÊ TODOS OS ASSISTENTE ADMINISTRATIVO
            case "Assistente Administrativo": {
                try {
                    FileReader arq = new FileReader("AssistentesAdm.txt");
                    BufferedReader lerArq = new BufferedReader(arq);

                    //Lê A PRIMEIRA LINHA QUE NO CASO É O NOME DO DENTISTA
                    String linha = lerArq.readLine();
                    String nome;
                    while (linha != null) {
                        //VERIFICA APENAS O NOME DO DENTISTA
                        if (linha.contains("Ass.Adm:\t")) {
                            nome = linha.replace("Ass.Adm:\t", "");
                            nomes.add(nome);
                        }
                        //LÊ DA SEGUNDA ATÉ A ÚLTIMA LINHA
                        linha = lerArq.readLine();
                    }
                    arq.close();
                } catch (IOException e) {
                    System.err.printf("Erro na abertura do arquivo: %s.\n", e.getMessage());
                }

                break;
            }

            // LÊ TODOS OS DENTISTA
            case "Dentista": {
                try {
                    FileReader arq = new FileReader("Dentistas.txt");
                    BufferedReader lerArq = new BufferedReader(arq);

                    //Lê A PRIMEIRA LINHA QUE NO CASO É O NOME DO DENTISTA
                    String linha = lerArq.readLine();
                    String nome;
                    while (linha != null) {
                        //VERIFICA APENAS O NOME DO DENTISTA
                        if (linha.contains("Dentista:\t")) {
                            nome = linha.replace("Dentista:\t", "");
                            nomes.add(nome);
                        }
                        //LÊ DA SEGUNDA ATÉ A ÚLTIMA LINHA
                        linha = lerArq.readLine();
                    }

                    arq.close();
                } catch (IOException e) {
                    System.err.printf("Erro na abertura do arquivo: %s.\n", e.getMessage());
                }
                break;
            }
            // LÊ TODOS ASSISTENTES DE DENTISTA
            case "Assistente de Dentista": {
                try {
                    FileReader arq = new FileReader("AssistentesDeDentista.txt");
                    BufferedReader lerArq = new BufferedReader(arq);

                    //Lê A PRIMEIRA LINHA QUE NO CASO É O NOME DO DENTISTA
                    String linha = lerArq.readLine();
                    String nome;
                    while (linha != null) {
                        //VERIFICA APENAS O NOME DO DENTISTA
                        if (linha.contains("Ass.Dentista:\t")) {
                            nome = linha.replace("Ass.Dentista:\t", "");
                            nomes.add(nome);
                        }
                        //LÊ DA SEGUNDA ATÉ A ÚLTIMA LINHA
                        linha = lerArq.readLine();
                    }

                    arq.close();
                } catch (IOException e) {
                    System.err.printf("Erro na abertura do arquivo: %s.\n", e.getMessage());
                }
                break;
            }
            // LÊ TODOS RECEPCIONISTA
            case "Recepcionista": {
                try {
                    FileReader arq = new FileReader("Recepcionistas.txt");
                    BufferedReader lerArq = new BufferedReader(arq);

                    //Lê A PRIMEIRA LINHA QUE NO CASO É O NOME DO DENTISTA
                    String linha = lerArq.readLine();
                    String nome;
                    while (linha != null) {
                        //VERIFICA APENAS O NOME DO DENTISTA
                        if (linha.contains("Recepcionista:\t")) {
                            nome = linha.replace("Recepcionista:\t", "");
                            nomes.add(nome);
                        }
                        //LÊ DA SEGUNDA ATÉ A ÚLTIMA LINHA
                        linha = lerArq.readLine();
                    }

                    arq.close();
                } catch (IOException e) {
                    System.err.printf("Erro na abertura do arquivo: %s.\n", e.getMessage());
                }
                break;
            }
            default: {
                System.err.println("Erro no cadastro de funcionario");
                break;
            }
        }
    }
    
    // GRAVA A FOLHA DE PONTO 
    public void gravarFolhaDePonto(String funcionario, String data, String observacao) {
        //CRIA UM ARQUIVO PARA JOGAR OS DADOS DA AGENDA
        File arq = new File("FolhaDePonto.txt");
        try {
            arq.createNewFile();
            
            //APONTA O PONTEIRO PARA A PRIMEIRA POSIÇÃO DO ARQUIVO
            //O 2º PARÂMETRO SENDO FALSE, SOBREESCREVE O ARQUIVO COM O NOVO CONTEÚDO
            //SENDO TRUE ESCREVE DE ONDE PAROU
            FileWriter fileWriter = new FileWriter(arq, true);
            
            PrintWriter printWriter = new PrintWriter(fileWriter);
            //USANDO A CLASSE PrintWriter PARA ESCREVER NO ARQUIVO
            printWriter.println("Folha de Ponto:\t" + funcionario);
            printWriter.println("Data:\t" + data);
            printWriter.println("Observação:\t" + observacao);
            printWriter.print("\n");
            

            //LIBERA A ESCRITA NO ARQUIVO
            printWriter.flush();

            //FECHA O ARQUIVO
            printWriter.close();

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    
    // LÊ A FOLHA DE PONTO DE UM DETERMINADO FUNCIONARIO
    public void lerFolhaDePonto(String funcionario, List<String> agendado) {
        try {
            FileReader arq = new FileReader("FolhaDePonto.txt");
            BufferedReader lerArq = new BufferedReader(arq);
            //Lê A PRIMEIRA LINHA QUE NO CASO É O NOME DO DENTISTA
            String linha = lerArq.readLine();
            while (linha != null) {
                //VERIFICA APENAS O NOME DO DENTISTA
                if (linha.contains("Folha de Ponto:\t" + funcionario)) {
                    linha = lerArq.readLine();
                    String dataLida = linha.replace("Data:\t", "");

                    linha = lerArq.readLine();
                    String obsLida = linha.replace("Observação:\t", "");

                    String spaces = "";
                    for (int i = 0; i < 10; i++) {
                        spaces += " ";
                    }
                    String lido = dataLida + spaces + obsLida;
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
    
    // RETORNA A FOLHA DE PAGAMENTO DE UM DETERMINADO FUNCIONÁRIO
    private void pagarSalario () {
        //VETOR PARA ADICIONAR TODOS OS FUNCIONARIOS QUE ESTÃO EM ARQUIVOS
        List<String> nomes = new ArrayList<>();

        lerFuncionarios(cargo, nomes);

        //IMPRIME OS NOMES DOS FUNCIONARIOS
        System.out.println("------------FUNCIONARIOS------------");
        nomes.forEach(i -> {
            System.out.println(i);
        });
        
        Scanner input = new Scanner(System.in);
        System.out.print("Qual funcionario que deseja pagar o salário? ");
        String nome = input.nextLine();
        
        System.out.println("1 - Folha de ponto\n2 - Efetuar pagamento\n0 - Sair");
        int opcao = input.nextInt();

        for (Object i : nomes) {
            if (nome.equals(i)) {
                while (opcao != 0) {
                    if (opcao == 1) {
                        try {
                            int diasTrabalhados = 0;
                            FileReader arq = new FileReader("FolhaDePonto.txt");
                            BufferedReader lerArq = new BufferedReader(arq);

                            //VERIFICA EM QUAL PERÍODO DEVE SER PROCURADO
                            String dataInicio;
                            String dataFim;

                            System.out.print("Data início (dd/mm/yy): ");
                            dataInicio = input.next();

                            System.out.print("Data fim (dd/mm/yy): ");
                            dataFim = input.next();

                            //Lê A PRIMEIRA LINHA QUE NO CASO É OS ÍNDICES
                            String linha = lerArq.readLine();
                            String data, obs;

                            while (linha != null) {

                                //VERIFICA APENAS O VALOR DA CONSULTA
                                if (linha.contains((CharSequence) i)) {

                                    System.out.println("\nFolha de Ponto - " + i);
                                    System.out.printf("%-10s %-10s\n", "Data", "Observação");

                                    linha = lerArq.readLine();
                                    linha = lerArq.readLine();

                                    while (linha != null) {
                                        //PEGA A DATA
                                        int comecoData = linha.indexOf("/");
                                        int fimData = linha.indexOf("/");
                                        //System.out.println(linha.substring(comecoData - 2, fimData+6));
                                        data = linha.substring(comecoData - 2, fimData + 6);
                                        //VERIFICA SE A DATA É VÁLIDA
                                        SimpleDateFormat formato = new SimpleDateFormat("dd/MM/yy");

                                        try {
                                            Date dataDesejadaInicio = formato.parse(dataInicio);
                                            Date dataDesejadaFim = formato.parse(dataFim);
                                            Date dataArquivo = formato.parse(data);

                                            //COMPARA SE A DATA DESEJADA JÁ PASSOU
                                            if (dataArquivo.after(dataDesejadaInicio) && dataArquivo.before(dataDesejadaFim)) {
                                                if (linha.contains("---")) {
                                                    diasTrabalhados++;
                                                    obs = "   ---";
                                                } else {
                                                    int comecoObs = linha.indexOf(" ");
                                                    int fimObs = linha.indexOf(".");
                                                    obs = linha.substring(comecoObs + 1, fimObs);
                                                }

                                                System.out.printf("%-10s", data);
                                                System.out.printf("%s\n", obs);

                                            }
                                        } catch (ParseException e) {
                                        }

                                        linha = lerArq.readLine();
                                    }
                                }
                                //LÊ AS PRÓXIMAS LINHAS
                                linha = lerArq.readLine();
                            }

                            arq.close();                           
                        } catch (IOException e) {
                            System.out.printf("Erro na abertura do arquivo: %s.\n", e.getMessage());
                        }
                    } else if (opcao == 2) {
                        System.out.println("Valor a ser pago: ");
                        double valor = input.nextDouble();
                        char pagar;
                        System.out.print("Deseja pagar (S/N)? ");
                        pagar = input.next().charAt(0);

                        String data, obs;

                        switch (pagar) {
                            case 'S': {
                                //PEGA A DATA ATUAL DO SISTEMA
                                Date hoje = new Date();
                                data = java.text.DateFormat.getDateInstance(DateFormat.DATE_FIELD).format(hoje);
                                
                                input = new Scanner(System.in);
                                System.out.print("Algum comentário a ser feito? ");
                                obs = input.nextLine();

                                //CRIA UM ARQUIVO PARA JOGAR OS DADOS DA AGENDA
                                File arq = new File("Salarios.txt");
                                try {
                                    arq.createNewFile();

                                    //APONTA O PONTEIRO PARA A PRIMEIRA POSIÇÃO DO ARQUIVO
                                    //O 2º PARÂMETRO SENDO FALSE, SOBREESCREVE O ARQUIVO COM O NOVO CONTEÚDO
                                    //SENDO TRUE ESCREVE DE ONDE PAROU
                                    FileWriter fileWriter = new FileWriter(arq, false);

                                    //USANDO A CLASSE PrintWriter PARA ESCREVER NO ARQUIVO
                                    PrintWriter printWriter = new PrintWriter(fileWriter);

                                    printWriter.println("Folha de Pagamento - " + i);
                                    printWriter.printf("%-20s %-20s %-20s\n", "Data", "Valor", "Descrição");
                                    printWriter.printf("%s", data);
                                    printWriter.printf("\t%s", valor);
                                    printWriter.printf("\t%s\n", obs);

                                    //LIBERA A ESCRITA NO ARQUIVO
                                    printWriter.flush();

                                    //FECHA O ARQUIVO
                                    printWriter.close();
                                    System.out.println("Salário pago");

                                } catch (IOException e) {
                                    e.printStackTrace();
                                }
                                return;
                            }
                            case 'N': {
                                return;
                            }
                            default: {
                                System.err.println("Opção inválida");
                                return;
                            }
                        }
                    }
                    System.out.println("\n1 - Folha de ponto\n2 - Efetuar pagamento");
                    opcao = input.nextInt();
                }
                    
            }
        }
        
        System.err.println("Esse funcionario não existe na clínica");
    }
}
