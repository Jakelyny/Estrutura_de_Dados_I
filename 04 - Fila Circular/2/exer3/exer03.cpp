#include <iostream>
#include <string>
using namespace std;

#include "pilha.hpp"
#include "filacircular.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Fila f1;
    Pilha p1;
    string str;
    int tam;
    char c1, c2;


    cout << "Informe uma string: ";
    cin >> str;

    tam = str.size();


    inicializaF(&f1, tam);
    inicializaP(&p1, tam);

    for(int i=0; i<str.size(); i++)
    {
        empilhaP(&p1, str.at(i) );
        enfileiraF(&f1, str.at(i) );
    }

    mostraP(&p1);
    mostraF(&f1);

    bool palindromo = true;
    for(int i=0; i<tam; i++)
    {
        desempilhaP(&p1, &c1);
        desenfileiraF(&f1, &c2);

        if(c1 != c2)
        {
            palindromo = false;
            break;
        }
    }

    if(palindromo)
        cout << "A string " << str << " é um palindromo!\n";
    else
        cout << "A string " << str << " NÃO é um palindromo!\n";

    destroiF(&f1);
    destroiP(&p1);
    return EXIT_SUCCESS;

}//final do main

