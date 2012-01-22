/**
 * @(#)BreakOutCanvas.java
 *
 * @author   Unknown
 * @date	 2007/11/30
 */


/* Declaração de bibliotecas */

import javax.microedition.lcdui.*;
import javax.microedition.lcdui.game.*;
import javax.microedition.midlet.*;

//Classe BreakOutCanvas
class BreakOutCanvas extends GameCanvas implements CommandListener,Runnable
{
	private int tamBola; //Tamanho da Bola
	
	private int larguraRaquete; //Largura da raquete
	private int alturaRaquete; // Altura da Raquete
	
	private int posXRaquete; // Posição X da Raquete
	private int posYRaquete; // Posição Y da Raquete
	
	private int posXBola; // Posição X da bola
	private int posYBola; // Posição Y da bola
	
	private int deslocY;
	private int sinal;
	
	private Command cmdSair; // Botão Sair
	private MIDlet mid; // Classe Midlet
	
	// método construtor
	public BreakOutCanvas(MIDlet mid)
	{
		super(true);
		this.mid = mid;
		
		//Criação do botão Sair
		cmdSair = new Command("Sair",Command.EXIT,1);
		this.addCommand(cmdSair);
		this.setCommandListener(this);
		
		//define a posição X inicial da raquete
		posXRaquete = 100;
		//define a posição Y inicial da raquete
		posYRaquete = (getHeight()/6*5 - alturaRaquete/2);
		
		//Define a posição inicial da bola
		posXBola = posYBola = 0;
		
		//define a altura da Raquete
		alturaRaquete = tamBola;
		
		sinal = 1;
		
	}
	
	//Método Paint
	public void paint(Graphics g)
	{
		limparTela(g);
		desenhaBola(g);
		desenhaRaquete(g);
	}
	
	//Método commandAction - Define as ações dos botões
	public void commandAction(Command c,Displayable d)
	{
		if(c == cmdSair)
		{
			mid.notifyDestroyed(); //Finaliza o jogo
		}
	}
	
	//Método start
	public void start()
	{
		//Cria a Thread
		Thread runner = new Thread(this);
		//Inicia a Thread/jogo
		runner.start();
	}
	
	//Método limpar tela
	public void limparTela(Graphics g)
	{
		//Define a cor Branca
		g.setColor(255,255,255);
		//Desenha um retangulo branco na tela inteira
		g.fillRect(0,0,getWidth(),getHeight());
	}
	
	//Método que desena Bola
	private void desenhaBola(Graphics g)
	{
		//Define uma nova posição
	    
	    posXBola = posYBola += 5*(sinal);
		
		//deslocY -= sinal;
		
		tamBola = 20;
		//desenha sombra da bola
		g.setColor(0,0,0);
		g.fillArc( posXBola + 3, posYBola +3 ,tamBola,tamBola,0,360 );
		
		//desenha bola
		g.setColor(255,0,0); //cor vermelha
		g.fillArc( posXBola,posYBola,tamBola,tamBola,0,360 );
		
		//desenha o brilho da bola
		g.setColor(255,255,255);
		g.fillArc( posXBola,posYBola,tamBola/4,tamBola/4,0,360 );
		 
	}
	
	//Método de desenho da raquete
	private void desenhaRaquete(Graphics g)
	{
		//Define o tamanho da raquete
	    larguraRaquete = 3 * tamBola;
	    alturaRaquete = tamBola;
		
		//desenha a sombra da raquete
		g.setColor(0,0,0);
		g.fillRoundRect(posXRaquete+3,(getHeight()/6*5- tamBola/2)+3,larguraRaquete,alturaRaquete,20,20) ;
		//desenha raquete
		g.setColor(255,128,50);
		g.fillRoundRect(posXRaquete,(getHeight()/6*5 - tamBola/2 ),larguraRaquete,alturaRaquete,20,20  );
	}
	
	//Método Run 
	public void run()
	{
		//looping infinito
		while(true)
		{
			//cria o objeto Graphics
			Graphics g = getGraphics();
			
			//chama os métodos da classe
			limparTela(g);
			desenhaParede(g);
			desenhaBola(g);
			verificaTeclas();
			desenhaRaquete(g);
			trataConflito();
			
			flushGraphics(); //Esvazia o cache e desenha os objetos na tela
			try //Tente ...
			{
				//Define a velocidade do jogo, mudando o valor de sleep(X), quanto maior X, menor a velocidade 
				Thread.currentThread().sleep(50);
			} // se não conseguir:
			catch(Exception e) {}
			
		}
	}
	
	// Método de tratamento de colisão
	private void trataConflito()
	{

		if( posYBola+tamBola >= posYRaquete && ( posXBola>=posXRaquete && posXBola<=posXRaquete+larguraRaquete) )
		{	
			if(posXBola>=posXRaquete)
				sinal=-sinal; //inverte o sentido da bola

		}
		
	}
	
	//Verifica as Telas
	private void verificaTeclas()
	{
		int keyState = getKeyStates();
		if( (keyState & this.LEFT_PRESSED) != 0 ) //Verifica se alguma tecla foi pressionada
		{
			if(posXRaquete-30>0)
				posXRaquete -=30; //Movimenta a raquete para esquerda
		} else if  ( (keyState & this.RIGHT_PRESSED) != 0 ) {
			if( posXRaquete+30+larguraRaquete<getWidth() )
				posXRaquete +=30; //Movimenta a raquete para direita
		}
	}
	
	//Desenha os blocos
	private void desenhaParede(Graphics g)
	{
		int tonalidade = 255;
		int larguraDoBloco = (getWidth()-15)/10;
		int alturaDoBloco = (getHeight()-15)/15;
		
		//desenha o preenchimento dos blocos
		for(int py=5; py < alturaDoBloco * 5; py += alturaDoBloco )
		{
			g.setColor(0,tonalidade,0);
			for(int px = 5;px < larguraDoBloco*10; px += larguraDoBloco)
			{
				//Desenha apenas retangulos preenchidos
				g.fillRect(px,py,larguraDoBloco,alturaDoBloco);
			}
			tonalidade -= 10;
		}
		
		//desenha a borda dos blocos
		for(int py=5; py < alturaDoBloco * 5; py += alturaDoBloco )
		{
			g.setColor(0,0,0);
			for(int px = 5;px < larguraDoBloco*10; px += larguraDoBloco)
			{
				//Desenha apenas retangulos com bordas, sem preenchimento
				g.drawRect(px,py,larguraDoBloco,alturaDoBloco);
			}
			tonalidade -= 10;
		}
		
		
	}
}
