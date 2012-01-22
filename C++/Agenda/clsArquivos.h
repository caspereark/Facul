/*
  Name: Projeto Agenda - L.P II - C++/O.O - Prof. Eraldo
  Copyright: [n/a] 
  Author: Edson A. Rodrigues, Marco Aureio R. Siqueira,Harley Viana
  Date: 21/10/06 06:21
  Description: Classe para manipulacao de arquivos
*/

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>

#include "estruturas.h"

using std::ios;
using std::cin;
using std::cout;

using std::filebuf;
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::streampos;

//Declaracao de cabecalho de biblioteca (n apagar)
#ifndef CLSARQUIVOS_H
#define CLSARQUIVOS_H
//Fim da declaracao de cabecalho
/*
class clsArquivos
{
      protected:
                ifstream fin;
                ofstream fout;
};*/

// ###################### clsArquivosLembretes #######################
/*
class clsArquivosLembretes : public clsArquivos
{
      public:
             void Salvar(Tlembrete x);
             void Recuperar(Tlembrete x[]); 
             void LimparArquivo();
             long NumerodeRegistros();
};*/


void LimparArquivoL()
{
    ofstream fout("lembretes.dat",ios::trunc); 
   
   fout.close();          
}

long NumerodeRegistrosL()
{
   long resultado=0;
   
   ifstream fin("lembretes.dat");
    
   fin.seekg(0,ios::end);
    
   resultado = ( fin.tellg() ) / ( sizeof(Tlembrete) );
    
   fin.close();
        
   return resultado;    
}

void RecuperarL(Tlembrete x[])
{
   int p=0;

    ifstream fin("lembretes.dat");
    Tlembrete li;


    while(fin.read((char *)&li ,sizeof(Tlembrete) ))
    {   
         x[p] = li;
         p++;
    }
    
    fin.close();  
}

void SalvarL(Tlembrete x)
{
   ofstream fout("lembretes.dat",ios::app); 
   
   fout.write((char *)&x,sizeof(Tlembrete));
   
   fout.close();    
}

// ###################### clsArquivosPessoas #########################
/*
class clsArquivosPessoas : public clsArquivos
{
      public:
             void Salvar(TPessoa x);
             void Recuperar(TPessoa x[]); 
             void LimparArquivo();
             long NumerodeRegistros();
};*/

void LimparArquivo()
{
    ofstream fout("pessoas.dat",ios::trunc); 
   
   
   fout.close();     
}

long NumerodeRegistros()
{
   long resultado=0;
   
   ifstream fin("pessoas.dat");
    
   fin.seekg(0,ios::end);
    
   resultado = ( fin.tellg() ) / ( sizeof(TPessoa) );
    
   fin.close();
        
   return resultado;    

}
    

void Salvar(TPessoa x)
{
   ofstream fout("pessoas.dat",ios::app); 
   
   fout.write((char *)&x,sizeof(TPessoa));
   
   fout.close();
       
}

void Recuperar(TPessoa x[])
{
   int p=0;

    ifstream fin("pessoas.dat");
    TPessoa li;

    fin.seekg(0);
    while(fin.read((char *)&li ,sizeof(TPessoa) ))
    { 
         x[p] = li;
         p++;
    }
    
    fin.close();  
    
}

#endif
