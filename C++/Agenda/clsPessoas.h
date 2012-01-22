/*
  Name: Projeto Agenda - L.P II - C++/O.O - Prof. Eraldo
  Copyright: [n/a] 
  Author: Edson A. Rodrigues, Marco Aureio R. Siqueira,Harley Viana
  Date: 21/10/06 07:11
  Description: Classe para cadastro de pessoas
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include "estruturas.h" //Estruturas
#include "funcoes.h"
#include "clsFila.h"
#include "clsArquivos.h"

using std::cin;
using std::cout;

//Declaracao de cabecalho de biblioteca (n apagar)
#ifndef CLSPESSOAS_H
#define CLSPESSOAS_H
//Fim da declaracao de cabecalho

class clsPessoas 
{
      public:
             clsPessoas();
             void incluir();
             void editar(char nome[]);
             bool excluir(char nome[]);
             void consultar();
             void exibir(TPessoa x);
	         void menu();
             void relatorio();
      private:
             clsFilaPessoa Fila;
             //clsArquivosPessoas arquivo;
             TPessoa pessoas;
             Tdata datacorrente;
             int localizarREG(char nome[]);        
};

clsPessoas::clsPessoas()
{
   cout << "Carregando arquivo pessoas.dat ...";
   Fila.filaAlloc();
   TPessoa * temp,* vet;
   long i,n,p=0;
   
   n = NumerodeRegistros();
   
	
    if(n != 0)
	{     vet = (TPessoa *) malloc(sizeof(TPessoa)* n);
          
          Recuperar(vet);
          
          
          while(p != n)
          {
             
             Fila.InserirNaFila(vet[p]);
             p++;
          }
      }
    cout << " Concluido\n";

    
    //free(vet);
   
                           
}

void clsPessoas::menu()
{
	int i=0,h=0,p=0;
	char nome[100];
	TPessoa * temp;
    int n=0; 
    
    do
    { 
        system("cls"); 
	cout << "\n ******************* -Pessoas- ****************\n\n\t1- Incluir\n\t 2- Editar\n\t 3- Excluir\n\t 4- Consultar\n\t 5- Relatorio\n\t 6- Exibir lista\n\t0 - Sair\n\tDigite sua opcao:   ";
	cin >> i;
	switch(i)
	{
		case 1:
			incluir();
			break;
		case 2:
            cout << "\nDigite o nome: ";
            fflush(stdin);
			fgets(nome,100,stdin);
			editar(nome);
			break;
		case 3:
            cout << "\nDigite o nome: ";
            fflush(stdin);
			fgets(nome,100,stdin);
			excluir(nome);
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
             system("pause");
             break;
        default:
              cout << "\n ERRO: Opcao invalida !!!";
              break;
	}
    } while(i != 0);
              cout << "\nSalvando as informações no arquivo ...";
              LimparArquivo();
              temp = Fila.GerarVetor(&n);

              while(h != n)
              {

                      Salvar(temp[h]);
                      h++;
              }
              cout << " Concluido!\n";
			
}


void clsPessoas::incluir()
{        
    cout << "\nDigite o nome: ";
    fflush(stdin);
    fgets(pessoas.nome,100,stdin);
    
	cout << "\nEndereco: ";
	fgets(pessoas.endereco,100,stdin);
	
	cout << "\nBairro: ";
	fflush(stdin);
    fgets(pessoas.bairro,50,stdin);
    
	cout << "\nCEP :";
	cin >> pessoas.cep ;
	
	pessoas.telefones = getFones();
	
	pessoas.aniversario = getData();
	
	cout << "\nE-mail:";
	cin >> pessoas.email;
	
	Fila.InserirNaFila(pessoas);
} //incluir

void clsPessoas::editar(char nome[])
{
     TPessoasCelula *cell;
     TPessoa *pess;

     cell = Fila.consultar(nome,pess);
     
     if(cell == NULL)
            cout << "\n Registro nao encontrado !! \n";
     else 
     { 
          cout << "\n\n * EDITANDO DADOS PESSOAIS DO CONTATO *\n\n";
          
          cout << "\nDigite o nome: ";
          fflush(stdin);
          fgets(cell->pessoa.nome,100,stdin);
          
          cout << "\nEndereco: " ;
          cin >> cell->pessoa.endereco ;
	      
          cout << "\nBairro: " ;
          fflush(stdin);
          cin >> cell->pessoa.bairro ;
          
          cout << "\nCEP :" ;
          cin >> cell->pessoa.cep;
     
          cout << "-> Telefones \n";
     
          cout << "\nTelefone Residencial: "; 
          cin >> cell->pessoa.telefones.telresidencial ;
          
          cout << "\nTelefone Comercial: " ;
          cin >> cell->pessoa.telefones.telcomercial;	
     
          cout << "\nTelefone Celular: " ;
          cin >> cell->pessoa.telefones.telcel ;
     
          cout << "\nFax: ";
          cin >> cell->pessoa.telefones.fax ;
     
          cout << "-> Data de Aniversario: ";
          cell->pessoa.aniversario = getData();
          
          cout << "\nE-mail: "; 
          cin >> cell->pessoa.email ; 
     }
        
} //editar

bool clsPessoas::excluir(char nome[])
{    
     TPessoasCelula *cel;
     TPessoa *pess;
     cel = Fila.consultar(nome,pess);
   
     if(cel == NULL)
            cout << "\n Registro nao encontrado !! \n";
     else 
     { 
          if(Fila.RemoverDaFila(cel) == true)
             cout << "\nExcluido!!\n";
     }   
   

} //excluir


void clsPessoas::exibir(TPessoa  x)
{    
     cout << "\n\n * DADOS PESSOAIS DO CONTATO *\n\n";
     cout << "\nNome: " << x.nome ;
     cout << "\nEndereco: " << x.endereco ;
	 cout << "\nBairro: " << x.bairro ;
     cout << "\nCEP :" << x.cep  ;
     cout << "-> Telefones \n";
     cout << "\nTelefone Residencial: " << x.telefones.telresidencial ;
     cout << "\nTelefone Comercial: " << x.telefones.telcomercial  ;	
     cout << "\nTelefone Celular: " << x.telefones.telcel ;
     cout << "\nFax: " << x.telefones.fax  ;
     cout << "-> Data de Aniversario: " << x.aniversario.dia << "/" << x.aniversario.mes << "/" <<  x.aniversario.ano ;
     cout << "\nE-mail: " << x.email << "\n\n";
     system("pause");
}

void clsPessoas::consultar()
{
    char titulo[100];
    TPessoasCelula * cell;
    TPessoa * pess;
    TPessoa y;
    
    cout << "\nDigite o Nome: ";
    fflush(stdin);
    fgets(titulo,100,stdin);  
    
    cell = Fila.consultar(titulo,pess);
    
    if(cell == NULL)
    {  cout << "\n ERRO: Registro nao encontrado!!\n";
       system("pause");
    }else
    {   y = cell->pessoa;
        exibir(y);
    } 
} //pesquisar

int clsPessoas::localizarREG(char nome[])
{
     
} //localizarREG;

void  clsPessoas::relatorio()
{

}

#endif //CLSCADASTRO_H
