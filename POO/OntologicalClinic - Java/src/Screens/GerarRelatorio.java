package Screens;

import Program.Administrador;
import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.List;
import javax.swing.DefaultComboBoxModel;
import javax.swing.DefaultListModel;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JOptionPane;
import javax.swing.JScrollPane;
import javax.swing.JTextField;


public class GerarRelatorio extends JFrame{
    JFrame frame = new JFrame();
    Administrador admin = new Administrador();

    JLabel paginaLabel = new JLabel("GERAR RELATÓRIO");
    
    String[] tipos = {"", "Relatório de Ganhos", "Relatório de Gastos", "Relatório de Salários"};
    JComboBox tipoButton = new JComboBox(tipos);
    JLabel tipoLabel = new JLabel();    
    
    List<String> valor = new ArrayList<>();
    List<String> dataPagamento = new ArrayList<>();
    List<String> clientes = new ArrayList<>(); 
    List<String> contas = new ArrayList<>();
    
    JLabel periodoLabel = new JLabel();  
    
    JLabel dataInicioLabel;
    JTextField dataInicioTextField = new JTextField();

    JLabel dataFimLabel;
    JTextField dataFimTextField = new JTextField();

    JLabel dataInicioMostradoLabel = new JLabel("Data inicial");
    JLabel dataFimMostradoLabel = new JLabel("Data final");

    JButton aplicarButton = new JButton("Gerar");
    JButton voltarButton = new JButton("Voltar");
    
    
    public GerarRelatorio() {
        GerarRelatorio.ValidaGerarRelatorio handler = new GerarRelatorio.ValidaGerarRelatorio();

        paginaLabel.setBounds(250, 40, 200, 20);
        add(paginaLabel); // adiciona o paginaLabel ao JFrame
        
        
        tipoLabel = new JLabel("Tipo");
        tipoButton.setBounds(250, 170, 300, 20);
        tipoButton.addActionListener(handler);
        add(tipoButton);
        tipoLabel.setToolTipText("Tipo");
        tipoLabel.setBounds(250, 150, 300, 20);
        add(tipoLabel); // adiciona o cargo ao JFrame
        
        periodoLabel = new JLabel("Periodo");
        periodoLabel.setToolTipText("periodo");
        periodoLabel.setBounds(250, 80, 300, 20);
        add(periodoLabel); // adiciona o cargo ao JFrame
        
        dataInicioLabel = new JLabel("Data inicial");
        dataInicioLabel.setToolTipText("Data");
        dataInicioLabel.setBounds(250, 100, 80, 20);
        add(dataInicioLabel); // adiciona o valorsLabelao JFrame
        dataInicioTextField.setBounds(250, 120, 80, 20);
        dataInicioTextField.addActionListener(handler);
        add(dataInicioTextField);

        dataFimLabel = new JLabel("Data final");
        dataFimLabel.setToolTipText("Data");
        dataFimLabel.setBounds(350, 100, 80, 20);
        add(dataFimLabel); // adiciona o valorsLabelao JFrame
        dataFimTextField.setBounds(350, 120, 80, 20);
        dataFimTextField.addActionListener(handler);
        add(dataFimTextField);
        
        aplicarButton = new JButton("Gerar");
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
 
    private class ValidaGerarRelatorio implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent event) {
            String tipo = tipoButton.getSelectedItem().toString();
            String inicio = dataInicioTextField.getText();   
            String fim = dataFimTextField.getText();
            //VERIFICA QUAL RELATÓRIO O USUARIO ESCOLHE
            if (event.getSource() == tipoButton) {
                if (tipo.equals("Relatório de Ganhos")) {
                    admin.lerConsultas(inicio, fim, valor, dataPagamento, clientes);   
                }
                else if (tipo.equals("Relatório de Gastos")) {
                    admin.lerGastos(inicio, fim, contas, valor, dataPagamento);
                    
                }
                else if (tipo.equals("Relatório de Salários")) {
                    JOptionPane.showMessageDialog(frame, "Função não implementada");
                }  
            }
            
            if (event.getSource() == aplicarButton) {
                int valid = 0;
                // VALIDA A DATA INICIAL DO PERIODO INSERIDA
                if (inicio.length() == 8 && inicio.matches("[0-9/]*")) {
                    dataInicioLabel.setForeground(Color.DARK_GRAY);
                    valid++;
                } else {
                    dataInicioLabel.setForeground(Color.RED);
                }
                // VALIDA A DATA FINAL DO PERIODO INSERIDA
                if (fim.length() == 8 && fim.matches("[0-9/]*")) {
                    dataFimLabel.setForeground(Color.DARK_GRAY);
                    valid++;
                } else {
                    dataFimLabel.setForeground(Color.RED);
                }
                if (valid == 2) {
                    JOptionPane.showMessageDialog(frame, "Relatório gerado");
                    dispose();
                }
            }

                
            if (event.getSource() == voltarButton) {
                Menu menu = new Menu();
                dispose();
            }
        }
    }
}
