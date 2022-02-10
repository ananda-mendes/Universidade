package Program;

public class Funcionario extends Pessoa {
    String salario;
    String cargaHoraria;
    String cargo;

    // CONSTRUTOR VAZIO
    public Funcionario() {}

    public Funcionario(String salario, String cargaHoraria, String cargo, String nome, String sobrenome, String endereco, String email, String CPF, String RG, String telefone, String idade) {
        super(nome, sobrenome, endereco, email, CPF, RG, telefone, idade);
        this.salario = salario;
        this.cargaHoraria = cargaHoraria;
        this.cargo = cargo;
    }

    /* GETTERS */
    // RETORNA O SALARIO DO FUNCIONARIO
    public String getSalario() {
        return salario;
    }
    // RETORNA A CARGA HORARIA DO FUNCIONARIO
    public String getCargaHoraria() {
        return cargaHoraria;
    }
    // RETORNA O CARGO DO FUNCIONARIO
    public String getCargo() {
        return cargo;
    }

    /* SETTERS */
    // ALTERA O SALARIO DO FUNCIONARIO
    protected void setSalario(String salario) {
        this.salario = salario;
    }
    // ALTERA A CARGA HORARIA DO FUNCIONARIO
    protected void setCargaHoraria(String cargaHoraria) {
        this.cargaHoraria = cargaHoraria;
    }
    // ALTERA O CARGO DO FUNCIONARIO
    protected void setCargo(String cargo) {
        this.cargo = cargo;
    }
}
