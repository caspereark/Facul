/**
 * @(#)BreakOutCanvas.java
 *
 * @author   Unknown
 * @date	 2007/11/30
 */


/* Declara��o das bibliotecas */
import javax.microedition.lcdui.*;
import javax.microedition.lcdui.game.*;
import javax.microedition.midlet.*;

public class BreakOut extends MIDlet
{
	private BreakOutCanvas bCanvas;
	
	//construtor
	public BreakOut()
	{
		bCanvas = new BreakOutCanvas(this);
	}
	
	// M�todo inicio
	protected void startApp()
	{
		//inicia o Canvas
		bCanvas.start();
		//Carrega o Jogo
		Display.getDisplay(this).setCurrent(bCanvas);
	}
	
	//M�todo Pause
	protected void pauseApp()
	{
	}
	
	//M�todo destoy
	protected void destroyApp(boolean unconditional)
	{
	}
} //BreakOut()