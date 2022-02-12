#include <iostream>
#include <ctime>
using namespace std;

//void criarVetor(int **vec, int tam);
void geraDados(int **vec, int tam);
void imprimerVetor(int *vec, int tam);
void imprimerVetorVers2(int *vec, int tam);


int main()
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int *vetor=nullptr, tamVec;

    cout << "Informe o tamanho do vetor: ";
    cin >> tamVec;

    vetor= new int[tamVec];
    //criarVetor(&vetor, tamVec);

    geraDados(&vetor, tamVec);

    imprimerVetor(vetor, tamVec);

    imprimerVetorVers2(vetor, tamVec);


    delete[] vetor;
}

//void criarVetor(int **vec, int tam)
//{
    //*vec= new int[tam];
//}
void geraDados(int **vec, int tam)
{
    for(int i=0; i<tam; i++)
    {
        (*vec)[i] = rand()%100;
    }
}

void imprimerVetor(int *vec, int tam)
{
    cout << "Vetor: ";
    for(int i=0; i<tam; i++)
    {
        cout << vec[i];
        if(i< tam-1)
            cout << ", ";

    }
    cout << endl << endl;
}

void imprimerVetorVers2(int *vec, int tam)
{
    int *ptrVec = vec;

    cout << "Vetor: ";
    for(int i=0; i<tam; i++)
    {
        cout << *ptrVec;
        if(i< tam-1)
            cout << ", ";

        ptrVec++;

    }
    cout << endl << endl;

}

