#ifndef _HPP_PILHA
#define _HPP_PILHA

#include <iomanip> //biblioteca usada para formatar a impressão da pilha

using namespace std;

typedef char DadoNoPilha;

struct Pilha
{
    int tam;
    int base;
    int topo;
    DadoNoPilha *dados; //Vetor que será alocado para armazenar os elementos da pilha

    Pilha() //Construtor. Usado para inicializar os dados das variáveis da struct
    {
        tam=0;
        base = -1;
        topo = -1;
        dados = NULL;
    }
};

bool inicializadaP(Pilha *p)
{
    if(p->dados != NULL)
        return true;
    else
        return false;
}

///inicialização dos dados da pilha
void inicializaP(Pilha *p, int tam)
{
  p->base = -1; ///  (*p).base = -1;  /// p->base  p.topo
  p->topo = -1;
  p->tam  =  tam;
  p->dados = new DadoNoPilha[tam];///aloca memória dinamicamente

}

void destroiP(Pilha *p)
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



bool cheiaP(Pilha *p)
{
    if (p->topo == p->tam - 1)
        return true;
    else
        return false;
}

bool vaziaP(Pilha *p)
{
    if (p->topo == p->base)
        return true;
    else
        return false;
}


bool empilhaP(Pilha *p, DadoNoPilha dado)
{
    /// retorna false se a pilha não foi inicializada ou se cheia
    if (p->dados == NULL || cheiaP(p))
        return false;
    else{
        p->topo++;
        p->dados[p->topo] = dado;
        return true;
    }
}

bool desempilhaP(Pilha *p, DadoNoPilha *dado)
{
    ///se a pilha foi inicializada && se não estiver vazia, retira valor
    if (p->dados != NULL && !vaziaP(p))
    {
        *dado = p->dados[p->topo];
        p->topo--;
        return true;
    }
    else
        return false;
}



void mostraP(Pilha *p)
{

    if (p->dados == NULL) /// retorna se a pilha não foi inicializada
        return;

    cout << "PILHA: " << endl;
    cout << "TAM: " << p->tam << endl;
    cout << "TOPO: " << p->topo << endl;
    if(!vaziaP(p))
    {
        cout << "   ------------" << endl;
        for(int i = p->topo; i > p->base; i--){

            cout << setfill(' ') << std::setw(3) << i << "|";
            cout << setfill(' ') << std::setw(10) << p->dados[i] << "|" << endl;
            cout << "   ------------" << endl;
        }
    }
}



bool buscaP(Pilha *p, DadoNoPilha dado)
{

    if (p->dados == NULL) /// retorna false se a pilha não foi inicializada
        return false;

   for(int i = p->topo ; i > p->base; i--)
   {
       if (dado == p->dados[i])
          return true;
   }
   return false;

}

#endif // _HPP_PILHA





