package app3;

import com.sun.speech.freetts.Voice;

import com.sun.speech.freetts.VoiceManager;

import javax.swing.*;

import java.awt.event.ActionEvent;

import java.awt.event.ActionListener;

public class Talktome2 {

public static void main(String[] args) {

JFrame frame = new JFrame("TalkToMe Part 2");

frame.setSize(400, 200);

frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

JPanel panel = new JPanel();

frame.add(panel);

placeComponents(panel);

frame.setVisible(true);

}

private static void placeComponents(JPanel panel) {

panel.setLayout(null);

JLabel label = new JLabel("Enter text:");

label.setBounds(50, 20, 80, 25);

panel.add(label);

JTextField textField = new JTextField(20);

textField.setBounds(140, 20, 200, 25);

panel.add(textField);

JButton speakButton = new JButton("Speak");

speakButton.setBounds(140, 60, 100, 40);

panel.add(speakButton);

speakButton.addActionListener(new ActionListener() {

@Override

public void actionPerformed(ActionEvent e) {

String text = textField.getText();

speak(text);

}

});

}

public static void speak(String text) {

System.setProperty("freetts.voices","com.sun.speech.freetts.en.us.cmu_us_kal.KevinVoiceDirectory");

Voice voice = VoiceManager.getInstance().getVoice("kevin16");

if (voice != null) {

voice.allocate();

voice.speak(text);

voice.deallocate();

} else {

System.out.println("Voice not found! Check FreeTTS setup.");

}

}

}