#include <iostream>
using namespace std;

#include <cstring>

#include "lista_descritor.hpp"

float mediaSal(Lista *lista);
void imprimirFuncMedia(Lista *lista);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    int contCodigo=0;


    Lista *lista = new Lista();


    cout << "\n\n###TESTE 1\n";
    insereInicioL(lista, Funcionario( ++contCodigo, "João", 20, 1220.50 ));
    insereInicioL(lista, Funcionario( ++contCodigo, "Maria", 21, 1320.70 ));
    cout << "Funcionários[" << lista->tamanho << "]:{" << lista << "}" << endl;


    cout << "\n\n###TESTE 2\n";
    insereFinalL(lista, Funcionario( ++contCodigo, "Pedro", 22, 2520.50 ));
    insereFinalL(lista, Funcionario( ++contCodigo, "Ana", 23, 3620.10 ));
    cout << "Funcionários[" << lista->tamanho << "]:{" << lista << "}" << endl;

    cout << "\n\n###TESTE 3\n";
    insereInicioL(lista, Funcionario( ++contCodigo, "Mario", 24, 1950.20 ));
    cout << "Funcionários[" << lista->tamanho << "]:{" << lista << "}" << endl;


    cout << "\n\n###TESTE 4\n";
    ordenaL(lista);
    cout << "Funcionários[" << lista->tamanho << "]:{" << lista << "}" << endl;

    cout << "\n\n###TESTE 5\n";
    cout << "Salário médio dos funcionários: " << mediaSal(lista) << endl;


    cout << "\n\n###TESTE 6\n";
    cout << "Funcionários com salário menor que a média: ";
    imprimirFuncMedia(lista);
    cout << endl;



    delete(lista); //executa desconstrutor (apaga todos os nós)
    return EXIT_SUCCESS;
}


float mediaSal(Lista *lista)
{
    float media, soma= 0.0f;
    int cont = 0;

    No *n = lista->inicio;
    while (n)
    {
        soma += n->dado.salario;
        cont++;

        n = n->prox;
    }

    if(cont>0) //para evitar divisão por zero
        media = soma / cont;
    else
        media = 0.0f;

    return media;

}

void imprimirFuncMedia(Lista *lista)
{
    float media = mediaSal(lista);

    No *n = lista->inicio;
    while (n)
    {
        if(n->dado.salario < media)
            cout << n->dado.nome << ", ";

        n = n->prox;
    }

}

