#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include <algorithm>
using namespace std;

#include "02_pilha.hpp"
#include "02_fila.hpp"

int main(){

    setlocale(LC_ALL, "Portuguese");
    Pilha p1;
    Fila f1;
    inicializa(&p1);
    inicializaF(&f1);
    int menu = -1, indice = -1, valor;

    do{
        system("cls");
        cout<<" ************ MENU ***************"<<endl;
        cout<<" | 1 - Incluir na fila           |"<<endl;
        cout<<" | 2 - Remover da fila           |"<<endl;
        cout<<" | 3 - Mostrar fila              |"<<endl;
        cout<<" | 4 - Inverter fila             |"<<endl;
        cout<<" | 5 - Sair                      |"<<endl;
        cout<<" *********************************"<<endl;
        cout<<"\nDigite a opção desejada: ";
        cin>>menu;
        fflush(stdin);
        switch(menu){
            case 1:
                system("cls");
                inicializa(&p1);
                cout<<"VALOR A SER EMPILHADO: ";
                cin>>valor;
                enfileiraF(&f1, valor);
                indice++;
                getchar();
                break;
            case 2:
                system("cls");
                if(indice < 0){
                    cout<<"\n\n\tÉ NECESSÁRIO CRIAR A PILHA!.."<<endl;
                }else{
                    if(desenfileiraF(&f1, &valor)){
                    cout<<"\n\n\tO VALOR "<<valor<<" FOI DESENFILEIRADO!"<<endl;
                    }else{
                        cout<<"\n\n\tA PILHA ESTÁ VAZIA!"<<endl;
                    }
                }
                getchar();
                break;
            case 3:
                system("cls");
                if(indice < 0){
                    cout<<"\n\n\tÉ NECESSÁRIO CRIAR A PILHA!.."<<endl;
                }else{
                    mostraF(&f1);
                }
                getchar();
                break;
            case 4:
                system("cls");
                if(indice < 0){
                    cout<<"\n\n\tÉ NECESSÁRIO CRIAR A PILHA!.."<<endl;
                }else{
                    while(!vaziaF(&f1)){
                    if(desenfileiraF(&f1, &valor)){
                        empilhar(&p1, valor);
                        }
                    }
                    while(!vazia(&p1)){
                        if(desempilhar(&p1, &valor)){
                            enfileiraF(&f1, valor);
                        }
                    }
                }
                cout<<"\n\n\tOS VALORES FORAM INVERTIDOS!";
                getchar();
                break;
            case 5:
                system("cls");
                cout<<"\n\n\t ENCERRANDO PROGRAMA..."<<endl;
                getchar();
                desalocar(&p1);
                break;
        }
    }while(menu != 5);
    return 0;
}



