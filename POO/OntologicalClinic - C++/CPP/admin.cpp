#include "../HPP/admin.hpp"
#include <unistd.h>

Administrador::Administrador(string nome, int idade, double salario, int cargaHoraria, int cargo, string login, string senha) 
    : Pessoa(nome, idade), Funcionario (nome, idade, salario, cargaHoraria, cargo), login(login), senha(senha) {}

Administrador::~Administrador() {}

string Administrador::getLogin() const {
    return this->login;
}

void Administrador::setLogin(string login) {
    this->login = login;
}

string Administrador::getSenha() const {
    return this->senha;
}

void Administrador::setSenha(string senha) {
    this->senha = senha;
}

Administrador Administrador::criarAdministrador(string nome, int idade, double salario, int cargaHoraria, int cargo) {
    Administrador administrador;

    string login, senha;

    cout << "Login: ";
    cin >> login;
    cout << "Senha: ";
    cin >> senha;

    administrador.setNome(nome);
    administrador.setIdade(idade);
    administrador.setCargo(cargo);
    administrador.setSalario(salario);
    administrador.setCargaHoraria(cargaHoraria);
    administrador.setLogin(login);
    administrador.setSenha(senha);

    return administrador;
}

Administrador Administrador::criarAssistenteAdm(string nome, int idade, double salario, int cargaHoraria, int cargo) {
    Administrador assistente;

    string login, senha;

    cout << "Login: ";
    cin >> login;
    cout << "Senha: ";
    cin >> senha;

    assistente.setNome(nome);
    assistente.setIdade(idade);
    assistente.setCargo(cargo);
    assistente.setSalario(salario);
    assistente.setCargaHoraria(cargaHoraria);
    assistente.setLogin(login);
    assistente.setSenha(senha);

    return assistente;
}

Dentista Administrador::criarDentista(string nome, int idade, double salario, int cargaHoraria, int cargo) {
    Dentista dentista;

    dentista.setNome(nome);
    dentista.setIdade(idade);
    dentista.setCargo(cargo);
    dentista.setSalario(salario);
    dentista.setCargaHoraria(cargaHoraria);

    return dentista;
}

Funcionario Administrador::criarAssistenteDeDentista(string nome, int idade, double salario, int cargaHoraria, int cargo) {
    Funcionario assistente;

    assistente.setNome(nome);
    assistente.setIdade(idade);
    assistente.setCargo(cargo);
    assistente.setSalario(salario);
    assistente.setCargaHoraria(cargaHoraria);
    
    return assistente;
}

Recepcionista Administrador::criarRecepcionista(string nome, int idade, double salario, int cargaHoraria, int cargo) {
    Recepcionista recepcionista;

    recepcionista.setNome(nome);
    recepcionista.setIdade(idade);
    recepcionista.setCargo(cargo);
    recepcionista.setSalario(salario);
    recepcionista.setCargaHoraria(cargaHoraria);

    return recepcionista;
}

void Administrador::leDados(string *nome, int *idade, double *salario, int *cargaHoraria, int *cargo) {
    // NOME
    bool valida;
    do {
        valida = 1;

        cout << "Nome: ";
        cin.ignore();
        getline(cin, *nome);

        char aux[(*nome).length()];
        strcpy(aux, (*nome).c_str());

        for(int i = 0; i < (*nome).length(); i++) {
            if (!isalpha(aux[i]) and !isspace(aux[i])) {
                cout << "Nome possui caracteres inválidos" << endl;
                valida = 0;
            }
        }
    } while (valida != 1);
    // IDADE
    do { 
        valida = 1;

        cout << "Idade: ";
        cin >> *idade;

        if (*idade < 18 or *idade > 90) {
            cout << "Idade Mínima: 18 anos" << endl;
            cout << "Idade Máxima: 90 anos" << endl;
            valida = 0;
        }
    } while (valida != 1);

    // CARGO
    do {
        valida = 1;

        cout << endl << "01 - ADMINISTRADOR" << '\t' << "02 - ASSISTENTE ADM" 
            << '\t' << "03 - DENTISTA" << endl << "04 - ASSISTENTE DENT." << '\t' << "05 - RECEPCIONISTA" << endl;
        cout << "Cargo: ";
        cin >> *cargo;
        if(*cargo < 1 or *cargo > 5) {
            cout << "Cargo inválido" << endl;
            valida = 0;
        }
    } while (valida != 1);

    // SALARIO
    do {
        valida = 1;

        cout << "Salario: ";
        cin >> *salario;
        if (*salario < 1100) {
            cout << "Salário mínimo: R$1100,00" << endl;
            valida = 0;
        }
        else if (*salario > 30000) {
            cout << "Salário máximo: R$30.000,00" << endl;
            valida = 0;
        }
    } while (valida != 1);

    // CARGA HORARIA
    do {
        valida = 1;

        cout << "Carga Horaria: ";
        cin >> *cargaHoraria;
        if(*cargaHoraria < 6) {
            cout << "Carga Horária Mínima: 6 horas" << endl;
            valida = 0;
        }
        else if (*cargaHoraria > 12) {
            cout << "Carga Horária Máxima: 12 horas" << endl;
            valida = 0;
        }
    } while (valida != 1);
}

