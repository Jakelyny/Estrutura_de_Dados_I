#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include <algorithm>
#include <cctype>
using namespace std;

#include "03.hpp"

int main(){

    setlocale(LC_ALL, "Portuguese");
    Pilha p1;
    bool certo = true;
    string expre;
    char simb, aux;

    cout<<"DIGITE A EXPRESSÃO: ";
    cin>>expre;

    inicializa(&p1);
    for(int i = 0; i < expre.size(); i++){
        simb = expre.at(i);
        if(simb == '(' || simb == '[' || simb == '{'){
            empilhar(&p1, simb);
        }else if( simb == ')' || simb == ']' || simb == '}'){
            if(vazia(&p1)){
                certo = false;
                break;
            }else{
                desempilhar(&p1, &aux);
            }
        }
    }
    if(!certo || !vazia(&p1)){
        cout<<"\n\n  PARÊNTESES NÃO AGRUPADOS DE FORMA CORRETA!\n"<<endl;
    }else{
        cout<<"\n\n  PARÊNTESES AGRUPADOS DE FORMA CORRETA!\n"<<endl;
    }
    desalocar(&p1);
}


