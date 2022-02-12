#ifndef _HPP_FILA_DINAMICA
#define _HPP_FILA_DINAMICA


typedef int DadoNoFila;

struct NoFila
{
    DadoNoFila dado; //informacao do nó
    NoFila *prox; //proximo elemento da fila
};

struct Fila
{
    NoFila *inicio;
    NoFila *fim;

    Fila(){ //Construtor. Usado para inicializar os dados das variáveis da struct
        inicio = nullptr;
        fim = nullptr;
    }
};


///inicialização dos dados da fila
void inicializaF(Fila *f)
{
    //define nulo para o inínio e o fim da fila
    f->inicio = nullptr;
    f->fim = nullptr;
}

bool vaziaF(Fila *f)
{
    if (!f->inicio) //verifica se a fila está vazia, ou seja, (f->inicio == NULL)
        return true;
    else
        return false;
}


//Enqueue
bool enfileiraF(Fila *f, DadoNoFila dado)
{
    NoFila *novo = new NoFila();
    if (!novo) /// não conseguiu alocar memória (novo == NULL)
        return false;

    novo->dado = dado;
    novo->prox = nullptr;
    if (!f->inicio) //verifica se a fila está vazia, ou seja, (f->inicio == NULL)
        f->inicio = novo;
    else
        f->fim->prox = novo;

    f->fim = novo;
    return true;
}

//Dequeue
bool desenfileiraF(Fila *f, DadoNoFila *dado)
{
    // se não estiver vazia, retira valor
    if (f->inicio) //verifica se a fila não está vazia, ou seja, (f->inicio != NULL)
    {
        *dado = f->inicio->dado; //pega o dado armazenado no primeiro nó
        NoFila *apagar = f->inicio; //guarda o primeiro nó em uma variável auxiliar;
        f->inicio = f->inicio->prox; // atualiza o início da fila
        delete apagar;  // libera a memória

        if (!f->inicio) //verifica se a fila está vazia, ou seja, (f->inicio == NULL)
            f->fim = nullptr;

        return true;
    }
    else
        return false;
}

//peek
bool espiaF(Fila* f, DadoNoFila *dado)
{
    if (f->inicio) //verifica se a fila não está vazia, ou seja, (f->inicio != NULL)
    {
        *dado= f->inicio->dado;
        return true;
    }
    else
        return false;
}

//show
void mostraF(Fila *f, string nome)
{
    cout << "Fila " << nome << ": ";

    if(f->inicio) //verifica se a fila não está vazia, ou seja, (f->inicio != NULL)
    {

        cout << "[";

        NoFila *no = f->inicio;
        while (no) //faça enquanto (no != NULL)
        {
            cout << no->dado;
            no = no->prox;

            if(no) //verifica se o próximo nó não é nulo (no != NULL)
                cout << ", ";
        }
        cout << "]" << endl;
    }
    else
        cout << "vazia!\n";
}

// retorna true se o valor existe na fila
// retorna false se o valor não existe na fila
bool buscaF(Fila *f, DadoNoFila dado)
{

    NoFila *no = f->inicio;
    while (no) //faça enquanto (no != NULL)
    {
        if(no->dado == dado)
            return true;

        no = no->prox;
    }

    return false;
}

void destroiF(Fila *f)
{

    NoFila *no = f->inicio;
    while (no) //faça enquanto (no != NULL)
    {
        NoFila *apagar = no; //guarda o nó em uma variável auxiliar;

        no = no->prox;

        delete apagar;
    }

    f->inicio = nullptr;
    f->fim = nullptr;
}




#endif // _HPP_FILA_DINAMICA





