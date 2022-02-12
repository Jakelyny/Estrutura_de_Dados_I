#include <iostream>
using namespace std;

#include "pilha.hpp"


int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Pilha p1;
    int opcaoMenu, tamPilha;
    string valor;

    do{
        system("cls");
        cout << "--------------MENU--------------" << endl;
        cout << "1: Criar\n";
        cout << "2: Inserir\n";
        cout << "3: Remover\n";
        cout << "4: Consultar\n";
        cout << "5: Mostrar\n";
        cout << "0: Sair\n";
		cout << "Escolha a opção: ";
		cin >> opcaoMenu;

		if(opcaoMenu>1 && opcaoMenu<=5 && !inicializada(&p1) )
            cout << "Erro: crie a pilha primeiro!\n";
        else if(opcaoMenu==1)
        {

            cout << "Informe o tamanho da pilha: ";
		    cin >> tamPilha;
            if(tamPilha<=0)
                cout << "Informe um tamanho válido para a pilha (tam > 0)!\n";
            else{
                if(inicializada(&p1))
                    desalocar(&p1);

                inicializa(&p1, tamPilha);
            }


        }
        else if(opcaoMenu==2)
        {
            cout << "Informe o valor: ";
		    cin >> valor;
			if(!cheia(&p1))
                if(!buscar(&p1, valor))
                    empilhar(&p1, valor);
                else
                    cout << "O valor " << valor << " não foi inserido. Valor duplicado!\n";
            else
                cout << "O valor " << valor << " não foi inserido. A pilha está cheia!\n";
        }
        else if(opcaoMenu==3)
        {
           if(desempilhar(&p1, &valor))
                cout << "O valor " << valor << " foi desempilhado.\n";
            else
                cout << "A pilha está vazia!\n";
        }
        else if(opcaoMenu==4)
        {
            cout << "Informe o valor: ";
            cin >> valor;
			if(buscar(&p1, valor))
                cout << "O valor " << valor << " foi encontrado na pilha!\n";
            else
                cout << "O valor " << valor << " NÃO foi encontrado na pilha!\n";
        }
        else if(opcaoMenu==5)
            mostrar(&p1);
        else if(opcaoMenu>4)
            cout << "Opção inválida!\n\n";

        if(opcaoMenu>0)
			system("pause");

	}while(opcaoMenu !=0);


    desalocar(&p1);

    return EXIT_SUCCESS;

}//final do main

