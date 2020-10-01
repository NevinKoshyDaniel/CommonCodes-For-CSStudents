import  java.awt.event.*;
import  java.awt.*;
public class classwork extends Frame implements ActionListener {
    
    Label bn1=new Label();
    Label bn2=new Label();
    Label bn3=new Label();
    Label bn4=new Label();
    int count1=0,count2=0,count3=0,count4=0;

    Button B1=new Button("Button 1");
    Button B2=new Button("Button 2");
    Button B3=new Button("Button 3");
    Button B4=new Button("Button 4");
    classwork()
    {
        addWindowListener(new MyWindowAdapter(this));
        B1.addActionListener(this);
        B2.addActionListener(this);
        B3.addActionListener(this);
        B4.addActionListener(this);
        add(B1);
        add(B2);
        add(B3);
        add(B4);
        add(bn1);
        add(bn2);
        add(bn3);
        add(bn4);
    }
    public void actionPerformed(ActionEvent AE) {

        String buttonName = AE.getActionCommand();
        if (buttonName == "Button 1") 
        {
            count1++;
            System.out.println(count1);
        } 
        else if (buttonName == "Button 2") 
        {
            count2++;
        }
        else if (buttonName == "Button 3") 
        {
                count3++;
        }
        else  if (buttonName == "Button 4") 
        {
                count4++;        
         }
         repaint();
    }
    public void paint(Graphics g)
    {
        g.drawString("The following buttons are pressed:",250,60);

        B1.setBounds(100, 150, 70, 40);
        bn1.setText("Pressed "+count1+"times");
        bn1.setBounds(110, 100, 100, 40);

        B2.setBounds(250, 150, 70, 40);
        bn2.setText("Pressed "+count2+ "times!");
        bn2.setBounds(260, 100, 100, 40);

        B3.setBounds(400, 150, 70, 40);
        bn3.setText("Pressed "+count3+ "times!");
        bn3.setBounds(410, 100, 100, 40);

        B4.setBounds(550, 150, 70, 40);
        bn4.setText("Pressed "+count4+ "times!");
        bn4.setBounds(560, 100, 100, 40);

        
    }
    public static void main(String args[])
    {
        classwork cs=new classwork();
        cs.setSize(700,700);
        cs.setTitle("ClassWork");
        cs.setVisible(true);
    }
}

class MyWindowAdapter extends WindowAdapter  // handles window closing, when close button is clicked
{
    classwork cs;
    public MyWindowAdapter(classwork cs)
    {
        this.cs= cs;
    }
    public void windowClosing(WindowEvent we)
    {
        System.exit(0);
    }
}