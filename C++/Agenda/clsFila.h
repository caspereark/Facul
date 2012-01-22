#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<strings.h>
#include "funcoes.h"

#include<iostream>

using std::cout;

//Declaracaoo de cabecalho de biblioteca (n apagar)
#ifndef CLSFILA_H
#define CLSFILA_H
//Fim da declaracao de cabecalho

/* #################### clsFilaPessoa ########################### */
class clsFilaPessoa 
{
      public:
              void filaAlloc(void);
              void InserirNaFila(TPessoa x);
              bool RemoverDaFila(TPessoasCelula *cell);
              TPessoasCelula * consultar(char texto[],TPessoa * celula);
              void Listar();
              TPessoa * GerarVetor(int * n);
              void RecuperaVetor(TPessoa * vetor,int n);
              void ExibirInicioEFim();
              //void DestruirFila();
      private:
              int NElementos();
              TPfila *fila;
              TPessoasCelula *celulaAlloc(TPessoa x);
              int filavazia();
              
};


/*void clsFilaPessoa::DestruirFila()
{
     free(fila);  
}*/

int clsFilaPessoa::NElementos()
{   TPessoasCelula *AuxCount;
    AuxCount = fila->inicio;
    int i=0;
    
    if(filavazia() == false)
    {
        do {     
             AuxCount = AuxCount->prox;
             i++;
        }while(AuxCount != fila->inicio);
        return i;
    }else return 0;  
     
     
}
void clsFilaPessoa::filaAlloc(void)
{
	fila = (TPfila *) malloc(sizeof(TPfila));
	fila->inicio = fila->fim = NULL;

}//filaAlloc

TPessoasCelula * clsFilaPessoa::celulaAlloc(TPessoa x)
{	TPessoasCelula *novacelula;
	novacelula = (TPessoasCelula *) malloc(sizeof(TPessoasCelula));
	novacelula->prox = NULL;
	novacelula->pessoa = x;
    return novacelula;
}//celulaAlloc

int clsFilaPessoa::filavazia()
{
	if(fila->inicio == NULL)
		return true;
	else
		return false;
}//filavazia

void clsFilaPessoa::InserirNaFila(TPessoa x)
{
	TPessoasCelula *n;
	n = celulaAlloc(x);
	if( filavazia() == true)
		fila->inicio = fila->fim = n;
	else
	{	
        fila->fim->prox =n;
		fila->fim = n;
		fila->fim->prox = fila->inicio;
	}
}//filainsertcirc

bool clsFilaPessoa::RemoverDaFila(TPessoasCelula *cell)
{
     TPessoasCelula *p;
	if(filavazia() == true)
	   return false;
	else
	{
        TPessoasCelula *aux,*AuxCount,*Ant;

        if(fila->inicio == NULL)
			fila->fim = NULL;
		else
		{	
          if(fila->inicio == fila->fim)
		  {		fila->inicio = fila->fim = NULL;
		        free(cell);
		        return true;
                
            }
			else
			{       
                    if(fila->inicio == cell)
                    {  
                       p = cell;
                       fila->fim->prox = fila->inicio->prox;
                       fila->inicio = fila->inicio->prox;
                       return true;
                    }
                    else
                    {  AuxCount = cell;
                       do {     
                            
                            Ant = AuxCount;
                            AuxCount = AuxCount->prox;
                       }while(AuxCount != cell);
                     
                       if(fila->fim == cell)
                       {   
                           fila->fim = Ant;
                           Ant->prox = cell->prox;
                           free(cell);
                           return true;                   
                       }       
                       if(AuxCount == cell ||  Ant->prox == cell)
                       {    
                            Ant->prox = cell->prox;
                            free(cell);
                            return true;
                       } else
                             return false;
                     //Aux->prox = p;
                  }
                }     
        }
  } free(cell);
	return true;
}//filaremovercirc

TPessoa * clsFilaPessoa::GerarVetor(int * n)
{
     int i=0,h=0;
    
    TPessoasCelula *aux,*AuxCount,*Ant;
    TPessoa * vet;
    AuxCount = fila->inicio;
    
    i = NElementos();
    
    if( i > 0)
    {  vet = (TPessoa *) malloc(sizeof(TPessoa)* i);
    
       AuxCount = fila->inicio;
       h = i;

       do {     
             vet[i-1] = AuxCount->pessoa;
             AuxCount = AuxCount->prox;
             i--;
       }while(i >= 0);

       *n = h;
    
    return vet;
    } else
    { *n = 0;
      return NULL;
    }
    
}

