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
    mostraL(&lista1, "L1");
    if(ordemL(&lista1, ORDEM_CRESCENTE) )
        cout << "A lista está em ordem crescente!\n";
    else
        cout << "A lista NÃO está em ordem crescente!\n";

    if(ordemL(&lista1, ORDEM_DECRESCENTE) )
        cout << "A lista está em ordem decrescente!\n";
    else
        cout << "A lista NÃO está em ordem decrescente!\n";


    cout << "\n\n###TESTE 2\n";
    insereL(&lista1, 10);
    mostraL(&lista1, "L1");
    if(ordemL(&lista1, ORDEM_CRESCENTE) )
        cout << "A lista está em ordem crescente!\n";
    else
        cout << "A lista NÃO está em ordem crescente!\n";

    if(ordemL(&lista1, ORDEM_DECRESCENTE) )
        cout << "A lista está em ordem decrescente!\n";
    else
        cout << "A lista NÃO está em ordem decrescente!\n";


    cout << "\n\n###TESTE 3\n";
    insereL(&lista1, 10);
    insereL(&lista1, 11);
    mostraL(&lista1, "L1");
    if(ordemL(&lista1, ORDEM_CRESCENTE) )
        cout << "A lista está em ordem crescente!\n";
    else
        cout << "A lista NÃO está em ordem crescente!\n";

    if(ordemL(&lista1, ORDEM_DECRESCENTE) )
        cout << "A lista está em ordem decrescente!\n";
    else
        cout << "A lista NÃO está em ordem decrescente!\n";


    cout << "\n\n###TESTE 4\n";
    destroiL(&lista1);
    insereL(&lista1, 12);
    insereL(&lista1, 11);
    insereL(&lista1, 10);
    mostraL(&lista1, "L1");
    if(ordemL(&lista1, ORDEM_CRESCENTE) )
        cout << "A lista está em ordem crescente!\n";
    else
        cout << "A lista NÃO está em ordem crescente!\n";

    if(ordemL(&lista1, ORDEM_DECRESCENTE) )
        cout << "A lista está em ordem decrescente!\n";
    else
        cout << "A lista NÃO está em ordem decrescente!\n";

    destroiL(&lista1);
    return EXIT_SUCCESS;


}//final do main

