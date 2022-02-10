package Program;

public class Clinica {
    private String nomeEmpresa;
    private String endereco;
    private String cnpj;
    private String telefone;
    private String email;

    // CONTRUTOR VAZIO
    public Clinica() {
        this.nomeEmpresa = "CURRAL";
        this.endereco = "Rua Qualquer, nº 22";
        this.cnpj = "12121212121";
        this.telefone = "3333-3333";
        this.email = "curral@contato.com";
    }

    public Clinica(String nomeEmpresa, String endereco, String cnpj, String telefone, String email) {
        this.nomeEmpresa = nomeEmpresa;
        this.endereco = endereco;
        this.cnpj = cnpj;
        this.telefone = telefone;
        this.email = email;
    }

    /* GETTERS */
    // RETORNA O NOME DA EMPRESA
    public String getNomeEmpresa() {
        return nomeEmpresa;
    }
    // RETORNA O ENDEREÇO DA EMPRESA
    public String getEndereco() {
        return endereco;
    }
    // RETORNA O CNPJ DA EMPRESA
    public String getCnpj() {
        return cnpj;
    }
    // RETORNA O TELEFONE DA EMPRESA
    public String getTelefone() {
        return telefone;
    }
    // RETORNA O EMAIL DA EMPRESA
    public String getEmail() {
        return email;
    }

    /* SETTERS */
    // ALTERA O NOME DA EMPRESA
    protected void setNomeEmpresa(String nomeEmpresa) {
        this.nomeEmpresa = nomeEmpresa;
    }
    // ALTERA O ENDEREÇO DA EMPRESA
    protected void setEndereco(String endereco) {
        this.endereco = endereco;
    }
    // ALTERA O CNPJ DA EMPRESA
    protected void setCnpj(String cnpj) {
        this.cnpj = cnpj;
    }
    // ALTERA O TELEFONE DA EMPRESA
    protected void setTelefone(String telefone) {
        this.telefone = telefone;
    }
    // ALTERA O EMAIL DA EMPRESA
    protected void setEmail(String email) {
        this.email = email;
    }   
}
