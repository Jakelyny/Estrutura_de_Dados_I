#ifndef _HPP_PILHA_DINAMICA
#define _HPP_PILHA_DINAMICA

#include <iomanip> //biblioteca usada para formatar a impressão da pilha

typedef char DadoNo;

struct No
{
    DadoNo dado; //informacao do nó
    No *prox; //proximo elemento da pilha
};

struct Pilha
{
    No *topo;

    Pilha(){ //Construtor. Usado para inicializar os dados das variáveis da struct
        topo = nullptr;
    }
};


///inicialização dos dados da pilha
void inicializa(Pilha *p)
{
    p->topo = nullptr; //define nulo para o topo da pilha
}

bool vazia(Pilha *p)
{
    if (!p->topo) //(p->topo == NULL)
        return true;
    else
        return false;
}





//push
bool empilhar(Pilha *p, DadoNo dado)
{
    No *novo =  new No(); //cria um novo nó
    if (!novo) /// sistema não conseguiu alocar a memória
        return false;

    novo->dado = dado; //armazena a informação no nó
    novo->prox = p->topo; //o próximo elemento do nó criado será o último elemento da pilha
    p->topo = novo; //atualiza o topo da pilha para o nó criado.
    return true;
}

//pop
bool desempilhar(Pilha *p, DadoNo *dado)
{
    // se não estiver vazia, retira valor
    if (!vazia(p))
    {
        *dado = p->topo->dado; //pega o dado armazenado no nó do topo
        No *apagar = p->topo; //guarda o nó do topo em uma variável auxiliar;
        p->topo = p->topo->prox; //atualiza o topo para o próximo elemento;
        delete apagar;  /// libera a memória
        return true;
    }
    else
        return false;
}

//peek
bool espiar(Pilha* p, DadoNo *dado)
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

/// retorna true se o valor existe na pilha
/// retorna false se o valor não existe na pilha
bool buscar(Pilha *p, DadoNo dado)
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
    DadoNo dado;
    while(!vazia(p))
        desempilhar(p, &dado);
}




#endif // _HPP_PILHA_DINAMICA





