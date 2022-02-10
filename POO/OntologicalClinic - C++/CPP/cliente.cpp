#include "../HPP/cliente.hpp"

Cliente::Cliente () : Pessoa ("Cliente", 0) {
    this->pagou = false;
    this->diaPagamento = -1;
    this->mesPagamento = -1;
    this->anoPagamento = -1;
}

Cliente::Cliente(string nome, int idade, bool pagou, int diaPagamento, int mesPagamento, int anoPagamento) : Pessoa (nome, idade) {
    this->pagou = pagou;
    this->diaPagamento = diaPagamento;
    this->mesPagamento = mesPagamento;
    this->anoPagamento = anoPagamento;
}

Cliente::~Cliente() {}

bool Cliente::getPagou() const {
    return this->pagou;
}

void Cliente::setPagou(bool pagamento) {
    this->pagou = false;
}

int Cliente::getDiaPagamento() const {
    return this->diaPagamento;
}

void Cliente::setDiaPagamento(int dia) {
    this->diaPagamento = dia;
}

int Cliente::getMesPagamento() const {
    return this->mesPagamento;
}

void Cliente::setMesPagamento(int mes) {
    this->mesPagamento = mes;
}

int Cliente::getAnoPagamento() const {
    return this->anoPagamento;
}

void Cliente::setAnoPagamento(int ano) {
    this->anoPagamento = ano;
}