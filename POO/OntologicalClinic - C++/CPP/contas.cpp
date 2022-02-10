#include "../HPP/contas.hpp"

Contas::Contas (double valor, int diaVencimento, int mesVencimento, int anoVencimento, int diaPagamento, int mesPagamento, int anoPagamento , string tipo) {
    setValor(valor);
    
    setDiaVencimento(diaVencimento);
    setMesVencimento(mesVencimento);
    setAnoVencimento(anoVencimento);

    setDiaPagamento(diaPagamento);
    setMesPagamento(mesPagamento);
    setAnoPagamento(anoPagamento);

    setTipoConta(tipo);
}

Contas::~Contas() {}
 
string Contas::getTipoConta() const {
    return this->tipo;
}
void Contas::setTipoConta(string tipo) {
    this->tipo = tipo;
}

double Contas::getValor() const {
    return this->valor;
}
void Contas::setValor(double valor) {
    this->valor = valor;
}

// VENCIMENTO
int Contas::getDiaVencimento() const {
    return this->diaVencimento;
}
void Contas::setDiaVencimento(int diaVencimento) {
    this->diaVencimento = diaVencimento;
}

int Contas::getMesVencimento() const {
    return this->mesVencimento;
}
void Contas::setMesVencimento(int mesVencimento) {
    this->mesVencimento = mesVencimento;
}

int Contas::getAnoVencimento() const {
    return this->anoVencimento;
}
void Contas::setAnoVencimento(int anoVencimento) {
    this->anoVencimento = anoVencimento;
}

// PAGAMENTO
int Contas::getDiaPagamento() const {
    return this->diaPagamento;
}
void Contas::setDiaPagamento(int diaPagamento) {
    this->diaPagamento = diaPagamento;
}

int Contas::getMesPagamento() const {
    return this->mesPagamento;
}
void Contas::setMesPagamento(int mesPagamento) {
    this->mesPagamento = mesPagamento;
}

int Contas::getAnoPagamento() const {
    return this->anoPagamento;
}
void Contas::setAnoPagamento(int anoPagamento) {
    this->anoPagamento = anoPagamento;
}

void Contas::pagamentoContas(FILE* arq) {
    Contas conta;
    char barra;
    cout << "Qual conta deseja pagar? ";
    cin >> conta.tipo;
    cout << "Data de vencimento? No seguinte formato dia/mes/ano: ";
    cin >> conta.diaVencimento >> barra >> conta.mesVencimento >> barra >> conta.anoVencimento;
    cout << "Valor: ";
    cin >> conta.valor;

    //Utilizando a struct tm para pegar a data direto do sistema
    struct tm *p;
    time_t seconds;
    time(&seconds);
    p = localtime(&seconds);

    //Verificar se deseja realizar o pagamento
    char opcao;
    cout << "Deseja realizar o pagamento? S ou N" << endl;
    cin >> opcao;
    if (opcao == 'S') { 
        conta.diaPagamento = p->tm_mday;
        conta.mesPagamento = p->tm_mon + 1;
        conta.anoPagamento = p->tm_year + 1900;
        cout << endl;
        fprintf (arq, "%d%c%d%c%d \t %s \t %.2lf", conta.diaPagamento, barra, conta.mesPagamento, barra, conta.anoPagamento, conta.getTipoConta().c_str(), conta.valor);
    }
    else {
        cout << "Não foi paga" << endl;
    }
}