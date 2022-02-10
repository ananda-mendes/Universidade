#ifndef ADMIN_HPP
#define ADMIN_HPP

#include "recepcionista.hpp"
#include "agenda.hpp"
#include "consulta.hpp"
#include "contas.hpp"
#include "clinica.hpp"
#include "dentista.hpp"
class Administrador : virtual public Funcionario {
    string login;
    string senha;

private:
    //Cria Pessoas
    Administrador criarAdministrador(string nome, int idade, double salario, int cargaHoraria, int cargo);
    Administrador criarAssistenteAdm(string nome, int idade, double salario, int cargaHoraria, int cargo);
    Dentista criarDentista(string nome, int idade, double salario, int cargaHoraria, int cargo);
    Funcionario criarAssistenteDeDentista(string nome, int idade, double salario, int cargaHoraria, int cargo);
    Recepcionista criarRecepcionista(string nome, int idade, double salario, int cargaHoraria, int cargo);
    Cliente criarCliente(string nome, int idade);

    void leDados(string *nome, int *idade, double *salario, int *cargaHoraria, int *cargo);
    void gerarRelatorio();
    void mostrarMenu(list<Administrador> *administrador, list<Administrador> *assistenteAdmin, list<Dentista> *dentista, list<Funcionario> *assistenteDeDentista, list<Recepcionista> *recepcionista);
    void folhaDePonto(list<Administrador> administrador, list<Administrador> assistenteAdmin, list<Dentista> dentista, list<Funcionario> assistenteDeDentista, list<Recepcionista> recepcionista, FILE* arquivo);

public: 
    Administrador(string nome = "", int idade = 0, double salario = 0.0, int cargaHoraria = 0, int cargo = 1, string login="admin", string senha="admin");
    ~Administrador();

    string getLogin() const;
    void setLogin(string login);

    string getSenha() const;
    void setSenha(string senha);

    void acessarSistema(Administrador administrador);

};

#endif 