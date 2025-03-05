package app2;

import com.sun.speech.freetts.Voice;

import com.sun.speech.freetts.VoiceManager;

import javax.swing.*;

import java.awt.event.ActionEvent;

import java.awt.event.ActionListener;

public class Talktome extends Thread{

public static void main(String[] args) {

JFrame frame = new JFrame("TalkToMe1");

frame.setSize(300, 200);

frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

JPanel panel = new JPanel();

frame.add(panel);

placeComponents(panel);

frame.setVisible(true);

}

private static void placeComponents(JPanel panel) {

panel.setLayout(null);

JButton speakButton = new JButton("Press Me!");

speakButton.setBounds(90, 50, 120, 40);

panel.add(speakButton);

speakButton.addActionListener(new ActionListener() {

@Override

public void actionPerformed(ActionEvent e) {

speak("CIAO 5° G-H-I!");

try {

Thread.sleep(1000);

} catch (InterruptedException e1) {

e1.printStackTrace();

}

speak("FATE I BRAVI!SE NO VI BOCCIAMO TUTTI");

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