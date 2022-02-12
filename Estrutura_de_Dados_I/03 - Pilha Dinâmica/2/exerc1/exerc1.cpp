#include <iostream>
#include <string>
using namespace std;

#include "pilha-dinamica.hpp"


int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Pilha p1;
    string str;
    char c, aux;

    inicializa(&p1);


    cout << "Digite uma frase: ";
    getline(cin, str);

    for(size_t i=0; i<str.size(); i++)
    {
        c = str.at(i);

        if(c != ' ')
            empilhar(&p1, c);

        if(c == ' ' || i==str.size()-1 )
        {
            while(!vazia(&p1))
            {
                desempilhar(&p1, &aux);
                cout << aux;
            }
            cout << " ";
        }
    }
    cout << endl;

    //desalocar memória
    desalocar(&p1);

    return EXIT_SUCCESS;

}//final do main

