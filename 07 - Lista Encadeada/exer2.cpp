#include <iostream>
using namespace std;

#include "lista.hpp"


int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    int valor;
    No *lista1, *lista2, *lista3;

    inicializaL(&lista1);
    inicializaL(&lista2);
    inicializaL(&lista3);

    cout << "\n\n###TESTE 1\n";
    insereL(&lista1, 10);
    insereL(&lista1, 20);
    insereL(&lista1, 30);
    insereL(&lista1, 40);
    mostraL(&lista1, "L1");

    insereL(&lista2, 10);
    insereL(&lista2, 20);
    insereL(&lista2, 30);
    insereL(&lista2, 50);
    mostraL(&lista2, "L2");

    cout << "Lista 1 e 2 são iguais? " << ( igual(&lista1, &lista2)  ? "SIM" : "NÃO") << endl;


    cout << "\n\n###TESTE 2\n";
    mostraL(&lista1, "L1");
    mostraL(&lista2, "L2");

    removeL(&lista2, 50);
    insereL(&lista2, 40);
    mostraL(&lista2, "L2");

    cout << "Lista 1 e 2 são iguais? " << ( igual(&lista1, &lista2)  ? "SIM" : "NÃO") << endl;


    cout << "\n\n###TESTE 3\n";
    mostraL(&lista1, "L1");
    insereFinalL(&lista1, 90);
    insereFinalL(&lista1, 110);
    mostraL(&lista1, "L1");




    cout << "\n\n###TESTE 4\n";
    destroiL(&lista1);
    mostraL(&lista1, "L1");
    insereOrdenadoL(&lista1, 10);
    insereOrdenadoL(&lista1, 9);
    insereOrdenadoL(&lista1, 8);
    insereOrdenadoL(&lista1, 5);
    insereOrdenadoL(&lista1, 1);
    insereOrdenadoL(&lista1, 15);
    mostraL(&lista1, "L1");




    cout << "\n\n###TESTE 5\n";
    mostraL(&lista1, "L1");
    int t = total(&lista1);
    for (int i=0; i<t; i++ )
    {
        if(lePosicao(&lista1, i, &valor))
        {
            cout << valor << ", ";
        }
    }
    cout << endl;



    cout << "\n\n###TESTE 6\n";
    mostraL(&lista1, "L1");
    removePosicaoL(&lista1, 0);
    mostraL(&lista1, "L1");
    removePosicaoL(&lista1, 4);
    mostraL(&lista1, "L1");
    cout << endl;


    cout << "\n\n###TESTE 7\n";
    mostraL(&lista1, "L1");
    mostraL(&lista2, "L2");
    uniao(&lista1, &lista2, &lista3);
    mostraL(&lista3, "L3");
    cout << endl;




    destroiL(&lista1);
    return EXIT_SUCCESS;


}//final do main

