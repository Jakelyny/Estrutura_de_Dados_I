#ifndef _HPP_LISTA_DINAMICA
#define _HPP_LISTA_DINAMICA

typedef int DadoNoLista;

enum ORDEM_LISTA
{
    ORDEM_CRESCENTE,
    ORDEM_DECRESCENTE

};

struct No
{
    DadoNoLista dado;
    struct No *prox;
};


void inicializaL(No **lista)
{
    *lista = nullptr;
}

bool vaziaL(No **lista)
{
    if(! (*lista) )
        return true;
    else
        return false;
}

/// excluir todos os elementos da lista
void destroiL(No **lista)
{
    No *n = *lista;
    while (n)
    {
        No *aux  = n;
        n = n->prox;
        delete aux;
    }
    *lista = nullptr;
}

bool ordemL(No **lista, int tipo)
{

    if(vaziaL(lista))
        return false;

    No *anterior = nullptr;
    No *atual = *lista;

    while(atual)
    {
        anterior = atual;
        atual = atual->prox;

        if(anterior && atual) //verifica se ambos os nós não são nulos
        {
            if(tipo == ORDEM_CRESCENTE)
            {
                if(anterior->dado > atual->dado)
                   return false;
            }
            else{ //ordem decrescente
                 if(anterior->dado < atual->dado)
                   return false;
            }
        }
    }

    return true;
}


//insere no início da lista
bool insereL(No **lista, DadoNoLista valor)
{

    No *novo = new No(); // aloca memória para o nó
    if (!novo)
        return false;

    novo->dado = valor;
    novo->prox = *lista;
    *lista = novo;

    return true;
}



void mostraL(No **lista, string label="L")
{
    No *n = *lista;

    cout << label << ":{";
    while(n) /// enquanto n não for NULL fica no laço
    {
        cout << n->dado;
        n = n->prox;

        if(n)
            cout << ", ";
    }
    cout << "}\n";
}

///remover um valor específico da lista
bool removeL(No **lista, DadoNoLista valor)
{
    No *anterior = nullptr;
    No *atual = *lista;
    ///fica no laço enquanto tiver elementos na lista
    /// e não encontrar o valor procurado
    while(atual && atual->dado != valor)
    {
        anterior = atual;
        atual = atual->prox;
    }
    /// pode sair do laço sem encontrar o valor (atual==NULL)
    /// se encontrar >>> atual tem o endereço do elemento para excluir
    /// NULL == false    >>> !false == true
    if(!atual) /// se atual é NULL >> não encontrou
        return false;
    if (!anterior) /// se anterior é igual a NULL
    {
        /// o elemento a ser excluído está no início da lista
        *lista = atual->prox;
    }
    else   /// elemento está no meio ou no fim
    {
        anterior->prox = atual->prox;
    }
    /// libera a memória do elemento
    delete(atual);
    return true;
}


No* buscaL(No **lista, DadoNoLista valor)
{
    No *n = *lista;
    while (n)
    {
        if (n->dado == valor)
            return n;

        n = n->prox;
    }

    return nullptr;
}



bool inserePosicaoL(No **lista, DadoNoLista valor, int posicao)
{
    No *anterior = NULL;
    No *atual = *lista;
    int p = 0;
    while (atual && p!=posicao)
    {
        anterior = atual;
        atual = atual->prox;
        p++;
    }
    if (p != posicao)
        return false; ///significa q não encontrou a posição

    No *novo = new No();
    novo->dado = valor;
    if (!anterior) /// primeira posição
    {
        novo->prox = *lista;
        *lista = novo;
    }
    else
    {
        novo->prox = anterior->prox;
        anterior->prox = novo;
    }

    return true;
}

bool igual(No **lista1, No **lista2)
{
    No *n1 = *lista1;
    No *n2 = *lista2;
    while(n1 && n2){

        if(n1->dado != n2->dado)
            return false;

        n1 = n1->prox;
        n2 = n2->prox;

    }
    if(!n1 && !n2)
        return true;

    return false;
}


void insereFinalL(No **lista, int valor)
{
    No *novo = new No();
    novo->dado = valor;
    novo->prox = NULL;

    No *aux = *lista;

    if(!aux)
    {
        *lista = novo;
    }
    else{
        while(aux->prox){
            aux = aux->prox;
        }
        aux->prox = novo;
    }

}

void insereOrdenadoL(No **lista, int valor)
{

    No *anterior = NULL;
    No *atual = *lista;
    while(atual && atual->dado < valor){
        anterior = atual;
        atual = atual->prox;
    }

    No *novo = new No();
    novo->dado = valor;
    if(!anterior){
        novo->prox = *lista;
        *lista = novo;
    }
    else{
        novo->prox = anterior->prox;
        anterior->prox = novo;
    }

}


int total(No **lista)
{
    int t=0;

    No *n = *lista;
    while (n)
    {
        t++;
        n = n->prox;
    }

    return t;
}


bool lePosicao(No **lista, int posicao, DadoNoLista *valor)
{
    int cont=0;

    No *n = *lista;
    while (n)
    {
        if(cont == posicao)
        {
            *valor = n->dado;
            return true;
        }

        n = n->prox;
        cont++;
    }

    return false;

}



bool removePosicaoL(No **lista, int pos)
{
    No *anterior = nullptr;
    No *atual = *lista;

    int cont=0;
    while(atual && pos != cont)
    {
        anterior = atual;
        atual = atual->prox;
        cont++;
    }
    /// pode sair do laço sem encontrar a posicao (atual==NULL)
    /// se encontrar >>> atual tem o endereço do elemento para excluir
    /// NULL == false    >>> !false == true
    if(!atual) /// se atual é NULL >> não encontrou
        return false;
    if (!anterior) /// se anterior é igual a NULL
    {
        /// o elemento a ser excluído está no início da lista
        *lista = atual->prox;
    }
    else   /// elemento está no meio ou no fim
    {
        anterior->prox = atual->prox;
    }
    /// libera a memória do elemento
    delete(atual);
    return true;
}

void uniao(No **lista1, No **lista2, No **listaSaida)
{
    destroiL(listaSaida);

    No *n = *lista1;
    while (n)
    {
        insereL(listaSaida, n->dado);
        n = n->prox;
    }

    n = *lista2;
    while (n)
    {
        insereL(listaSaida, n->dado);
        n = n->prox;
    }

}

#endif // _HPP_LISTA_DINAMICA









