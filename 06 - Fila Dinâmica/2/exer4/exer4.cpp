#include <iostream>
using namespace std;

#include "fila-dinamica.hpp"

void separaF (int n, Fila *f1, Fila *f2)
{

    int valor;
    bool addF2 = false;
    Fila fAux;

    destroiF(f2);

    while (!vaziaF(f1))
    {
        desenfileiraF(f1, &valor);

        if(addF2)
            enfileiraF(f2, valor);
        else
            enfileiraF(&fAux, valor);

        if(n == valor)
            addF2 = true;
    }

    while (!vaziaF(&fAux))
    {
        desenfileiraF(&fAux, &valor);
        enfileiraF(f1, valor);
    }

}



int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    Fila f1, f2;

    int n, tam;



    cout << "Informe o tamanho de F1: ";
    cin >> tam;



    for (int i=0; i<tam; i++)
        enfileiraF(&f1, rand()%10);

    mostraF(&f1, "F1");
    mostraF(&f2, "F2");

    cout << "\nInforme um valor inteiro positivo: ";
    cin >> n;

    separaF (n, &f1, &f2);

    cout << "\n\nN: " << n << endl;
    cout << "Separar...\n";
    mostraF(&f1, "F1");
    mostraF(&f2, "F2");



    destroiF(&f1);
    destroiF(&f2);

    return EXIT_SUCCESS;

}//final do main


