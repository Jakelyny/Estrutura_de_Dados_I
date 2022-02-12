#ifndef _HPP_FILA_DINAMICA
#define _HPP_FILA_DINAMICA


typedef int DadoNoFila;

struct NoFila{
    DadoNoFila dado;
    NoFila *prox;
};

struct Fila{
    NoFila *inicio;
    NoFila *fim;

    Fila(){
        inicio = nullptr;
        fim = nullptr;
    }
};

void inicializaF(Fila *f){

    f->inicio = nullptr;
    f->fim = nullptr;
}

bool vaziaF(Fila *f){
    if (!f->inicio)
        return true;
    else
        return false;
}

bool enfileiraF(Fila *f, DadoNoFila dado){
    NoFila *novo = new NoFila();
    if (!novo)
        return false;

    novo->dado = dado;
    novo->prox = nullptr;
    if (!f->inicio)
        f->inicio = novo;
    else
        f->fim->prox = novo;

    f->fim = novo;
    return true;
}

bool desenfileiraF(Fila *f, DadoNoFila *dado){

    if (f->inicio){
        *dado = f->inicio->dado;
        NoFila *apagar = f->inicio;
        f->inicio = f->inicio->prox;
        delete apagar;

        if (!f->inicio)
            f->fim = nullptr;

        return true;
    }
    else
        return false;
}

bool espiaF(Fila* f, DadoNoFila *dado){
    if (f->inicio){
        *dado= f->inicio->dado;
        return true;
    }
    else
        return false;
}

void mostraF(Fila *f){
    cout << "Fila: ";

    if(f->inicio){
        cout << "[";

        NoFila *no = f->inicio;
        while (no){
            cout << no->dado;
            no = no->prox;

            if(no)
                cout << ", ";
        }
        cout << "]" << endl;
    }
    else
        cout << "vazia!\n";
}

bool buscaF(Fila *f, DadoNoFila dado){

    NoFila *no = f->inicio;
    while (no){
        if(no->dado == dado)
            return true;
        no = no->prox;
    }

    return false;
}

void destroiF(Fila *f){

    NoFila *no = f->inicio;
    while (no)
    {
        NoFila *apagar = no;

        no = no->prox;

        delete apagar;
    }

    f->inicio = nullptr;
    f->fim = nullptr;
}

#endif
