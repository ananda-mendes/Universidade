package Screens;

import Program.Agendas;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.List;
import javax.swing.DefaultListModel;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JScrollPane;

public class Agenda extends JFrame{
    JLabel paginaLabel; // titulo da tela
    
    JComboBox dentistasButton; // botao para escolher qual dentista deve ser selecionado
    JLabel dentistasLabel;
    
    JLabel clienteLabel = new JLabel("Cliente");
    JLabel dataLabel = new JLabel("Data");
    JLabel horarioLabel = new JLabel("Horário");
    
    JButton editarButton;
    JButton voltarButton;
    
    Agendas agenda = new Agendas();
    List<String> dentistas = new ArrayList<>();
    List<String> agendado = new ArrayList<>();

    DefaultListModel<String> l1 = new DefaultListModel<>();
    JList<String> list = new JList<>(l1);
    JScrollPane scroll = new JScrollPane(list);
    
    public Agenda() {
        ValidateSchedule handler = new ValidateSchedule();
        
        paginaLabel = new JLabel("CONSULTAR AGENDA");
        paginaLabel.setBounds(250, 40, 200, 20);
        add(paginaLabel); // adiciona o paginaLabel ao JFrame
        
        agenda.lerDentistas(dentistas);
        dentistasButton = new JComboBox(dentistas.toArray());
        
        dentistasLabel = new JLabel("Dentistas");
        dentistasButton.setBounds(250, 100, 300, 20);
        dentistasButton.addActionListener(handler);
        add(dentistasButton);
        dentistasLabel.setToolTipText("Dentistas");
        dentistasLabel.setBounds(250, 80, 300, 20);
        add(dentistasLabel); // adiciona o dentistasLabel ao JFrame
        
        clienteLabel.setBounds(200, 130, 100, 20);
        add(clienteLabel);
        dataLabel.setBounds(360, 130, 100, 20);
        add(dataLabel);
        horarioLabel.setBounds(490, 130, 100, 20);
        add(horarioLabel);
        

        agenda.lerAgenda(dentistasButton.getSelectedItem().toString(), agendado);
        for(String i : agendado) {
            l1.addElement(i);
        }

        scroll.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
        scroll.setBounds(200, 150, 400, 200);
        add(scroll);
        
        editarButton = new JButton("Editar");
        editarButton.setBounds(400, 460, 150, 20);
        editarButton.setFocusable(false);
        editarButton.addActionListener(handler);
        add(editarButton);
        
        voltarButton = new JButton("Voltar");
        voltarButton.setBounds(250, 460, 150, 20);
        voltarButton.setFocusable(false);
        voltarButton.addActionListener(handler);
        add(voltarButton);
        
        setTitle("CLINICA CURRAL");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setResizable(false);
        setSize(800, 600); // ajusta o tamanho do frame
        setLayout(null);
        setVisible(true); // mostra o frame
    }

    private class ValidateSchedule implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent event) {
            //SE SELECIONOU OUTRO DENTISTA LIMPA A TELA E MOSTRA A AGENDA DO DENTISTA SELECIONADO
            if(event.getSource() == dentistasButton) {
                l1.removeAllElements();
                agendado.clear();
                agenda.lerAgenda(dentistasButton.getSelectedItem().toString(), agendado);
                for(String i : agendado) {
                    l1.addElement(i);
                }
            }
            //SE CLICOU EM EDITAR
            if(event.getSource() == editarButton) {
                if(dentistasButton.getSelectedItem() == "") {
                    paginaLabel.setText("Selecione um dentista");
                }
                else {
                    EditarAgenda editar = new EditarAgenda(dentistasButton.getSelectedItem().toString());
                    dispose();
                }
            }
            if(event.getSource() == voltarButton) {
                Menu menu = new Menu();
                dispose();
            }
        }
    }
}
