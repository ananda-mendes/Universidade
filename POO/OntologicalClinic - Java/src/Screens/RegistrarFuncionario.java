package Screens;

import Program.Administrador;
import Program.Dentista;
import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPasswordField;
import javax.swing.JTextField;

public class RegistrarFuncionario extends JFrame{
    Administrador admin = new Administrador();
    Dentista dentista = new Dentista();
    JLabel pageLabel;
    
    JTextField nomeTextField = new JTextField(20);
    JLabel nomeLabel = new JLabel("Nome");
    
    JTextField sobrenomeTextField = new JTextField(20);
    JLabel sobrenomeLabel = new JLabel("Sobrenome");
    
    JTextField enderecoTextField = new JTextField(20);
    JLabel enderecoLabel = new JLabel("Endereço");
    
    JTextField emailTextField = new JTextField(20);
    JLabel emailLabel = new JLabel("E-mail");
    
    JTextField cpfTextField;
    JLabel cpfLabel = new JLabel("CPF");
    
    JTextField rgTextField;
    JLabel rgLabel = new JLabel("RG");
    
    JTextField telefoneTextField;
    JLabel telefoneLabel = new JLabel("Telefone");
    
    String[] idades = {"","18", "19", "20", "21", "22", "23","24","25","26","27","28","30",
        "31", "32", "33", "34", "35", "36","37","38","39","40","41","42", "43", "44",
        "45", "46", "47", "48","49","50","51","52","53","54", "55", "56", "57", "58",
        "59", "60","61","62","63","64","65","66", "67", "68", "69", "70", "71", "72",
        "73","74","75","76","77","78", "79", "80"};
    JComboBox idadeButton = new JComboBox(idades);
    JLabel idadeLabel = new JLabel("Idade");
    
    JTextField salarioTextField = new JTextField(20);
    JLabel salarioLabel = new JLabel("Salário");
    
    String[] workload = {"","6", "7", "8", "9", "10", "11", "12"};
    JComboBox regimeButton = new JComboBox(workload);
    JLabel regimeLabel = new JLabel("Regime de Trabalho");
    
    String[] roles = {"","Administrador", "Assistente Administrativo", "Dentista", "Assistente de Dentista",
        "Recepcionista"};
    JComboBox cargoButton = new JComboBox(roles);
    JLabel cargoLabel = new JLabel("Cargo");
    
    JTextField usuarioTextField = new JTextField(20);
    JLabel usuarioLabel = new JLabel("Usuário");
    
    JPasswordField senhaField = new JPasswordField(20);
    JLabel senhaLabel = new JLabel("Senha");
    
    JPasswordField confirmarSenhaField = new JPasswordField(20);
    JLabel confirmarSenhaLabel = new JLabel("Confirmar Senha");
    
    JButton registrarButton = new JButton("Registrar");
    JButton backButton = new JButton("Voltar");
    int contador = 0;
    
