#include <iostream>

using namespace std;


int main()
{
    setlocale(LC_ALL, "Portuguese");

    float *notas, media=0;
    int nAlunos;

    cout << "Informe o n�mero de alunos: ";
    cin >> nAlunos;

    notas= new float[nAlunos];
    for(int i=0; i<nAlunos; i++)
    {
        cout << "\nInforme a nota do aluno n� " << i+1 << ": ";
        cin >> notas[i];

        media += notas[i];
    }

    media /= nAlunos;

    cout << "\nM�dia: " << media << endl;

    delete[] notas;
}

