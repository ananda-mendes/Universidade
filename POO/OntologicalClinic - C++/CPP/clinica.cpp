#include "../HPP/clinica.hpp"

Clinica::Clinica() {
    this->nomeEmpresa = "CURRAL";
    this->endereco = "Avenida blabla, 1398";
}

Clinica::Clinica(string nomeEmpresa, string endereco) {
    this->nomeEmpresa = nomeEmpresa;
    this->endereco = endereco;
}

Clinica::~Clinica() {}

string Clinica::getNomeEmpresa() const {
    return this->nomeEmpresa;
}

void Clinica::setNomeEmpresa(string nomeEmpresa) {
    this->nomeEmpresa = nomeEmpresa;
}

string Clinica::getEndereco()  const{
    return this->endereco;
}

void Clinica::setEndereco(string endereco) {
    this->endereco = endereco;
}