#ifndef DENTISTA_HPP
#define DENTISTA_HPP

#include "funcionario.hpp"
#include "cliente.hpp"

class Dentista : virtual public Funcionario {
    Funcionario assistenteDeConsultorio;
    Cliente paciente;
    
public: 
    Dentista(string nome = "", int idade = 0, double salario = 0.0, int cargaHoraria = 0, int cargo = 03, Funcionario assistente = {}, Cliente paciente = {});
    ~Dentista();

    void setAssistente (Funcionario);
    Funcionario getAssistente() const;

    void setPaciente (Cliente);
    Cliente getPaciente() const;
};

#endif