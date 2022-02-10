package Screens;

import Program.Agendas;
import Program.Consultas;
import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.List;
import javax.swing.ButtonGroup;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JRadioButton;
import javax.swing.JTextField;

public class EditarAgenda extends JFrame{
    JLabel paginaLabel;
    
    JRadioButton clienteExistente = new JRadioButton("Cliente Existente");
    JRadioButton novoCliente = new JRadioButton("Registrar Novo Cliente");
    ButtonGroup group = new ButtonGroup();

    JLabel dataLabel;
    JTextField dataTextField;
    
    JLabel horarioLabel;
    JTextField horarioTextField;
    
    JLabel valorLabel;
    JTextField valorTextField;
    
    List<String> clientes = new ArrayList<>();
    JLabel clientesLabel;
    JComboBox clientesButton;
    Consultas consulta = new Consultas();
    
    JTextField nomeTextField = new JTextField(20);
    JLabel nomeLabel = new JLabel("Nome");
    
    JTextField sobrenomeTextField = new JTextField(20);
    JLabel sobrenomeLabel = new JLabel("Sobrenome");
    
    JTextField enderecoTextField = new JTextField(20);
    JLabel enderecoLabel = new JLabel("Endereço");
    
    JTextField emailTextField = new JTextField(20);
    JLabel emailLabel = new JLabel("E-mail");
    
    JTextField cpfTextField = new JTextField(20);
    JLabel cpfLabel = new JLabel("CPF");
    
    JTextField rgTextField = new JTextField(20);
    JLabel rgLabel = new JLabel("RG");
    
    JTextField telefoneTextField = new JTextField(20);
    JLabel telefoneLabel = new JLabel("Telefone");
    
    String[] idades = {"","18", "19", "20", "21", "22", "23","24","25","26","27","28","30",
        "31", "32", "33", "34", "35", "36","37","38","39","40","41","42", "43", "44",
        "45", "46", "47", "48","49","50","51","52","53","54", "55", "56", "57", "58",
        "59", "60","61","62","63","64","65","66", "67", "68", "69", "70", "71", "72",
        "73","74","75","76","77","78", "79", "80"};
    JComboBox idadeButton = new JComboBox(idades);
    JLabel idadeLabel = new JLabel("Idade");
    
    JButton registrarButton = new JButton("Agendar");
    JButton voltarButton = new JButton("Voltar");
    
    String dentista;
    
