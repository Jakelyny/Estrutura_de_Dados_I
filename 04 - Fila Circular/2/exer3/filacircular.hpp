
#ifndef _HPP_FILA
#define _HPP_FILA

#include <iomanip> //biblioteca usada para formatar a impressão da fila

typedef char DadoNoFila;





struct Fila
{
    int tam; //tamanho do vetor de dados
    int total; //total de elementos armazenados na fila
    int inicio; //ponteiro para o elemento armazenado no inicio da fila
    int fim; //ponteiro para o fim da fila (posição do vetor onde será armazenado o próximo elemento)
    DadoNoFila *dados;//ponteiro para o vetor que será alocado para armazenar os dados

    Fila() //Construtor. Usado para inicializar os dados das variáveis da struct
    {
        tam =0;
        total = 0;
        inicio = 0;
        fim = 0;
        dados = nullptr;
    }
};



void inicializaF(Fila *f, int tam) /// inicialização da fila
{
    f->tam = tam;
    f->inicio = 0;
    f->fim = 0;
    f->total = 0;
    f->dados = new DadoNoFila[tam];/// aloca memória para vetor
}

bool inicializadaF(Fila *f) //verifica de a fila foi inicializada
{
    if(f->dados != NULL)
        return true;
    else
        return false;
}

void destroiF(Fila *f)
{
    f->fim = 0;
    f->inicio = 0;
    f->total = 0;
    f->tam = 0;

    if(f->dados) //f->dados != NULL
    {
        delete[] (f->dados);
        f->dados = nullptr;
    }
}


bool vaziaF(Fila *f)// fila vazia
{
    if (f->total == 0)
        return true;
    else
        return false;
}

bool cheiaF(Fila *f)// fila cheia
{
    if (f->total == f->tam)
        return true;
    else
        return false;
}

//Enqueue
bool enfileiraF(Fila *f, DadoNoFila valor) /// incluir valor na fila
{
    if (!f->dados || cheiaF(f)) // retorna false se a fila não foi inicializada ou se cheia
        return false;

    //inserir no final da fila
    f->dados[f->fim] = valor;

    //incrementa a quantidade de elementos armazenados na fila
    f->total++;

    //avança o ponteiro fim
    f->fim++;

    if(f->fim>=f->tam)
       f->fim = 0; //circular

    return true;
}

//Dequeue
bool desenfileiraF(Fila *f, DadoNoFila *valor)  //retirar da fila
{
    if (!f->dados || vaziaF(f)) // retorna false se a fila não foi inicializada ou se vazia
        return false;

    //remover do inicio da fila
    *valor = f->dados[f->inicio];

    //diminui a quantidade de elementos armazenados na fila
    f->total--;

    //avança o ponteiro início
    f->inicio++;

    if(f->inicio>=f->tam)
       f->inicio = 0; //circular

    return true;
}

//Peek
bool espiarF(Fila *f, DadoNoFila *valor) ///peek
{
    if (!f->dados || vaziaF(f))  // retorna false se a fila não foi inicializada ou se vazia
        return false;

    *valor = f->dados[f->inicio];

    return true;
}

void mostraF(Fila *f)
{
    cout << "\nFila{TAM = " << f->tam << ", TOTAL = " <<  f->total << "} -> ";


    if (!f->dados)  // retorna se a fila não foi inicializada
        return;

    if (!vaziaF(f))
    {
        int idx = f->inicio;
        cout << "[";
        for(int i = 0; i < f->total; i++)
        {
            cout << f->dados[i];

            if(i < f->total-1)
                cout << ", ";

            idx++;
            if(idx >= f->tam)
                idx=0; //circular
        }
        cout << "]\n";
    }else
        cout << "Fila vazia!\n";
}




void mostraVetorFila(Fila *f)
{
    cout << "\nFila{TAM = " << f->tam << ", TOTAL = " <<  f->total;
    cout << ", I = " << f->inicio << ", F = " <<  f->fim << "} -> ";


    if (!f->dados)  // retorna se a fila não foi inicializada
        return;

    //A quantidade de dados armazenados na fila pode ser menor que o tamanho do vetor de dados "f->dados"
    //Assim, o vetor de dados "f->dados" pode conter posições livres quando a fila não está cheia.
    //O vetor "dadosFila[f->tam]" foi usado para determinar se uma posição i do vetor f->dados está livre ou não
    bool dadosFila[f->tam];

    //inicializa o vetor, indicando que que todos as posições do vetor estão livres, ou seja, fila vazia
    for(int i = 0; i < f->tam; i++)
        dadosFila[i] = false;

    //Atribui TRUE para cada posição do vetor de dados que armazena um valor da fila
    int idx = f->inicio;
    for(int i = 0; i < f->total; i++) // FOR percorrendo f->inicio até f->fim
    {
        dadosFila[idx] = true;
        idx++;
        if(idx >= f->tam)
            idx=0; //circular
    }

    //imprimir o vetor, colocando "-" para posições livres
    cout << "[";
    for(int i = 0; i < f->tam; i++)
    {
        //para cada posição não nula do vetor de dados, imprimir o valor do dado
        if(dadosFila[i])
            cout << f->dados[i];
        else
            cout << "-";

        if(i < f->tam-1)
            cout << ", ";
    }
    cout << "]\n";
}


#endif // _HPP_FILA

