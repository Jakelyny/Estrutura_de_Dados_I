#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include <algorithm>
using namespace std;

#include "02.hpp"

int main(){

    setlocale(LC_ALL, "Portuguese");
    Fila f;
    int menu = -1, tamFila = 10, indice = 0;
    inicializaF(&f, tamFila);
    Aviao a;

    do{
        system("cls");
        cout<<" ********************** MENU ************************"<<endl;
        cout<<" | 1 - N� de avi�es � espera de decolar             |"<<endl;
        cout<<" | 2 - Incluir avi�o para fila de decolagem         |"<<endl;
        cout<<" | 3 - Retirada avi�o da fila de decolagem          |"<<endl;
        cout<<" | 4 - Listar avi�es espera decolagem               |"<<endl;
        cout<<" | 5 - Listar informa��es do prox. avi�o a decolar  |"<<endl;
        cout<<" | 6 - Sair                                         |"<<endl;
        cout<<" ****************************************************"<<endl;
        cout<<"\nDigite a op��o desejada: ";
        cin>>menu;
        fflush(stdin);
        switch(menu){
            case 1:
                system("cls");
                cout<<"\n\n\tEXISTEM "<<indice<<" AVI�ES EM ESPERA PARA DECOLAGEM!";
                getchar();
                break;
            case 2:
                system("cls");
                cout<<"\nINFORME O CODIGO DO AVI�O: ";
                cin>>a.codigo;
                cout<<"\nINFORME QUANTIDADE DE PASSAGEIROS: ";
                cin>>a.numPassageiro;
                cout<<"\nINFORME A EMPRESA: ";
                cin>>a.empresa;
                if(enfileiraF(&f, a)){
                    system("cls");
                    cout<<"\n\n\tAVI�O INCLU�DO!";
                    getchar();
                }else{
                    system("cls");
                    cout<<"\n\n\tN�O FOI POSS�VEL INCLUIR O AVI�O..";
                    getchar();
                }
                indice++;
                getchar();
                break;
            case 3:
                system("cls");
                if(enfileiraF(&f, a)){
                    system("cls");
                    cout<<"\n\n\tO AVI�O "<<a.codigo<<" J� DECOLOU, RETIRADO DA LISTA DE DECOLAGEM!";
                    getchar();
                }else{
                    system("cls");
                    cout<<"\n\n\tN�O FOI POSS�VEL RETIRAR O AVI�O..";
                    getchar();
                }
                getchar();
                break;
            case 4:
                system("cls");
                cout<<"AVI�ES A ESPERA DA DECOLAGEM:\n"<<endl;
                mostraF(&f);
                getchar();
                break;
            case 5:
                system("cls");
                if(enfileiraF(&f, a)){
                    cout<<"INFORMA��ES DO PR�XIMO AVI�O A DECOLAR:\n"<<endl;
                    cout<<"C�DIGO: "<<a.codigo<<endl;
                    cout<<"N� PASSAGEIROS: "<<a.numPassageiro<<endl;
                    cout<<"EMPRESA: "<<a.empresa<<endl;
                    getchar();
                }else{
                    cout<<"\n\n\tN�O FOI POSS�VEL VERIFICAR AS INFORMA��ES..";
                    getchar();
                }
                getchar();
                break;
            case 6:
                system("cls");
                cout<<"\n\n\t ENCERRANDO PROGRAMA..."<<endl;
                getchar();
                break;
        }
    }while(menu != 6);
    return 0;
}


