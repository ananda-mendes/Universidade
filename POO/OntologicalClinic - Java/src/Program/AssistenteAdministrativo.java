package Program;

import java.util.List;

public class AssistenteAdministrativo extends Administrador {
    
    // CONSTRUTOR VAZIO
    public AssistenteAdministrativo() {}

    public AssistenteAdministrativo(String salario, String cargaHoraria, String cargo, String nome, 
            String sobrenome, String endereco, String email, String CPF, 
            String RG, String telefone, String idade, String login, String senha) {
        super(salario, cargaHoraria, cargo, nome, sobrenome, endereco, email, CPF, 
                RG, telefone, idade, login, senha);
    }
}
