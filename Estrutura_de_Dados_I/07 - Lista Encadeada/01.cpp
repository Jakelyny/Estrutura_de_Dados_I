#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include <algorithm>
using namespace std;

#include "01_lista.hpp"

int main(){

    setlocale(LC_ALL, "Portuguese");
    int menu = -1, indice = -1, valor;
    bool resultado;
    No* lista;

    do{
        system("cls");
        cout<<" ************ MENU *****************"<<endl;
        cout<<" |                                 |"<<endl;
        cout<<" | 1 - Criar lista                 |"<<endl;
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
                    inicializaL(&lista);
                    cout<<"\n\n\tLISTA CRIADA COM SUCESSO!"<<endl;
                }else{
                    destroiL(&lista);
                    inicializaL(&lista);
                    cout<<"\n\n\tLISTA CRIADA COM SUCESSO!"<<endl;
                }
                indice++;
                getchar();
                break;
            case 2:
                system("cls");
                if(indice < 0){
                    cout<<"\n\n\tÉ NECESSÁRIO CRIAR A LISTA!.."<<endl;
                }else{
                    cout<<"INSIRA O VALOR A SER INSERIDO: ";
                    cin>>valor;
                    if(buscaL(&lista, valor)){
                        system("cls");
                        cout<<"\n\n\tO VALOR "<<valor<<" JÁ EXISTE NA LISTA!\n";
                        getchar();
                    }else{
                        insereL(&lista, valor);
                        system("cls");
                        cout<<"\n\n\tO VALOR "<<valor<<" FOI INSERIDO NA LISTA!\n";
                        getchar();
                    }
                }
                getchar();
                break;
            case 3:
                system("cls");
                if(indice < 0){
                    cout<<"\n\n\tÉ NECESSÁRIO CRIAR A LISTA!.."<<endl;
                }else{
                    if(vaziaL(&lista)){
                        cout<<"\n\n\tA LISTA ESTÁ VAZIA!\n";
                        getchar();
                    }else{
                        cout<<"INSIRA O VALOR A SER REMOVIDO: ";
                        cin>>valor;
                        if(removeL(&lista, valor)){
                            system("cls");
                            cout<<"\n\n\tO VALOR "<<valor<<" FOI REMOVIDO.."<<endl;
                            getchar();
                        }else{
                            system("cls");
                            cout<<"\n\n\tO VALOR "<<valor<<" NÃO EXISTE NA LISTA!\n";
                            getchar();
                        }
                    }
                }
                getchar();
                break;
            case 4:
                system("cls");
                if(indice < 0){
                    cout<<"\n\n\tÉ NECESSÁRIO CRIAR A LISTA!.."<<endl;
                }else{
                    cout<<"INSIRA O VALOR PARA CONSULTA: ";
                    cin>>valor;
                    if(buscaL(&lista, valor)){
                        system("cls");
                        cout<<"\n\n\tO VALOR "<<valor<<" FOI ENCONTRADO NA LISTA!\n";
                        getchar();
                    }else{
                        system("cls");
                        cout<<"\n\n\tO VALOR "<<valor<<" NÃO FOI ENCONTRADO NA LISTA!\n";
                        getchar();
                    }
                }
                getchar();
                break;
            case 5:
                system("cls");
                if(indice < 0){
                    cout<<"\n\n\tÉ NECESSÁRIO CRIAR A LISTA!.."<<endl;
                }else{
                    mostraL(&lista);
                }
                getchar();
                break;
            case 6:
                system("cls");
                cout<<"\n\n\t ENCERRANDO PROGRAMA..."<<endl;
                getchar();
                destroiL(&lista);
                break;
        }
    }while(menu != 6);
    return 0;
}
