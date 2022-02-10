#ifndef AGENDA_HPP
#define AGENDA_HPP 

#include <vector>
#include <list>

#include "dentista.hpp"

class Agenda {
    int dia;
    int mes;
    int ano;
    int hora;
    int minutos;

public: 
    Agenda();
    Agenda(int dia, int mes, int ano, int hora, int minutos);
    ~Agenda();

    int getDia() const;
    void setDia(int);

    int getMes() const;
    void setMes(int);

    int getAno() const;
    void setAno(int);

    int getHora() const;
    void setHora(int);

    int getMinutos() const;
    void setMinutos(int);

    void abrirAgenda(list<Dentista> *dentista);
    void editarAgenda(list<Agenda> *agenda);
};

#endif