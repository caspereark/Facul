/*
 * Contatos.java
 *
 * Created on 11 de Março de 2007, 19:09
 */


import javax.microedition.midlet.*;
import javax.microedition.lcdui.*;

/**
 *
 * @author  PCS
 * @version
 */
public class Contatos extends MIDlet implements CommandListener{
    
    private Form frm;
    private List lstNomes, lstFones;
    private TextField txtNome, txtTel;
    private Command cmdSair, cmdVoltar, cmdAdicionar, cmdListar, cmdVer;
    private int pos;
    private String nomes[];
    private String telefones[];
    private Display tela;
   
    public Contatos(){
        frm = new Form("NOVOS CONTATOS"); //Formulario Principal
        nomes = new String[100]; // vetor de nomes
        telefones = new String[100]; // vetor de telefones
        txtNome = new TextField("Nome:","",12,TextField.ANY); // caixa de texto para nomes
        txtTel = new TextField("Fone: ","",12,TextField.PHONENUMBER);// caixa de texto para fones
        cmdSair = new Command("Sair",Command.EXIT,0); //comando sair do formulário principal
        cmdVoltar = new Command("Voltar",Command.BACK,0);
        cmdAdicionar = new Command("Adicionar",Command.SCREEN,0);
        cmdListar = new Command("Listar",Command.SCREEN,1);
        cmdVer = new Command("Ver",Command.SCREEN,0);
        lstNomes = new List("LISTA DE CONTATOS",List.IMPLICIT);
        lstFones = new List("",List.IMPLICIT);
        frm.addCommand(cmdSair);
        frm.addCommand(cmdAdicionar);
        frm.addCommand(cmdListar);
        frm.append(txtNome);
        frm.append(txtTel);
        tela = Display.getDisplay(this);
        frm.setCommandListener(this);
        lstNomes.addCommand(cmdVoltar);
        lstFones.addCommand(cmdVoltar);
        //lstNomes.addCommand(cmdVer);
        lstNomes.setCommandListener(this);
        lstFones.setCommandListener(this);
    }
    
    public void startApp() {
        tela.setCurrent(frm);
    }
    
    public void pauseApp() {
    }
    
    public void destroyApp(boolean unconditional) {
    }
    
    public void commandAction(Command c, Displayable d){
       if(c==cmdSair){
        this.destroyApp(true);
        this.notifyDestroyed();
       }
       else if(c==cmdAdicionar){
           nomes[pos]=txtNome.getString();
           telefones[pos++]=txtTel.getString();
           txtTel.setString("");
           txtNome.setString("");
       }
       else if (c==cmdListar){
           lstNomes.deleteAll();
           for(int i=0;nomes[i]!=null;i++)lstNomes.append(nomes[i] + ' ' + telefones[i],null);
           tela.setCurrent(lstNomes);
       }
       else if (c==cmdVoltar && d==lstNomes){
           tela.setCurrent(frm);
       }
       else if (c==cmdVoltar && d==lstFones){
           tela.setCurrent(lstNomes);
       }
       else if(c==cmdVer){
           lstFones.deleteAll();
           lstFones.setTitle(lstNomes.getString(lstNomes.getSelectedIndex()));
           lstFones.append(telefones[lstNomes.getSelectedIndex()],null);
           tela.setCurrent(lstFones);
       }
    }
}
