#include <bits/stdc++.h>
using namespace std;
#ifndef _HPP_FILA
#define _HPP_FILA
#include <iomanip>

struct Fila
{
    int tam;
    int total;
    int inicio;
    int fim;
    int *dados;

    Fila()
    {
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
    f->dados = new int[tam];
}

void destroiF(Fila *f){
    f->fim = 0;
    f->inicio = 0;
    f->total = 0;
    f->tam = 0;

    if(f->dados)
    {
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

bool enfileiraF(Fila *f, int valor){
    if (!f->dados || cheiaF(f))
        return false;
    f->dados[f->fim] = valor;
    f->total++;
    f->fim++;

    if(f->fim>=f->tam)
       f->fim = 0;

    return true;
}

bool desenfileiraF(Fila *f, int *valor){
    if (!f->dados || vaziaF(f))
        return false;

    *valor = f->dados[f->inicio];
    f->total--;
    f->inicio++;

    if(f->inicio>=f->tam)
       f->inicio = 0;

    return true;
}

bool espiarF(Fila *f, int *valor){
    if (!f->dados || vaziaF(f))
        return false;

    *valor = f->dados[f->inicio];

    return true;
}

void mostraF(Fila *f){
    cout << "\nFila{TAM = " << f->tam << ", TOTAL = " <<  f->total << "} -> ";
    if (!f->dados)
        return;

    if (!vaziaF(f))
    {
        int idx = f->inicio;
        cout << "[";
        for(int i = 0; i < f->total; i++)
        {
            cout << f->dados[idx];

            if(i < f->total-1)
                cout << ", ";

            idx++;
            if(idx >= f->tam)
                idx=0;
        }
        cout << "]\n";
    }else
        cout << "Fila vazia!\n";
}

void mostraVetorDadosF(Fila *f){
    cout << "\nFila{TAM = " << f->tam << ", TOTAL = " <<  f->total;
    cout << ", I = " << f->inicio << ", F = " <<  f->fim << "} -> ";


    if (!f->dados)
        return;
    bool dadosFila[f->tam];

    for(int i = 0; i < f->tam; i++)
        dadosFila[i] = false;
    int idx = f->inicio;
    for(int i = 0; i < f->total; i++){
        dadosFila[idx] = true;
        idx++;
        if(idx >= f->tam)
            idx=0;
    }
    cout << "[";
    for(int i = 0; i < f->tam; i++){
        if(dadosFila[i])
            cout << f->dados[i];
        else
            cout << "-";

        if(i < f->tam-1)
            cout << ", ";
    }
    cout << "]\n";
}

#endif
