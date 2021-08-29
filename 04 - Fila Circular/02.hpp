#ifndef _HPP_FILA
#define _HPP_FILA

#include "infAvioes.hpp"
#include <iomanip>

struct Fila{

    int tam;
    int total;
    int inicio;
    int fim;
    Aviao *dados;

    Fila(){
        tam =0;
        total = 0;
        inicio = 0;
        fim = 0;
        dados = nullptr;
    }
};

void inicializaF(Fila *f, int tam){
    f->tam = tam;
    f->inicio = 0;
    f->fim = 0;
    f->total = 0;
    f->dados = new Aviao[tam];
}

void destroiF(Fila *f){
    f->fim = 0;
    f->inicio = 0;
    f->total = 0;
    f->tam = 0;

    if(f->dados){
        delete[] (f->dados);
        f->dados = nullptr;
    }
}

bool vaziaF(Fila *f){
    if (f->total == 0)
        return true;
    else
        return false;
}

bool cheiaF(Fila *f){
    if (f->total == f->tam)
        return true;
    else
        return false;
}

bool enfileiraF(Fila *f, Aviao valor){
    if (!f->dados || cheiaF(f))
        return false;

    f->dados[f->fim] = valor;
    f->total++;
    f->fim++;

    if(f->fim>=f->tam)
       f->fim = 0;

    return true;
}

bool desenfileiraF(Fila *f, Aviao *valor){
    if (!f->dados || vaziaF(f))
        return false;
    *valor = f->dados[f->inicio];

    f->total--;
    f->inicio++;

    if(f->inicio>=f->tam)
       f->inicio = 0;

    return true;
}

bool espiarF(Fila *f, Aviao *valor){
    if (!f->dados || vaziaF(f))
        return false;

    *valor = f->dados[f->inicio];
    return true;
}

void mostraF(Fila *f){
    cout << "\nFila{TAM = " << f->tam << ", TOTAL = " <<  f->total << "} -> ";
    if (!f->dados)
        return;

    if (!vaziaF(f)){
        int idx = f->inicio;
        cout << "[";
        for(int i = 0; i < f->total; i++){
            cout << f->dados[idx].codigo;
            if(i < f->total-1)
                cout << ", ";
            idx++;
            if(idx >= f->tam)
                idx=0;
        }
        cout << "]\n";
    }else{
        cout << "Fila vazia!\n";
    }
}


#endif
