package com.company;

import java.util.ArrayList;
import java.util.List;

public class Student{
    List oceny = new ArrayList();
    String imie,nazwisko;

    Student(String setImie, String setNazwisko)
    {
        imie = setImie;
        nazwisko = setNazwisko;
    }
    public void dodajOcene(int ocena)
    {
        oceny.add(ocena);
    }
    public void wyswietlStudenta()
    {
        System.out.println("Student: " + imie + " " + nazwisko);
        wyswietlOceny();
    }
    public void wyswietlOceny()
    {
        if(oceny.isEmpty())
        {
            System.out.println("Brak ocen");
        }
        else
        {
            System.out.println("Oceny: " + oceny);
        }
    }

}
