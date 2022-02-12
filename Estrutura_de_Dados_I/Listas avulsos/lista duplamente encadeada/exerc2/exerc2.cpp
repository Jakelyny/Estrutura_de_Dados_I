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
    insereFimL(lista, 10);
    insereFimL(lista, 20);
    insereFimL(lista, 30);
    insereFimL(lista, 31);
    cout << "L[" << lista->tamanho << "]:{" << lista << "}" << endl;


    cout << "\n\n###TESTE 2\n";
    cout << "L[" << lista->tamanho << "]:{" << lista << "}" << endl; //mostra a lista
    removeFimL(lista);
    cout << "L[" << lista->tamanho << "]:{" << lista << "}" << endl;


    cout << "\n\n###TESTE 3\n";
    cout << "L[" << lista->tamanho << "]:{" << lista << "}" << endl; //mostra a lista
    removeInicioL(lista);
    cout << "L[" << lista->tamanho << "]:{" << lista << "}" << endl;


    cout << "\n\n###TESTE 4\n";
    cout << "L[" << lista->tamanho << "]:{" << lista << "}" << endl; //mostra a lista
    removeInicioL(lista);
    removeInicioL(lista);
    cout << "L[" << lista->tamanho << "]:{" << lista << "}" << endl;


    cout << "\n\n###TESTE 5\n";
    cout << "L[" << lista->tamanho << "]:{" << lista << "}" << endl; //mostra a lista
    insereFimL(lista, 10);
    insereFimL(lista, 20);
    cout << "L[" << lista->tamanho << "]:{" << lista << "}" << endl;


     cout << "\n\n###TESTE 6\n";
    cout << "L[" << lista->tamanho << "]:{" << lista << "}" << endl; //mostra a lista
    removeFimL(lista);
    removeFimL(lista);
    cout << "L[" << lista->tamanho << "]:{" << lista << "}" << endl;



    delete(lista); //executa desconstrutor (apaga todos os nós)
    return EXIT_SUCCESS;
}

