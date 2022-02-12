#ifndef _HPP_LISTA_DINAMICA
#define _HPP_LISTA_DINAMICA

typedef int DadoNoLista;

struct No{

    DadoNoLista dado;
    struct No *prox;
};


void inicializaL(No **lista){

    *lista = nullptr;
}

bool vaziaL(No **lista){

    if(!lista)
        return true;
    else
        return false;
}

void destroiL(No **lista){

    No *n = *lista;
    while (n)
    {
        No *aux  = n;
        n = n->prox;
        delete aux;
    }
    *lista = nullptr;
}

bool insereL(No **lista, DadoNoLista valor){

    No *novo = new No();
    if (!novo)
        return false;

    novo->dado = valor;
    novo->prox = *lista;
    *lista = novo;
    return true;
}

void mostraL(No **lista){

    No *n = *lista;
    cout << "L:{";
    while(n){
        cout << n->dado;
        n = n->prox;

        if(n)
            cout << ", ";
    }
    cout << "}\n";
}

bool removeL(No **lista, DadoNoLista valor){

    No *anterior = nullptr;
    No *atual = *lista;
    while(atual && atual->dado != valor){
        anterior = atual;
        atual = atual->prox;
    }
    if(!atual)
        return false;
    if (!anterior){
        *lista = atual->prox;
    }
    else{
        anterior->prox = atual->prox;
    }
    delete(atual);
    return true;
}

No* buscaL(No **lista, DadoNoLista valor){

    No *n = *lista;
    while (n){
        if (n->dado == valor)
            return n;

        n = n->prox;
    }
    return nullptr;
}

bool inserePosicaoL(No **lista, DadoNoLista valor, int posicao){

    No *anterior = NULL;
    No *atual = *lista;
    int p = 0;
    while (atual && p!=posicao){
        anterior = atual;
        atual = atual->prox;
        p++;
    }
    if (p != posicao)
        return false;

    No *novo = new No();
    novo->dado = valor;
    if (!anterior){
        novo->prox = *lista;
        *lista = novo;
    }else{
        novo->prox = anterior->prox;
        anterior->prox = novo;
    }
    return true;
}

#endif









