package Screens;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;

public class RegistrarCliente extends JFrame{
    JLabel paginaLabel;
    
    JTextField nomeTextField = new JTextField(20);
    JLabel nomeLabel = new JLabel("Nome");
    
    JTextField sobrenome = new JTextField(20);
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
    
    JButton registarButton = new JButton("Registrar");
    JButton voltarButton = new JButton("Voltar");
    
    public RegistrarCliente() {
        nomeTextField.setBounds(250, 100, 150, 20);
        add(nomeTextField);
        nomeLabel.setToolTipText("Insira o nome");
        nomeLabel.setBounds(250, 80, 300, 20);
        add(nomeLabel); // adiciona o nomeao JFrame
        
        sobrenome.setBounds(400, 100, 150, 20);
        add(sobrenome);
        sobrenomeLabel.setToolTipText("Insira o sobrenome");
        sobrenomeLabel.setBounds(400, 80, 150, 20);
        add(sobrenomeLabel); // adiciona o lastnomeao JFrame
        
        enderecoTextField.setBounds(250, 140, 300, 20);
        add(enderecoTextField);
        enderecoLabel.setToolTipText("Insira o endereço");
        enderecoLabel.setBounds(250, 120, 300, 20);
        add(enderecoLabel); // adiciona o enderecoao JFrame
        
        emailTextField.setBounds(250, 180, 300, 20);
        add(emailTextField);
        emailLabel.setToolTipText("Insira o e-mail");
        emailLabel.setBounds(250, 160, 300, 20);
        add(emailLabel); // adiciona o emailLabel ao JFrame
        
        cpfTextField.setBounds(250, 220, 150, 20);
        add(cpfTextField);
        cpfLabel.setToolTipText("Insira o CPF");
        cpfLabel.setBounds(250, 200, 150, 20);
        add(cpfLabel); // adiciona o cpfLabel ao JFrame
        
        rgTextField.setBounds(400, 220, 150, 20);
        add(rgTextField);
        rgLabel.setToolTipText("Insira o RG");
        rgLabel.setBounds(400, 200, 150, 20);
        add(rgLabel); // adiciona o rgLabel ao JFrame
        
        telefoneTextField.setBounds(250, 260, 150, 20);
        add(telefoneTextField);
        telefoneLabel.setToolTipText("Insira o telefone");
        telefoneLabel.setBounds(250, 240, 150, 20);
        add(telefoneLabel); // adiciona o telefoneao JFrame
        
        idadeButton.setBounds(400, 260, 150, 20);
        add(idadeButton);
        idadeLabel.setToolTipText("Insira a idade");
        idadeLabel.setBounds(400, 240, 150, 20);
        add(idadeLabel); // adiciona o idade ao JFrame
        
        ValidarRegistro handler = new ValidarRegistro();
        registarButton.setBounds(400, 300, 150, 20);
        registarButton.setFocusable(false);
        registarButton.addActionListener(handler);
        add(registarButton);
        
        voltarButton.setBounds(250, 300, 150, 20);
        voltarButton.setFocusable(false);
        voltarButton.addActionListener(handler);
        add(voltarButton);
        
        setTitle("CLINICA CURRAL");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setResizable(false);
        setSize(800, 600); // ajusta o tamanho da tela
        setLayout(null);
        setVisible(true); // mostra a tela
    }
    
    private class ValidarRegistro implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent event) {
            if(event.getSource() == voltarButton) {
                Menu menu = new Menu();
                dispose();
            }
        }
    }
}