#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include <algorithm>
#include <cctype>
using namespace std;

#include "05.hpp"

int main(){

    setlocale(LC_ALL, "Portuguese");
    Pilha p1;
    Pilha p2;
    char frase[10];

    cout<<"DIGITE SUA FRASE: ";
    cin>>frase;
    fflush(stdin);

    inicializa(&p1, 10);
    inicializa(&p2, 10);

    for(int i = 0; i <= strlen(frase); i++){
        if(isalpha(frase[i])){
            empilhar(&p1, frase[i]);
        }if(isdigit(frase[i])){
            empilhar(&p2, frase[i]);
        }
    }
    cout<<"\n ___________________";
    cout<<"\n|______LETRAS";
    mostrar(&p1);
    cout<<"\n ___________________";
    cout<<"\n|____NÚMEROS ";
    mostrar(&p2);
    desalocar(&p1);
    desalocar(&p2);
    return 0;
}