void Administrador::acessarSistema(Administrador admin) {
    list<Administrador> administrador;
    list<Administrador> assistenteAdmin;
    list<Administrador>::iterator i;

    list<Dentista> dentista;
    list<Funcionario> assistenteDeDentista;
    list<Recepcionista> recepcionista;

    Clinica clinica;
    
    administrador.push_back(admin);
    
    string login, senha;

    system ("clear || cls");
    cout << "--------------CLINICA " << clinica.getNomeEmpresa() << "--------------" << endl << endl;
    
    while(true) {
        cout << "Login: ";
        cin >> login;
        cout << "Senha: ";
        cin >> senha;
        for(i = administrador.begin(); i != administrador.end(); i++){
            if(login != i->getLogin() or senha != i->getSenha()) {
                system("clear || cls");
                cout << "Acesso inválido, por favor tente novamente" << endl << endl;
            }
            else {
                system("clear || cls");
                cout << "Bem vindo " << i->getNome() << endl << endl;
                
                mostrarMenu(&administrador, &assistenteAdmin, &dentista, &assistenteDeDentista, &recepcionista);
            }
        }
    };
}

void Administrador::mostrarMenu(list<Administrador> *administrador, list<Administrador> *assistenteAdmin, list<Dentista> *dentista, list<Funcionario> *assistenteDeDentista, list<Recepcionista> *recepcionista) {
    Agenda agenda;
    Consulta consulta;
    Contas conta;
    Cliente paciente;
    
    int comando;


    FILE* arqContas, *arqConsultas, *arqSalarios, *arqFolhaDePonto;
    if((arqConsultas = fopen ("Consultas.txt", "w")) == NULL || (arqContas = fopen("Contas.txt", "w")) == NULL || (arqSalarios = fopen("Salarios.txt", "w")) == NULL || (arqFolhaDePonto = fopen ("FolhaDePonto.txt", "w")) == NULL) {
        cout << "Falha ao abrir arquivo" << endl;
        exit(0);
    }

    while(true) {
        cout << "------------MENU------------" << endl;
        cout << "01 - Acessar agenda" << endl;
        cout << "02 - Receber Consulta" << endl;
        cout << "03 - Pagamento de Contas" << endl;
        cout << "04 - Mostrar Folha de Ponto" << endl;
        cout << "05 - Cadastrar novo Usuário" << endl;
        cout << "00 - Fechar Sistema" << endl << endl;

        cout << "Digite uma opcao: ";
        cin >> comando;
        system("clear || cls");

        switch(comando) {
            case 01: {
                agenda.abrirAgenda(dentista);
                break;
            }
            case 02: {
                cout << "Com qual dentista é a consulta? ";
                cin.ignore();
                string nome;
                getline(cin, nome);

               list<Dentista>::iterator i;

                for (i = (*dentista).begin(); i != (*dentista).end(); i++) {
                    if (strcmp (i->getNome().c_str(), nome.c_str()) == 0) {
                        paciente = i->getPaciente();
                    }
                }
                consulta.receberConsulta(arqConsultas, paciente);
                break;
            }
            case 03: {            
                conta.pagamentoContas(arqContas);
                break;
            }
            case 04: {
                folhaDePonto(*administrador, *assistenteAdmin, *dentista, *assistenteDeDentista, *recepcionista, arqFolhaDePonto);
                break;
            }
            case 05: {
                string nome;
                int idade, cargaHoraria, cargo;
                double salario;
                leDados(&nome, &idade, &salario, &cargaHoraria, &cargo);

                if (cargo == 01) {
                    (*administrador).push_back(criarAdministrador(nome, idade, salario, cargaHoraria, cargo));
                }
                else if (cargo == 02) {
                    (*assistenteAdmin).push_back(criarAssistenteAdm(nome, idade, salario, cargaHoraria, cargo));
                }
                else if (cargo == 03) {
                    (*dentista).push_back(criarDentista(nome, idade, salario, cargaHoraria, cargo));
                }
                else if (cargo == 04) {
                    (*assistenteDeDentista).push_back(criarAssistenteDeDentista(nome, idade, salario, cargaHoraria, cargo));
                }
                else {
                    (*recepcionista).push_back(criarRecepcionista(nome, idade, salario, cargaHoraria, cargo));
                }

                system("clear || cls");
                cout << "Cadastro realizado com sucesso" << endl;
                cout << "Redirecionando para o menu..." <<endl;
                usleep(2000000);
                system("clear || cls");

                break;
            }
            case 00: {
                fclose (arqConsultas);
                fclose(arqSalarios);
                fclose (arqContas);
                fclose (arqFolhaDePonto);
                cout << "ENCERRANDO SESSÃO..." << endl;
                usleep(1000000);
                exit(0);
            }
        }
    }
}

