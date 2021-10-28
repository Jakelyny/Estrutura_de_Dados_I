#include <iomanip>
#ifndef _HPP_PilhaFichaDoacaoObjetos
#define _HPP_PilhaFichaDoacaoObjetos
using namespace std;
#include "01_estruturas.hpp"

typedef Doacao FichaDoacaoObjetos;

struct NoFichaObjetos{

    FichaDoacaoObjetos dado;
    NoFichaObjetos *prox;

};

struct PilhaFichaDoacaoObjetos{

    NoFichaObjetos *topo;
    PilhaFichaDoacaoObjetos(){
        topo = nullptr;
    }
};

void inicializaFichaDoacaoObjetos(PilhaFichaDoacaoObjetos *p){

    p->topo = nullptr;
}

bool vaziaFichaDoacaoObjetos(PilhaFichaDoacaoObjetos *p){

    if (!p->topo)
        return true;
    else
        return false;
}

bool empilharFichaDoacaoObjetos(PilhaFichaDoacaoObjetos *p, FichaDoacaoObjetos dado){

    NoFichaObjetos *NoFichaObjetosnovos =  new NoFichaObjetos();
    if (!NoFichaObjetosnovos)
        return false;
    NoFichaObjetosnovos->dado = dado;
    NoFichaObjetosnovos->prox = p->topo;
    p->topo = NoFichaObjetosnovos;
    return true;
}

bool desempilharFichaDoacaoObjetos(PilhaFichaDoacaoObjetos *p, FichaDoacaoObjetos *dado){

    if (!vaziaFichaDoacaoObjetos(p)){
        *dado = p->topo->dado;
        NoFichaObjetos *apagar = p->topo;
        p->topo = p->topo->prox;
        delete apagar;
        return true;
    }
    else
        return false;
}

bool espiarFichaDoacaoObjetos(PilhaFichaDoacaoObjetos* p, FichaDoacaoObjetos *dado){

    if (p->topo){
        *dado= p->topo->dado;
        return true;
    }
    else
        return false;
}

void mostrarFichaDoacaoObjetos(PilhaFichaDoacaoObjetos *p){
    cout << "PILHA DE OBJETOS DOAÇÃO: " << endl;

    if(!vaziaFichaDoacaoObjetos(p))
    {
        cout << "--------------------------------------------" << endl;
        cout << setfill(' ') << std::setw(13) << "Nó" << " | ";
        cout << setfill(' ') << std::setw(13) << "Prox" << " | ";
        cout << setfill(' ') << std::setw(10) << "Dado" << " |" << endl;
        cout << "--------------------------------------------" << endl;
        NoFichaObjetos *NoFichaObjetos = p->topo;
        while (NoFichaObjetos != NULL){
            cout<<setfill(' ')<<std::setw(13)<<NoFichaObjetos<<" | ";
            cout<<setfill(' ')<<std::setw(13)<<NoFichaObjetos->prox<<" | ";
            cout<<setfill(' ')<<std::setw(10)<<NoFichaObjetos->dado.pessoa.nomeCompleto<<" |"<<endl;
            NoFichaObjetos = NoFichaObjetos->prox;
        }
        cout << "--------------------------------------------" << endl;
    }
}

bool buscarFichaDoacaoObjetos(PilhaFichaDoacaoObjetos *p, FichaDoacaoObjetos dado){

    NoFichaObjetos *NoFichaObjetos = p->topo;
    while (NoFichaObjetos != NULL)
    {
        if(NoFichaObjetos->dado.pessoa.nomeCompleto == dado.pessoa.nomeCompleto)
            return true;

        NoFichaObjetos = NoFichaObjetos->prox;
    }
    return false;
}

void desalocarFichaDoacaoObjetos(PilhaFichaDoacaoObjetos *p){

    FichaDoacaoObjetos dado;
    while(!vaziaFichaDoacaoObjetos(p))
        desempilharFichaDoacaoObjetos(p, &dado);
}

#endif
