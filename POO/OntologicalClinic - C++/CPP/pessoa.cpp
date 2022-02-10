#include "../HPP/pessoa.hpp"

Pessoa::Pessoa(string nome, int idade) : nome(nome), idade(idade) {}

Pessoa::~Pessoa() {}

string Pessoa::getNome() const {
    return this->nome;
}

void Pessoa::setNome(string nome) {
    this->nome = nome;
}

int Pessoa::getIdade() const {
    return idade;
}

void Pessoa::setIdade(int idade) {
    this->idade = idade;
}