/**
 * @(#)BreakOutCanvas.java
 *
 * @author   Unknown
 * @date	 2007/11/30
 */


/* Declaração das bibliotecas */
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
	
	// Método inicio
	protected void startApp()
	{
		//inicia o Canvas
		bCanvas.start();
		//Carrega o Jogo
		Display.getDisplay(this).setCurrent(bCanvas);
	}
	
	//Método Pause
	protected void pauseApp()
	{
	}
	
	//Método destoy
	protected void destroyApp(boolean unconditional)
	{
	}
} //BreakOut()