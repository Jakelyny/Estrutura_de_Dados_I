#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include <algorithm>
using namespace std;

#include "03.hpp"

int main(){

    setlocale(LC_ALL, "Portuguese");
    Pilha p1;
    int menu = -1, indice = -1, tamPilha, valor, indicePilha;
    bool resultado;

    do{
        system("cls");
        cout<<" ************ MENU *****************"<<endl;
        cout<<" |                                 |"<<endl;
        cout<<" | 1 - Criar pilha                 |"<<endl;
        cout<<" | 2 - Inserir                     |"<<endl;
        cout<<" | 3 - Remover                     |"<<endl;
        cout<<" | 4 - Mostrar                     |"<<endl;
        cout<<" | 5 - Sair                        |"<<endl;
        cout<<" **********************************"<<endl;
        cout<<"\nDigite a op��o desejada: ";
        cin>>menu;
        fflush(stdin);
        switch(menu){
            case 1:
                system("cls");
                if(indice < 0){
                    cout<<"\nINFORME O TAMANHO DA PILHA (max 10): ";
                    cin>>tamPilha;
                    if(tamPilha < 10){
                        inicializa(&p1, tamPilha);
                    }
                }else{
                    desalocar(&p1);
                    cout<<"\nINFORME O TAMANHO DA PILHA (max 10): ";
                    cin>>tamPilha;
                    if(tamPilha < 10){
                        inicializa(&p1, tamPilha);
                    }
                }
                indice++;
                getchar();
                break;
            case 2:
                system("cls");
                if(indice < 0){
                    cout<<"\n\n\t� NECESS�RIO CRIAR A PILHA!.."<<endl;
                }else{
                    cout<<"QUAL PILHA SER� EMPILHADA? \n 1 - Pilha 1\n 2 - Pilha 2\n Escolha: ";
                    cin>>indicePilha;
                    indicePilha--;
                    cout<<"\n\nDIGITE O VALOR A SER EMPILHADO: ";
                    cin>>valor;
                    if(indicePilha != PILHA_1 && indicePilha != PILHA_2){
                        system("cls");
                        cout<<"\n\n\tVALOR INV�LIDO!";
                    }else if(!cheia(&p1)){
                        empilhar(&p1, indicePilha, valor);
                    }else{
                        system("cls");
                        cout<<"\n\n\tO "<<valor<<" N�O FOI INSERIDO, PILHA CHEIA!";
                    }
                }
                getchar();
                break;
            case 3:
                system("cls");
                if(indice < 0){
                    cout<<"\n\n\t� NECESS�RIO CRIAR A PILHA!.."<<endl;
                }else{
                    cout<<"QUAL PILHA SER� DESEMPILHADA? \n 1 - Pilha 1\n 2 - Pilha 2\n Escolha: ";
                    cin>>indicePilha;
                    indicePilha--;
                    cout<<"\n\nDIGITE O VALOR A SER DESEMPILHADO: ";
                    cin>>valor;
                    if(indicePilha != PILHA_1 && indicePilha != PILHA_2){
                        system("cls");
                        cout<<"\n\n\tVALOR INV�LIDO!";
                        getchar();
                    }else if(desempilhar(&p1, indicePilha, &valor)){
                        system("cls");
                        cout<<"\n\n\tO "<<valor<<" FOI DESEMPILHADO!";
                    }else{
                        system("cls");
                        cout<<"\n\n\tA PILHA EST� VAZIA!";
                    }
                }
                getchar();
                break;
            case 4:
                system("cls");
                if(indice < 0){
                    cout<<"\n\n\t� NECESS�RIO CRIAR A PILHA!.."<<endl;
                }else{
                    mostrar(&p1, PILHA_1);
                    mostrar(&p1, PILHA_2);
                }
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

