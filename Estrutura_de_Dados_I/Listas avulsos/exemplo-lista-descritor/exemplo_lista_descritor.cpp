#include <iostream>
using namespace std;

#include <cstring>


#include "lista_descritor.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");


    int valor, pos;
    No* aux = nullptr;
    Lista *lista = new Lista();//executa o construtor (inicializa a lista)....

    cout << "\n\n###TESTE 1\n";
    cout << "L[" << lista->tamanho << "]:{" << lista << "}" << endl; //mostra a lista
    insereInicioL(lista, 10);
    insereInicioL(lista, 20);
    insereInicioL(lista, 30);
    insereInicioL(lista, 40);
    cout << "L[" << lista->tamanho << "]:{" << lista << "}" << endl;


    cout << "\n\n###TESTE 2\n";
    cout << "L[" << lista->tamanho << "]:{" << lista << "}" << endl;
    if(vaziaL(lista))
        cout << "A lista est� vazia\n";
    else
        cout << "A lista N�O est� vazia\n";


    cout << "\n\n###TESTE 3\n";
    cout << "L[" << lista->tamanho << "]:{" << lista << "}" << endl;
    cout << "remover o n� com o valor 40, o primeiro elemento (no in�cio da lista)\n";
    removeL(lista, 40);
    cout << "L[" << lista->tamanho << "]:{" << lista << "}" << endl;


    cout << "\n\n###TESTE 4\n";
    cout << "L[" << lista->tamanho << "]:{" << lista << "}" << endl;
    cout << "remover o n� com o valor 20, o segundo elemento (no meio da lista)\n";
    removeL(lista, 20);
    cout << "L[" << lista->tamanho << "]:{" << lista << "}" << endl;


    cout << "\n\n###TESTE 5\n";
    cout << "L[" << lista->tamanho << "]:{" << lista << "}" << endl;
    cout << "remover o n� com o valor 10, o �ltimo elemento (no final da lista)\n";
    removeL(lista, 10);
    cout << "L[" << lista->tamanho << "]:{" << lista << "}" << endl;


    cout << "\n\n###TESTE 6\n";
    cout << "L[" << lista->tamanho << "]:{" << lista << "}" << endl;
    aux = buscaL(lista, 30);
    if(aux)
        cout << "Um n� com o valor 30 foi encontrado: " << aux->dado << "\n";
    else
        cout << "O valor 30 n�o foi entrado na lista\n";


    cout << "\n\n###TESTE 7\n";
    cout << "L[" << lista->tamanho << "]:{" << lista << "}" << endl;
    aux = buscaL(lista, 50);
    if(aux)
        cout << "Um n� com o valor 50 foi encontrado!: " << aux->dado << "\n";
    else
        cout << "O valor 50 n�o foi entrado na lista\n";



    cout << "\n\n###TESTE 8\n";
    cout << "L[" << lista->tamanho << "]:{" << lista << "}" << endl;
    valor = 60;
    pos = 5;
    if(inserePosicaoL(lista, valor, pos))
        cout << "O valor " << valor << " foi adicionado na posi��o " << pos << " da sucesso!\n";
    else
        cout << "N�o foi poss�vel adicionar o valor " << valor << " na posi��o " << pos << " da lista!\n";

    cout << "L[" << lista->tamanho << "]:{" << lista << "}" << endl;


    cout << "\n\n###TESTE 9\n";
    cout << "L[" << lista->tamanho << "]:{" << lista << "}" << endl;
    valor = 60;
    pos = 1;
    if(inserePosicaoL(lista, valor, pos))
        cout << "O valor " << valor << " foi adicionado na posi��o " << pos << " da lista com sucesso!\n";
    else
        cout << "N�o foi poss�vel adicionar o valor " << valor << " na posi��o " << pos << " da lista!\n";

    cout << "L[" << lista->tamanho << "]:{" << lista << "}" << endl;


    cout << "\n\n###TESTE 10\n";
    cout << "L[" << lista->tamanho << "]:{" << lista << "}" << endl;
    valor = 80;
    pos = 1;
    if(inserePosicaoL(lista, valor, pos))
        cout << "O valor " << valor << " foi adicionado na posi��o " << pos << " da lista com sucesso!\n";
    else
        cout << "N�o foi poss�vel adicionar o valor " << valor << " na posi��o " << pos << " da lista!\n";

    cout << "L[" << lista->tamanho << "]:{" << lista << "}" << endl;


    cout << "\n\n###TESTE 11\n";
    cout << "L[" << lista->tamanho << "]:{" << lista << "}" << endl;
    valor = 90;
    pos = 0;
    if(inserePosicaoL(lista, valor, pos))
        cout << "O valor " << valor << " foi adicionado na posi��o " << pos << " da lista com sucesso!\n";
    else
        cout << "N�o foi poss�vel adicionar o valor " << valor << " na posi��o " << pos << " da lista!\n";

    cout << "L[" << lista->tamanho << "]:{" << lista << "}" << endl;


    cout << "\n\n###TESTE 12\n";
    cout << "L[" << lista->tamanho << "]:{" << lista << "}" << endl;
    removeL(lista, 90);
    removeL(lista, 30);
    removeL(lista, 60);
    removeL(lista, 80);
    cout << "L[" << lista->tamanho << "]:{" << lista << "}" << endl;
    if(vaziaL(lista))
        cout << "A lista est� vazia\n";
    else
        cout << "A lista N�O est� vazia\n";



    delete(lista); //executa desconstrutor (apaga todos os n�s)
    return EXIT_SUCCESS;
}

