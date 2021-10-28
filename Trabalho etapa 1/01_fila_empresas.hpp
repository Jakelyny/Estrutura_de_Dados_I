#include <iomanip>
#ifndef _HPP_FilaEmpresa
#define _HPP_FilaEmpresa
using namespace std;
#include "01_estruturas.hpp"

typedef Empresa DadoNoFilaEmpresa;

struct NoFilaEmpresa{

    DadoNoFilaEmpresa dado;
    NoFilaEmpresa *prox;

};

struct FilaEmpresa{

    NoFilaEmpresa *inicio;
    NoFilaEmpresa *fim;

    FilaEmpresa(){
        inicio = nullptr;
        fim = nullptr;
    }
};

void inicializaFempresa(FilaEmpresa *f){

    f->inicio = nullptr;
    f->fim = nullptr;
}

bool vaziaFempresa(FilaEmpresa *f){

    if (!f->inicio)
        return true;
    else
        return false;
}

bool enfileiraFempresa(FilaEmpresa *f, DadoNoFilaEmpresa dado){

    NoFilaEmpresa *novo = new NoFilaEmpresa();
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

bool desenfileiraFempresa(FilaEmpresa *f, DadoNoFilaEmpresa *dado){

    if (f->inicio){
        *dado = f->inicio->dado;
        NoFilaEmpresa *apagar = f->inicio;
        f->inicio = f->inicio->prox;
        delete apagar;

        if (!f->inicio)
            f->fim = nullptr;

        return true;
    }
    else
        return false;
}

bool espiaFempresa(FilaEmpresa* f, DadoNoFilaEmpresa *dado){

    if (f->inicio){
        *dado= f->inicio->dado;
        return true;
    }
    else
        return false;
}

void mostraFempresa(FilaEmpresa *f){

    cout<<"FILA: ";
    if(f->inicio){
        cout<<"[";
        NoFilaEmpresa *no = f->inicio;
        while (no){
            cout<<no->dado.nomeEmpresa;
            no = no->prox;

            if(no)
                cout<<", ";
        }
        cout<<"]"<<endl;
    }
    else
        cout<<"VAZIA!\n";
}

bool buscaFempresa(FilaEmpresa *f, DadoNoFilaEmpresa dado){

    NoFilaEmpresa *no = f->inicio;
    while (no){
        if(no->dado.nomeEmpresa == dado.nomeEmpresa)
            return true;
        no = no->prox;
    }

    return false;
}

void destroiFempresa(FilaEmpresa *f){

    NoFilaEmpresa *no = f->inicio;
    while (no)
    {
        NoFilaEmpresa *apagar = no;

        no = no->prox;

        delete apagar;
    }

    f->inicio = nullptr;
    f->fim = nullptr;
}

#endif
