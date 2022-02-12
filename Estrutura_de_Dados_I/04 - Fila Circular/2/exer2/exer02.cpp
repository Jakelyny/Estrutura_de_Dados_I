#include <iostream>
using namespace std;

#include "filacircular.hpp"


int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Fila f1;
    int tamFila=0, opcaoMenu;
    Aviao aviao;
    bool resultado;


    do{
        system("cls");
        cout << "--------------MENU--------------" << endl;
        cout << "1: Definir N� de avi�es � espera de decolar\n";
        cout << "2: Entrada de um novo avi�o para decolar\n";
        cout << "3: Descolagem de um avi�o\n";
        cout << "4: Listar todos os avi�es � espera para decolagem\n";
        cout << "5: Listar as caracter�sticas do pr�ximo avi�o a decolar\n";
        cout << "0: Sair\n";
		cout << "Escolha a op��o: ";
		cin >> opcaoMenu;

		if(opcaoMenu>1 && opcaoMenu<=5 && !inicializadaF(&f1) )
            cout << "Erro: Defina o N� de avi�es primeiro!\n";
        else if(opcaoMenu==1)
        {

            cout << "Informe o N� de avi�es � espera de decolar: ";
		    cin >> tamFila;
            if(tamFila<=0)
                cout << "Informe um n�mero inteiro positivo!\n";
            else{

                if(inicializadaF(&f1))
                    destroiF(&f1);

                inicializaF(&f1, tamFila);
            }


        }
        else if(opcaoMenu==2)
        {

			if(!cheiaF(&f1))
            {
                cout << "Informe o c�digo do avi�o: ";
                cin >> aviao.codigo;

                cout << "Informe o n�mero de passageiros: ";
                cin >> aviao.nPassageiros;

                cout << "Informe o nome da empresa: ";
                cin >> aviao.empresa;

                enfileiraF(&f1, aviao);
            }
            else
                cout << "A fila de espera est� cheia, aguarde a pr�xima decolagem para poder entrar da fila de espera.\n";
        }
        else if(opcaoMenu==3)
        {
           if(desenfileiraF(&f1, &aviao))
                cout << "O avi�o de c�digo " << aviao.codigo << " da empresa " << aviao.empresa << " com " << aviao.nPassageiros <<  " passageiros decolou.\n";
            else
                cout << "A fila de espera est� vazia! N�o h� avi�es esperando para decolar!\n";
        }
        else if(opcaoMenu==4)
        {
            if(!vaziaF(&f1))
            {
                cout << "Avi�es � espera para decolagem: ";
                mostraFila(&f1);
            }
            else
                cout << "N�o h� avi�es esperando para decolar!\n";
        }
        else if(opcaoMenu==5)
        {
            if(espiarF(&f1, &aviao))
            {
                cout << "Pr�ximo avi�o a decolar �: ";
                cout << "{" << aviao.codigo;
                cout << ", " << aviao.nPassageiros;
                cout << ", " << aviao.empresa <<  "}\n";
            }
            else
                cout << "N�o h� avi�es esperando para decolar!\n";
        }
        else if(opcaoMenu>4)
            cout << "Op��o inv�lida!\n\n";

        if(opcaoMenu>0)
			system("pause");

	}while(opcaoMenu !=0);

    destroiF(&f1);
    return EXIT_SUCCESS;

}//final do main

