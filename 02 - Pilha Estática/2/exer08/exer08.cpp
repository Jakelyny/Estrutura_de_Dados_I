#include <iostream>
using namespace std;

#include "pilha.hpp"


int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Pilha p1, p2;
    int tamPilha=5, valor;

    inicializa(&p1, tamPilha);
    inicializa(&p2, tamPilha);

    cout << "\n\n---------------TESTE 1---------------\n";
    empilhar(&p1, 10);
    empilhar(&p1, 21);
    empilhar(&p1, 30);
    empilhar(&p1, 40);


    empilhar(&p2, 10);
    empilhar(&p2, 21);
    empilhar(&p2, 30);

    mostrar(&p1);
    mostrar(&p2);

    cout << "As pilhas P1 e P2 são iguais? " << (iguais(&p1, &p2) ? "verdadeiro" : "falso") << endl;


    cout << "\n\n---------------TESTE 2---------------\n";
    desempilhar(&p1, &valor);
    mostrar(&p1);
    mostrar(&p2);
    cout << "As pilhas P1 e P2 são iguais? " << (iguais(&p1, &p2) ? "verdadeiro" : "falso") << endl;


    cout << "\n\n---------------TESTE 3---------------\n";
    mostrar(&p1);
    cout << "O número de elementos pares da pilha P1 é: " << contPar(&p1) << endl;

    desalocar(&p1);
    desalocar(&p2);

    return EXIT_SUCCESS;

}//final do main

