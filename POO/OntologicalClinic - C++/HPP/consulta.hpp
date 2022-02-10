#ifndef CONSULTA_HPP
#define CONSULTA_HPP 

#include <time.h>
#include <stdio.h>

#include "cliente.hpp"

class Consulta {
    double valor;
    bool confirmarPagamento;
    int diaPagamento;
    int mesPagamento;
    int anoPagamento;

public:
    Consulta (double valor = 0.0, bool confirmarPagamento = false, int diaPagamento = 0, int mesPagamento = 0, int anoPagamento = 0);
    ~Consulta();

    double getValorConsulta() const;
    void setValorConsulta (double);

    bool getConfirmarPagamento () const;
    void setConfirmarPagamento (bool);

    int getDiaPagamentoConsulta() const;
    void setDiaPagamentoCosulta(int);

    int getMesPagamentoConsulta() const;
    void setMesPagamentoCosulta(int);

    int getAnoPagamentoConsulta() const;
    void setAnoPagamentoCosulta(int);

    void receberConsulta(FILE*, Cliente);
};


#endif