void Administrador::folhaDePonto(list<Administrador> administrador, list<Administrador> assistenteAdmin, list<Dentista> dentista, list<Funcionario> assistenteDeDentista, list<Recepcionista> recepcionista, FILE* arquivo) {
    list<Administrador>::iterator i;
    list<Dentista>::iterator j;
    list<Funcionario>::iterator k;
    list<Recepcionista>::iterator m;

    //vetor para adicionar todos os funcionarios
    string nomes[100];
    int aux = 0;

    //Lendo todos funcionarios
    cout << "------------FUNCIONARIOS------------" << endl;
    for(i = administrador.begin(); i != administrador.end(); i++){
        cout << i->getNome() << endl;
        nomes[aux] = i->getNome();
        aux++;
    }
    for(i = assistenteAdmin.begin(); i != assistenteAdmin.end(); i++){
        cout << i->getNome() << endl;
        nomes[aux] = i->getNome();
        aux++;
    }
    for(j = dentista.begin(); j != dentista.end(); j++){
        cout << j->getNome() << endl;
        nomes[aux] = j->getNome();
        aux++;
    }
    for(k = assistenteDeDentista.begin(); k != assistenteDeDentista.end(); k++){
        cout << k->getNome() << endl;
        nomes[aux] = k->getNome();
        aux++;
    } 
    for(m = recepcionista.begin(); m != recepcionista.end(); m++){
        cout << m->getNome() << endl;
        nomes[aux] = m->getNome();
        aux++;
    }

    string nome;
    cout << endl << "Qual funcionario deseja editar a folha de ponto? ";
    cin.ignore();
    getline(cin, nome);
    for (aux=0; aux < 100; aux++) { 
        if (nomes[aux] == nome) {
            cout << "Insira a data em que o funcionario trabalhou (dd/mm/aa):" << endl;
            char barra;
            int dia, mes, ano;
            cin >> dia >> barra >> mes >> barra >> ano;
            if (dia > 31 || dia <= 0 || mes <= 0 || mes > 12 || ano <= 0 || ano > 2021) {
                cout << "Data invalida" << endl << endl;     
                return;
            }
            cout << "Alguma observacao a ser feita referente ao dia de trabalho?" << endl;
            cin.ignore();
            string obs;
            getline (cin, obs);

            //FAZER UMA TABELA BONITA
            cout << "Folha de Ponto – " << nomes[aux] << endl;
            cout << "Data \t Observacao" << endl;
            cout << dia << barra << mes << barra << ano << "\t" << obs << endl;
                
            char salvar;
            cout << "Deseja salvar? S ou N" << endl;
            cin >> salvar;
                
            if (salvar == 'S') {
                //Jogando tudo isso para um arquivo
                fprintf (arquivo, "%s \t %d%c%d%c%d \t %s", nomes[aux].c_str(), dia, barra, mes, barra, ano, obs.c_str());
                return;
            }
            else if (salvar == 'N') {
                system("clear || cls");
                return;
            }
            else {
                cout << "Opcao invalida" << endl << endl;
                return;
            }
       }
    }
    cout << "Esse funcionario nao trabalha na clinica" << endl << endl;
}