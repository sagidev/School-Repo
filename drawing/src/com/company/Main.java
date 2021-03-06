package com.company;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.EventQueue;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Point;
import java.awt.event.ActionEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.image.BufferedImage;
import javax.swing.AbstractAction;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.UIManager;
import javax.swing.UnsupportedLookAndFeelException;

public class Main {
    public int brushSize = 10;
    public String brushShape = "dot";

    public static void main(String[] args) {
        new Main();
    }

    public Main() {
        EventQueue.invokeLater(new Runnable() {
            @Override
            public void run() {
                try {
                    UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
                } catch (ClassNotFoundException | InstantiationException | IllegalAccessException | UnsupportedLookAndFeelException ex) {
                }

                JFrame frame = new JFrame("Paint");
                frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                frame.setLayout(new BorderLayout());
                frame.add(new TestPane());
                frame.pack();
                frame.setLocationRelativeTo(null);
                frame.setVisible(true);
            }
        });
    }

    public class TestPane extends JPanel {

        private PaintPane paintPane;

        public TestPane() {
            setLayout(new BorderLayout());
            add((paintPane = new PaintPane()));

            add(new ColorsPane(paintPane), BorderLayout.NORTH);
        }
    }

    public class ColorsPane extends JPanel {

        public ColorsPane(PaintPane paintPane) {
            add(new JButton(new ColorAction(paintPane, "Black", Color.BLACK)));
            add(new JButton(new ColorAction(paintPane, "Red", Color.RED)));
            add(new JButton(new ColorAction(paintPane, "Green", Color.GREEN)));
            add(new JButton(new ColorAction(paintPane, "Blue", Color.BLUE)));
            add(new JButton(new BrushAction(paintPane, "Small", 2)));
            add(new JButton(new BrushAction(paintPane, "Medium", 10)));
            add(new JButton(new BrushAction(paintPane, "Big", 30)));
            add(new JButton(new ShapeAction(paintPane, "Dot", "dot")));
            add(new JButton(new ShapeAction(paintPane, "Square", "square")));

        }

        public class BrushAction extends AbstractAction {

            private PaintPane paintPane;
            private Integer tempsize;

            private BrushAction(PaintPane paintPane, String name, Integer tempsize) {
                putValue(NAME, name);
                this.paintPane = paintPane;
                this.tempsize = tempsize;
            }

            @Override
            public void actionPerformed(ActionEvent e) {
                brushSize = tempsize;
            }

        }

        public class ShapeAction extends AbstractAction {

            private PaintPane paintPane;
            private String shape;

            private ShapeAction(PaintPane paintPane, String name, String shape) {
                putValue(NAME, name);
                this.paintPane = paintPane;
                this.shape = shape;
            }

            @Override
            public void actionPerformed(ActionEvent e) {
                brushShape = shape;
            }

        }

        public class ColorAction extends AbstractAction {

            private PaintPane paintPane;
            private Color color;

            private ColorAction(PaintPane paintPane, String name, Color color) {
                putValue(NAME, name);
                this.paintPane = paintPane;
                this.color = color;
            }

            @Override
            public void actionPerformed(ActionEvent e) {
                paintPane.setForeground(color);
            }

        }

    }

    public class PaintPane extends JPanel {

        private BufferedImage background;

        public PaintPane() {
            setBackground(Color.WHITE);
            MouseAdapter handler = new MouseAdapter() {

                @Override
                public void mousePressed(MouseEvent e) {
                    if(brushShape=="dot")
                    {
                        drawDot(e.getPoint());
                    }
                    else
                    {
                        drawSquare(e.getPoint());
                    }
                }

                @Override
                public void mouseDragged(MouseEvent e) {
                    if(brushShape=="dot")
                    {
                        drawDot(e.getPoint());
                    }
                    else
                    {
                        drawSquare(e.getPoint());
                    }

                }

            };
            addMouseListener(handler);
            addMouseMotionListener(handler);
        }

        protected void drawDot(Point p) {
            if (background == null) {
                updateBuffer();
            }

            if (background != null) {
                Graphics2D g2d = background.createGraphics();
                g2d.setColor(getForeground());
                g2d.fillOval(p.x - (brushSize/2), p.y - (brushSize/2), brushSize, brushSize);
                g2d.dispose();
            }
            repaint();
        }

        protected void drawSquare(Point p) {
            if (background == null) {
                updateBuffer();
            }
            if (background != null) {
                Graphics2D g2d = background.createGraphics();
                g2d.setColor(getForeground());
                g2d.fillRect(p.x - (brushSize/2), p.y - (brushSize/2), brushSize, brushSize);
                g2d.dispose();
            }
            repaint();
        }

        @Override
        public void invalidate() {
            super.invalidate();
            updateBuffer();
        }

        protected void updateBuffer() {

            if (getWidth() > 0 && getHeight() > 0) {
                BufferedImage newBuffer = new BufferedImage(getWidth(), getHeight(), BufferedImage.TYPE_INT_RGB);
                Graphics2D g2d = newBuffer.createGraphics();
                g2d.setColor(Color.WHITE);
                g2d.fillRect(0, 0, getWidth(), getHeight());
                if (background != null) {
                    g2d.drawImage(background, 0, 0, this);
                }
                g2d.dispose();
                background = newBuffer;
            }

        }

        @Override
        public Dimension getPreferredSize() {
            return new Dimension(1000, 500);
        }

        @Override
        protected void paintComponent(Graphics g) {
            super.paintComponent(g);
            Graphics2D g2d = (Graphics2D) g.create();
            if (background == null) {
                updateBuffer();
            }
            g2d.drawImage(background, 0, 0, this);
            g2d.dispose();
        }
    }
}