    public RegistrarFuncionario(){
        ValidateRegister handler = new ValidateRegister();
        pageLabel = new JLabel("REGISTRAR FUNCIONARIO"); // titulo da tela
        pageLabel.setBounds(250, 40, 200, 20);
        add(pageLabel); // adiciona o pageLabel ao JFrame
        
        nomeTextField.setBounds(250, 100, 150, 20);
        add(nomeTextField);
        nomeLabel.setToolTipText("O nome deve conter entre 1 e 30 letras");
        nomeLabel.setBounds(250, 80, 300, 20);
        add(nomeLabel); // adiciona o nomeao JFrame
        
        sobrenomeTextField.setBounds(400, 100, 150, 20);
        add(sobrenomeTextField);
        sobrenomeLabel.setToolTipText("O sobrenome deve conter entre 1 e 30 letras");
        sobrenomeLabel.setBounds(400, 80, 150, 20);
        add(sobrenomeLabel); // adiciona o sobrenome ao JFrame
        
        enderecoTextField.setBounds(250, 140, 300, 20);
        add(enderecoTextField);
        enderecoLabel.setToolTipText("Insira o endereço");
        enderecoLabel.setBounds(250, 120, 300, 20);
        add(enderecoLabel); // adiciona o enderecoao JFrame
        
        emailTextField.setBounds(250, 180, 300, 20);
        add(emailTextField);
        emailLabel.setToolTipText("Endereços de Email devem conter @");
        emailLabel.setBounds(250, 160, 300, 20);
        add(emailLabel); // adiciona o emailLabel ao JFrame
        
        cpfTextField = new JTextField(11);
        cpfTextField.setBounds(250, 220, 150, 20);
        add(cpfTextField);
        cpfLabel.setToolTipText("CPF deve ter 11 dígitos e ser composto apenas por números");
        cpfLabel.setBounds(250, 200, 150, 20);
        add(cpfLabel); // adiciona o cpfLabel ao JFrame
        
        rgTextField = new JTextField(8);
        rgTextField.setBounds(400, 220, 150, 20);
        add(rgTextField);
        rgLabel.setToolTipText("RG deve ter 8 dígitos e ser composto apenas por números");
        rgLabel.setBounds(400, 200, 150, 20);
        add(rgLabel); // adiciona o rgLabel ao JFrame
        
        telefoneTextField = new JTextField(11);
        telefoneTextField.setBounds(250, 260, 150, 20);
        add(telefoneTextField);
        telefoneLabel.setToolTipText("Telefone deve ter 11 dígitos e ser composto apenas por números");
        telefoneLabel.setBounds(250, 240, 150, 20);
        add(telefoneLabel); // adiciona o telefoneao JFrame
        
        idadeButton.setBounds(400, 260, 150, 20);
        add(idadeButton);
        idadeLabel.setToolTipText("Deve ser diferente de nulo");
        idadeLabel.setBounds(400, 240, 150, 20);
        add(idadeLabel); // adiciona o idadeao JFrame
        
        salarioTextField = new JTextField("0");
        salarioTextField.setBounds(250, 300, 150, 20);
        add(salarioTextField);
        salarioLabel.setToolTipText("O mínimo é 1100");
        salarioLabel.setBounds(250, 280, 150, 20);
        add(salarioLabel); // adiciona o salarioao JFrame
        
        regimeButton.setBounds(400, 300, 150, 20);
        add(regimeButton);
        regimeLabel.setToolTipText("Deve ser diferente de nulo");
        regimeLabel.setBounds(400, 280, 150, 20);
        add(regimeLabel); // adiciona o regimeao JFrame
        
        cargoButton.setBounds(250, 340, 300, 20);
        cargoButton.addActionListener(handler);
        add(cargoButton);
        cargoLabel.setToolTipText("Deve ser diferente de nulo");
        cargoLabel.setBounds(250, 320, 300, 20);
        add(cargoLabel); // adiciona o cargoao JFrame
        
        usuarioTextField.setBounds(250, 380, 300, 20);
        usuarioTextField.setVisible(false);
        add(usuarioTextField);
        usuarioLabel.setToolTipText("Deve possuir pelo menos 5 caracteres");
        usuarioLabel.setBounds(250, 360, 300, 20);
        usuarioLabel.setVisible(false);
        add(usuarioLabel); // adiciona o usuario ao JFrame
        
        senhaField.setBounds(250, 420, 150, 20);
        senhaField.setVisible(false);
        add(senhaField);
        senhaLabel.setToolTipText("Deve possuir pelo menos 6 caracteres");
        senhaLabel.setBounds(250, 400, 150, 20);
        senhaLabel.setVisible(false);
        add(senhaLabel); // adiciona o senhaao JFrame
        
        confirmarSenhaField.setBounds(400, 420, 150, 20);
        confirmarSenhaField.setVisible(false);
        add(confirmarSenhaField);
        confirmarSenhaLabel.setToolTipText("Deve ser o mesmo que a senha");
        confirmarSenhaLabel.setBounds(400, 400, 150, 20);
        confirmarSenhaLabel.setVisible(false);
        add(confirmarSenhaLabel); // adiciona o confirmsenhaao JFrame
        
        registrarButton.setBounds(400, 460, 150, 20);
        registrarButton.setFocusable(false);
        registrarButton.addActionListener(handler);
        add(registrarButton);
        
        backButton.setBounds(250, 460, 150, 20);
        backButton.setFocusable(false);
        backButton.addActionListener(handler);
        add(backButton);
        
        setTitle("CLINICA CURRAL");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setResizable(false);
        setSize(800, 600); // ajust the size of the frame
        setLayout(null);
        setVisible(true); // show the frame
    }
   
