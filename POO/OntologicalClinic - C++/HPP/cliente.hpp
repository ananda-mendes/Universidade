#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include "pessoa.hpp"
class Cliente : virtual public Pessoa {
    bool pagou;
    int diaPagamento;
    int mesPagamento;
    int anoPagamento;


public: 
    Cliente();
    Cliente(string, int, bool, int, int, int);
    ~Cliente();

    bool getPagou() const;
    void setPagou(bool);

    int getDiaPagamento() const;
    void setDiaPagamento(int);

    int getMesPagamento() const;
    void setMesPagamento(int);

    int getAnoPagamento() const;
    void setAnoPagamento(int);
};

#endif