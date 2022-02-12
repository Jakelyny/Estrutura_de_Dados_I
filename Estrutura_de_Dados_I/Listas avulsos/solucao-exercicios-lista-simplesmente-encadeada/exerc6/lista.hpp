#ifndef _HPP_LISTA_DINAMICA
#define _HPP_LISTA_DINAMICA

#include <string>

typedef string DadoNoLista;


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

//insere no in�cio da lista
bool insereL(No **lista, DadoNoLista valor)
{

    No *novo = new No(); // aloca mem�ria para o n�
    if (!novo)
        return false;

    novo->dado = valor;
    novo->prox = *lista;
    *lista = novo;

    return true;
}


int contaNoL(No **lista, DadoNoLista valor)
{
    int cont = 0;

    No *n = *lista;
    while (n)
    {
        if (n->dado == valor)
            cont++;

        n = n->prox;
    }

    return cont;
}

void naoSeguras(No **senhas, No **senhasNS)
{
    destroiL(senhasNS);
    inicializaL(senhasNS);


    No *n = *senhas;
    while (n)
    {
        if(n->dado.size()< 4 || contaNoL(senhas, n->dado) > 5) //verifica se a senha � "n�o segura"
        {
            if(contaNoL(senhasNS, n->dado) == 0) //para n�o inserir senhas repetidas na lista
                insereL(senhasNS, n->dado);
        }

        n = n->prox;
    }
}




bool removeInicioL(No **lista, DadoNoLista *valor)
{
    if(vaziaL(lista))
        return false;

    //pega a referencia do primeiro n� e seu valor
    No *no = *lista;
    *valor = no->dado;

    //atualiza o inicio da lista para o pr�ximo n�
    *lista = no->prox;

    //remove o n�
    delete(no);
    return true;
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










void mostraL(No **lista, string label="L")
{
    No *n = *lista;

    cout << label << ":{";
    while(n) /// enquanto n n�o for NULL fica no la�o
    {
        cout << n->dado;
        n = n->prox;

        if(n)
            cout << ", ";
    }
    cout << "}\n";
}

///remover um valor espec�fico da lista
bool removeL(No **lista, DadoNoLista valor)
{
    No *anterior = nullptr;
    No *atual = *lista;
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
        *lista = atual->prox;
    }
    else   /// elemento est� no meio ou no fim
    {
        anterior->prox = atual->prox;
    }
    /// libera a mem�ria do elemento
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
        return false; ///significa q n�o encontrou a posi��o

    No *novo = new No();
    novo->dado = valor;
    if (!anterior) /// primeira posi��o
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
    /// pode sair do la�o sem encontrar a posicao (atual==NULL)
    /// se encontrar >>> atual tem o endere�o do elemento para excluir
    /// NULL == false    >>> !false == true
    if(!atual) /// se atual � NULL >> n�o encontrou
        return false;
    if (!anterior) /// se anterior � igual a NULL
    {
        /// o elemento a ser exclu�do est� no in�cio da lista
        *lista = atual->prox;
    }
    else   /// elemento est� no meio ou no fim
    {
        anterior->prox = atual->prox;
    }
    /// libera a mem�ria do elemento
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

#endif // _HPP_LISTA_DINAMICA









