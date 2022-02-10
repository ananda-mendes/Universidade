#ifndef ASSISTENTEADMIN_HPP
#define ASSISTENTEADMIN_HPP

#include "admin.hpp"
class assistenteAdmin: virtual public Administrador {

public: 
    assistenteAdmin (string nome = "", int idade = 0, double salario = 0.0, int cargaHoraria = 0, int cargo = 1, string login="admin", string senha="admin");
    ~assistenteAdmin();
};

#endif