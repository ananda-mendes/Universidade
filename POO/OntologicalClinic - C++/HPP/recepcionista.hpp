#ifndef RECEPCIONISTA_HPP
#define RECEPCIONISTA_HPP

#include "funcionario.hpp"
class Recepcionista : virtual public Funcionario {
public: 
    Recepcionista(string nome = "", int idade = 0, double salario = 0.0, int cargaHoraria = 0, int cargo = 0);
    ~Recepcionista();
};

#endif