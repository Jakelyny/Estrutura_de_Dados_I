#include <iostream>
using namespace std;

#include "fila-dinamica.hpp"
#include "pilha-dinamica.hpp"



void inverteF(Fila *f)
{
    Pilha p;
    int valor;

    while(!vaziaF(f))
    {
        desenfileiraF(f, &valor);
        empilhaP(&p, valor);
    }

    while(!vaziaP(&p))
    {
        desempilhaP(&p, &valor);
        enfileiraF(f, valor);
    }
}

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Pilha p1;
    Fila f1;
    int n, opcaoMenu;


    do
    {
        system("cls");
        cout << "--------------MENU--------------" << endl;
        cout << "1: Incluir na fila\n";
        cout << "2: Remover da fila\n";
        cout << "3: Mostrar fila\n";
        cout << "4: Inverter fila\n";
        cout << "0: Sair\n";
        cout << "Escolha a opção: ";
        cin >> opcaoMenu;

        if(opcaoMenu==1)
        {

            cout << "Informe um número inteiro: ";
            cin >> n;

            enfileiraF(&f1, n);

        }
        else if(opcaoMenu==2)
        {
            if(desenfileiraF(&f1, &n))
                cout << "O elemento " << n << " foi retirado da fila.\n";
            else
                cout << "O caminhão está vazio!\n";
        }
        else if(opcaoMenu==3)
            mostraF(&f1);
        else if(opcaoMenu==4)
            inverteF(&f1);
        else if(opcaoMenu>4)
            cout << "Opção inválida!\n\n";

        if(opcaoMenu>0)
            system("pause");

    }
    while(opcaoMenu !=0);

    destroiF(&f1);
    destroiP(&p1);

    return EXIT_SUCCESS;

}//final do main


