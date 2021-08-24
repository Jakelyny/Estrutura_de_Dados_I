#include <iostream>
#include <ctime>
using namespace std;

/*Escreva um programa que solicita ao usuário a quantidade de alunos de uma turma e aloca um vetor de notas
(números reais). Depois de ler as notas, imprime a média aritmética. Obs: não deve ocorrer desperdício de
memória; e após ser utilizada a memória deve ser devolvida.*/

int main(){

    setlocale(LC_ALL, "Portuguese");
    int quant;
    double soma = 0.0;

    cout<<" Defina o número de alunos: ";
    cin>>quant;
    cout<<"_______________________________\n";

    double *vet = new double[quant];
    for(int i = 0; i < quant; i++){
        cout<<"Digite a nota do "<<i+1<<"º aluno: ";
        cin>>vet[i];
        soma += vet[i];
    }
    cout<<"\n-------- NOTAS ---------\n";
    for(int i = 0; i < quant; i++){
        cout<<i+1<<"º aluno: "<<vet[i]<<endl;
    }
    delete[] vet;
    cout<<"------------------------\n";
    cout<<" Média: "<<soma/quant<<endl;
}

