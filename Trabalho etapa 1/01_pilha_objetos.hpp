#ifndef _HPP_PilhaObjeto
#define _HPP_PilhaObjeto
using namespace std;
#include <iomanip>
#include "01_estruturas.hpp"

typedef Objeto Objeto;

struct No{

    Objeto dado;
    No *prox;

};

struct PilhaObjeto{

    No *topo;
    PilhaObjeto(){
        topo = nullptr;
    }
};

void inicializaObjeto(PilhaObjeto *p){

    p->topo = nullptr;
}

bool vaziaObjeto(PilhaObjeto *p){

    if (!p->topo)
        return true;
    else
        return false;
}

bool empilharObjeto(PilhaObjeto *p, Objeto dado){
    No *novo =  new No();
    if (!novo)
        return false;

    novo->dado = dado;
    novo->prox = p->topo;
    p->topo = novo;
    return true;
}

bool desempilharObjeto(PilhaObjeto *p, Objeto *dado){

    if (!vaziaObjeto(p)){
        *dado = p->topo->dado;
        No *apagar = p->topo;
        p->topo = p->topo->prox;
        delete apagar;
        return true;
    }
    else
        return false;
}

bool espiarObjeto(PilhaObjeto* p, Objeto *dado){
    if (p->topo){
        *dado= p->topo->dado;
        return true;
    }
    else
        return false;
}

void mostrarObjeto(PilhaObjeto *p){
    cout << "PILHA DE OBJETOS: " << endl;

    if(!vaziaObjeto(p))
    {
        cout << "--------------------------------------------" << endl;
        cout << setfill(' ') << std::setw(13) << "Nó" << " | ";
        cout << setfill(' ') << std::setw(13) << "Prox" << " | ";
        cout << setfill(' ') << std::setw(10) << "Dado" << " |" << endl;
        cout << "--------------------------------------------" << endl;
        No *no = p->topo;
        while (no != NULL)
        {
            cout<<setfill(' ')<<std::setw(13)<<no<<" | ";
            cout<<setfill(' ')<<std::setw(13)<<no->prox<<" | ";
            cout<<setfill(' ')<<std::setw(10)<<no->dado.descricao<<" |"<<endl;

            no = no->prox;
        }
        cout << "--------------------------------------------"<<endl;
    }
}

bool buscarObjeto(PilhaObjeto *p, Objeto dado){

    No *no = p->topo;
    while (no != NULL){
        if(no->dado.descricao == dado.descricao)
            return true;
        no = no->prox;
    }
    return false;
}

void desalocarObjeto(PilhaObjeto *p){
    Objeto dado;
    while(!vaziaObjeto(p))
        desempilharObjeto(p, &dado);
}

#endif
