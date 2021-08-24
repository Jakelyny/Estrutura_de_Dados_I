#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include <algorithm>
#include <cctype>
using namespace std;

#include "06.hpp"

int main(){

    setlocale(LC_ALL, "Portuguese");
    Pilha p1;
    char frase[50], frase2[50], valor;

    cout<<"DIGITE A FRASE: ";
    cin>>frase;
    fflush(stdin);

    inicializa(&p1, 50);
    for(int i = 0; frase[i] != '\0'; i++){
        empilhar(&p1, frase[i]);
    }
    mostrar(&p1);
    for(int i = 0; frase[i] != '\0'; i++){
        desempilhar(&p1, &valor);
        cout<<valor<<endl;
        frase2[i] = valor;
    }
    int val = strcmp(frase,frase2);
    if(val == 0){
        cout<<"É UM PALÍNDROMO!.."<<endl;
    }else{
        cout<<"NÃO É UM PALÍNDROMO!.."<<endl;
    }
    desalocar(&p1);
    return 0;
}

