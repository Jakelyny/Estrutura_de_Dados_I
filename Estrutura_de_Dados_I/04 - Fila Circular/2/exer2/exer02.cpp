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
        cout << "1: Definir Nº de aviões à espera de decolar\n";
        cout << "2: Entrada de um novo avião para decolar\n";
        cout << "3: Descolagem de um avião\n";
        cout << "4: Listar todos os aviões à espera para decolagem\n";
        cout << "5: Listar as características do próximo avião a decolar\n";
        cout << "0: Sair\n";
		cout << "Escolha a opção: ";
		cin >> opcaoMenu;

		if(opcaoMenu>1 && opcaoMenu<=5 && !inicializadaF(&f1) )
            cout << "Erro: Defina o Nº de aviões primeiro!\n";
        else if(opcaoMenu==1)
        {

            cout << "Informe o Nº de aviões à espera de decolar: ";
		    cin >> tamFila;
            if(tamFila<=0)
                cout << "Informe um número inteiro positivo!\n";
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
                cout << "Informe o código do avião: ";
                cin >> aviao.codigo;

                cout << "Informe o número de passageiros: ";
                cin >> aviao.nPassageiros;

                cout << "Informe o nome da empresa: ";
                cin >> aviao.empresa;

                enfileiraF(&f1, aviao);
            }
            else
                cout << "A fila de espera está cheia, aguarde a próxima decolagem para poder entrar da fila de espera.\n";
        }
        else if(opcaoMenu==3)
        {
           if(desenfileiraF(&f1, &aviao))
                cout << "O avião de código " << aviao.codigo << " da empresa " << aviao.empresa << " com " << aviao.nPassageiros <<  " passageiros decolou.\n";
            else
                cout << "A fila de espera está vazia! Não há aviões esperando para decolar!\n";
        }
        else if(opcaoMenu==4)
        {
            if(!vaziaF(&f1))
            {
                cout << "Aviões à espera para decolagem: ";
                mostraFila(&f1);
            }
            else
                cout << "Não há aviões esperando para decolar!\n";
        }
        else if(opcaoMenu==5)
        {
            if(espiarF(&f1, &aviao))
            {
                cout << "Próximo avião a decolar é: ";
                cout << "{" << aviao.codigo;
                cout << ", " << aviao.nPassageiros;
                cout << ", " << aviao.empresa <<  "}\n";
            }
            else
                cout << "Não há aviões esperando para decolar!\n";
        }
        else if(opcaoMenu>4)
            cout << "Opção inválida!\n\n";

        if(opcaoMenu>0)
			system("pause");

	}while(opcaoMenu !=0);

    destroiF(&f1);
    return EXIT_SUCCESS;

}//final do main

