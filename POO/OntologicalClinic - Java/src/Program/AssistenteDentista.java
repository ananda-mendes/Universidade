package Program;

public class AssistenteDentista extends Funcionario {

    // CONSTRUTOR VAZIO
    public AssistenteDentista() {}

    public AssistenteDentista(String salario, String cargaHoraria, String cargo, 
            String nome, String sobrenome, String endereco, String email, 
            String CPF, String RG, String telefone, String idade) {
        super(salario, cargaHoraria, cargo, nome, sobrenome, endereco, email, 
                CPF, RG, telefone, idade);
    }
}
