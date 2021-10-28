#include <iostream>
using namespace std;

#include "fila-dinamica.hpp"



void concatenaF (Fila  *f1, Fila  *f2, Fila *f3)
{
    NoFila *no = f1->inicio;
    while (no) //faça enquanto (no != NULL)
    {
        enfileiraF(f3, no->dado);
        no = no->prox;
    }

    no = f2->inicio;
    while (no) //faça enquanto (no != NULL)
    {
        enfileiraF(f3, no->dado);
        no = no->prox;
    }

}

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    Fila f1, f2, f3;

    for (int i=0; i<3; i++)
        enfileiraF(&f1, rand()%20);

    for (int i=0; i<5; i++)
        enfileiraF(&f2, rand()%20);

    concatenaF(&f1, &f2, &f3);

    mostraF(&f1, "F1");
    mostraF(&f2, "F2");
    mostraF(&f3, "F3");

    destroiF(&f1);
    destroiF(&f2);
    destroiF(&f3);


    return EXIT_SUCCESS;

}//final do main


