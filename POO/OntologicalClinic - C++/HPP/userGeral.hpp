#ifndef USERGERAL_HPP
#define USERGERAL_HPP

#include "admin.hpp"
class UserGeral : virtual public Administrador {
public: 
    UserGeral(string nome = "", int idade = 0, double salario = 0.0, int cargaHoraria = 0, int cargo = 1, string login="admin", string senha="admin");
    ~UserGeral();

    void acessarSistema(UserGeral user);
    void mostrarMenu(list<Dentista> *dentista);
};

#endif