#ifndef _HPP_PILHA
#define _HPP_PILHA

#include <iomanip> //biblioteca usada para formatar a impressão da pilha

using namespace std;

struct Caixa
{
    int codigo;
    float peso;
};

struct Pilha
{
    int tam;
    int base;
    int topo;
    Caixa *dados; //Vetor que será alocado para armazenar os elementos da pilha

    Pilha() //Construtor. Usado para inicializar os dados das variáveis da struct
    {
        tam=0;
        base = -1;
        topo = -1;
        dados = NULL;
    }
};

bool inicializada(Pilha *p)
{
    if(p->dados != NULL)
        return true;
    else
        return false;
}

///inicialização dos dados da pilha
void inicializa(Pilha *p, int tam)
{
  p->base = -1; ///  (*p).base = -1;  /// p->base  p.topo
  p->topo = -1;
  p->tam  =  tam;
  p->dados = new Caixa[tam];///aloca memória dinamicamente

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


bool empilhar(Pilha *p, int cod, float pes)
{
    /// retorna false se a pilha não foi inicializada ou se cheia
    if (p->dados == NULL || cheia(p))
        return false;
    else{
        p->topo++;
        Caixa c;
        c.codigo = cod;
        c.peso = pes;
        p->dados[p->topo] = c;
        return true;
    }
}

bool desempilhar(Pilha *p, Caixa *valor)
{
    ///se a pilha foi inicializada && se não estiver vazia, retira valor
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

    if (p->dados == NULL) /// retorna se a pilha não foi inicializada
        return;

    cout << "PILHA: " << endl;
    cout << "TAM: " << p->tam << endl;
    cout << "TOPO: " << p->topo << endl;
    if(!vazia(p))
    {
        cout << "   ------------" << endl;
        for(int i = p->topo; i > p->base; i--){

            cout << setfill(' ') << std::setw(3) << i << "|";
            cout << setfill(' ') << std::setw(3) << p->dados[i].codigo << ", ";
            cout << setfill(' ') << std::setw(5) << p->dados[i].peso << "|" << endl;
            cout << "   ------------" << endl;
        }
    }
}



bool buscar(Pilha *p, int codigo)
{

    if (p->dados == NULL) /// retorna false se a pilha não foi inicializada
        return false;

   for(int i = p->topo ; i > p->base; i--)
   {
       if (codigo == p->dados[i].codigo)
          return true;
   }
   return false;

}

#endif // _HPP_PILHA





