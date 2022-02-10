#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <iostream>
#include <cstring>

using namespace std;

class Pessoa {
private:
    string nome;
    int idade;

public: 
    Pessoa(string nome = "Pessoa", int idade = 0);
    ~Pessoa();

    string getNome() const;
    int getIdade() const;

    void setNome(string);
    void setIdade(int);
};

#endif
