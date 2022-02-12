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
    insereL(&lista1, 10);
    insereL(&lista1, 7);
    insereL(&lista1, 11);
    insereL(&lista1, 12);
    insereL(&lista1, 9);
    insereL(&lista1, 8);
    insereL(&lista1, 5);
    insereL(&lista1, 3);
    mostraL(&lista1, "L1");

    cout << "\n\n###TESTE 2\n";
    retiraInicioInsereFimL(&lista1, 4);
    mostraL(&lista1, "L1");



    destroiL(&lista1);
    return EXIT_SUCCESS;


}//final do main

