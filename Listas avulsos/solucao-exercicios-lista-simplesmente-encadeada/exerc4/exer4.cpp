#include <iostream>
using namespace std;

#include "lista.hpp"


int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    int valor;
    No *lista1;

    inicializaL(&lista1);

    cout << "\n\n###TESTE 1\n";
    insereL(&lista1, 'U');
    insereL(&lista1, 'O');
    insereL(&lista1, 'I');
    insereL(&lista1, 'E');
    insereL(&lista1, 'A');
    mostraL(&lista1);


    cout << "\n\n###TESTE 2\n";
    mostraInvL(&lista1);



    destroiL(&lista1);
    return EXIT_SUCCESS;


}//final do main

