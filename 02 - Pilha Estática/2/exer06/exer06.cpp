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
    char valor;

    cout << "Digite uma string: ";
    cin >> str;

    inicializa(&p1, str.size());

    for(int i=0; i<str.size(); i++)
        empilhar(&p1, str.at(i) );


    bool palindromo = true;
    for(int i=0; i<str.size(); i++){

        if(!desempilhar(&p1, &valor ) )
            palindromo = false;
        else if(valor != str.at(i))
            palindromo = false;
    }

    if(palindromo)
        cout << "A string " << str << " é um palindromo!\n";
    else
        cout << "A string " << str << " NÃO é um palindromo!\n";


    desalocar(&p1);

    return EXIT_SUCCESS;

}//final do main


