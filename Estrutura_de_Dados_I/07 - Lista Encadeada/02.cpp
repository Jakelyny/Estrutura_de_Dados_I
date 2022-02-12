#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include <algorithm>
using namespace std;

#include "02_lista.hpp"

int main(){

    setlocale(LC_ALL, "Portuguese");
    int menu = -1, indice = -1, tamPilha, valor;
    bool resultado;
    No* lista1;
    No* lista2;

    do{
        system("cls");
        cout<<" ************ MENU *****************"<<endl;
        cout<<" | 1 - Criar listas                |"<<endl;
        cout<<" | 2 - Listas iguais?              |"<<endl;
        cout<<" | 3 - Inserir ordenado            |"<<endl;
        cout<<" | 4 - Inserir final               |"<<endl;
        cout<<" | 5 - Total                       |"<<endl;
        cout<<" | 6 - Ler posição                 |"<<endl;
        cout<<" | 7 - Remover posição             |"<<endl;
        cout<<" | 8 - União                       |"<<endl;
        cout<<" | 9 - Sair                        |"<<endl;
        cout<<" **********************************"<<endl;
        cout<<"\nDigite a opção desejada: ";
        cin>>menu;
        fflush(stdin);
        switch(menu)
        {
            case 1:
                system("cls");
                if(indice < 0){
                    inicializaL(&lista1);
                    inicializaL(&lista2);
                    cout<<"\n\n\tLISTAS CRIADAS COM SUCESSO!"<<endl;
                }else{
                    destroiL(&lista1);
                    destroiL(&lista2);
                    inicializaL(&lista1);
                    inicializaL(&lista2);
                    cout<<"\n\n\tLISTAS CRIADAS COM SUCESSO!"<<endl;
                }
                indice++;
                getchar();
                break;
            case 2:
                system("cls");
                if(indice < 0){
                    cout<<"\n\n\tÉ NECESSÁRIO CRIAR A LISTA!.."<<endl;
                }else{
                    if(vaziaL(&lista)){
                        cout<<"\n\n\tA LISTA ESTÁ VAZIA!\n";
                        getchar();
                    }else{
                        if(igual(&lista1, &lista2)){
                            system("cls");
                            cout<<"\n\n\tAS LISTAS SÃO IGUAIS!"<<endl;
                            getchar();
                        }else{
                            system("cls");
                            cout<<"\n\n\tAS LISTAS NÃO SÃO IGUAIS!"<<endl;
                            getchar();
                        }
                    }
                }
                getchar();
                break;
            case 3:
                system("cls");
                int escolha = 0;
                if(indice < 0){
                    cout<<"\n\n\tÉ NECESSÁRIO CRIAR AS LISTAS!.."<<endl;
                }else{
                    cout<<"EM QUAL LISTA DESEJA INSERIR VALOR (1 / 2): ";
                    cin>>escolha;
                    if(escolha == 1){
                        cout<<"INSIRA O VALOR A SER INSERIDO: ";
                        cin>>valor;
                        if(buscaL(&lista, valor)){
                            system("cls");
                            cout<<"\n\n\tO VALOR "<<valor<<" JÁ EXISTE NA LISTA!\n";
                            getchar();
                        }else{
                            insereOrdenado(&lista1, valor);
                            system("cls");
                            cout<<"\n\n\tO VALOR "<<valor<<" FOI INSERIDO NA LISTA 1!\n";
                            getchar();
                        }
                    }
                    else if(escolha == 2){
                        cout<<"INSIRA O VALOR A SER INSERIDO: ";
                        cin>>valor;
                        if(buscaL(&lista2, valor)){
                            system("cls");
                            cout<<"\n\n\tO VALOR "<<valor<<" JÁ EXISTE NA LISTA!\n";
                            getchar();
                        }else{
                            insereOrdenado(&lista2, valor);
                            system("cls");
                            cout<<"\n\n\tO VALOR "<<valor<<" FOI INSERIDO NA LISTA 2!\n";
                            getchar();
                        }
                    }else{
                        system("cls");
                        cout<<"\n\n\tOPÇÃO INVÁLIDA!";
                        getchar();
                    }
                }
                getchar();
                break;
            case 4:
                system("cls");
                int escolha = 0;
                if(indice < 0){
                    cout<<"\n\n\tÉ NECESSÁRIO CRIAR AS LISTAS!.."<<endl;
                }else{
                    cout<<"EM QUAL LISTA DESEJA INSERIR VALOR (1 / 2): ";
                    cin>>escolha;
                    if(escolha == 1){
                        cout<<"INSIRA O VALOR A SER INSERIDO: ";
                        cin>>valor;
                        if(buscaL(&lista, valor)){
                            system("cls");
                            cout<<"\n\n\tO VALOR "<<valor<<" JÁ EXISTE NA LISTA!\n";
                            getchar();
                        }else{
                            insereFinalL(&lista1, valor);
                            system("cls");
                            cout<<"\n\n\tO VALOR "<<valor<<" FOI INSERIDO NA LISTA 1!\n";
                            getchar();
                        }
                    }
                    else if(escolha == 2){
                        cout<<"INSIRA O VALOR A SER INSERIDO: ";
                        cin>>valor;
                        if(buscaL(&lista2, valor)){
                            system("cls");
                            cout<<"\n\n\tO VALOR "<<valor<<" JÁ EXISTE NA LISTA!\n";
                            getchar();
                        }else{
                            insereFinalL(&lista2, valor);
                            system("cls");
                            cout<<"\n\n\tO VALOR "<<valor<<" FOI INSERIDO NA LISTA 2!\n";
                            getchar();
                        }
                    }else{
                        system("cls");
                        cout<<"\n\n\tOPÇÃO INVÁLIDA!";
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
            case 7:
                system("cls");
                if(indice < 0){
                    cout<<"\n\n\tÉ NECESSÁRIO CRIAR AS LISTAS!.."<<endl;
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
        }
    }while(menu != 6);
    return 0;
}

