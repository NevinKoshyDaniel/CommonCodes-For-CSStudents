import java.awt.*;
import java.awt.event.*;
import java.applet.*;

class Frame2 extends Frame              //subclass of the frame class is created
{
Frame2(String name)                     //initialization of various objects   
{super(name);
WindowA adapter=new WindowA(this);
addWindowListener(adapter);
} 
public void paint(Graphics g)           // graphics paintings configurations
{
g.drawString("Inside the created frame window",50,100);
}
}

class WindowA extends WindowAdapter     //  It creates a window adapter extension for the class Frame2
{
Frame2 frame;
public WindowA(Frame2 frame)
{
this.frame=frame;
}
public void WindowClosing(WindowEvent me)
{
frame.setVisible(false);
}
}

public class AppFrame extends Applet    // applet creation, toggle with visibility based on applet's life 
{
Frame fw;
public void init()                      //initialization of default properties
{
fw=new Frame2("New frame window");
fw.setSize(500,250);
fw.setVisible(true);
}
public void start()
{
fw.setVisible(true);
}
public void stop()
{
fw.setVisible(false);
}
public void paint(Graphics g)               
{
    g.drawString("Inside applet window",40,100);
}

}