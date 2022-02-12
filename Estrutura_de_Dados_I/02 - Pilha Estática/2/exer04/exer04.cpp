#include <iostream>
#include <ctime>
using namespace std;

#include "pilha.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    Pilha p1, pPar, pImpar;
    int opcaoMenu,tamPilha, valor;

    do{
        system("cls");
        cout << "--------------MENU--------------" << endl;
        cout << "1: Criar / Zerar\n";
        cout << "2: Remover\n";
        cout << "3: Mostrar\n";
        cout << "0: Sair\n";
		cout << "Escolha a opção: ";
		cin >> opcaoMenu;

		if(opcaoMenu>1 && opcaoMenu<=3 && !inicializada(&p1) )
            cout << "Erro: crie a pilha primeiro!\n";
        else if(opcaoMenu==1)
        {
            cout << "Informe o tamanho da pilha (máximo 6): ";
            cin >> tamPilha;

            if(tamPilha<=0 || tamPilha>6)
                cout << "Informe um tamanho válido para a pilha ( 0< tam <7)!\n";
            else
            {
                //pilha principal
                if(inicializada(&p1))
                    desalocar(&p1);

                inicializa(&p1, tamPilha, "P1");

                //par
                if(inicializada(&pPar))
                    desalocar(&pPar);

                inicializa(&pPar, tamPilha, "PAR");

                //impar
                if(inicializada(&pImpar))
                    desalocar(&pImpar);

                inicializa(&pImpar, tamPilha, "IMPAR");

                //empilha valores aleatorios para a pilha principal
                for (int i=0; i<tamPilha; i++)
                    empilhar(&p1, rand()%100);
            }

        }
        else if(opcaoMenu==2)
        {
            if(desempilhar(&p1, &valor))
            {
                cout << "O valor " << valor << " foi desempilhado.\n";

                if(valor%2==0)
                    empilhar(&pPar, valor);
                else
                    empilhar(&pImpar, valor);
            }
            else
                cout << "A pilha está vazia!\n";
        }
        else if(opcaoMenu==3)
        {
            mostrar(&p1);
            mostrar(&pPar);
            mostrar(&pImpar);
        }
        else if(opcaoMenu>3)
            cout << "Opção inválida!\n\n";

        if(opcaoMenu>0)
			system("pause");

	}while(opcaoMenu !=0);


    desalocar(&p1);
    desalocar(&pPar);
    desalocar(&pImpar);

    return EXIT_SUCCESS;

}//final do main


