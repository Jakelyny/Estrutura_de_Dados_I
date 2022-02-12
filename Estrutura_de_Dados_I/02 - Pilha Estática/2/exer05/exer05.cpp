#include <iostream>
#include <string>
#include <cctype>
using namespace std;

#include "pilha.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");


    Pilha p1, p2;
    string str;

    cout << "Digite uma string: ";
    cin >> str;

    inicializa(&p1, str.size());
    inicializa(&p2, str.size());


    for(int i=0; i<str.size(); i++)
    {
        char c = str.at(i);

        if( isalpha(c) )
            empilhar(&p1, c);
        else if( isdigit(c) )
            empilhar(&p2, c);
    }

    cout << "\nLetras: ";
    desempilharMostrar(&p1);


    cout << "\nNúmeros: ";
    desempilharMostrar(&p2);


    desalocar(&p1);
    desalocar(&p2);

    return EXIT_SUCCESS;

}//final do main


