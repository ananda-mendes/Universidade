package Screens;

import Program.Consultas;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.List;
import javax.swing.DefaultListModel;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JScrollPane;
import javax.swing.JTextField;

public class ReceberConsulta extends JFrame {
    JLabel paginaLabel;
    
    JButton pagarButton;
    JButton voltarButton;

    Consultas consulta = new Consultas();
    List<String> code = new ArrayList<>();
    List<String> valor = new ArrayList<>();
    List<String> status = new ArrayList<>();
    List<String> agendado = new ArrayList<>();
    String aux = "";
    JLabel identificacaoLabel;
    JTextField identificacaoTextField = new JTextField();
    
    JLabel valorLabel;
    JTextField valorTextField = new JTextField();
    
    JLabel identificacaoMostradoLabel = new JLabel("Identificação");
    JLabel valorMostradoLabel = new JLabel("Valor");
    JLabel statusMostradoLabel = new JLabel("Status");
    
    DefaultListModel<String> l1 = new DefaultListModel<>();
    JList<String> list = new JList<>(l1);
    JScrollPane scroll = new JScrollPane(list);
    
    public ReceberConsulta(){
        ValidateConsulta handler = new ValidateConsulta();
        
        identificacaoLabel = new JLabel("Identificação");
        identificacaoLabel.setToolTipText("O número digitado deve ser igual a algum dos codes mostrados");
        identificacaoLabel.setBounds(250, 80, 150, 20);
        add(identificacaoLabel); // adiciona o identificacaoJFrame
        identificacaoTextField.setBounds(250, 100, 150, 20);
        identificacaoTextField.addActionListener(handler);
        add(identificacaoTextField);
        
        valorLabel = new JLabel("Preço");
        valorLabel.setToolTipText("Preço da conta");
        valorLabel.setBounds(400, 80, 150, 20);
        add(valorLabel); // adiciona o valorsLabelao JFrame
        valorTextField.setBounds(400, 100, 150, 20);
        valorTextField.addActionListener(handler);
        add(valorTextField);
        
        identificacaoMostradoLabel.setBounds(200, 130, 100, 20);
        add(identificacaoMostradoLabel);
        valorMostradoLabel.setBounds(360, 130, 100, 20);
        add(valorMostradoLabel);
        statusMostradoLabel.setBounds(490, 130, 100, 20);
        add(statusMostradoLabel);
        
        paginaLabel = new JLabel("RECEBER CONSULTA");
        paginaLabel.setBounds(250, 40, 200, 20);
        add(paginaLabel); // adiciona o paginaLabel ao JFrame
        
        consulta.lerConsultas(code, valor, status);
        for(int i = 0; i < code.size(); i++) {
            String spaces = "";
            for (int k = 0; k < 25; k++) {
                spaces += " ";
            }
            aux = code.get(i) + spaces + valor.get(i) + spaces + status.get(i);
            agendado.add(aux);
        }
        for(String i : agendado) {
            l1.addElement(i);
        }
        scroll.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
        scroll.setBounds(200, 150, 400, 200);
        add(scroll);

        pagarButton = new JButton("Receber");
        pagarButton.setBounds(400, 460, 150, 20);
        pagarButton.setFocusable(false);
        pagarButton.addActionListener(handler);
        add(pagarButton);
        
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
    
    private class ValidateConsulta implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent event) {
            if(event.getSource() == pagarButton) {
                String codeInput = identificacaoTextField.getText();
                String valorInput = valorTextField.getText();
                
                l1.removeAllElements();
                agendado.clear();
                code.clear();
                consulta.lerConsultas(code, valor, status);
                for (int i = 0; i < code.size(); i++) {
                    String spaces = "";
                    for (int k = 0; k < 25; k++) {
                        spaces += " ";
                    }
                    
                    if (code.get(i).equals(codeInput) && valor.get(i).equals(valorInput)
                            && status.get(i).equals("pendente")) {
                        aux = code.get(i) + spaces + valor.get(i) + spaces + "pago";
                        agendado.add(aux);
                    }
                    else {
                        aux = code.get(i) + spaces + valor.get(i) + spaces + status.get(i);
                        agendado.add(aux);
                    }
                }
                for (String i : agendado) {
                    l1.addElement(i);
                }
            }
            if(event.getSource() == voltarButton) {
                Menu menu = new Menu();
                dispose();
            }
        }
    }
}
