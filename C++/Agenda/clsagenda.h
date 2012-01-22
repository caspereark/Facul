/*
  Name: Projeto Agenda - L.P II - C++/O.O - Prof. Eraldo
  Copyright: [n/a]
  Author: Edson A. Rodrigues,Marco Aurélio R. Siqueira,Harley Viana
  Date: 21/10/06 06:20
  Description: Classe Agenda
*/
#include<iostream>
#include "clsPessoas.h"
#include "clslembretes.h"
#include "clsArquivos.h"
#include "estruturas.h"
#include "funcoes.h"

using std::cin;
using std::cout;

//Declaração de cabeçalho de biblioteca (não apagar)
#ifndef CLSAGENDA_H
#define CLSAGENDA_H
//Fim da declaração de cabeçalho

// **** CLASSE clsAgenda ********
class clsAgenda 
{
	public:
        clsPessoas Pessoas;
        clslembrete Lembretes;
        void menu(); //menu principal	
};

//Métodos

void clsAgenda::menu()
{
	int i,f;
    Tdata atual;
    
    atual = DataLocal(&f);
	do
	{
		cout << "****************** -Menu Principal- **************\n\n" << atual.dia << "/" << atual.mes << "/" << atual.ano << " Faltando " << f <<" dias para terminar o ano\n\n1-Pessoas\n2- Compromissos\n3- Sair\n\nDigite a opcao: ";
		cin >> i;
		switch(i)
		{
			case 1:
				Pessoas.menu();
				break;
			case 2:
				Lembretes.menu();
				break;
			case 3:
                 break;
		    default:
                 cout << "\nERRO: Opcao invalida !!\n";
                 break; 
		}
        system("cls");	
	} while(i != 3);

			
}//menu

#endif // CLSAGENDA_H
