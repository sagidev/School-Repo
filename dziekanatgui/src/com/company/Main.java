package com.company;

import java.util.ArrayList;
import javax.swing.*;
import java.util.List;

public class Main {

    public static void main(String[] args) {
	    Student stu1 = new Student("Adam", "Malysz");
	    stu1.wyswietlStudenta();
	    stu1.dodajOcene(5);
        stu1.dodajOcene(2);
        stu1.dodajOcene(4);
        stu1.wyswietlOceny();

        OcenyGUI gui = new OcenyGUI();


    }
}
