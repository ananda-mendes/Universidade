#ifndef CLINICA_HPP
#define CLINICA_HPP

#include <iostream>
#include <cstring>

using namespace std;
class Clinica {
    string nomeEmpresa;
    string endereco;

public: 
    Clinica();
    Clinica(string, string);
    ~Clinica();

    string getNomeEmpresa() const;
    void setNomeEmpresa(string);
    
    string getEndereco() const;
    void setEndereco(string);
};

#endif