#include <iomanip>
#ifndef _HPP_FilaPessoa
#define _HPP_FilaPessoa
using namespace std;
#include "01_estruturas.hpp"

typedef Pessoa DadoNoFilaPessoa;

struct NoFilaPessoa{

    DadoNoFilaPessoa dado;
    NoFilaPessoa *prox;

};

struct FilaPessoa{

    NoFilaPessoa *inicio;
    NoFilaPessoa *fim;

    FilaPessoa(){
        inicio = nullptr;
        fim = nullptr;
    }
};

void inicializaFpessoa(FilaPessoa *f){

    f->inicio = nullptr;
    f->fim = nullptr;
}

bool vaziaFpessoa(FilaPessoa *f){

    if (!f->inicio)
        return true;
    else
        return false;
}

bool enfileiraFpessoa(FilaPessoa *f, DadoNoFilaPessoa dado){

    NoFilaPessoa *novo = new NoFilaPessoa();
    if (!novo)
        return false;

    novo->dado = dado;
    novo->prox = nullptr;
    if (!f->inicio)
        f->inicio = novo;
    else
        f->fim->prox = novo;

    f->fim = novo;
    return true;
}

bool desenfileiraFPessoa(FilaPessoa *f, DadoNoFilaPessoa *dado){

    if (f->inicio){
        *dado = f->inicio->dado;
        NoFilaPessoa *apagar = f->inicio;
        f->inicio = f->inicio->prox;
        delete apagar;

        if (!f->inicio)
            f->fim = nullptr;

        return true;
    }
    else
        return false;
}

bool espiaFpessoa(FilaPessoa* f, DadoNoFilaPessoa *dado){

    if (f->inicio){
        *dado= f->inicio->dado;
        return true;
    }
    else
        return false;
}

void mostraFpessoa(FilaPessoa *f){

    cout<<"FILA: ";
    if(f->inicio){
        cout<<"[";
        NoFilaPessoa *no = f->inicio;
        while (no){
            cout<<no->dado.nomeCompleto;
            no = no->prox;

            if(no)
                cout<<", ";
        }
        cout<<"]"<<endl;
    }
    else
        cout<<"VAZIA!\n";
}

bool buscaFpessoa(FilaPessoa *f, DadoNoFilaPessoa dado){

    NoFilaPessoa *no = f->inicio;
    while (no){
        if(no->dado.nomeCompleto == dado.nomeCompleto)
            return true;
        no = no->prox;
    }
    return false;
}

void destroiFpessoa(FilaPessoa *f){

    NoFilaPessoa *no = f->inicio;
    while (no)
    {
        NoFilaPessoa *apagar = no;

        no = no->prox;

        delete apagar;
    }

    f->inicio = nullptr;
    f->fim = nullptr;
}

#endif
