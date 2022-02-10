#include "../HPP/agenda.hpp"
#include <unistd.h>

Agenda::Agenda() {
    this->dia = -1;
    this->mes = -1;
    this->ano = -1;
    this->hora = -1;
    this->minutos = -1;
}

Agenda::Agenda(int dia, int mes, int ano, int hora, int minutos) {
    this->dia = dia;
    this->mes = mes;
    this->ano = ano;
    this->hora = hora;
    this->minutos = minutos;
}

Agenda::~Agenda() {}

int Agenda::getDia() const {
    return this->dia;
}

void Agenda::setDia(int dia) {
    this->dia = dia;
}

int Agenda::getMes() const {
    return this->mes;
}

void Agenda::setMes(int mes) {
    this->mes = mes;
}

int Agenda::getAno() const {
    return this->ano;
}

void Agenda::setAno(int ano) {
    this->ano = ano;
}

int Agenda::getHora() const {
    return this->hora;
}

void Agenda::setHora(int hora) {
    this->hora = hora;
}

int Agenda::getMinutos() const {
    return this->minutos;
}

void Agenda::setMinutos(int minutos) {
    this->minutos = minutos;
}

void Agenda::abrirAgenda(list<Dentista> *dentista) {
    list<Agenda> agenda;
    list<Agenda>::iterator j;

    list<Dentista>::iterator i;

    string nome;

    bool encontrou = 0;
    bool sairDaAgenda = 0;

    do {
        //Verifica se há dentistas cadastrados
        if((*dentista).size() == 0) {
            Dentista dentistaPadrao ("Maria", 20, 2000.0, 8, 03, {}, {});
            dentista->push_back(dentistaPadrao);
        }

        do {
            //Imprime os dentistas disponíveis
            cout << "Dentistas disponíveis: " << endl;
            for (i = (*dentista).begin(); i != (*dentista).end(); i++) {
                cout << i->getNome() << endl;
            }
            cout << endl << "Qual deles você deseja visualizar a agenda? ";
            cin >> nome;

            //Transforma std::string em const char para que possa ser comparada no strcmp
            for (i = (*dentista).begin(); i != (*dentista).end(); i++) {
                if (strcmp (i->getNome().c_str(), nome.c_str()) == 0) {
                    system("clear || cls");
                    cout << "Agenda do dentista: " << i->getNome() << endl;
                    
                    for (j = agenda.begin(); j != agenda.end(); j++) {
                        cout << j->getDia() << "/" << j->getMes() << "/" << j->getAno() << '\t' << j->getHora() << ":" << j->getMinutos() << endl;
                    }
                    encontrou = 1;
                    break;
                }
            }

            if (encontrou != 1) {
                system("clear || cls");
                cout << "Nome inválido ou incorreto!" << endl << endl;
                usleep(1000000);
                system("clear || cls");
            }

        } while (encontrou != 1);

        char opcao;
        do {
            cout << endl << "Deseja editar a agenda (S/N)? ";
            cin >> opcao;
            if (opcao != 'S' and opcao != 'N') {
                cout << "Comando inválido, digite novamente!" << endl << endl;
            }
        } while(opcao != 'S' and opcao != 'N');

        if (opcao == 'S') {
            Cliente paciente;
            string nomePaciente;
            int idade;
            bool valida;
                
            do {
                valida = 1;

                cout << "Qual seu nome: ";
                cin.ignore();
                getline(cin, nomePaciente);

                char aux[(nomePaciente).length()];
                strcpy(aux, (nomePaciente).c_str());

                for(int i = 0; i < (nomePaciente).length(); i++) {
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
                cin >> idade;

                if (idade < 18 or idade > 90) {
                    cout << "Idade Mínima: 18 anos" << endl;
                    cout << "Idade Máxima: 90 anos" << endl;
                    valida = 0;
                }
            } while (valida != 1);

            paciente.setNome(nomePaciente);
            paciente.setIdade(idade);

            //Associando o paciente ao dentista selecionado
            for (i = (*dentista).begin(); i != (*dentista).end(); i++) {
                if (strcmp (i->getNome().c_str(), nome.c_str()) == 0) {
                    i->setPaciente(paciente);
                }
            }

            cout << endl;

            editarAgenda(&agenda);
        }
        else {
            system("clear || cls");
            cout << "Redirecionando para o menu..." << endl;
            usleep(2000000);
            system("clear || cls");

            sairDaAgenda = 1;
        }
    } while (sairDaAgenda != 1);
}

void Agenda::editarAgenda(list<Agenda> *agenda) {
    Agenda aux;
    list<Agenda>::iterator i;
    int comando;

    do{
        cout << "01 - Agendar Consulta" << endl;
        cout << "02 - Desmarcar Consulta" << endl;
        cout << "03 - Sair" << endl << endl;
        cout << "Comando: ";
        cin >> comando;

        if(comando != 01 and comando != 02 and comando != 03) {
            cout << "Comando inválido, digite novamente" << endl;
        }
    }while(comando != 01 and comando != 02 and comando != 03);

    int dia, mes, ano, hora, minutos;
    char barra = '/', doisPontos = ':', espaco = '-';

    system("clear || cls");
    
    if(comando == 1) {
        bool agendar = 1;

            cout << "*** AGENDAMENTO DE CONSULTA ***" << endl << endl;
            do {
                cout << "Data (dd/mm/aa): ";
                cin >> dia >> barra >> mes >> barra >> ano;
                
                // Validação da data
                if(dia < 1 or dia > 31 or mes < 1 or mes > 12 or ano < 21 or ano > 23) {
                    if (ano < 21 or ano > 23) cout << "Agendamentos apenas para os próximos 2 anos" << endl;
                    cout << "Data Inválida, digite novamente..." << endl << endl;
                }
            } while (dia < 1 or dia > 31 or mes < 1 or mes > 12 or ano < 21 or ano > 23);
            
            do {
                cout << "Horário (hh:mm): ";
                cin >> hora >> doisPontos >> minutos;
                
                // Validação da hora
                if(hora < 0 or hora > 23 or minutos < 0 or minutos > 59) {
                    cout << "Horário Inválido, digite novamente..." << endl << endl;
                }
            } while (hora < 0 or hora > 23 or minutos < 0 or minutos > 59);
            
        system("clear || cls");

        //Verifica se esse horário já foi reservado
        for(i = (*agenda).begin(); i != (*agenda).end(); i++) {
            if(dia == i->getDia() and mes == i->getMes() and ano == i->getAno() and hora == i->getHora() and minutos == i->getMinutos()) {
                cout << "Horário já reservado" << endl;
                agendar = 0;
                break;
            }
        }

        //Agenda esse horário
        if(agendar != 0) {
            aux.setDia(dia);
            aux.setMes(mes);
            aux.setAno(ano);
            aux.setHora(hora);
            aux.setMinutos(minutos);

            (*agenda).push_back(aux);
        }
    }

    else if (comando == 2) {
        do{
           cout << "*** DESAGENDAMENTO DE CONSULTA ***" << endl << endl;
            cout << "Data (dd/mm/aa): ";
            cin >> dia >> barra >> mes >> barra >> ano;
            cout << "Horário (hh:mm): ";
            cin >> hora >> doisPontos >> minutos;

            if(dia < 1 or dia > 31 or mes < 1 or mes > 12 or ano < 21 or ano > 23) {
                cout << "Data Inválida, digite novamente..." << endl;
            } 
            if(hora < 0 or hora > 23 or minutos < 0 or minutos > 59) {
                cout << "Horário Inválido, digite novamente..." << endl;
            }
        } while(dia < 1 or dia > 31 or mes < 1 or mes > 12 or ano < 21 or ano > 23 or hora < 0 or hora > 23 or minutos < 0 or minutos > 59);
        
        system("clear || cls");

        for(i = (*agenda).begin(); i != (*agenda).end(); i++) {
            if(dia != i->getDia() or mes != i->getMes() or ano != i->getAno() or hora != i->getHora() or minutos != i->getMinutos()) {
                cout << "Consulta Inexistente" << endl;
                break;
            }
            if(dia == i->getDia() or mes == i->getMes() or ano == i->getAno() or hora == i->getHora() or minutos == i->getMinutos()) {
                (*agenda).erase(i);
                cout << "Consulta Desmarcada" << endl;
                break;
            }
        }
    }

    else if (comando == 3)  {
        system("clear || cls");
        cout << "Redirecionando para o menu..." << endl;
        usleep(2000000);
        system("clear || cls");
        return;
    }
}