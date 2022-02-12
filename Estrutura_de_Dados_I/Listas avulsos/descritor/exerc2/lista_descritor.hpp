#ifndef _HPP_LISTA_DESCRITOR
#define _HPP_LISTA_DESCRITOR

#include "funcionario.hpp"

typedef Funcionario DadoNoLista;

struct No
{
    DadoNoLista dado;
    struct No *prox;
    No() // construtor
    {
        //dado = Funcionario j� � inicializado no seu pr�prio construtor...
        prox = nullptr;
    }
};

struct Lista
{
    No *inicio;
    No *fim;
    int tamanho;
    Lista() /// construtor
    {
        //cout << "\n executando o construtor...\n";
        inicio = nullptr;
        fim = nullptr;
        tamanho =0;
    }
    ~Lista() /// desconstrutor /// quando chame delete(ponteiro)
    {
        //cout << "\n executando o desconstrutor....\n";
        No *n = inicio;
        while(n)
        {
            No *aux = n;
            n = n->prox;
            delete aux;
        }
    }

}; //fim struct


/// quando cout receber uma struct No
ostream& operator<<(ostream& os, const No *n)
{
    return os << n->dado;
}

/// quanto cout receber uma struct Lista
ostream& operator << (ostream& os, const Lista *l)
{
    No *n = l->inicio;

    while(n)
    {
        os << n;
        n = n->prox;
        if(n)
            os << ", ";
    }

    return os;
}

bool vaziaL(Lista *lista)
{
    if(! (lista->inicio) )
        return true;
    else
        return false;
}

///insere no in�cio da lista
bool insereInicioL(Lista *lista, DadoNoLista valor)
{

    No *novo = new No();
    if (!novo)
        return false;

    novo->dado = valor;
    novo->prox = lista->inicio;
    lista->inicio = novo;
    lista->tamanho++;
    if (!lista->fim)
        lista->fim = lista->inicio;

    return true;
}

bool insereFinalL(Lista *lista, DadoNoLista valor)
{
    No *novo = new No();

    if (!novo)
        return false;

    novo->dado = valor;
    novo->prox = nullptr;

    if(lista->fim) // a lista n�o est� vazia ?
    {
        lista->fim->prox = novo;
        lista->fim = novo;
    }
    else{
        lista->inicio = novo;
        lista->fim = novo;
    }
    lista->tamanho++;

    return true;
}

void ordenaL(Lista *lista)
{
    bool trocou;
    DadoNoLista aux;
    No *anterior, *atual;

    if( vaziaL(lista) )
        return;


    do{
        trocou = false;
        No *anterior = nullptr;
        No *atual = lista->inicio;
        while(atual)
        {

            if(anterior && anterior->dado > atual->dado) //verifica se precisa trocar
            {
                DadoNoLista aux = anterior->dado;
                anterior->dado = atual->dado;
                atual->dado = aux;
                trocou = true;
            }

            anterior = atual;
            atual = atual->prox;
        }

    }while(trocou);


}




bool removeL(Lista *lista, DadoNoLista valor)
{
    No *anterior = nullptr;
    No *atual = lista->inicio;
    ///fica no la�o enquanto tiver elementos na lista
    /// e n�o encontrar o valor procurado
    while(atual && atual->dado != valor)
    {
        anterior = atual;
        atual = atual->prox;
    }
    /// pode sair do la�o sem encontrar o valor (atual==NULL)
    /// se encontrar >>> atual tem o endere�o do elemento para excluir
    /// NULL == false    >>> !false == true
    if(!atual) /// se atual � NULL >> n�o encontrou
        return false;
    if (!anterior) /// se anterior � igual a NULL
    {
        /// o elemento a ser exclu�do est� no in�cio da lista
        lista->inicio = atual->prox;
        if (!lista->inicio) ///lista ficou vazia ?
            lista->fim = lista->inicio;
    }
    else   /// elemento est� no meio ou no fim
    {
        anterior->prox = atual->prox;
        if (!atual->prox)/// se for retirado �ltimo da lista
            lista->fim = anterior;
    }
    /// libera a mem�ria do elemento
    lista->tamanho--;

    delete(atual);
    return true;

}

No* buscaL(Lista *lista, DadoNoLista valor)
{
    No *n = lista->inicio;
    while (n)
    {
        if (n->dado == valor)
            return n;

        n = n->prox;
    }

    return nullptr;
}

bool inserePosicaoL(Lista *lista, DadoNoLista valor, int posicao)
{
    No *anterior = NULL;
    No *atual = lista->inicio;
    int p = 0;
    while (atual && p!=posicao)
    {
        anterior = atual;
        atual = atual->prox;
        p++;
    }
    if (p != posicao)
        return false; ///significa q n�o encontrou a posi��o

    No *novo = new No();
    novo->dado = valor;
    if(!anterior)/// inclus�o no in�cio da lista
    {
        novo->prox = lista->inicio;
        lista->inicio = novo;

        if (!lista->fim)
            lista->fim = lista->inicio;
    }
    else
    {
        novo->prox = anterior->prox;
        anterior->prox = novo;

        if (!novo->prox) //o n� adicionado est� no final da lista?
            lista->fim = novo;
    }

    lista->tamanho++;

    return true;
}



#endif // _HPP_LISTA_DESCRITOR



