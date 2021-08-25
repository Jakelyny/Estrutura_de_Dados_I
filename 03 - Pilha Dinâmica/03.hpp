#ifndef _HPP_PILHA_DINAMICA
#define _HPP_PILHA_DINAMICA

#include <iomanip>

struct No
{
    char dado;
    No *prox;
};

struct Pilha
{
    No *topo;

    Pilha(){
        topo = nullptr;
    }
};

void inicializa(Pilha *p)
{
    p->topo = nullptr;
}

bool vazia(Pilha *p)
{
    if (!p->topo)
        return true;
    else
        return false;
}

bool empilhar(Pilha *p, char dado)
{
    No *novo =  new No();
    if (!novo)
        return false;

    novo->dado = dado;
    novo->prox = p->topo;
    p->topo = novo;
    return true;
}

bool desempilhar(Pilha *p, char *dado)
{
    if (!vazia(p))
    {
        *dado = p->topo->dado;
        No *apagar = p->topo;
        p->topo = p->topo->prox;
        delete apagar;
        return true;
    }
    else
        return false;
}

bool espiar(Pilha* p, char *dado)
{
    if (p->topo)
    {
        *dado= p->topo->dado;
        return true;
    }
    else
        return false;
}


void mostrar(Pilha *p)
{
    cout << "PILHA: " << endl;

    if(!vazia(p))
    {
        cout << "--------------------------------------------" << endl;
        cout << setfill(' ') << std::setw(13) << "Nó" << " | ";
        cout << setfill(' ') << std::setw(13) << "Prox" << " | ";
        cout << setfill(' ') << std::setw(10) << "Dado" << " |" << endl;
        cout << "--------------------------------------------" << endl;
        No *no = p->topo;
        while (no != NULL)
        {
            cout << setfill(' ') << std::setw(13) << no << " | ";
            cout << setfill(' ') << std::setw(13) << no->prox << " | ";
            cout << setfill(' ') << std::setw(10) << no->dado << " |" << endl;

            no = no->prox;
        }
        cout << "--------------------------------------------" << endl;
    }
}

bool buscar(Pilha *p, char dado)
{

    No *no = p->topo;
    while (no != NULL)
    {
        if(no->dado == dado)
            return true;

        no = no->prox;
    }

    return false;

}

void desalocar(Pilha *p)
{
    char dado;
    while(!vazia(p))
        desempilhar(p, &dado);
}

#endif
