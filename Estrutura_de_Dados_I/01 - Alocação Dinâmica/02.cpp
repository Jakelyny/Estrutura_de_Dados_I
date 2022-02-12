#include <iostream>
#include <ctime>
using namespace std;

/*Escreva um programa que solicita ao usu�rio a quantidade de alunos de uma turma e aloca um vetor de notas
(n�meros reais). Depois de ler as notas, imprime a m�dia aritm�tica. Obs: n�o deve ocorrer desperd�cio de
mem�ria; e ap�s ser utilizada a mem�ria deve ser devolvida.*/

int main(){

    setlocale(LC_ALL, "Portuguese");
    int quant;
    double soma = 0.0;

    cout<<" Defina o n�mero de alunos: ";
    cin>>quant;
    cout<<"_______________________________\n";

    double *vet = new double[quant];
    for(int i = 0; i < quant; i++){
        cout<<"Digite a nota do "<<i+1<<"� aluno: ";
        cin>>vet[i];
        soma += vet[i];
    }
    cout<<"\n-------- NOTAS ---------\n";
    for(int i = 0; i < quant; i++){
        cout<<i+1<<"� aluno: "<<vet[i]<<endl;
    }
    delete[] vet;
    cout<<"------------------------\n";
    cout<<" M�dia: "<<soma/quant<<endl;
}

