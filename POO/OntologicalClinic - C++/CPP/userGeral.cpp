#include "../HPP/userGeral.hpp"
#include <unistd.h>

UserGeral::UserGeral(string nome, int idade, double salario, int cargaHoraria, int cargo, string login, string senha) 
    : Administrador (nome, idade, salario, cargaHoraria, cargo, login, senha), Pessoa (nome, idade), Funcionario (nome, idade, salario, cargaHoraria, cargo) {}


UserGeral::~UserGeral() {}

void UserGeral::acessarSistema(UserGeral user) {
    list<UserGeral> users;
    list<UserGeral>::iterator i;

    list<Dentista> dentista;

    Clinica clinica;
    
    users.push_back(user);
    
    string login, senha;

    system ("clear || cls");
    cout << "--------------CLINICA " << clinica.getNomeEmpresa() << "--------------" << endl << endl;
    
    while(true) {
        cout << "Login: ";
        cin >> login;
        cout << "Senha: ";
        cin >> senha;
        for(i = users.begin(); i != users.end(); i++){
            if(login != i->getLogin() or senha != i->getSenha()) {
                system("clear || cls");
                cout << "Acesso inválido, por favor tente novamente" << endl << endl;
            }
            else {
                system("clear || cls");
                cout << "Bem vindo " << i->getNome() << endl << endl;
                
                mostrarMenu(&dentista);
            }
        }
    };
}

void UserGeral::mostrarMenu(list<Dentista> *dentista) {
    Agenda agenda;

    int comando;

    while(true) {
        cout << "------------MENU------------" << endl;
        cout << "01 - Acessar agenda" << endl;
        cout << "00 - Fechar Sistema" << endl << endl;

        cout << "Digite uma opcao: ";
        cin >> comando;
        system("clear || cls");

        switch(comando) {
            case 01: {
                agenda.abrirAgenda(dentista);
                break;
            }
            case 00: {
                cout << "ENCERRANDO SESSÃO..." << endl;
                usleep(1000000);
                exit(0);
            }
        }
    }
}