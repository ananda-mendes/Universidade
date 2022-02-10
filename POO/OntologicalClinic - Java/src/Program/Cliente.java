package Program;

public class Cliente extends Pessoa{
    private String dataPagamento;
    private String dataVencimento;

    // CONSTRUTOR VAZIO
    public Cliente() {
    }

    public Cliente(String dataPagamento, String dataVencimento, String nome, String sobrenome, String endereco, String email, String CPF, String RG, String telefone, String idade) {
        super(nome, sobrenome, endereco, email, CPF, RG, telefone, idade);
        this.dataPagamento = dataPagamento;
        this.dataVencimento = dataVencimento;
    }
    
    /* GETTERS */
    // RETORNA O DIA DO PAGAMENTO
    public String getDataPagamento() {
        return dataPagamento;
    }
    // RETORNA O MES DO PAGAMENTO
    public String getDataVencimento() {
        return dataVencimento;
    }

    /* SETTERS */
    // ALTERA A DATA DO PAGAMENTO
    protected void setDataPagamento(String dataPagamento) {
        this.dataPagamento = dataPagamento;
    }
    // ALTERA A DATA DO VENCIMENTO
    protected void setDataVencimento(String dataVencimento) {
        this.dataVencimento = dataVencimento;
    }
    
}
