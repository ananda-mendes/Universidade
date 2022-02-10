package Screens;

import Program.Administrador;
import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.List;
import javax.swing.ComboBoxModel;
import javax.swing.DefaultComboBoxModel;
import javax.swing.DefaultListModel;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JScrollPane;
import javax.swing.JTextField;

public class PagarSalario extends JFrame{
    Administrador admin;
    JLabel paginaLabel;
    
    String[] cargos = {"", "Administrador", "Assistente Administrativo", "Dentista", 
        "Assistente de Dentista", "Recepcionista"};
    JComboBox cargoButton = new JComboBox(cargos);
    JLabel cargoLabel = new JLabel();
    
    List<String> funcionarios = new ArrayList<>();
    JComboBox funcionariosButton = new JComboBox();
    JLabel funcionariosLabel = new JLabel();
    
    JButton aplicarButton;
    JButton voltarButton;
    
    JLabel dataLabel = new JLabel("Data");
    JTextField dataTextField = new JTextField();
    JLabel obsLabel = new JLabel("Observação");
    JTextField obsTextField = new JTextField();
    
    public PagarSalario() {
        admin = new Administrador();
        paginaLabel = new JLabel("PAGAR SALÁRIO");
        
        ValidaPagarSalario handler = new ValidaPagarSalario();

        paginaLabel.setBounds(250, 40, 200, 20);
        add(paginaLabel); // adiciona o paginaLabel ao JFrame
        
        cargoLabel = new JLabel("Cargo");
        cargoButton.setBounds(250, 100, 300, 20);
        cargoButton.addActionListener(handler);
        add(cargoButton);
        cargoLabel.setToolTipText("Cargo");
        cargoLabel.setBounds(250, 80, 300, 20);
        add(cargoLabel); // adiciona o cargoao JFrame
        
        funcionariosLabel = new JLabel("Funcionarios");
        funcionariosButton.setBounds(250, 140, 300, 20);
        funcionariosButton.addActionListener(handler);
        funcionariosButton.setVisible(false);
        add(funcionariosButton);
        funcionariosLabel.setToolTipText("Funcionarios");
        funcionariosLabel.setBounds(250, 120, 300, 20);
        funcionariosLabel.setVisible(false);
        add(funcionariosLabel); // adiciona o funcionariosao JFrame
        
        dataLabel.setBounds(250, 160, 300, 20);
        add(dataLabel);
        dataTextField.setBounds(250, 180, 100, 20);
        add(dataTextField);
        obsLabel.setBounds(350, 160, 300, 20);
        add(obsLabel);
        obsTextField.setBounds(350, 180, 200, 20);
        add(obsTextField);
        
        aplicarButton = new JButton("Adicionar");
        aplicarButton.setBounds(400, 460, 150, 20);
        aplicarButton.setFocusable(false);
        aplicarButton.addActionListener(handler);
        add(aplicarButton);
        
        voltarButton = new JButton("Voltar");
        voltarButton.setBounds(250, 460, 150, 20);
        voltarButton.setFocusable(false);
        voltarButton.addActionListener(handler);
        add(voltarButton);
        
        setTitle("CLINICA CURRAL");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setResizable(false);
        setSize(800, 600); // ajust the size of the frame
        setLayout(null);
        setVisible(true); // show the frame
    }
 
    private class ValidaPagarSalario implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent event) {
            if(event.getSource() == cargoButton) {
                String cargo = cargoButton.getSelectedItem().toString();
                if(funcionariosButton.getItemCount() != 0) {
                    funcionarios.clear();
                }
                if (!cargo.equals("")) {
                    funcionariosLabel.setVisible(true);
                    funcionariosButton.setVisible(true);
                    admin.lerFuncionarios(cargoButton.getSelectedItem().toString(), funcionarios);
                    funcionariosButton.setModel(new DefaultComboBoxModel<>(funcionarios.toArray(new String[0])));
                }
                else{
                    funcionariosLabel.setVisible(false);
                    funcionariosButton.setVisible(false);
                }
            }
            if(event.getSource() == voltarButton) {
                Menu menu = new Menu();
                dispose();
            }
        }
    }
}