void  clsFilaPessoa::RecuperaVetor(TPessoa * vetor,int n)
{
    do {     
             InserirNaFila(vetor[n-1]);
             n--;
    }while(n >= 0);  
}

TPessoasCelula * clsFilaPessoa::consultar(char texto[],TPessoa * celula)
{	
    TPessoasCelula *aux;
	int i;
	if(filavazia() == false)
	{	aux = fila->inicio;
		do{
			if(strcmp(aux->pessoa.nome,texto)==0)
			{   cout << "\nAchou!!\n";
                celula = &aux->pessoa;
                return aux;
            }
			else	
				aux = aux->prox;
		} while (aux != fila->inicio && aux != NULL);
		//if(aux == NULL)
			return NULL;
	}
	
}//consultar

void clsFilaPessoa::ExibirInicioEFim()
{
                   cout << "\n elementos na fila: " << NElementos();
                   cout << "\n inicio: " << fila->inicio->pessoa.nome;
                   cout << "\n fim: " << fila->fim->pessoa.nome;   
}

void clsFilaPessoa::Listar()
{	TPessoasCelula *aux;
	int i;
	if(filavazia() == false)
	{	aux = fila->inicio;
		do{
            cout << "\n\n * DADOS PESSOAIS DO CONTATO *\n\n";
            cout << "\nNome: " << aux->pessoa.nome << "\n";
            cout << "\nEndereco: " << aux->pessoa.endereco << "\n";
            cout << "\nBairro: " << aux->pessoa.bairro << "\n";
            cout << "\nCEP :" << aux->pessoa.cep << "\n\n";
            cout << "-> Telefones \n";
            cout << "\nTelefone Residencial: " << aux->pessoa.telefones.telresidencial << "\n";
            cout << "\nTelefone Comercial: " << aux->pessoa.telefones.telcomercial << "\n";	
            cout << "\nTelefone Celular: " << aux->pessoa.telefones.telcel << "\n";
            cout << "\nFax: " << aux->pessoa.telefones.fax << "\n\n";
            cout << "-> Data de Aniversario: " << aux->pessoa.aniversario.dia << "/" << aux->pessoa.aniversario.mes << "/" <<  aux->pessoa.aniversario.ano << "\n\n" ;
            cout << "\nE-mail: " << aux->pessoa.email << "\n\n";
			
			aux = aux->prox;
		} while (aux != fila->inicio && aux != NULL);
	}
}//filalistar



/* #################### clsFilaLembrete ######################### */

class clsFilaLembrete 
{
      public:
              void InicializaFila();
              void filaAlloc(void);
              void InserirNaFila(Tlembrete x);
              bool RemoverDaFila(TlembreteCelula *cell);
              TlembreteCelula * consultar(char titulo[],Tlembrete * celula);
              void Listar();
              Tlembrete * GerarVetor(int * n);
              void RecuperaVetor(Tlembrete * vetor,int n);
              void ExibirInicioEFim();
              //void DestruirFila();
      private:
              int NElementos();
              TLfila *fila;
              TlembreteCelula *celulaAlloc(Tlembrete x);
              int filavazia();
              
};

/*void clsFilaPessoa::DestruirFila()
{
     free(fila);  
}*/

int clsFilaLembrete::NElementos()
{   TlembreteCelula *AuxCount;
    AuxCount = fila->inicio;
    int i=0;
    
    if(filavazia() == false)
    {
        do {     
             AuxCount = AuxCount->prox;
             i++;
        }while(AuxCount != fila->inicio);
        return i;
    }else return 0;  
       
}
void clsFilaLembrete::filaAlloc(void)
{
	fila = (TLfila *) malloc(sizeof(TLfila));
	fila->inicio = fila->fim = NULL;

}//filaAlloc

TlembreteCelula * clsFilaLembrete::celulaAlloc(Tlembrete x)
{	TlembreteCelula *novacelula;
	novacelula = (TlembreteCelula *) malloc(sizeof(TlembreteCelula));
	novacelula->prox = NULL;
	novacelula->lembrete = x;
    return novacelula;
}//celulaAlloc

