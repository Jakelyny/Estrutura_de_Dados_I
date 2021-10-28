#include <iostream>
using namespace std;

#include "lista.hpp"


int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    int valor;
    No *senhas, *senhasNS;

    inicializaL(&senhas);
    inicializaL(&senhasNS);

    cout << "\n\n###TESTE 1\n";
    insereL(&senhas, "ABC");
    insereL(&senhas, "BAC");//repetir 4x
    insereL(&senhas, "BAC");
    insereL(&senhas, "BAC");
    insereL(&senhas, "BAC");
    insereL(&senhas, "CAB");//repetir 6x
    insereL(&senhas, "CAB");
    insereL(&senhas, "CAB");
    insereL(&senhas, "CAB");
    insereL(&senhas, "CAB");
    insereL(&senhas, "CAB");
    insereL(&senhas, "ABCD");
    insereL(&senhas, "ABCDE");
    insereL(&senhas, "ABCDEF");//repetir 6x
    insereL(&senhas, "ABCDEF");
    insereL(&senhas, "ABCDEF");
    insereL(&senhas, "ABCDEF");
    insereL(&senhas, "ABCDEF");
    insereL(&senhas, "ABCDEF");
    insereL(&senhas, "ABCDEFG");
    mostraL(&senhas, "Senhas");

    cout << "\n\n###TESTE 2\n";
    naoSeguras(&senhas, &senhasNS);
    mostraL(&senhasNS, "Senhas NS");



    destroiL(&senhas);
    destroiL(&senhasNS);
    return EXIT_SUCCESS;


}//final do main