    private class ValidateRegister implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent event) {
            String nome = nomeTextField.getText();
            String sobrenome = sobrenomeTextField.getText();
            String endereco = enderecoTextField.getText();
            String email = emailTextField.getText();
            String cpf = cpfTextField.getText();
            String rg = rgTextField.getText();
            String telefone = telefoneTextField.getText();
            double salario = Double.parseDouble(salarioTextField.getText());
            String cargaHoraria = regimeButton.getSelectedItem().toString();
            String cargo = cargoButton.getSelectedItem().toString();
            String idade = idadeButton.getSelectedItem().toString();
            String password = String.copyValueOf(senhaField.getPassword());
            String confirmPassword = String.copyValueOf(confirmarSenhaField.getPassword());
            String user = usuarioTextField.getText();
            int valid = 0;

            if(event.getSource() == registrarButton){
                // valida nome
                if(nome.length() < 30 && nome.length() > 0 && nome.matches("[a-zA-Z]*")) {
                    nomeLabel.setForeground(Color.DARK_GRAY);
                    valid++;
                }
                else{
                    nomeLabel.setForeground(Color.RED);
                }
                // valida sobrenome
                if(sobrenome.length() < 30 && sobrenome.length() > 0 && sobrenome.matches("[a-zA-Z]*")) {
                    sobrenomeLabel.setForeground(Color.DARK_GRAY);
                    valid++;
                }
                else{
                    sobrenomeLabel.setForeground(Color.RED);
                }
                // valida endereço
                if(endereco.length() != 0) {
                    enderecoLabel.setForeground(Color.DARK_GRAY);
                    valid++;
                }
                else {
                    enderecoLabel.setForeground(Color.RED);
                }
                // valida e-mail
                if (email.contains("@") && email.length() > 0){
                    emailLabel.setForeground(Color.DARK_GRAY);
                    valid++;
                }
                else {
                    emailLabel.setForeground(Color.RED);
                }
                // valida cpf
                if (cpf.length() == 11 && cpf.matches("[0-9]*")){
                    cpfLabel.setForeground(Color.DARK_GRAY);
                    valid++;
                }
                else {
                    cpfLabel.setForeground(Color.RED);
                }
                // valida rg
                if(rg.length() == 8 && rg.matches("[0-9]*")) {
                    rgLabel.setForeground(Color.DARK_GRAY);
                    valid++;
                }
                else {
                    rgLabel.setForeground(Color.RED);
                }
                // valida telefone
                if(telefone.length() == 11 && telefone.matches("[0-9]*")){
                    telefoneLabel.setForeground(Color.DARK_GRAY);
                    valid++;
                }
                else {
                    telefoneLabel.setForeground(Color.RED);
                }
                // valida salario
                if(salario >= 1100){
                    salarioLabel.setForeground(Color.DARK_GRAY);
                    valid++;
                }
                else {
                    salarioLabel.setForeground(Color.RED);
                }
                // valida regime de trabalho
                if(regimeButton.getSelectedItem() != "") {
                    regimeLabel.setForeground(Color.DARK_GRAY);
                    valid++;
                } else {
                    regimeLabel.setForeground(Color.RED);
                }
                
                // Valida a idade
                if(idadeButton.getSelectedItem() != "") {
                    idadeLabel.setForeground(Color.DARK_GRAY);
                    valid++;
                }
                else {
                    idadeLabel.setForeground(Color.RED);
                }
                // valida cargo
                if(cargoButton.getSelectedItem() != "") {
                    cargoLabel.setForeground(Color.DARK_GRAY);
                    valid++;
                }
                else {
                    cargoLabel.setForeground(Color.RED);
                }
                
                
                if(cargoButton.getSelectedItem().equals("Administrador")
                    || cargoButton.getSelectedItem().equals("Assistente Administrativo")) {
                    
                    // valida usuario
                    if(user.length() > 4) {
                        usuarioLabel.setForeground(Color.DARK_GRAY);
                        valid++;
                    }
                    else {
                        usuarioLabel.setForeground(Color.RED);
                    }
                    // valida senha
                    if (confirmPassword.equals(password) && !(confirmPassword.length() < 6)){
                        senhaLabel.setForeground(Color.DARK_GRAY);
                        confirmarSenhaLabel.setForeground(Color.DARK_GRAY);
                        valid++;
                    }
                    else{
                        senhaLabel.setForeground(Color.RED);
                        confirmarSenhaLabel.setForeground(Color.RED);
                    }
                }
                
                // Se todos os campos forem devidamente preenchidos o funcionario é criado
                if (valid == 11 && !cargoButton.getSelectedItem().equals("Administrador")
                        && !cargoButton.getSelectedItem().equals("Assistente Administrativo")){
                    
                    // caso seja um dentista
                    if(cargoButton.getSelectedItem().equals("Dentista")){
                        try {
                            admin.cadastraDentista(nome, sobrenome,endereco, email, cpf, rg,
                                telefone, idade, salarioTextField.getText(), 
                                cargaHoraria, cargo);
                        } catch (Exception e) {
                            System.err.println(e);
                        }
                    }
                    // caso seja um assistente de dentista
                    else if(cargoButton.getSelectedItem().equals("Assistente de Dentista")){
                        try {
                            admin.cadastraAssistenteDentista(nome, sobrenome,endereco, email, cpf, rg,
                                telefone, idade, salarioTextField.getText(), 
                                cargaHoraria, cargo);
                        } catch (Exception e) {
                            System.err.println(e);
                        }
                    }
                    // caso seja um recepcionista
                    else if(cargoButton.getSelectedItem().equals("Recepcionista")){
                        try {
                            admin.cadastraRecepcionista(nome, sobrenome,endereco, email, cpf, rg,
                                telefone, idade, salarioTextField.getText(), 
                                cargaHoraria, cargo);
                        } catch (Exception e) {
                            System.err.println(e);
                        }
                    }
                    JOptionPane.showMessageDialog(rgLabel, "Funcionário cadastrado");
                    Menu menu = new Menu();
                    dispose();
                }
                else if(valid == 13) {
                    // caso seja um administrador
                    if(cargoButton.getSelectedItem().equals("Administrador")){
                        try {
                            admin.cadastraAdministrador(nome, sobrenome,endereco, email, cpf, rg,
                                telefone, idade, salarioTextField.getText(), 
                                cargaHoraria, cargo, user, password);
                        } catch (Exception e) {
                            System.err.println(e);
                        }
                        
                    }
                    // caso seja um assistente administrativo
                    else if(cargoButton.getSelectedItem().equals("Assistente Administrativo")){
                        try {
                            admin.cadastraAssistenteAdm(nome, sobrenome,endereco, email, cpf, rg,
                                telefone, idade, salarioTextField.getText(), 
                                cargaHoraria, cargo, user, password);
                        } catch (Exception e) {
                            System.err.println(e);
                        }
                    }
                    JOptionPane.showMessageDialog(rgLabel, "Funcionário cadastrado");
                    Menu menu = new Menu();
                    dispose();
                }
                else {
                    System.err.println("Não foi posssivel registrar o funcionario, campos inválidos");
                }
            }
                
            if(event.getSource() == cargoButton) {
                // checa se o funcionario é um administrador ou assistente administrativo
                // caso sejam o campo de usuario e senha é apresentado para eles
                if (cargoButton.getSelectedItem().equals("Administrador") 
                        || cargoButton.getSelectedItem().equals("Assistente Administrativo")){
                    usuarioTextField.setVisible(true);
                    usuarioLabel.setVisible(true);
                    senhaField.setVisible(true);
                    senhaLabel.setVisible(true);
                    confirmarSenhaField.setVisible(true);
                    confirmarSenhaLabel.setVisible(true);
                }
                // caso contrário os campos permanecem escondidos
                else {
                    usuarioTextField.setVisible(false);
                    usuarioLabel.setVisible(false);
                    senhaField.setVisible(false);
                    senhaLabel.setVisible(false);
                    confirmarSenhaField.setVisible(false);
                    confirmarSenhaLabel.setVisible(false);
                }
            }
            if(event.getSource() == backButton) {
                Menu menu = new Menu();
                dispose();
            }
        }
    }
}
