#ifndef _HPP_LISTA
#define _HPP_LISTA
#include <string>
#include <iostream>


struct Usuario;
struct No{

    Usuario *dado;
    No *prox;

    No(){

        dado = nullptr;
        prox = nullptr;
    }
};

struct Lista{

    No* inicio;
    No* fim;
    int tamanho;
    Lista(){

        inicio = nullptr;
        fim = nullptr;
        tamanho = 0;
    }
    ~Lista(){

        No *n = inicio;
        while(n){

            No *aux = n;
            n = n->prox;

            delete aux;
        }
        inicio = nullptr;
        fim = nullptr;
        tamanho = 0;
    }
};

struct Usuario{

    int ID;
    int idade;
    int sexo;
    std::string nome;
    Lista *amigos;


    Usuario(int id, int ida, int sx, string nm){

        ID = id;
        idade = ida;
        sexo = sx;
        nome =  nm;
        amigos = new Lista();
    }

    Usuario(){

        ID = 0;
        idade = 0;
        sexo = 0;
        nome =  "";
        amigos = nullptr;
    }

    ~Usuario(){

        if(amigos)
            delete amigos;

        amigos = nullptr;

        ID = 0;
        idade = 0;
        sexo = 0;
        nome =  "";
        amigos = nullptr;
    }
};

bool insereOrdenadoL(Lista *lista, Usuario *valor){

    No *anterior = nullptr;
    No *atual = lista->inicio;
    while(atual && atual->dado->ID<=valor->ID){
        anterior = atual;
        atual = atual->prox;
    }
    No *novo = new No();
    if (!novo)
        return false;

    novo->dado=valor;
    if (!anterior){
        novo->prox=lista->inicio;
        lista->inicio=novo;
        if (!lista->fim)
            lista->fim=lista->inicio;
    }else{
        novo->prox=anterior->prox;
        anterior->prox=novo;
    }
    return true;
}

void imprimirUsuariosL(Lista *lista){
    No *n = lista->inicio;
    ofstream escreve("saida.txt", ios::app);
    escreve<<"Usuários da rede: ";
    while(n){
        escreve<<n->dado->nome<<" ("<<n->dado->ID<<")";
        n = n->prox;

        if(n)
            escreve<<", ";
    }
    escreve<<"\n";
    escreve.close();
}

No* buscaL(Lista *lista, int valor){

    No *n = lista->inicio;
    while (n)
    {
        if (n->dado->ID==valor)
            return n;

        n = n->prox;
    }

    return nullptr;
}

bool removeL(Lista *lista, Usuario *valor){

    No *anterior = nullptr;
    No *atual = lista->inicio;
    while(atual && atual->dado->ID != valor->ID){
        anterior=atual;
        atual=atual->prox;
    }
    if(!atual)
        return false;
    if(!anterior){
        lista->inicio=atual->prox;
        if(!lista->inicio)
            lista->fim=lista->inicio;

    }else{
        anterior->prox=atual->prox;
        if(!atual->prox){
            lista->fim=anterior;
        }
    }
    lista->tamanho--;
    delete(atual);
    return true;
}




#endif
































