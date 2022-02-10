#include "../HPP/consulta.hpp"

Consulta::Consulta(double valor, bool confirmarPagamento, int diaPagamento, int mesPagamento, int anoPagamento) : valor(valor), confirmarPagamento(confirmarPagamento), diaPagamento(diaPagamento), mesPagamento(mesPagamento), anoPagamento(anoPagamento) {}

Consulta::~Consulta() {}

double Consulta::getValorConsulta() const {
    return this->valor;
}

void Consulta::setValorConsulta (double valor) {
    this->valor = valor;
}

bool Consulta::getConfirmarPagamento () const {
    return this->confirmarPagamento;
}

void Consulta::setConfirmarPagamento (bool confirmarPagamento) {
    this->confirmarPagamento = confirmarPagamento;
} 

int Consulta::getDiaPagamentoConsulta() const {
    return this->diaPagamento;
}

void Consulta::setDiaPagamentoCosulta(int diaPagamento) {
    this->diaPagamento = diaPagamento;
}

int Consulta::getMesPagamentoConsulta() const {
    return this->mesPagamento;
}

void Consulta::setMesPagamentoCosulta(int mesPagamento) {
    this->mesPagamento = mesPagamento;
}

int Consulta::getAnoPagamentoConsulta() const {
    return this->anoPagamento;
}

void Consulta::setAnoPagamentoCosulta(int anoPagamento) {
    this->anoPagamento = anoPagamento;
}

void Consulta::receberConsulta(FILE* arq, Cliente paciente) {
    Consulta consulta(0.0, false, 0, 0, 0);
    char barra = '/';

    //Utilizando a struct tm para pegar a data direto do sistema
    struct tm *p;
    time_t seconds;
    time(&seconds);
    p = localtime(&seconds);
    cout << "Valor: ";
    cin >> consulta.valor;
    char opcao;
    cout << "Confirmar pagamento? S ou N" << endl;
    cin >> opcao;
    
    if (opcao == 'S') {
        consulta.confirmarPagamento = true;
        cout << endl << "Pagamento confirmado" << endl << endl;;
        consulta.diaPagamento = p->tm_mday;
        consulta.mesPagamento = p->tm_mon + 1;
        consulta.anoPagamento = p->tm_year + 1900;
        fprintf(arq, "%d%c%d%c%d \t %s \t %.2lf\n", consulta.diaPagamento, barra, consulta.mesPagamento, barra, consulta.anoPagamento, paciente.getNome().c_str(), consulta.valor);
        paciente.setPagou(consulta.confirmarPagamento);
    }
    else {
        consulta.confirmarPagamento = false;
        cout << endl << "Pagamento nao realizado" << endl << endl;;
    }
}