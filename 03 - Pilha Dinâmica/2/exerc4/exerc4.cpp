#include <iostream>
using namespace std;

#include "pilha-dinamica.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    Pilha p1, p2;


    inicializa(&p1);
    inicializa(&p2);


    cout << "\n\n###Teste1\n";
    for(int i=1; i<5; i++)
    {
        empilhar(&p1, i);
        empilhar(&p2, i);
    }
    mostrar(&p1);
    mostrar(&p2);

    cout << "Número de elementos pares na pilha p1 é: " << contPar(&p1) << endl;
    cout << "Número de elementos pares na pilha p2 é: " << contPar(&p2) << endl;
    if(iguais(&p1, &p2))
        cout << "As pilhas p1 e p2 são iguais! " << endl;
    else
        cout << "As pilhas p1 e p2 não são iguais! " << endl;



    cout << "\n\n###Teste2\n";
    desalocar(&p1);
    desalocar(&p2);
    inicializa(&p1);
    inicializa(&p2);

    for(int i=1; i<3; i++)
        empilhar(&p1, i);

    for(int i=1; i<5; i++)
        empilhar(&p2, i);

    mostrar(&p1);
    mostrar(&p2);

    cout << "Número de elementos pares na pilha p1 é: " << contPar(&p1) << endl;
    cout << "Número de elementos pares na pilha p2 é: " << contPar(&p2) << endl;
    if(iguais(&p1, &p2))
        cout << "As pilhas p1 e p2 são iguais! " << endl;
    else
        cout << "As pilhas p1 e p2 não são iguais! " << endl;


    cout << "\n\n###Teste3\n";
    desalocar(&p1);
    desalocar(&p2);
    inicializa(&p1);
    inicializa(&p2);

    for(int i=1; i<5; i++)
    {
        empilhar(&p1, rand()%30);
        empilhar(&p2, rand()%30);
    }

    mostrar(&p1);
    mostrar(&p2);

    cout << "Número de elementos pares na pilha p1 é: " << contPar(&p1) << endl;
    cout << "Número de elementos pares na pilha p2 é: " << contPar(&p2) << endl;
    if(iguais(&p1, &p2))
        cout << "As pilhas p1 e p2 são iguais! " << endl;
    else
        cout << "As pilhas p1 e p2 não são iguais! " << endl;



    //desalocar memória
    desalocar(&p1);
    desalocar(&p2);

    return EXIT_SUCCESS;

}//final do main


