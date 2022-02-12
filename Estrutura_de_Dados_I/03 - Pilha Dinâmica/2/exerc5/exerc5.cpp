#include <iostream>
using namespace std;

#include "pilha-dinamica.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Pilha p1;
    int opcaoMenu, tamPilha, cod;
    float peso;
    Caixa cx;

    inicializa(&p1);

    do{
        system("cls");
        cout << "--------------MENU--------------" << endl;
        cout << "1: Carregar caixa\n";
        cout << "2: Descarregar caixa\n";
        cout << "3: Mostrar carga\n";
        cout << "4: Mostrar peso total\n";
        cout << "5: Mostrar quantidade de caixas\n";
        cout << "0: Sair\n";
		cout << "Escolha a opção: ";
		cin >> opcaoMenu;

		if(opcaoMenu==1)
        {

            cout << "Informe o código da caixa: ";
		    cin >> cx.codigo;

		    cout << "Informe o peso da caixa: ";
		    cin >> cx.peso;

            empilhar(&p1, cx);

        }
        else if(opcaoMenu==2)
        {
            if(desempilhar(&p1, &cx))
                cout << "A caixa de código " << cx.codigo << " e peso " << cx.peso << " foi descarregada.\n";
            else
                cout << "O caminhão está vazio!\n";
        }
        else if(opcaoMenu==3)
            mostrar(&p1);
        else if(opcaoMenu==4)
            cout << "Peso total: " << somaPeso(&p1) << endl;
        else if(opcaoMenu==5)
            cout << "Quantidade de caixas: " << total(&p1) << endl;
        else if(opcaoMenu>4)
            cout << "Opção inválida!\n\n";

        if(opcaoMenu>0)
			system("pause");

	}while(opcaoMenu !=0);


    desalocar(&p1);

    return EXIT_SUCCESS;

}//final do main


