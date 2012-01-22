/*
  Name: Projeto Agenda - L.P II - C++/O.O - Prof. Eraldo
  Copyright: [N/A]
  Author: Edson A. Rodriges, Marco Aur�io R. Siqueira,Harley Viana
  Date: 21/10/06 06:12
  Description: Programa principal da agenda
*/
#include <cstdlib>
#include <iostream>
#include "clsagenda.h" // class's header file

using namespace std;

int main(int argc, char *argv[])
{
    clsAgenda x;
    x.menu();
    system("PAUSE");
    return EXIT_SUCCESS;
}
