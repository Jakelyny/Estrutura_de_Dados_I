#include <iostream>
#include <ctime>
using namespace std;

void geraDados(float **mat, int tam);
void imprimerMat(float *mat, int l, int c);
void somaMat(int tam, float *matIn1, float *matIn2, float **matOut);
void somaMatVers2(int tam, float *matIn1, float *matIn2, float **matOut);


int main()
{
    setlocale(LC_ALL, "Portuguese");

    srand(time(NULL));

    int c, l, tamM;

    cout << "Informe o número de linhas: ";
    cin >> l;

    cout << "Informe o número de colunas: ";
    cin >> c;

    tamM = l*c;

    float *mat1= new float[tamM];
    float *mat2= new float[tamM];
    float *soma= new float[tamM];
    float *soma2= new float[tamM];

    geraDados(&mat1, tamM);
    geraDados(&mat2, tamM);

    imprimerMat(mat1, l, c);
    imprimerMat(mat2, l, c);

    somaMat(tamM, mat1, mat2, &soma);
    imprimerMat(soma, l, c);

    somaMatVers2(tamM, mat1, mat2, &soma2);
    imprimerMat(soma2, l, c);

    delete[] mat1;
    delete[] mat2;
    delete[] soma;
    delete[] soma2;
}

void geraDados(float **mat, int tam)
{
    for(int i=0; i<tam; i++)
    {
        (*mat)[i] = rand()%9;
    }
}

void imprimerMat(float *mat, int l, int c)
{
    cout << endl;
    for(int linha=0; linha<l; linha++)
    {
        for(int coluna=0; coluna<c; coluna++)
        {
            int indice = linha*c + coluna;
            cout << mat[indice]  << "\t";
        }
        cout << endl;

    }
}


void somaMat(int tam, float *matIn1, float *matIn2, float **matOut)
{
    for(int i=0; i<tam; i++)
    {
        (*matOut)[i] = matIn1[i] + matIn2[i];
    }

}

void somaMatVers2(int tam, float *matIn1, float *matIn2, float **matOut)
{
    float *ptrMatOut = *matOut; //primeiro elemento
    float *ptrMatIn1 = matIn1; //primeiro elemento
    float *ptrMatIn2 = matIn2; //primeiro elemento
    for(int i=0; i<tam; i++)
    {
        *ptrMatOut = *ptrMatIn1 + *ptrMatIn2;

        ptrMatOut++;
        ptrMatIn1++;
        ptrMatIn2++;
    }

}

