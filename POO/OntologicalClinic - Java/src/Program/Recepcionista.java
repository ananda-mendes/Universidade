package Program;

public class Recepcionista extends Funcionario {

    // CONSTRUTOR VAZIO
    public Recepcionista() {}

    public Recepcionista(String salario, String cargaHoraria, String cargo, 
            String nome, String sobrenome, String endereco, String email, 
            String CPF, String RG, String telefone, String idade) {
        super(salario, cargaHoraria, cargo, nome, sobrenome, endereco, email, 
                CPF, RG, telefone, idade);
    }

}
