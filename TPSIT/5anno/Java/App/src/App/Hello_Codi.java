package App;

import javax.swing.*;

import java.awt.*;

import java.awt.event.ActionEvent;

import java.awt.event.ActionListener;

public class Hello_Codi {

public static void main(String[] args) {

JFrame frame = new JFrame("Hello Codi!");

frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

frame.setSize(300, 200);

frame.setLayout(new FlowLayout());

JLabel label = new JLabel("Hello!");

label.setFont(new Font("Arial", Font.BOLD, 18));

JButton button = new JButton("Click Me!");

button.addActionListener(new ActionListener() {

@Override

public void actionPerformed(ActionEvent e) {

label.setText("Hello Codi!");

}

});

frame.add(label);

frame.add(button);

frame.setVisible(true);

}

}