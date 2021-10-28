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

bool igual(No **lista1, No **lista2){

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

void insereOrdenadoL(No **lista, int valor){

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

void insereFinalL(No **lista, int valor){

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

int total(No **lista){

    int t=0;
    No *n = *lista;
    while (n)
    {
        t++;
        n = n->prox;
    }

    return t;
}

bool lePosicao(No **lista, int posicao, DadoNoLista *valor){

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

bool removePosicaoL(No **lista, int pos){

    No *anterior = nullptr;
    No *atual = *lista;

    int cont=0;
    while(atual && pos != cont)
    {
        anterior = atual;
        atual = atual->prox;
        cont++;
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

void uniao(No **lista1, No **lista2, No **listaSaida)
{
    destroiL(listaSaida);

    No *n = *lista1;
    while (n){

        insereL(listaSaida, n->dado);
        n = n->prox;
    }

    n = *lista2;
    while (n){

        insereL(listaSaida, n->dado);
        n = n->prox;
    }

}

bool verificarOrdem(No **lista){
    No *n = *lista;
    No *aux = new No();
    inicializaL(&aux);

    if(n){
        insereL(&aux, n->dado);
        n = n->prox;
        if(n->dado <= aux->dado){
            aux = aux->prox;
            insereL(&aux, n->dado);
            n = n->prox;
            while(n){
                if(n->dado >= aux->dado){
                    return false;
                }
                aux = aux->prox;
                insereL(&aux, n->dado);
                n = n->prox;
            }
        } else if(n->dado >= aux->dado){
            aux = aux->prox;
            insereL(&aux, n->dado);
            n = n->prox;
            while(n){
                if(n->dado <= aux->dado){
                    return false;
                }
                aux = aux->prox;
                insereL(&aux, n->dado);
                n = n->prox;
            }
        }
    }
    return true;
}
#endif









