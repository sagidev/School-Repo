package com.company;

import com.sun.org.apache.xpath.internal.operations.Bool;

import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionAdapter;
import java.awt.event.MouseMotionListener;

public class PaintGUI extends JFrame{
    private JPanel panel;
    public int x = 0;
    public int y = 0;
    public PaintGUI()
    {
        setContentPane(panel);
        setVisible(true);
        setSize(900,900);
        //panel.setForeground(Color.white);
        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        Graphics g = getGraphics();
        //addMouseMotionListener(this);
        //this.pack();
        //paint(g);

        addMouseMotionListener(
                new MouseMotionAdapter() {
                    // store drag coordinates and repaint
                    public void mouseDragged( MouseEvent event )
                    {
                        x = event.getX();
                        y = event.getY();
                        //repaint();
                    }
                }
        );
    }

    public void paint( Graphics g )
    {
        g.fillOval( x, y, 4, 4 );
    }
}
