#ifndef _HPP_PILHA_DINAMICA
#define _HPP_PILHA_DINAMICA

#include <iomanip> //biblioteca usada para formatar a impress�o da pilha

typedef int DadoNoPilha;

struct NoPilha
{
    DadoNoPilha dado; //informacao do n�
    NoPilha *prox; //proximo elemento da pilha
};

struct Pilha
{
    NoPilha *topo;

    Pilha(){ //Construtor. Usado para inicializar os dados das vari�veis da struct
        topo = nullptr;
    }
};


///inicializa��o dos dados da pilha
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
    NoPilha *novo =  new NoPilha(); //cria um novo n�
    if (!novo) /// sistema n�o conseguiu alocar a mem�ria
        return false;

    novo->dado = dado; //armazena a informa��o no n�
    novo->prox = p->topo; //o pr�ximo elemento do n� criado ser� o �ltimo elemento da pilha
    p->topo = novo; //atualiza o topo da pilha para o n� criado.
    return true;
}

//pop
bool desempilhaP(Pilha *p, DadoNoPilha *dado)
{
    // se n�o estiver vazia, retira valor
    if (!vaziaP(p))
    {
        *dado = p->topo->dado; //pega o dado armazenado no n� do topo
        NoPilha *apagar = p->topo; //guarda o n� do topo em uma vari�vel auxiliar;
        p->topo = p->topo->prox; //atualiza o topo para o pr�ximo elemento;
        delete apagar;  /// libera a mem�ria
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
        cout << setfill(' ') << std::setw(13) << "N�" << " | ";
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





