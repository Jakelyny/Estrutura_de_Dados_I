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
    bool balanceada= true;

    //[{()()}{}]
    //{[([{}])]}
    //{[(}])
    //{[)()(]}
    cout << "Digite uma express�o matem�tica: ";
    cin >> str;

    inicializa(&p1);


    for(int i=0; i<str.size(); i++)
    {
        c = str.at(i);
        if( c == '(' || c == '['  || c == '{' )
            empilhar(&p1, c);
        else if( c == ')' || c == ']'  || c == '}' )
        {
            if(vazia(&p1))
                balanceada = false;
            else
            {
                desempilhar(&p1, &aux);
                if(c == ')' && aux != '(' )
                    balanceada = false;
                else if(c == ']' && aux != '[' )
                    balanceada = false;
                else if(c == '}' && aux != '{' )
                    balanceada = false;
            }

            if(!balanceada)
                break;

        }

    }


    if(!balanceada || !vazia(&p1))
        cout << "A express�o " << str << " n�o � balanceada!\n";
    else
        cout << "A express�o " << str << " � balanceada!\n";


    //desalocar mem�ria
    desalocar(&p1);

    return EXIT_SUCCESS;

}//final do main

