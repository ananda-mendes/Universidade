#include "../HPP/funcionario.hpp"

Funcionario::Funcionario(string nome, int idade, double salario, int cargaHoraria, int cargo) : Pessoa (nome, idade), salario(salario), cargaHoraria(cargaHoraria), cargo(cargo) {}

Funcionario::~Funcionario() {}

double Funcionario::getSalario() const {
    return this->salario;
}
void Funcionario::setSalario(double salario) {
    this->salario = salario;
}

int Funcionario::getCargaHoraria() const {
    return this->cargaHoraria;
}
void Funcionario::setCargaHoraria(int cargaHoraria) {
    this->cargaHoraria = cargaHoraria;
}

int Funcionario::getCargo() const {
    return this->cargo;
}
void Funcionario::setCargo(int cargo) {
    this->cargo = cargo;
}
