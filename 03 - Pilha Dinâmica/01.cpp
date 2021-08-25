#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include <algorithm>
#include <cctype>
using namespace std;

#include "01.hpp"

int main(){

    setlocale(LC_ALL, "Portuguese");
    Pilha p1;
    string frase, frase2;
    char valor;

    cout<<"DIGITE UMA FRASE: ";
    getline(cin, frase);

    inicializa(&p1, frase.size());
    for(int i = 0; i < frase.size(); i++){
        empilhar(&p1, frase.at(i) );
    }
    for(int i = 0; i < frase.size(); i++){
        if(desempilhar(&p1, &valor )){
            frase2 += valor;
        }
    }
    cout<<"\nFRASE INVERTIDA: "<<frase2<<endl;
    desalocar(&p1);
}

