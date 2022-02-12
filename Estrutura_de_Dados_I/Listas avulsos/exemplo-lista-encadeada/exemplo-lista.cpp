#include <iostream>
using namespace std;

#include "lista.hpp"


int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    int valor, pos;
    No* aux;
    No* lista; //evite usar "list", pois � uma palavra reservada

    inicializaL(&lista);

    cout << "\n\n###TESTE 1\n";
    mostraL(&lista);
    insereL(&lista, 10);
    insereL(&lista, 20);
    insereL(&lista, 30);
    insereL(&lista, 40);
    mostraL(&lista);


    cout << "\n\n###TESTE 2\n";
    mostraL(&lista);
    if(vaziaL(&lista))
        cout << "A lista est� vazia\n";
    else
        cout << "A lista N�O est� vazia\n";


    cout << "\n\n###TESTE 3\n";
    mostraL(&lista);
    cout << "remover o n� com o valor 40, o primeiro elemento (no in�cio da lista)\n";
    removeL(&lista, 40);
    mostraL(&lista);

    cout << "\n\n###TESTE 4\n";
    mostraL(&lista);
    cout << "remover o n� com o valor 20, o segundo elemento (no meio da lista)\n";
    removeL(&lista, 20);
    mostraL(&lista);


    cout << "\n\n###TESTE 5\n";
    mostraL(&lista);
    cout << "remover o n� com o valor 10, o �ltimo elemento (no final da lista)\n";
    removeL(&lista, 10);
    mostraL(&lista);


    cout << "\n\n###TESTE 6\n";
    mostraL(&lista);
    aux = buscaL(&lista, 30);
    if(aux)
        cout << "Um n� com o valor 30 foi encontrado: " << aux->dado << "\n";
    else
        cout << "O valor 30 n�o foi entrado na lista\n";


    cout << "\n\n###TESTE 7\n";
    mostraL(&lista);
    aux = buscaL(&lista, 50);
    if(aux)
        cout << "Um n� com o valor 50 foi encontrado!: " << aux->dado << "\n";
    else
        cout << "O valor 50 n�o foi entrado na lista\n";



    cout << "\n\n###TESTE 8\n";
    mostraL(&lista);
    valor = 60;
    pos = 5;
    if(inserePosicaoL(&lista, valor, pos))
        cout << "O valor " << valor << " foi adicionado na posi��o " << pos << " da sucesso!\n";
    else
        cout << "N�o foi poss�vel adicionar o valor " << valor << " na posi��o " << pos << " da lista!\n";

    mostraL(&lista);


    cout << "\n\n###TESTE 9\n";
    mostraL(&lista);
    valor = 60;
    pos = 1;
    if(inserePosicaoL(&lista, valor, pos))
        cout << "O valor " << valor << " foi adicionado na posi��o " << pos << " da lista com sucesso!\n";
    else
        cout << "N�o foi poss�vel adicionar o valor " << valor << " na posi��o " << pos << " da lista!\n";

    mostraL(&lista);

    cout << "\n\n###TESTE 10\n";
    mostraL(&lista);
    valor = 80;
    pos = 1;
    if(inserePosicaoL(&lista, valor, pos))
        cout << "O valor " << valor << " foi adicionado na posi��o " << pos << " da lista com sucesso!\n";
    else
        cout << "N�o foi poss�vel adicionar o valor " << valor << " na posi��o " << pos << " da lista!\n";

    mostraL(&lista);


    cout << "\n\n###TESTE 11\n";
    mostraL(&lista);
    valor = 90;
    pos = 0;
    if(inserePosicaoL(&lista, valor, pos))
        cout << "O valor " << valor << " foi adicionado na posi��o " << pos << " da lista com sucesso!\n";
    else
        cout << "N�o foi poss�vel adicionar o valor " << valor << " na posi��o " << pos << " da lista!\n";

    mostraL(&lista);


    destroiL(&lista);
    return EXIT_SUCCESS;


}//final do main

