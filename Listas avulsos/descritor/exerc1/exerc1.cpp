#include <iostream>
using namespace std;

#include <cstring>


#include "lista_descritor.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");



    Lista *lista = new Lista();
    mostraDescritorL(lista);
    insereInicioL(lista, 10);
    insereInicioL(lista, 20);
    insereInicioL(lista, 30);
    insereInicioL(lista, 50);
    mostraDescritorL(lista);
    cout << "L[" << lista->tamanho << "]:{" << lista << "}" << endl;


    delete(lista); //executa desconstrutor (apaga todos os nós)
    return EXIT_SUCCESS;
}