int clsFilaLembrete::filavazia()
{
	if(fila->inicio == NULL)
		return true;
	else
		return false;
}//filavazia

void clsFilaLembrete::InserirNaFila(Tlembrete x)
{
	TlembreteCelula *n;
	n = celulaAlloc(x);
	if( filavazia() == true)
		fila->inicio = fila->fim = n;
	else
	{	
        fila->fim->prox =n;
		fila->fim = n;
		fila->fim->prox = fila->inicio;
	}
}//filainsertcirc

bool clsFilaLembrete::RemoverDaFila(TlembreteCelula *cell)
{
     TlembreteCelula *p;
	if(filavazia() == true)
	   return false;
	else
	{
        TlembreteCelula *aux,*AuxCount,*Ant;

        if(fila->inicio == NULL)
			fila->fim = NULL;
		else
		{	
          if(fila->inicio == fila->fim)
		  {		fila->inicio = fila->fim = NULL;
		        free(cell);
		        return true;
                
            }
			else
			{       
                    if(fila->inicio == cell)
                    {  
                       p = cell;
                       fila->fim->prox = fila->inicio->prox;
                       fila->inicio = fila->inicio->prox;
                       return true;
                    }
                    else
                    {  
                       do {     
                            
                            Ant = AuxCount;
                            AuxCount = AuxCount->prox;
                       }while(AuxCount != cell);
                     
                       if(fila->fim == cell)
                       {   
                           fila->fim = Ant;
                           Ant->prox = cell->prox;
                           free(cell);
                           return true;                   
                       }       
                       if(AuxCount == cell ||  Ant->prox == cell)
                       {   
                            Ant->prox = cell->prox;
                            free(cell);
                            return true;
                       } else
                             return false;
                  }
                }     
        }
  } free(cell);
	return true;
}//filaremovercirc

Tlembrete * clsFilaLembrete::GerarVetor(int * n)
{
    int i=0,h=0;
    
    TlembreteCelula *aux,*AuxCount,*Ant;
    Tlembrete * vet;
    AuxCount = fila->inicio;
    
    i = NElementos();
    
    if( i > 0)
    
    {  vet = (Tlembrete *) malloc(sizeof(Tlembrete)* i);
    
       AuxCount = fila->inicio;
       h = i;

       do {     
             vet[i-1] = AuxCount->lembrete;
             AuxCount = AuxCount->prox;
             i--;
       }while(i >= 0);

       *n = h;
    
    return vet;
    } else
    { *n = 0;
      return NULL;
    }
    
}

void  clsFilaLembrete::RecuperaVetor(Tlembrete * vetor,int n)
{
    do {     
             InserirNaFila(vetor[n-1]);
             n--;
    }while(n >= 0);  
}

TlembreteCelula * clsFilaLembrete::consultar(char titulo[],Tlembrete * celula)
{	
    TlembreteCelula *aux;
	int i;
	if(filavazia() == false)
	{	aux = fila->inicio;
		do{
			if(strcmp(aux->lembrete.titulo,titulo)==0)
			{  
                celula = &aux->lembrete;
                return aux;
            }
			else	
				aux = aux->prox;
		} while (aux != fila->inicio && aux != NULL);
		//if(aux == NULL)
			return NULL;
	}
	
}//consultar

void clsFilaLembrete::ExibirInicioEFim()
{
                   cout << "\n elementos na fila: " << NElementos();
                   cout << "\n inicio: " << fila->inicio->lembrete.titulo;
                   cout << "\n fim: " << fila->fim->lembrete.titulo;   
}

void clsFilaLembrete::Listar()
{	TlembreteCelula *aux;
	int i;
	if(filavazia() == false)
	{	aux = fila->inicio;
		do{
            cout << "\n\n * DADOS DO LEMBRETE *\n\n";
            cout << "\nTitulo: " << aux->lembrete.titulo << "\n";
            cout << "\nDescricao: " << aux->lembrete.msg << "\n";
            cout << "-> Data: " << aux->lembrete.data.dia << "/" << aux->lembrete.data.mes << "/" <<  aux->lembrete.data.ano << "\n" ;
			aux = aux->prox;
		} while (aux != fila->inicio && aux != NULL);
	}
}//filalistar

#endif
