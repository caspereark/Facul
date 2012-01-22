/*
  Name: Projeto Agenda - L.P II - C++/O.O - Prof. Eraldo
  Copyright: [n/a] 
  Author: Edson A. Rodrigues, Marco Aureio R. Siqueira,Harley Viana
  Date: 21/10/06 06:56
  Description: Classe para lembretes/compromisso
*/
#include<iostream>
#include "clsArquivos.h"
#include "estruturas.h" //Estruturas
#include "funcoes.h"

using std::cin;
using std::cout;

//Declaração de cabecalho de biblioteca (n apagar)
#ifndef CLSLEMBRETES_H
#define CLSLEMBRETES_H
//Fim da declaracao de cabecalho

class clslembrete
{
      public:
             clslembrete();
             void incluir();
             void editar(char nome[]);
             bool excluir(char nome[]);
             void consultar();
             void exibir(Tlembrete x);
	         void menu();
             void relatorio();
      private:
             clsFilaLembrete Fila;
             //clsArquivosLembretes arquivo;
             Tlembrete lembrete;
             int localizarREG(char nome[]);        
};

clslembrete::clslembrete()
{
   cout << "\nCarregando arquivo lembretes.dat ...";
   Fila.filaAlloc();
   Tlembrete * temp,* vet;
   long i,n,p=0;
   
   n = NumerodeRegistrosL();
   
	
    if(n != 0)
	{     vet = (Tlembrete *) malloc(sizeof(Tlembrete)* n);
          RecuperarL(vet);
          
          while(p != n)
          {
             Fila.InserirNaFila(vet[p]);
             p++;
          }
      }
    
    cout << " Concluido\n\n";
   
                           
}

void clslembrete::menu()
{
	int i=0,h=0,p=0;
	char titulo[20];
	Tlembrete * temp;
    int n=0; 
    
    do
    { 
    system("cls"); 
	cout << "\n**************** -Lembretes- ****************\n\n1- Incluir\n2- Editar\n3- Excluir\n4- Consultar\n5- Relatorio\n6- Exibir Tudo\n 0 - Sair\n\tDigite sua opcao:   ";
	cin >> i;
	switch(i)
	{
		case 1:
			incluir();
			break;
		case 2:
            cout << "\nDigite o Titulo: ";
            fflush(stdin);
			fgets(titulo,20,stdin);
			editar(titulo);
			break;
		case 3:
            cout << "\nDigite o Titulo: ";
            fflush(stdin);
			fgets(titulo,20,stdin);
			excluir(titulo);
			break;
		case 4:
			consultar();
			break;
		case 5:
			//relatório
			cout << "\nFuncao nao implementada !!";
			system("pause");
			break;
		case 6:
		     Fila.Listar();
		     system("pause");
		     break;   
        case 7:
             Fila.ExibirInicioEFim();
             break;
        case 0:
             break;
        default:
              cout << "\n ERRO: Opcao invalida !!!";
              break;
	}
    } while(i != 0);
             LimparArquivoL();
              temp = Fila.GerarVetor(&n);
              
              
              
              
              while(h != n)
              {
                      SalvarL(temp[h]);
                      h++;
              }
              system("pause");

			
}


void clslembrete::incluir()
{        
    cout << "\nDigite o Titulo: ";
    fflush(stdin);
    fgets(lembrete.titulo,20,stdin);
    
              
    cout << "\nDigite a Descricao: ";
    fflush(stdin);
    fgets(lembrete.msg,50,stdin);
          
    lembrete.data = getData();  
	
	Fila.InserirNaFila(lembrete);
} //incluir

void clslembrete::editar(char nome[])
{
     TlembreteCelula *cell;
     Tlembrete *pess;

     cell = Fila.consultar(nome,pess);
     
     if(cell == NULL)
            cout << "\n Registro nao encontrado !! \n";
     else 
     { 
          cout << "\n\n * EDITANDO DADOS DO LEMBRETE *\n\n";
          
          cout << "\nNome: " ;
          
          cout << "\nDigite o Titulo: ";
          fflush(stdin);
          fgets(cell->lembrete.titulo,20,stdin);  
          
          cout << "\nDigite a Descricao: ";
          fflush(stdin);
          fgets(cell->lembrete.msg,50,stdin);
          
          cell->lembrete.data = getData();  
          
           
          
     }
        
} //editar

bool clslembrete::excluir(char nome[])
{    
     TlembreteCelula *cel;
     Tlembrete *pess;
     cel = Fila.consultar(nome,pess);
   
     if(cel == NULL)
            cout << "\n Registro nao encontrado !! \n";
     else 
     { 
          if(Fila.RemoverDaFila(cel) == true)
             cout << "\nExcluido!!\n";
     }   

} //excluir


void clslembrete::exibir(Tlembrete  x)
{    
     cout << "\n\n * DADOS DO LEMBRETE *\n\n";
     cout << "\nTitulo: " << x.titulo ;
     cout << "\nDescricao: " << x.msg ;
     cout << "-> Data: " << x.data.dia << "/" << x.data.mes << "/" <<  x.data.ano << "\n" ;
     system("pause");
}

void clslembrete::consultar()
{
    char titulo[20];
    TlembreteCelula * cell;
    Tlembrete * pess;
    
    cout << "\nDigite o Titulo: ";
    fflush(stdin);
    fgets(titulo,20,stdin);  
    
    
    cell = Fila.consultar(titulo,pess);
    
    if(cell == NULL)
    {  cout << "\n ERRO: Registro nao encontrado!!\n";
       system("pause");
    }else
       exibir(*pess);     

} //pesquisar

int clslembrete::localizarREG(char nome[])
{
     
} //localizarREG;

void  clslembrete::relatorio()
{


}

#endif //CLSLEMBRETES_H
