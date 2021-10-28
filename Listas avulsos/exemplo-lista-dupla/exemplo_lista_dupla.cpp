#include <iostream>
using namespace std;
#include "lista_dupla.hpp"

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
    insereInicioL(lista, 31);
    insereInicioL(lista, 32);
    insereInicioL(lista, 33);
    insereInicioL(lista, 34);
    insereInicioL(lista, 40);
    cout << "L[" << lista->tamanho << "]:{" << lista << "}" << endl;


    cout << "\n\n###TESTE 2\n";
    mostrarInversoL(lista);


    cout << "\n\n###TESTE 3\n";
    cout << "L[" << lista->tamanho << "]:{" << lista << "}" << endl;
    if(vaziaL(lista))
        cout << "A lista est� vazia\n";
    else
        cout << "A lista N�O est� vazia\n";


    cout << "\n\n###TESTE 4\n";
    cout << "L[" << lista->tamanho << "]:{" << lista << "}" << endl;
    cout << "remover o n� com o valor 40, o primeiro elemento (no in�cio da lista)\n";
    removeL(lista, 40);
    cout << "L[" << lista->tamanho << "]:{" << lista << "}" << endl;


    cout << "\n\n###TESTE 5\n";
    cout << "L[" << lista->tamanho << "]:{" << lista << "}" << endl;
    cout << "remover o n� com o valor 33, o segundo elemento (no meio da lista)\n";
    removeL(lista, 33);
    cout << "L[" << lista->tamanho << "]:{" << lista << "}" << endl;

    cout << "\n\n###TESTE 6\n"; //para testar os ponteiros, ant e prox, vamos impremir a lista de v�rias formas..
    cout << "L[" << lista->tamanho << "]:{" << lista << "}" << endl;
    mostrarInversoL(lista);

    cout << "\n\n###TESTE 7\n";
    cout << "L[" << lista->tamanho << "]:{" << lista << "}" << endl;
    cout << "remover o n� com o valor 10, o �ltimo elemento (no final da lista)\n";
    removeL(lista, 10);
    cout << "L[" << lista->tamanho << "]:{" << lista << "}" << endl;


    cout << "\n\n###TESTE 8\n";
    cout << "L[" << lista->tamanho << "]:{" << lista << "}" << endl;
    aux = buscaL(lista, 30);
    if(aux)
        cout << "Um n� com o valor 30 foi encontrado!\n";
    else
        cout << "O valor 30 n�o foi entrado na lista\n";


    cout << "\n\n###TESTE 9\n";
    cout << "L[" << lista->tamanho << "]:{" << lista << "}" << endl;
    aux = buscaL(lista, 31);
    if(aux)
    {
        removerNoL(lista, aux);
        cout << "Um n� com o valor 31 foi encontrado e removido!\n";
    }
    else
        cout << "O valor 31 n�o foi entrado na lista\n";

    cout << "L[" << lista->tamanho << "]:{" << lista << "}" << endl;
    mostrarInversoL(lista);


    delete(lista); //executa desconstrutor (apaga todos os n�s)
    return EXIT_SUCCESS;
}

