package Screens;

import Program.Administrador;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JButton;

public class Menu extends JFrame{
    // variavel que mostra o usuario logado
    JLabel userLabel;
    
    JButton acessarAgendaButton;
    JButton marcarConsultaButton;
    JButton pagarContasButton;
    JButton pagarSalarioButton;
    JButton folhaDePontoButton;
    JButton gerarRelatorioButton;
    JButton registrarFuncionarioButton;
    JButton logoutSistemaButton;

    public Menu() {
        GoTo go = new GoTo();
        acessarAgendaButton = new JButton("Acessar Agenda");
        acessarAgendaButton.setBounds(250, 60, 300, 40);
        acessarAgendaButton.setFocusable(false);
        acessarAgendaButton.addActionListener(go);
        add(acessarAgendaButton);
        
        marcarConsultaButton = new JButton("Receber Consulta");
        marcarConsultaButton.setBounds(250, 110, 300, 40);
        marcarConsultaButton.setFocusable(false);
        marcarConsultaButton.addActionListener(go);
        add(marcarConsultaButton);
        
        pagarContasButton = new JButton("Pagamento de Contas");
        pagarContasButton.setBounds(250, 160, 300, 40);
        pagarContasButton.setFocusable(false);
        pagarContasButton.addActionListener(go);
        add(pagarContasButton);
        
        pagarSalarioButton = new JButton("Pagamento Salario");
        pagarSalarioButton.setBounds(250, 210, 300, 40);
        pagarSalarioButton.setFocusable(false);
        pagarSalarioButton.addActionListener(go);
        add(pagarSalarioButton);
        
        folhaDePontoButton = new JButton("Folha de Ponto");
        folhaDePontoButton.setBounds(250, 260, 300, 40);
        folhaDePontoButton.setFocusable(false);
        folhaDePontoButton.addActionListener(go);
        add(folhaDePontoButton);
        
        gerarRelatorioButton = new JButton("Gerar Relatório");
        gerarRelatorioButton.setBounds(250, 310, 300, 40);
        gerarRelatorioButton.setFocusable(false);
        gerarRelatorioButton.addActionListener(go);
        add(gerarRelatorioButton);
        
        registrarFuncionarioButton = new JButton("Registrar Funcionário");
        registrarFuncionarioButton.setBounds(250, 360, 300, 40);
        registrarFuncionarioButton.setFocusable(false);
        registrarFuncionarioButton.addActionListener(go);
        add(registrarFuncionarioButton);
        
        logoutSistemaButton = new JButton("Logout");
        logoutSistemaButton.setBounds(250, 410, 300, 40);
        logoutSistemaButton.setFocusable(false);
        logoutSistemaButton.addActionListener(go);
        add(logoutSistemaButton);
    
        setTitle("CLINICA CURRAL");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setResizable(false);
        setSize(800, 600); // ajusta o tamanho da tela
        setLayout(null);
        setVisible(true); // mostra a tela
    }

    private class GoTo implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent event) {
            //EXIBE TODAS AS OPÇÕES NO MENU
            if(event.getSource() == acessarAgendaButton) {
                Agenda agenda = new Agenda();
            }
            else if(event.getSource() == marcarConsultaButton) {
                ReceberConsulta appointment = new ReceberConsulta();
            }
            else if(event.getSource() == pagarContasButton) {
                Conta payBills = new Conta();
            }
            else if(event.getSource() == pagarSalarioButton) {
                PagarSalario salario = new PagarSalario();
            }
            else if(event.getSource() == folhaDePontoButton) {
                FolhaDePonto timeSheet = new FolhaDePonto();
            }
            else if(event.getSource() == gerarRelatorioButton) {
                GerarRelatorio relatorio = new GerarRelatorio();
            }
            else if(event.getSource() == registrarFuncionarioButton) {
                RegistrarFuncionario registerEmployee = new RegistrarFuncionario();
            }
            else if(event.getSource() == logoutSistemaButton) {
                dispose();
                Login login = new Login();
            }
            dispose();
        }
    }
}
