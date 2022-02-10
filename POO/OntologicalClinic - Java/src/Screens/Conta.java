package Screens;

import Program.Contas;
import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.List;
import javax.swing.DefaultListModel;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JOptionPane;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.JTextField;

public class Conta extends JFrame{
    JFrame frame = new JFrame();
    JLabel paginaLabel = new JLabel("PAGAMENTO DE CONTAS");
  
    Contas conta = new Contas();
    List<String> tipo = new ArrayList<>();
    List<String> valor = new ArrayList<>();
    List<String> dataPagamento = new ArrayList<>();
    List<String> dataVencimento = new ArrayList<>();
    List<String> contasList = new ArrayList<>();
    String aux = "";
    
    JLabel tipoLabel;
    JTextField tipoTextField = new JTextField();

    JLabel valorLabel;
    JTextField valorTextField = new JTextField();

    JLabel dataPagamentoLabel;
    JTextField dataPagamentoTextField = new JTextField();
    
    JLabel dataVencimentoLabel;
    JTextField dataVencimentoTextField = new JTextField();
    
    JLabel tipoMostradoLabel = new JLabel("Tipo");
    JLabel valorMostradoLabel = new JLabel("Valor");
    JLabel dataPagamentoMostradoLabel = new JLabel("Pagamento");
    JLabel dataVencimentoMostradoLabel = new JLabel("Vencimento");

    DefaultListModel<String> l1 = new DefaultListModel<>();
    JList<String> list = new JList<>(l1);
    JScrollPane scroll = new JScrollPane(list);
    
    JButton voltarButton = new JButton("Voltar"); // volta para o menu
    JButton pagarButton = new JButton("Pagar"); // arquiva a conta paga
    
    JTable tabela;
    public Conta() {
        ValidarPagamento handler = new ValidarPagamento();
        
        paginaLabel.setBounds(320, 40, 200, 20);
        add(paginaLabel); // adiciona o paginaLabel ao JFrame
        
        tipoLabel = new JLabel("Tipo");
        tipoLabel.setToolTipText("O número digitado deve ser igual a algum dos tipos mostrados");
        tipoLabel.setBounds(175, 80, 150, 20);
        add(tipoLabel); // adiciona o identificacaoJFrame
        tipoTextField.setBounds(175, 100, 150, 20);
        tipoTextField.addActionListener(handler);
        add(tipoTextField);
        
        valorLabel = new JLabel("Valor");
        valorLabel.setToolTipText("Valor da conta");
        valorLabel.setBounds(325, 80, 100, 20);
        add(valorLabel); // adiciona o valorsLabelao JFrame
        valorTextField.setBounds(325, 100, 100, 20);
        valorTextField.addActionListener(handler);
        add(valorTextField);
        
        dataPagamentoLabel = new JLabel("Pagamento");
        dataPagamentoLabel.setToolTipText("Valor da conta");
        dataPagamentoLabel.setBounds(425, 80, 100, 20);
        add(dataPagamentoLabel); // adiciona o valorsLabelao JFrame
        dataPagamentoTextField.setBounds(425, 100, 100, 20);
        dataPagamentoTextField.addActionListener(handler);
        add(dataPagamentoTextField);
        
        dataVencimentoLabel = new JLabel("Vencimento");
        dataVencimentoLabel.setToolTipText("Valor da conta");
        dataVencimentoLabel.setBounds(525, 80, 100, 20);
        add(dataVencimentoLabel); // adiciona o valorsLabelao JFrame
        dataVencimentoTextField.setBounds(525, 100, 100, 20);
        dataVencimentoTextField.addActionListener(handler);
        add(dataVencimentoTextField);
        
        tipoMostradoLabel.setBounds(175, 130, 150, 20);
        add(tipoMostradoLabel);
        valorMostradoLabel.setBounds(325, 130, 100, 20);
        add(valorMostradoLabel);
        dataPagamentoMostradoLabel.setBounds(425, 130, 100, 20);
        add(dataPagamentoMostradoLabel);
        dataVencimentoMostradoLabel.setBounds(525, 130, 100, 20);
        add(dataVencimentoMostradoLabel);
        
        conta.lerContas(tipo, valor, dataPagamento, dataVencimento);
        System.out.println(tipo);
        for(int i = 0; i < tipo.size(); i++) {
            String spaces = "";
            for (int k = 0; k < 20; k++) {
                spaces += " ";
            }
            aux = tipo.get(i) + spaces + valor.get(i) + spaces + dataPagamento.get(i) + spaces + dataVencimento.get(i);
            contasList.add(aux);
        }
        for(String i : contasList) {
            l1.addElement(i);
        }
        scroll.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
        scroll.setBounds(175, 150, 450, 200);
        add(scroll);
        
        voltarButton.setBounds(250, 460, 150, 20);
        voltarButton.setFocusable(false);
        voltarButton.addActionListener(handler);
        add(voltarButton);
        
        pagarButton.setBounds(400, 460, 150, 20);
        pagarButton.setFocusable(false);
        pagarButton.addActionListener(handler);
        add(pagarButton);
        
                            
        setTitle("CLINICA CURRAL");
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setResizable(false);
        setSize(800, 600); // ajusta o tamanho da tela
        setLayout(null);
        setVisible(true); // mostra a tela
    }
    
    private class ValidarPagamento implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent event) {
            if(event.getSource() == voltarButton) {
                Menu menu = new Menu();
                dispose();
            }
            if(event.getSource() == pagarButton) {
                String tipo = tipoTextField.getText();
                String valor = valorTextField.getText();
                String pagamento = dataPagamentoTextField.getText();
                String vencimento = dataVencimentoTextField.getText();
                
                int valid = 0;
                // valida o tipo de conta inserido
                if(tipo.length() > 2 && tipo.length() < 15 
                        && tipo.matches("[a-zA-Z]*")) {
                    tipoLabel.setForeground(Color.DARK_GRAY);
                    valid++;
                }
                else {
                    tipoLabel.setForeground(Color.RED);
                }
                // VALIDA O VALOR DA CONTA
                if(valor.length() > 3 && valor.length() < 10 && valor.matches("[0-9.]*")) {
                    valorLabel.setForeground(Color.DARK_GRAY);
                    valid++;
                }
                else {
                    valorLabel.setForeground(Color.RED);
                }
                // VALIDA A DATA DE PAGAMENTO INSERIDA
                if(pagamento.length() == 8 && pagamento.matches("[0-9/]*")) {
                    dataPagamentoLabel.setForeground(Color.DARK_GRAY);
                    valid++;
                }
                else {
                    dataPagamentoLabel.setForeground(Color.RED);
                }
                // VALIDA A DATA DE VENCIMENTO INSERIDA
                if (vencimento.length() == 8 && vencimento.matches("[0-9/]*")) {
                    dataVencimentoLabel.setForeground(Color.DARK_GRAY);
                    valid++;
                } else {
                    dataVencimentoLabel.setForeground(Color.RED);
                }
                if (valid == 4){
                    conta.jogaEmArquivo(tipo, valor, pagamento, vencimento);
                    JOptionPane.showMessageDialog(frame, "Pagamento registrado");
                    dispose();
                    Conta conta = new Conta();
                }
            }
        }
    }
   
}

