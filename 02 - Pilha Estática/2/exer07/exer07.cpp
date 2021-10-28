#include <iostream>
#include <string>
#include <cctype>
using namespace std;

#include "pilha.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");


    Pilha p1;
    string str;
    char c, aux;
    bool correto= true;


    cout << "Digite uma expressão matemática: ";
    cin >> str;

    inicializa(&p1, str.size());

    for(int i=0; i<str.size(); i++)
    {
        c = str.at(i);
        if( c == '(' )
            empilhar(&p1, c);
        else if ( c == ')' )
        {
            if(vazia(&p1))
            {
                correto = false;
                break;
            }
            else
                desempilhar(&p1, &aux);
        }

    }

    if(!correto || !vazia(&p1))
        cout << "Os parênteses NÃO foram agrupados corretamente!" << endl;
    else
        cout << "Os parênteses foram agrupados corretamente!" << endl;


    desalocar(&p1);

    return EXIT_SUCCESS;

}//final do main


