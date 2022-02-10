#include "../HPP/dentista.hpp"

Dentista::Dentista(string nome, int idade, double salario, int cargaHoraria, int cargo, Funcionario assistente, Cliente paciente) 
    : Pessoa(nome, idade), Funcionario (nome, idade, salario, cargaHoraria, cargo), assistenteDeConsultorio(assistente), paciente(paciente) {}

Dentista::~Dentista() {}

void Dentista::setAssistente(Funcionario assistente) {
    this->assistenteDeConsultorio = assistente;
}

Funcionario Dentista::getAssistente() const {
    return this->assistenteDeConsultorio;
}

void Dentista::setPaciente (Cliente paciente) {
    this->paciente = paciente;
}

Cliente Dentista::getPaciente() const {
    return this->paciente;
}