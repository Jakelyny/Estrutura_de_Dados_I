#include <iostream>
using namespace std;

#include "pilhadupla.hpp"


int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Pilha p1;
    int opcaoMenu, valor, tamPilha, indicePilha;

    do{
        system("cls");
        cout << "--------------MENU--------------" << endl;
        cout << "1: Criar\n";
        cout << "2: Inserir\n";
        cout << "3: Remover\n";
        cout << "4: Mostrar\n";
        cout << "0: Sair\n";
		cout << "Escolha a opção: ";
		cin >> opcaoMenu;

		if(opcaoMenu>1 && opcaoMenu<=4 && !inicializada(&p1) )
            cout << "Erro: crie a pilha primeiro!\n";
        else if(opcaoMenu==1)
        {
            cout << "Informe o tamanho da pilha (máximo 10): ";
		    cin >> tamPilha;
            if(tamPilha<=0 || tamPilha>10)
                cout << "Informe um tamanho válido para a pilha ( 0< tam <11)!\n";
            else
            {
                if(inicializada(&p1))
                    desalocar(&p1);

                inicializa(&p1, tamPilha);
                cout << "As pilhas foram criadas !\n";
            }

        }
        else if(opcaoMenu==2)
        {

            cout << "Informe qual pilha deseja inserir (1-Pilha 1, 2-Pilha 2): ";
            cin >> indicePilha;

            indicePilha--; //PILHA_1=0, PILHA_2=1

            cout << "Informe o valor: ";
		    cin >> valor;
			if(indicePilha!=PILHA_1 && indicePilha!=PILHA_2)
                cout << "Erro: o índice da pilha é inválido! Informe 1-Pilha 1, 2-Pilha 2.\n";
			else if(!cheia(&p1))
                empilhar(&p1, indicePilha, valor);
            else
                cout << "O valor " << valor << " não foi inserido. A pilha está cheia!\n";
        }
        else if(opcaoMenu==3)
        {
            cout << "Informe qual pilha deseja inserir (1-Pilha 1, 2-Pilha 2): ";
            cin >> indicePilha;

            indicePilha--; //PILHA_1=0, PILHA_2=1

            if(indicePilha!=PILHA_1 && indicePilha!=PILHA_2)
                cout << "Erro: o índice da pilha é inválido! Informe 1-Pilha 1, 2-Pilha 2.\n";
            else if(desempilhar(&p1, indicePilha, &valor))
                cout << "O valor " << valor << " foi desempilhado.\n";
            else
                cout << "A pilha está vazia!\n";
        }
        else if(opcaoMenu==4)
        {
            mostrar(&p1, PILHA_1);
            mostrar(&p1, PILHA_2);
        }

        else if(opcaoMenu>4)
            cout << "Opção inválida!\n\n";

        if(opcaoMenu>0)
			system("pause");

	}while(opcaoMenu !=0);


     desalocar(&p1);

    return EXIT_SUCCESS;

}//final do main

