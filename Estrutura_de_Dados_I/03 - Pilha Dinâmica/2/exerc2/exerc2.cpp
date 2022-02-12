#include <iostream>
#include <string>
using namespace std;

#include "pilha-dinamica.hpp"

bool ehNumero(string s)
{
    for (size_t i = 0; i < s.size(); i++)
        if (s.at(i)!='-' && !isdigit(s.at(i)))
            return false;

    return true;
}

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Pilha ORD, AUX;
    string str;
    bool sair =false;
    int nlido, nEspiado, nAux;

    inicializa(&ORD);
    inicializa(&AUX);


    do{
        cout << "\nInforme um número (para sair digite uma letra): ";
        cin >> str;

        if(ehNumero(str))
        {
            nlido = stoi( str );

            while(espiar(&ORD, &nEspiado) && nlido < nEspiado)
            {
                desempilhar(&ORD, &nAux);
                empilhar(&AUX, nAux);
            }

            empilhar(&ORD, nlido);

            while(!vazia(&AUX))
            {
                desempilhar(&AUX, &nAux);
                empilhar(&ORD, nAux);
            }

            mostrar(&ORD);

        }
        else
            sair = true;

    }while(!sair);



    //desalocar memória
    desalocar(&ORD);
    desalocar(&AUX);

    return EXIT_SUCCESS;

}//final do main