    public EditarAgenda(String dentista) {
        ValidarConsulta handler = new ValidarConsulta();
        this.dentista = dentista;
        
        paginaLabel = new JLabel("MARCAR CONSULTA");
        paginaLabel.setBounds(250, 40, 150, 20);
        add(paginaLabel);
        
        clienteExistente.setBounds(250, 80, 150, 20);
        clienteExistente.setSelected(true);
        clienteExistente.addActionListener(handler);
        add(clienteExistente);
        
        novoCliente.setBounds(400, 80, 200, 20);
        novoCliente.addActionListener(handler);
        add(novoCliente);

        group.add(clienteExistente);
        group.add(novoCliente);
        
        consulta.lerClientes(clientes);
        clientesButton = new JComboBox(clientes.toArray());
        clientesButton.setBounds(250, 140, 300, 20);
        clientesButton.addActionListener(handler);
        add(clientesButton);
        clientesLabel = new JLabel("Clientes");
        clientesLabel.setToolTipText("Clientes cadastrados");
        clientesLabel.setBounds(250, 120, 300, 20);
        add(clientesLabel); // adiciona o clientesLabel ao JFrame
        
        dataLabel = new JLabel("Data");
        dataLabel.setBounds(250, 160, 300, 20);
        dataLabel.setToolTipText("Data deve estar no formato ##/##/##");
        add(dataLabel);
        dataTextField = new JTextField();
        dataTextField.setBounds(250, 180, 300, 20);
        add(dataTextField);
        
        horarioLabel = new JLabel("Horário");
        horarioLabel.setBounds(250, 200, 300, 20);
        horarioLabel.setToolTipText("Horário deve estar no formato hh:mm");
        add(horarioLabel);
        horarioTextField = new JTextField();
        horarioTextField.setBounds(250, 220, 300, 20);
        add(horarioTextField);
        
        valorLabel = new JLabel("Valor");
        valorLabel.setBounds(250, 240, 300, 20);
        valorLabel.setToolTipText("Valor deve estar no formato ###.##");
        add(valorLabel);
        valorTextField = new JTextField();
        valorTextField.setBounds(250, 260, 300, 20);
        add(valorTextField);
        
        nomeTextField.setBounds(250, 140, 150, 20);
        add(nomeTextField);
        nomeLabel.setToolTipText("Insira o nome");
        nomeLabel.setBounds(250, 120, 300, 20);
        add(nomeLabel); // adiciona o nomeao JFrame
        
        sobrenomeTextField.setBounds(400, 140, 150, 20);
        add(sobrenomeTextField);
        sobrenomeLabel.setToolTipText("Insira o sobrenome");
        sobrenomeLabel.setBounds(400, 120, 150, 20);
        add(sobrenomeLabel); // adiciona o lastnomeao JFrame
        
        enderecoTextField.setBounds(250, 180, 300, 20);
        add(enderecoTextField);
        enderecoLabel.setToolTipText("Insira o endereço");
        enderecoLabel.setBounds(250, 160, 300, 20);
        add(enderecoLabel); // adiciona o enderecoao JFrame
        
        emailTextField.setBounds(250, 220, 300, 20);
        add(emailTextField);
        emailLabel.setToolTipText("Insira o e-mail");
        emailLabel.setBounds(250, 200, 300, 20);
        add(emailLabel); // adiciona o emailLabel ao JFrame
        
        cpfTextField.setBounds(250, 260, 150, 20);
        add(cpfTextField);
        cpfLabel.setToolTipText("Insira o CPF");
        cpfLabel.setBounds(250, 240, 150, 20);
        add(cpfLabel); // adiciona o cpfLabel ao JFrame
        
        rgTextField.setBounds(400, 260, 150, 20);
        add(rgTextField);
        rgLabel.setToolTipText("Insira o RG");
        rgLabel.setBounds(400, 240, 150, 20);
        add(rgLabel); // adiciona o rgLabel ao JFrame
        
        telefoneTextField.setBounds(250, 300, 150, 20);
        add(telefoneTextField);
        telefoneLabel.setToolTipText("Insira o telefone");
        telefoneLabel.setBounds(250, 280, 150, 20);
        add(telefoneLabel); // adiciona o telefoneao JFrame
        
        idadeButton.setBounds(400, 300, 150, 20);
        add(idadeButton);
        idadeLabel.setToolTipText("Insira a idade");
        idadeLabel.setBounds(400, 280, 150, 20);
        add(idadeLabel); // adiciona o idade ao JFrame
        
        registrarButton.setBounds(400, 340, 150, 20);
        registrarButton.addActionListener(handler);
        add(registrarButton);
        
        voltarButton.setBounds(250, 340, 150, 20);
        voltarButton.addActionListener(handler);
        add(voltarButton);
        
        clientesLabel.setVisible(true);
        clientesButton.setVisible(true);
        
        valorLabel.setVisible(true);
        valorTextField.setVisible(true);
        
        nomeTextField.setVisible(false);
        nomeLabel.setVisible(false);
        sobrenomeTextField.setVisible(false);
        sobrenomeLabel.setVisible(false);
        enderecoTextField.setVisible(false);
        enderecoLabel.setVisible(false);
        emailTextField.setVisible(false);
        emailLabel.setVisible(false);
        cpfTextField.setVisible(false);
        cpfLabel.setVisible(false);
        rgTextField.setVisible(false);
        rgLabel.setVisible(false);
        telefoneTextField.setVisible(false);
        telefoneLabel.setVisible(false);
        idadeButton.setVisible(false);
        idadeLabel.setVisible(false);
        
        setTitle("CLINICA CURRAL");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setResizable(false);
        setSize(800, 600); // ajusta o tamanho da tela
        setLayout(null);
        setVisible(true); // mostra a tela
    }
    
