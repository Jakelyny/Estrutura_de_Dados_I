#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include <algorithm>
using namespace std;

#include "02.hpp"

int main(){

    setlocale(LC_ALL, "Portuguese");
    Pilha p1;
    int menu = -1, indice = -1, tamPilha, valor;
    bool resultado;

    do{
        system("cls");
        cout<<" ************ MENU *****************"<<endl;
        cout<<" |                                 |"<<endl;
        cout<<" | 1 - Criar pilha                 |"<<endl;
        cout<<" | 2 - Inserir                     |"<<endl;
        cout<<" | 3 - Remover                     |"<<endl;
        cout<<" | 4 - Consultar                   |"<<endl;
        cout<<" | 5 - Mostrar                     |"<<endl;
        cout<<" | 6 - Sair                        |"<<endl;
        cout<<" **********************************"<<endl;
        cout<<"\nDigite a opção desejada: ";
        cin>>menu;
        fflush(stdin);
        switch(menu)
        {
            case 1:
                system("cls");
                if(indice < 0){
                    cout<<"\nINFORME O TAMANHO DA PILHA: ";
                    cin>>tamPilha;
                    inicializa(&p1, tamPilha);
                }else{
                    desalocar(&p1);
                    cout<<"\nINFORME O TAMANHO DA PILHA: ";
                    cin>>tamPilha;
                    inicializa(&p1, tamPilha);
                }
                indice++;
                getchar();
                break;
            case 2:
                system("cls");
                if(indice < 0){
                    cout<<"\n\n\tÉ NECESSÁRIO CRIAR A PILHA!.."<<endl;
                }else{
                    if(cheia(&p1)){
                        cout << "\n\n\tA PILHA ESTÁ CHEIA!..\n";
                    }else{
                        cout<<"INSIRA O VALOR A SER EMPILHADO: ";
                        cin>>valor;
                        if(buscar(&p1, valor)){
                            cout<<"\n\n\tO VALOR "<<valor<<" JÁ EXISTE NA PILHA!\n";
                            getchar();
                        }else{
                            empilhar(&p1, valor);
                        }
                    }
                }
                getchar();
                break;
            case 3:
                system("cls");
                if(indice < 0){
                    cout<<"\n\n\tÉ NECESSÁRIO CRIAR A PILHA!.."<<endl;
                }else{
                    if(vazia(&p1)){
                        cout << "\n\n\tA PILHA ESTÁ VAZIA!\n";
                        getchar();
                    }else{
                        desempilhar(&p1, &valor);
                        cout<<"\n\n\tO VALOR "<<valor<<" FOI DESEMPILHADO.."<<endl;
                    }
                }
                getchar();
                break;
            case 4:
                system("cls");
                if(indice < 0){
                    cout<<"\n\n\tÉ NECESSÁRIO CRIAR A PILHA!.."<<endl;
                }else{
                    cout<<"INSIRA O VALOR PARA CONSULTA: ";
                    cin>>valor;
                    if(buscar(&p1, valor)){
                        cout<<"\n\n\tO VALOR "<<valor<<" FOI ENCONTRADO NA PILHA!\n";
                        getchar();
                    }else{
                        cout<<"\n\n\tO VALOR "<<valor<<" NÃO FOI ENCONTRADO NA PILHA!\n";
                        getchar();
                    }
                }
                getchar();
                break;
            case 5:
                system("cls");
                if(indice < 0){
                    cout<<"\n\n\tÉ NECESSÁRIO CRIAR A PILHA!.."<<endl;
                }else{
                    mostrar(&p1);
                }
                getchar();
                break;
            case 6:
                system("cls");
                cout<<"\n\n\t ENCERRANDO PROGRAMA..."<<endl;
                getchar();
                desalocar(&p1);
                break;
        }
    }while(menu != 6);
    return 0;
}

