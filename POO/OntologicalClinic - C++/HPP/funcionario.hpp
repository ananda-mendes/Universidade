#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP

#include "pessoa.hpp"
class Funcionario : virtual public Pessoa {
    double salario;
    int cargaHoraria;
    int cargo;

public:
    Funcionario(string nome = "", int idade = 0, double salario = 0.0,  int cargaHoraria = 0,  int cargo = 05);
    ~Funcionario();

    double getSalario() const;
    void setSalario(double);

    int getCargaHoraria() const;
    void setCargaHoraria(int);

    int getCargo() const;
    void setCargo (int);
};

#endif