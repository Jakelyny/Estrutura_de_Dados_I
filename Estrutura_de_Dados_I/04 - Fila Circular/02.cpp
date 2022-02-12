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
        cout<<" | 1 - Nº de aviões à espera de decolar             |"<<endl;
        cout<<" | 2 - Incluir avião para fila de decolagem         |"<<endl;
        cout<<" | 3 - Retirada avião da fila de decolagem          |"<<endl;
        cout<<" | 4 - Listar aviões espera decolagem               |"<<endl;
        cout<<" | 5 - Listar informações do prox. avião a decolar  |"<<endl;
        cout<<" | 6 - Sair                                         |"<<endl;
        cout<<" ****************************************************"<<endl;
        cout<<"\nDigite a opção desejada: ";
        cin>>menu;
        fflush(stdin);
        switch(menu){
            case 1:
                system("cls");
                cout<<"\n\n\tEXISTEM "<<indice<<" AVIÕES EM ESPERA PARA DECOLAGEM!";
                getchar();
                break;
            case 2:
                system("cls");
                cout<<"\nINFORME O CODIGO DO AVIÃO: ";
                cin>>a.codigo;
                cout<<"\nINFORME QUANTIDADE DE PASSAGEIROS: ";
                cin>>a.numPassageiro;
                cout<<"\nINFORME A EMPRESA: ";
                cin>>a.empresa;
                if(enfileiraF(&f, a)){
                    system("cls");
                    cout<<"\n\n\tAVIÃO INCLUÍDO!";
                    getchar();
                }else{
                    system("cls");
                    cout<<"\n\n\tNÃO FOI POSSÍVEL INCLUIR O AVIÃO..";
                    getchar();
                }
                indice++;
                getchar();
                break;
            case 3:
                system("cls");
                if(enfileiraF(&f, a)){
                    system("cls");
                    cout<<"\n\n\tO AVIÃO "<<a.codigo<<" JÁ DECOLOU, RETIRADO DA LISTA DE DECOLAGEM!";
                    getchar();
                }else{
                    system("cls");
                    cout<<"\n\n\tNÃO FOI POSSÍVEL RETIRAR O AVIÃO..";
                    getchar();
                }
                getchar();
                break;
            case 4:
                system("cls");
                cout<<"AVIÕES A ESPERA DA DECOLAGEM:\n"<<endl;
                mostraF(&f);
                getchar();
                break;
            case 5:
                system("cls");
                if(enfileiraF(&f, a)){
                    cout<<"INFORMAÇÕES DO PRÓXIMO AVIÃO A DECOLAR:\n"<<endl;
                    cout<<"CÓDIGO: "<<a.codigo<<endl;
                    cout<<"Nº PASSAGEIROS: "<<a.numPassageiro<<endl;
                    cout<<"EMPRESA: "<<a.empresa<<endl;
                    getchar();
                }else{
                    cout<<"\n\n\tNÃO FOI POSSÍVEL VERIFICAR AS INFORMAÇÕES..";
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


