#include <iostream>
using namespace std;
#include "lista_dupla.hpp"

No* buscaCod(Lista *lista, int cod)
{
    No *n = lista->inicio;
    while (n)
    {
        if (n->dado.codigo == cod)
            return n;

        n = n->prox;
    }

    return nullptr;
}

bool removeCod(Lista *lista, int cod)
{
    No* no = buscaCod(lista, cod);

    if(!no)
        return false;

    removerNoL(lista, no);

    return true;
}

void mostrar3Ultimos(Lista *lista)
{

    No *no = lista->fim;
    if(no)
    {
        cout << "Último: " << no << endl;
        no = no->ant;
        if(no)
        {
            cout << "Penúltimo : " << no << endl;
            no = no->ant;
            if(no)
            {
                cout << "Antepenúltimo  : " << no << endl;
            }
        }
    }

}


void separaL(float peso, Lista *lista, Lista *L2, Lista *L3)
{
    if(!lista || !L2 || !L3)
        return;

    No *n = lista->inicio;
    while (n)
    {
        Animal animal(n->dado); //cria uma cópia de "n->dado", gravando os dados em "animal", veja o construtor

        if (n->dado.peso <= peso)
            insereInicioL(L2, animal);
        else
            insereInicioL(L3, animal);

        n = n->prox;
    }


}


int main(void)
{
    setlocale(LC_ALL, "Portuguese");



    Lista *lista = new Lista();//executa o construtor (inicializa a lista)....
    Lista *L2 = new Lista();
    Lista *L3 = new Lista();
    int contCodigo=0;



    cout << "\n\n###Inserir\n";
    insereInicioL(lista, Animal( ++contCodigo, 5, 10.0 ));
    insereInicioL(lista, Animal( ++contCodigo, 3, 70.70 ));
    insereInicioL(lista, Animal( ++contCodigo, 2, 30.20 ));
    insereInicioL(lista, Animal( ++contCodigo, 4, 80.10 ));
    insereInicioL(lista, Animal( ++contCodigo, 7, 60.35 ));
    insereInicioL(lista, Animal( ++contCodigo, 9, 25.60 ));
    insereInicioL(lista, Animal( ++contCodigo, 9, 14.60 ));
    cout << "Animais[" << lista->tamanho << "]:{" << lista << "}" << endl;


    cout << "\n\n###Remover pelo código\n";
    int cod = 3;
    if( removeCod(lista, cod) )
        cout << "O animal de código " << cod << " foi removido da lista com sucesso!\n";
    else
        cout << "O animal de código " << cod << " não existe!\n";

    cout << "Animais[" << lista->tamanho << "]:{" << lista << "}" << endl;


    cout << "\n\n###Imprimir na ordem de chegada\n";
    cout << "Animais[" << lista->tamanho << "]:";
    mostrarInversoL(lista);


    cout << "\n\n###Imprimir os três últimos nós da lista\n";
    cout << "Animais[" << lista->tamanho << "]:{" << lista << "}" << endl;
    mostrar3Ultimos(lista);


    cout << "\n\n###Separas a lista\n";
    cout << "Animais[" << lista->tamanho << "]:{" << lista << "}" << endl;
    separaL(50.0, lista, L2, L3); // separa com base no peso do animal (50kg)
    cout << "L2[" << L2->tamanho << "]:{" << L2 << "}" << endl;
    cout << "L3[" << L3->tamanho << "]:{" << L3 << "}" << endl;




    delete(lista); //executa desconstrutor (apaga todos os nós)
    delete(L2);
    delete(L3);
    return EXIT_SUCCESS;
}

