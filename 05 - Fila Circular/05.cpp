#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include <algorithm>
using namespace std;

#include "05_pilha.hpp"
#include "05_fila.hpp"

int main(){

    setlocale(LC_ALL, "Portuguese");
    Pilha p1;
    Fila fPrimo, fPar, fImpar;
    inicializaF(&fPar, 10);
    inicializaF(&fImpar, 10);
    inicializaF(&fPrimo, 10);
    int menu = -1, indice = -1, valor, novo, aux = 0;
    bool resultado;

    do{
        system("cls");
        cout<<" ******************** MENU **********************"<<endl;
        cout<<" | 1 - Incluir na pilha                         |"<<endl;
        cout<<" | 2 - Remover da pilha                         |"<<endl;
        cout<<" | 3 - Mostrar pilha                            |"<<endl;
        cout<<" | 4 - Mostrar as filas (Primos/Pares/Ímpares)  |"<<endl;
        cout<<" | 5 - Sair                                     |"<<endl;
        cout<<" ************************************************"<<endl;
        cout<<"\nDigite a opção desejada: ";
        cin>>menu;
        fflush(stdin);
        switch(menu){
            case 1:
                system("cls");
                inicializa(&p1);
                cout<<"VALOR A SER EMPILHADO: ";
                cin>>novo;
                empilhar(&p1, novo);
                indice++;
                getchar();
                break;
            case 2:
                system("cls");
                if(indice < 0){
                    cout<<"\n\n\tÉ NECESSÁRIO CRIAR A PILHA!.."<<endl;
                }else{
                    if(desempilhar(&p1, &valor)){
                        cout<<"O "<<valor<<" FOI DESEMPILHADO"<<endl;
                        if(valor % 2 == 0){
                            enfileiraF(&fPar, valor);
                        }else if(valor % 2 == 1){
                            enfileiraF(&fImpar, valor);
                        }
                        for(int i =1; i <= valor; i++){
                            if(valor % i == 0 && i != 1 && i != 0 && i != valor){
                                aux++;
                            }
                        }
                        if(aux == 0){
                            enfileiraF(&fPrimo, valor);
                        }
                        aux=0;
                    }else{
                        cout<<"\n\n\tA PILHA ESTÁ VAZIA!!!.."<<endl;
                        getchar();
                    }
                }
                getchar();
                break;
            case 3:
                system("cls");
                if(indice < 0){
                    cout<<"\n\n\tÉ NECESSÁRIO CRIAR A PILHA!.."<<endl;
                }else{
                    mostrar(&p1);
                }
                getchar();
                break;

            case 4:
                system("cls");
                if(indice < 0){
                    cout<<"\n\n\tÉ NECESSÁRIO CRIAR A PILHA!.."<<endl;
                }else{
                    cout<<"FILA DOS PRIMOS: ";
                    mostraF(&fPrimo);
                    cout<<"FILA DOS PARES: ";
                    mostraF(&fPar);
                    cout<<"FILA DOS ÍMPARES: ";
                    mostraF(&fImpar);
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


