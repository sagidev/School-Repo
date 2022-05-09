package com.company;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.List;

public class OcenyGUI extends  JFrame{
    private JPanel panel1;
    private JTextField imieText;
    private JButton dodajStudentaButton;
    private JTextField nazwiskoText;
    private JComboBox comboBox1;
    private JLabel ocenyLbl;
    private JButton dodajButton;
    private JComboBox comboBox2;
    public int iloscStudentow=0;
    List<Student> studenci = new ArrayList<>();
    public OcenyGUI()
    {

        setContentPane(panel1);
        setVisible(true);
        setSize(900,500);
        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);

        studenci.add(new Student("Albert", "Einstein"));
        comboBox1.addItem(studenci.get(iloscStudentow).imie + " " + studenci.get(iloscStudentow).nazwisko);
        iloscStudentow++;
        studenci.get(0).dodajOcene(5);
        studenci.get(0).dodajOcene(4);

        studenci.add(new Student("Adam", "Malysz"));
        comboBox1.addItem(studenci.get(iloscStudentow).imie + " " + studenci.get(iloscStudentow).nazwisko);
        iloscStudentow++;

        studenci.add(new Student("Jan", "Pawel"));
        comboBox1.addItem(studenci.get(iloscStudentow).imie + " " + studenci.get(iloscStudentow).nazwisko);
        iloscStudentow++;

        ocenyLbl.setText(String.valueOf(studenci.get(comboBox1.getSelectedIndex()).oceny));

        dodajStudentaButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                studenci.add(new Student(imieText.getText(), nazwiskoText.getText()));
                System.out.println("dodano " + imieText.getText() + " " + nazwiskoText.getText());
                comboBox1.addItem(studenci.get(iloscStudentow).imie + " " + studenci.get(iloscStudentow).nazwisko);
                iloscStudentow++;
            }
        });
        comboBox1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(studenci.get(comboBox1.getSelectedIndex()).oceny.isEmpty())
                {
                    ocenyLbl.setText("Brak ocen");
                }
                else
                {
                    ocenyLbl.setText(String.valueOf(studenci.get(comboBox1.getSelectedIndex()).oceny));
                }

            }
        });
        dodajButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                studenci.get(comboBox1.getSelectedIndex()).dodajOcene(Integer.valueOf((String)comboBox2.getSelectedItem()));

                ocenyLbl.setText(String.valueOf(studenci.get(comboBox1.getSelectedIndex()).oceny));
            }
        });
    }

}
