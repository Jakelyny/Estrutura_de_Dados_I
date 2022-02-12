#ifndef _HPP_PILHA_DINAMICA
#define _HPP_PILHA_DINAMICA

#include <iomanip> //biblioteca usada para formatar a impressão da pilha

typedef int DadoNoPilha;

struct NoPilha
{
    DadoNoPilha dado; //informacao do nó
    NoPilha *prox; //proximo elemento da pilha
};

struct Pilha
{
    NoPilha *topo;

    Pilha(){ //Construtor. Usado para inicializar os dados das variáveis da struct
        topo = nullptr;
    }
};


///inicialização dos dados da pilha
void inicializaP(Pilha *p)
{
    p->topo = nullptr; //define nulo para o topo da pilha
}

bool vaziaP(Pilha *p)
{
    if (!p->topo) //(p->topo == NULL)
        return true;
    else
        return false;
}


//push
bool empilhaP(Pilha *p, DadoNoPilha dado)
{
    NoPilha *novo =  new NoPilha(); //cria um novo nó
    if (!novo) /// sistema não conseguiu alocar a memória
        return false;

    novo->dado = dado; //armazena a informação no nó
    novo->prox = p->topo; //o próximo elemento do nó criado será o último elemento da pilha
    p->topo = novo; //atualiza o topo da pilha para o nó criado.
    return true;
}

//pop
bool desempilhaP(Pilha *p, DadoNoPilha *dado)
{
    // se não estiver vazia, retira valor
    if (!vaziaP(p))
    {
        *dado = p->topo->dado; //pega o dado armazenado no nó do topo
        NoPilha *apagar = p->topo; //guarda o nó do topo em uma variável auxiliar;
        p->topo = p->topo->prox; //atualiza o topo para o próximo elemento;
        delete apagar;  /// libera a memória
        return true;
    }
    else
        return false;
}

//peek
bool espiaP(Pilha* p, DadoNoPilha *dado)
{
    if (p->topo)
    {
        *dado= p->topo->dado;
        return true;
    }
    else
        return false;
}


void mostraP(Pilha *p)
{
    cout << "PILHA: " << endl;

    if(!vaziaP(p))
    {
        cout << "--------------------------------------------" << endl;
        cout << setfill(' ') << std::setw(13) << "Nó" << " | ";
        cout << setfill(' ') << std::setw(13) << "Prox" << " | ";
        cout << setfill(' ') << std::setw(10) << "Dado" << " |" << endl;
        cout << "--------------------------------------------" << endl;
        NoPilha *no = p->topo;
        while (no != NULL)
        {
            cout << setfill(' ') << std::setw(13) << no << " | ";
            cout << setfill(' ') << std::setw(13) << no->prox << " | ";
            cout << setfill(' ') << std::setw(3) << "[" << no->dado << "]" << " |" << endl;

            no = no->prox;
        }
        cout << "--------------------------------------------" << endl;
    }
}


int total(Pilha *p)
{
    int cont = 0;

    NoPilha *no = p->topo;
    while (no != NULL)
    {
        cont++;

        no = no->prox;
    }

    return cont;

}


void destroiP(Pilha *p)
{
    DadoNoPilha dado;
    while(!vaziaP(p))
        desempilhaP(p, &dado);
}




#endif // _HPP_PILHA_DINAMICA





