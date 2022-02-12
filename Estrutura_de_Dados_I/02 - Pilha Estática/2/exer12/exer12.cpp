#include <iostream>
using namespace std;

#include "pilha.hpp"


int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Pilha p1;
    int opcaoMenu, tamPilha, cod;
    float peso;
    Caixa cx;

    do{
        system("cls");
        cout << "--------------MENU--------------" << endl;
        cout << "1: Definir quantidade de caixa\n";
        cout << "2: Carregar caixa\n";
        cout << "3: Descarregar caixa\n";
        cout << "4: Consultar caixa\n";
        cout << "5: Mostrar carga\n";
        cout << "0: Sair\n";
		cout << "Escolha a op��o: ";
		cin >> opcaoMenu;

		if(opcaoMenu>1 && opcaoMenu<=5 && !inicializada(&p1) )
            cout << "Erro: informe o n�mero de caixas primeiro!\n";
        else if(opcaoMenu==1)
        {

            cout << "Informe a quantidade de caixas: ";
		    cin >> tamPilha;
            if(tamPilha<=0)
                cout << "Informe um valor v�lido (quantidade > 0)!\n";
            else{
                if(inicializada(&p1))
                    desalocar(&p1);

                inicializa(&p1, tamPilha);
            }


        }
        else if(opcaoMenu==2)
        {
            cout << "Informe o c�digo da caixa: ";
		    cin >> cod;

		    cout << "Informe o peso da caixa: ";
		    cin >> peso;

			if(!cheia(&p1))
                empilhar(&p1, cod, peso);
            else
                cout << "A caixa de c�digo " << cod << " n�o foi carregada. O caminh�o est� cheio!\n";
        }
        else if(opcaoMenu==3)
        {
           if(desempilhar(&p1, &cx))
                cout << "A caixa de c�digo " << cx.codigo << " e peso " << cx.peso << " foi descarregada.\n";
            else
                cout << "O caminh�o est� vazio!\n";
        }
        else if(opcaoMenu==4)
        {
            cout << "Informe o c�digo da caixa: ";
            cin >> cod;
			if(buscar(&p1, cod))
                cout << "A caixa de c�digo " << cod << " foi encontrada!\n";
            else
                cout << "A caixa de c�digo " << cod << " N�O foi encontrada!\n";
        }
        else if(opcaoMenu==5)
            mostrar(&p1);
        else if(opcaoMenu>4)
            cout << "Op��o inv�lida!\n\n";

        if(opcaoMenu>0)
			system("pause");

	}while(opcaoMenu !=0);


    desalocar(&p1);

    return EXIT_SUCCESS;

}//final do main

