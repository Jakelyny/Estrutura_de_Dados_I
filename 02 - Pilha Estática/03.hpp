#ifndef _HPP_PILHA_DUPLA
#define _HPP_PILHA_DUPLA
#include <iomanip>

enum PILHA_IDX{
    PILHA_1,
    PILHA_2
};

struct Pilha{
    int tam;
    int base1;
    int topo1;
    int base2;
    int topo2;
    int *dados;

    Pilha(){
        tam=0;
        base1 = -1;
        topo1 = -1;
        base2 = 0;
        topo2 = 0;
        dados = NULL;
    }
};

bool inicializada(Pilha *p){

    if(p->dados != NULL){
        return true;
    }else{
        return false;
    }
}

void inicializa(Pilha *p, int tam){

    p->base1 = -1;
    p->topo1 = -1;
    p->base2 = tam;
    p->topo2 = tam;
    p->tam  =  tam;
    p->dados = new int[tam];
}

void desalocar(Pilha *p){

    p->base1 = -1;
    p->topo1 = -1;
    p->base2 = 0;
    p->topo2 = 0;
    p->tam = 0;
    if(p->dados != NULL){
        delete[] (p->dados);
        p->dados = NULL;
    }
}

bool cheia(Pilha *p){

    if (p->topo1 == p->tam - 1 || p->topo2 == 0 || abs(p->topo1 - p->topo2) == 1){
        return true;
    }else{
        return false;
    }
}

bool vazia(Pilha *p, int indicePilha){

    if(indicePilha == PILHA_1 && p->topo1 == p->base1){
        return true;
    }if(indicePilha == PILHA_2 && p->topo2 == p->base2){
        return true;
    }else{
        return false;
    }
}

bool empilhar(Pilha *p, int indicePilha, int valor){

    if (p->dados == NULL || cheia(p)){
        return false;
    }else{
        if(indicePilha == PILHA_1){
            p->topo1++;
            p->dados[p->topo1] = valor;
        }else if(indicePilha == PILHA_2){
            p->topo2--;
            p->dados[p->topo2] = valor;
        }else{
            return false;
        }
    }
    return true;
}

bool desempilhar(Pilha *p, int indicePilha, int *valor){

    if (p->dados != NULL && !vazia(p, indicePilha)){
        if(indicePilha == PILHA_1){
            *valor = p->dados[p->topo1];
            p->topo1--;
        }else if(indicePilha == PILHA_2){
            *valor = p->dados[p->topo2];
            p->topo2++;
        }else{
            return false;
        }
    }else{
        return false;
    }
    return true;
}

void mostrar(Pilha *p, int indicePilha){

    if (p->dados == NULL){
        return;
    }if(indicePilha == PILHA_1){
        cout << "PILHA 1: " << endl;
        cout << "TAM VETOR: " << p->tam << endl;
        cout << "TOPO: " << p->topo1 << endl;
        cout << "   ------------" << endl;
        for(int i = p->topo1; i > p->base1; i--){
            cout << setfill(' ') << std::setw(3) << i << "|";
            cout << setfill(' ') << std::setw(10) << p->dados[i] << "|" << endl;
            cout << "   ------------" << endl;
        }
    }
    else if(indicePilha == PILHA_2){
        cout << "PILHA 2: " << endl;
        cout << "TAM VETOR: " << p->tam << endl;
        cout << "TOPO: " << p->topo2 << endl;
        cout << "   ------------" << endl;
        for(int i = p->topo2; i < p->base2; i++){
            cout << setfill(' ') << std::setw(3) << i << "|";
            cout << setfill(' ') << std::setw(10) << p->dados[i] << "|" << endl;
            cout << "   ------------" << endl;
        }
    }
}

#endif

