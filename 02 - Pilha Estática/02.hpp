#ifndef _HPP_PILHA
#define _HPP_PILHA

#include <iomanip>

struct Pilha
{
    int tam;
    int base;
    int topo;
    int *dados;

    Pilha()
    {
        tam = 0;
        base = -1;
        topo = -1;
        dados = NULL;
    }
};

void inicializa(Pilha *p, int tam)
{
  p->base = -1;
  p->topo = -1;
  p->tam  =  tam;
  p->dados = new int[tam];

}

void desalocar(Pilha *p)
{
    p->base = -1;
    p->topo = -1;
    p->tam = 0;

    if(p->dados != NULL)
    {
        delete[] (p->dados);
        p->dados = NULL;
    }
}

bool cheia(Pilha *p)
{
    if (p->topo == p->tam - 1)
        return true;
    else
        return false;
}

bool vazia(Pilha *p)
{
    if (p->topo == p->base)
        return true;
    else
        return false;
}

bool empilhar(Pilha *p, int valor)
{
    if (p->dados == NULL || cheia(p))
        return false;
    else{
        p->topo++;
        p->dados[p->topo] = valor;
        return true;
    }
}

bool desempilhar(Pilha *p, int *valor)
{
    if (p->dados != NULL && !vazia(p))
    {
        *valor = p->dados[p->topo];
        p->topo--;
        return true;
    }
    else
        return false;
}

void mostrar(Pilha *p)
{

    if (p->dados == NULL)
        return;

    cout << "---- PILHA ---- " << endl;
    cout << "TAM: " << p->tam << endl;
    cout << "TOPO: " << p->topo << endl;
    if(!vazia(p))
    {
        cout << "   ------------" << endl;
        for(int i = p->topo; i > p->base; i--){

            cout << setfill(' ') << std::setw(3) << i << "|";
            cout << setfill(' ') << std::setw(10) << p->dados[i] << "|" << endl;
            cout << "   ------------" << endl;
        }
    }
}

bool buscar(Pilha *p, int valor)
{

   if (p->dados == NULL)
        return false;

   for(int i = p->topo ; i > p->base; i--)
   {
       if (valor == p->dados[i])
          return true;
   }
   return false;

}

#endif

