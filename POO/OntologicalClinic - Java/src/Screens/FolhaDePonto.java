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

public class FolhaDePonto extends JFrame{
    Administrador admin = new Administrador();

    JLabel paginaLabel = new JLabel("FOLHA DE PONTO");
    
    String[] cargos = {"", "Administrador", "Assistente Administrativo", "Dentista", 
        "Assistente de Dentista", "Recepcionista"};
    JComboBox cargoButton = new JComboBox(cargos);
    JLabel cargoLabel = new JLabel();
    
    List<String> funcionarios = new ArrayList<>();
    JComboBox funcionariosButton = new JComboBox();
    JLabel funcionariosLabel = new JLabel();
    
    JButton aplicarButton = new JButton("Editar");
    JButton voltarButton = new JButton("Voltar");
    
    List<String> dataList = new ArrayList<>();
    List<String> observacaoList = new ArrayList<>();
    
    JLabel dataLabel = new JLabel("Data");
    JTextField dataTextField = new JTextField();
    JLabel obsLabel = new JLabel("Observação");
    JTextField obsTextField = new JTextField();
    
    DefaultListModel<String> l1 = new DefaultListModel<>();
    JList<String> list = new JList<>(l1);
    JScrollPane scroll = new JScrollPane(list);
    List<String> folhaPontoList = new ArrayList<>();

    
    public FolhaDePonto() {
        ValidaFolhaDePonto handler = new ValidaFolhaDePonto();

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
        
        scroll.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
        scroll.setBounds(250, 200, 300, 200);
        add(scroll);
        
        aplicarButton = new JButton("Adicionar");
        aplicarButton.setBounds(400, 460, 150, 20);
        aplicarButton.setFocusable(false);
        aplicarButton.addActionListener(handler);
        add(aplicarButton);
        
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
 
    private class ValidaFolhaDePonto implements ActionListener {
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
                    
                    String func = funcionariosButton.getSelectedItem().toString();
                    l1.removeAllElements();
                    folhaPontoList.clear();
                    admin.lerFolhaDePonto(func, folhaPontoList);
                    for (String i : folhaPontoList) {
                        l1.addElement(i);
                    }
                }
                else{
                    funcionariosLabel.setVisible(false);
                    funcionariosButton.setVisible(false);
                }
            }
            if(event.getSource() == funcionariosButton) {
                String cargo = cargoButton.getSelectedItem().toString();
                String func = funcionariosButton.getSelectedItem().toString();
                l1.removeAllElements();
                folhaPontoList.clear();
                admin.lerFolhaDePonto(func, folhaPontoList);
                for (String i : folhaPontoList) {
                    l1.addElement(i);
                }
            }

            if(event.getSource() == aplicarButton) {
                String func = funcionariosButton.getSelectedItem().toString();
                String data = dataTextField.getText();
                String obs = obsTextField.getText();
                if(!cargoButton.getSelectedItem().equals("")) {
                    int valid = 0;
                    // VALIDA A DATA
                    if(data.matches("[0-9/]*") && data.length() == 8 && data.charAt(2) == '/'
                        && data.charAt(5) == '/') {
                        dataLabel.setForeground(Color.DARK_GRAY);
                        valid++;
                    } else {
                        dataLabel.setForeground(Color.RED);
                    }
                    // VALIDA A OBS
                    if(obs.length() == 0) {
                        obsTextField.setText("---");
                    }
                    if(obs.length() < 30) {
                        obsLabel.setForeground(Color.DARK_GRAY);
                        valid++;
                    }
                    else {
                        obsLabel.setForeground(Color.RED);
                    }
                    if(valid == 2) {
                        admin.gravarFolhaDePonto(func, data, obs);
                    }
                }
            }
            if(event.getSource() == voltarButton) {
                Menu menu = new Menu();
                dispose();
            }
        }
    }
}