    private class ValidarConsulta implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent event) {
            if(event.getSource() == voltarButton) {
                Agenda agenda = new Agenda();
                dispose();
            }
            
            if(event.getSource() == registrarButton && novoCliente.isSelected()){
                String nome = nomeTextField.getText();
                String sobrenome = sobrenomeTextField.getText();
                String endereco = enderecoTextField.getText();
                String email = emailTextField.getText();
                String cpf = cpfTextField.getText();
                String rg = rgTextField.getText();
                String telefone = telefoneTextField.getText();
                String idade = idadeButton.getSelectedItem().toString();
                int valid = 0;

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
                // Valida a idade
                if(idadeButton.getSelectedItem() != "") {
                    idadeLabel.setForeground(Color.DARK_GRAY);
                    valid++;
                }
                else {
                    idadeLabel.setForeground(Color.RED);
                }
                // Se todos os campos forem devidamente preenchidos o funcionario é criado
                if (valid == 8){
                    // caso seja um administrador
                    try {
                        consulta.cadastraCliente(nome, sobrenome,endereco, email, cpf, rg,
                            telefone, idade);
                    } catch (Exception e) {
                        System.err.println(e);
                    }

                    JOptionPane.showMessageDialog(rgLabel, "Cliente cadastrado");
                    EditarAgenda editar = new EditarAgenda(dentista);
                    dispose();
                }
                else {
                    System.err.println("Não foi posssivel registrar o cliente, campos inválidos");
                }
            }
            if (event.getSource() == novoCliente) {
                paginaLabel.setText("CADASTRAR CLIENTE");
                registrarButton.setText("Registrar");
                clientesLabel.setVisible(false);
                clientesButton.setVisible(false);
                
                dataLabel.setVisible(false);
                dataTextField.setVisible(false);
                
                horarioLabel.setVisible(false);
                horarioTextField.setVisible(false);
                
                valorLabel.setVisible(false);
                valorTextField.setVisible(false);
                
                nomeTextField.setVisible(true);
                nomeLabel.setVisible(true);
                sobrenomeTextField.setVisible(true);
                sobrenomeLabel.setVisible(true);
                enderecoTextField.setVisible(true);
                enderecoLabel.setVisible(true);
                emailTextField.setVisible(true);
                emailLabel.setVisible(true);
                cpfTextField.setVisible(true);
                cpfLabel.setVisible(true);
                rgTextField.setVisible(true);
                rgLabel.setVisible(true);
                telefoneTextField.setVisible(true);
                telefoneLabel.setVisible(true);
                idadeButton.setVisible(true);
                idadeLabel.setVisible(true);
            }
            else if(event.getSource() == clienteExistente) {
                paginaLabel.setText("MARCAR CONSULTA");
                registrarButton.setText("Agendar");
                clientesLabel.setVisible(true);
                clientesButton.setVisible(true);
                
                dataLabel.setVisible(true);
                dataTextField.setVisible(true);
                
                horarioLabel.setVisible(true);
                horarioTextField.setVisible(true);
                
                valorLabel.setVisible(true);
                valorTextField.setVisible(true);
                
                nomeTextField.setVisible(false);
                nomeLabel.setVisible(false);
                sobrenomeTextField.setVisible(false);
                sobrenomeLabel.setVisible(false);
                enderecoTextField.setVisible(false);
                enderecoLabel.setVisible(false);
                emailTextField.setVisible(false);
                emailLabel.setVisible(false);
                cpfTextField.setVisible(false);
                cpfLabel.setVisible(false);
                rgTextField.setVisible(false);
                rgLabel.setVisible(false);
                telefoneTextField.setVisible(false);
                telefoneLabel.setVisible(false);
                idadeButton.setVisible(false);
                idadeLabel.setVisible(false);
            }
            
            // GRAVA NA AGENDA DO DENTISTA SELECIONADO A CONSULTA MARCADA
            if(event.getSource() == registrarButton && clienteExistente.isSelected()) {
                String data = dataTextField.getText();
                String hora = horarioTextField.getText();
                String valor = valorTextField.getText();
                String cpf = cpfTextField.getText();
                String nome = clientesButton.getSelectedItem().toString();
                // VALIDA DATA
                int valid = 0;
                if(data.matches("[0-9/]*") && data.length() == 8 && data.charAt(2) == '/'
                        && data.charAt(5) == '/') {
                    dataLabel.setForeground(Color.DARK_GRAY);
                    valid++;
                }
                else {
                    dataLabel.setForeground(Color.RED);
                }
                // VALIDA HORARIO
                if(hora.matches("[0-9:]*") && hora.length() == 5 && hora.charAt(2) == ':') {
                    horarioLabel.setForeground(Color.DARK_GRAY);
                    valid++;
                }
                else {
                    horarioLabel.setForeground(Color.RED);
                }
                // VALIDA VALOR
                if(valor.matches("[0-9.]*") && valor.length() > 3) {
                    valorLabel.setForeground(Color.DARK_GRAY);
                    valid++;
                }
                else {
                    valorLabel.setForeground(Color.RED);
                }
                if(valid == 3) {
                    Agendas agendaLogic = new Agendas();
                    agendaLogic.gravaAgenda(dentista, cpf, nome, data, hora, valor);
                    JOptionPane.showMessageDialog(rgLabel, "Consulta agendada");
                    dispose();
                    Agenda screen = new Agenda();
                }
                else {
                    System.err.println("Não agendar horário, campos inválidos");
                }
                
            }
            
        }
    }
}