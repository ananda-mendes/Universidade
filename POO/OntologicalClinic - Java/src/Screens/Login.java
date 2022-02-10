package Screens;
import Program.Administrador;
import Program.Clinica;

import java.awt.Color; // alterar cor
import java.awt.Font; // alterar fonte
import java.awt.event.ActionEvent; // lidar com alteração de comportamento
import java.awt.event.ActionListener; // lidar com alteração de comportamento

import javax.swing.JFrame; // fornece as funcionalidade básicas de janelas
import javax.swing.JLabel; // exibe texto e imagem
import javax.swing.JButton; // lida com botoes
import javax.swing.JPasswordField; // lida com senhas
import javax.swing.JTextField; // lida com caixas de inserção de texto

public class Login extends JFrame{
    // lida com entrada de usuario
    Administrador admin = new Administrador();
    Clinica clinica = new Clinica(); // criado para fornecer exclusivamente o nome da clinica

    private JLabel usuarioLabel;
    private JTextField usuarioTextField;
    
    // lida com entrada de senha
    private JLabel senhaLabel;
    private JPasswordField senhaField;
    
    private JButton loginButton; // botao de login
    private JButton sairButton; // botao de login
    private JLabel warningLabel; // botao de aviso
    
    public Login(){
        setTitle(clinica.getNomeEmpresa()); // define o titulo do programa

        usuarioTextField = new JTextField(20); // variavel de inserção de dados
        usuarioTextField.setBounds(300, 200, 200, 20); // define a posição da caixa na tela
        add(usuarioTextField); // adiciona ao JFrame
        usuarioLabel = new JLabel("User"); // variavel que define a caixa de texto
        usuarioLabel.setToolTipText("Enter the user id"); // dica do que faz
        usuarioLabel.setBounds(300, 180, 200, 20); // define a posição do label na tela
        add(usuarioLabel); // adiciona ao JFrame
        
        senhaField = new JPasswordField(20); // variavel de inserção de dados
        senhaField.setBounds(300, 250, 200, 20); // define a posição da caixa na tela
        add(senhaField); // adiciona ao JFrame
        senhaLabel = new JLabel("Password"); // variavel que define a caixa de texto
        senhaLabel.setToolTipText("Enter the password login"); // dica do que faz
        senhaLabel.setBounds(300, 230, 200, 20); // define a posição do label na tela
        add(senhaLabel); // adiciona ao JFrame
        
        ValidarLogin handler = new ValidarLogin(); // variavel que lida com as alterações
        loginButton = new JButton("Login"); // botao para acessar o sistema
        loginButton.setBounds(400, 280, 100, 20); // define a posição do botão na tela
        loginButton.setFocusable(false); // retira a caixa que fica em volta do texto do botão
        loginButton.addActionListener(handler); // ouve alterações de comportamento
        add(loginButton);
        
        sairButton = new JButton("Sair"); // botao para acessar o sistema
        sairButton.setBounds(300, 280, 100, 20); // define a posição do botão na tela
        sairButton.setFocusable(false); // retira a caixa que fica em volta do texto do botão
        sairButton.addActionListener(handler); // ouve alterações de comportamento
        add(sairButton); // adiciona ao JFrame
        
        warningLabel = new JLabel(); // variavel de aviso para entrada invalida
        warningLabel.setBounds(300, 300, 200, 20); // define a posição do aviso na tela
        warningLabel.setFont(new Font(null, Font.ITALIC, 12)); // define a fonte do aviso de erro
        add(warningLabel); // adiciona ao JFrame
        
        
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // define a operação default de encerramento
        setResizable(false); // bloqueia o tamnho da tela
        setSize(800, 600); // ajusta o tamanho do frame
        setLayout(null); // uso de nenhum layout pré-definido
        setVisible(true); // exibe o frame
    }
    
    // valida comportamentos alterados
    private class ValidarLogin implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent event) {
            if(event.getSource() == loginButton) { // se o botao de login for pressionado
                String userID = usuarioTextField.getText(); // transforma o campo de inserção em string
                String passwordID = String.copyValueOf(senhaField.getPassword()); // transforma o campo de inserção em string
                if(userID.equals(admin.getLogin())) { // se o usuario for encontrado no banco de dados
                    if(passwordID.equals(admin.getSenha())) { // se a senha for encontrada no banco de dados
                        dispose(); // esconde a tela de login
                        Menu menu = new Menu(); // mostra o menu
                    }
                    else { // do contrario apresenta um waning de Acesso Negado
                        warningLabel.setForeground(Color.red);
                        warningLabel.setText("Acesso Negado");
                    }
                }
                else { // do contrario apresenta um waning de Acesso Negado
                    warningLabel.setForeground(Color.red);
                    warningLabel.setText("Acesso Negado");
                }
            }
            if(event.getSource() == sairButton) {
                dispose();
            }
        }
    }
}

