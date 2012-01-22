/*
  Name: Projeto Agenda - L.P II - C++/O.O - Prof. Eraldo
  Copyright: [n/a] 
  Author: Edson A. Rodrigues, Marco Aurélio R. Siqueira,Harley Viana
  Date: 21/10/06 06:21
  Description: Funções extras da agenda
*/
#include<iostream>
#include<time.h>
#include"estruturas.h"

using std::cin;
using std::cout;

//Declaraïcao de cabecalho de biblioteca (n apagar)
#ifndef FUNCOES_H
#define FUNCOES_H
//Fim da declaracao de cabecalho

//Devolve a data do computador local
Tdata DataLocal(int * faltando)
{
      Tdata DataFinal;
      struct tm *area;
      time_t t;
      
      t = time(NULL);
      area = localtime(&t);
      
      DataFinal.dia = area->tm_mday;
      DataFinal.mes = area->tm_mon +1;
      DataFinal.ano = area->tm_year+1900;
      
      *faltando = 365 - area->tm_yday;
      
      return DataFinal;
}

//Pega a Data
Tdata getData()
{
      Tdata data;
      bool ok=false;
      
      cout << "\nDigite a data (dd/mm/aaaa): ";

      scanf("%d/%d/%d",&data.dia,&data.mes,&data.ano);
           
      return data;
}

int DataCmp(Tdata data1,Tdata data2)
{
    if((data1.dia == data2.dia) && (data1.mes == data2.mes) && (data1.ano == data2.ano)  )
      return 0;
    else
      return -1;  
}

//Pega os telefones
Tfone getFones()
{
      Tfone fone;
      
      cout << "\nTelefone Residencial: ";
	  cin >> fone.telresidencial; 

      cout << "\nTelefone Comercial: ";
	  cin >> fone.telcomercial;
      
      cout << "\nTelefone Celular: ";
	  cin >> fone.telcel;
      
      cout << "\nFax: ";
	  cin >> fone.fax;  
      
      return fone; 
      
           
}

#endif
