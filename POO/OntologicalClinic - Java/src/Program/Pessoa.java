package Program;

public class Pessoa {
    private String nome;
    private String sobrenome;
    private String endereco;
    private String email;
    private String CPF;
    private String RG;
    private String telefone;
    private String idade;
    

    // CONSTRUTOR VAZIO
    public Pessoa() {}

    public Pessoa(String nome, String sobrenome, String endereco, String email, String CPF, String RG, 
            String telefone, String idade) {
        this.nome = nome;
        this.sobrenome = sobrenome;
        this.endereco = endereco;
        this.email = email;
        this.CPF = CPF;
        this.RG = RG;
        this.telefone = telefone;
        this.idade = idade;
    }

    /* GETTERS */
    // RETURNA O NOME DA PESSOA
    public String getNome() {
        return nome;
    }
    // RETORNA O SOBRENOME DA PESSOA
    public String getSobrenome() {
        return sobrenome;
    }
    // RETORNA O ENDERECO DA PESSOA
    public String getEndereco() {
        return endereco;
    }
    // RETORNA O EMAIL DA PESSOA
    public String getEmail() {
        return email;
    }
    // RETORNA O CPF DA PESSOA
    public String getCPF() {
        return CPF;
    }
    // RETORNA O RG DA PESSOA
    public String getRG() {
        return RG;
    }
    // RETORNA O TELEFONE DA PESSOA
    public String getTelefone() {
        return telefone;
    }
    // RETORNA A DATA DE NASCIMENTO DA PESSOA
    public String getIdade() {
        return idade;
    }

    /* SETTERS */
    // ALTERA O NOME DA PESSOA
    protected void setNome(String nome) {
        this.nome = nome;
    }
    // ALTERA O SOBRENOME DA PESSOA
    protected void setSobrenome(String sobrenome) {
        this.sobrenome = sobrenome;
    }
    // ALTERA O ENDEREÇO DA PESSOA
    protected void setEndereco(String endereco) {
        this.endereco = endereco;
    }
    // ALTERA O EMAIL DA PESSOA
    protected void setEmail(String email) {
        this.email = email;
    }
    // ALTERA O CPF DA PESSOA
    protected void setCPF(String CPF) {
        this.CPF = CPF;
    }
    // ALTERA O RG DA PESSOA
    protected void setRG(String RG) {
        this.RG = RG;
    }
    // ALTERA O TELEFONE DA PESSOA
    protected void setTelefone(String telefone) {
        this.telefone = telefone;
    }
    // ALTERA A DATA DE NASCIMENTO DA PESSOA
    protected void setIdade(String idade) {
        this.idade = idade;
    }
}
