#include <iostream>
using namespace std;

#include "pilha.hpp"


int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Pilha p1;
    int tamPilha, valor, cod;


    cout << "Informe o número de cidades: ";
    cin >> tamPilha;



    inicializa(&p1, tamPilha);

    for(int i=0; i<tamPilha; i++)
    {
        cout << "Informe o código da cidade nº" << i << ": ";
        cin >> valor;
        empilhar(&p1, valor);

    }

    cout << "\n\nPILHA ANTES DA BUSCA\n";
    mostrar(&p1);

    cout << "\n\nInforme um código: ";
    cin >> cod;

    cout << "A cidade de código " << cod << " está na pilha? " << ( buscar(&p1, cod) ? "verdadeiro" : "falso") << endl;


    cout << "\n\nPILHA APÓS DA BUSCA\n";
    mostrar(&p1);

    return EXIT_SUCCESS;

}//final do main

