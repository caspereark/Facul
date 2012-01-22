/*
  Name: Projeto Agenda - L.P II - C++/O.O - Prof. Eraldo
  Copyright: [n/a] 
  Author: Edson A. Rodrigues, Marco Aurelio R. Siqueira,Harley Viana
  Date: 21/10/06 06:21
  Description: Estruturas a ser usado no programa
*/

//Declaracaoo de cabecalho de biblioteca (n apagar)
#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H
//Fim da declaracao de cabecalho


//Estrutura de ponteiros para a Filas Dinâmicas
typedef struct Pcelula *apontadorP;
typedef struct Lcelula *apontadorL;


// Estrutura telefone
typedef struct
{
        char telresidencial[15];
        char telcomercial[15];
        char telcel[15];
        char fax[15];
} Tfone;

//Estrutura Data
typedef struct
{
        int dia;
        int mes;
        int ano;
        /*int hora;
        int min;*/
} Tdata;  

//Estrutura Pessoa
typedef struct
{
        char nome[100];
        char endereco[100];
        char bairro[50];
        char cep[10];
        Tfone telefones;
        Tdata aniversario;
        char email[50];
}TPessoa;

//Estrutura lembrete
typedef struct
{
        char titulo[20];
        char msg[50];
        Tdata data;
} Tlembrete;

//Celula Pessoa
typedef struct Pcelula
{
	TPessoa pessoa;
	apontadorP prox;
} TPessoasCelula;

//Celula Lembretes
typedef struct Lcelula
{
    Tlembrete lembrete;
	apontadorL prox;
} TlembreteCelula;

//Fila de Pessoas
typedef struct Pfila
{
	apontadorP inicio;
	apontadorP fim;
} TPfila;

//Fila de Lembretes
typedef struct Lfila
{
	apontadorL inicio;
	apontadorL fim;
} TLfila;

#endif // ESTRUTURAS_H
