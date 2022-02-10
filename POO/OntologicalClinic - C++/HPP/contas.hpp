#ifndef CONTAS_HPP
#define CONTAS_HPP 

#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

class Contas {
    double valor;

    int diaVencimento;
    int mesVencimento;
    int anoVencimento;

    int diaPagamento;
    int mesPagamento;
    int anoPagamento;

    string tipo;

public: 
    Contas(double = 0.0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, string = "");
    ~Contas();


    double getValor() const;
    void setValor(double);

    string getTipoConta() const;
    void setTipoConta(string);

    // VENCIMENTO
    int getDiaVencimento() const;
    void setDiaVencimento(int);

    int getMesVencimento() const;
    void setMesVencimento(int);

    int getAnoVencimento() const;
    void setAnoVencimento(int);

    // PAGAMENTO
    int getDiaPagamento() const;
    void setDiaPagamento(int);

    int getMesPagamento() const;
    void setMesPagamento(int);

    int getAnoPagamento() const;
    void setAnoPagamento(int);

    void pagamentoContas(FILE*);
};

#endif
