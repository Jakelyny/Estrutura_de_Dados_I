#include <iostream>
#include <ctime>
using namespace std;

/* Faça um programa que crie dinamicamente um vetor de n elementos e passe esse vetor para uma função que
vai ler os elementos desse vetor. Depois, no programa principal (main), o vetor preenchido deve ser impresso.
Além disso, antes de finalizar o programa, deve-se liberar a área de memória alocada.*/

void criaVetor(int quant, int *vet);

int main(){

    setlocale(LC_ALL, "Portuguese");
    int quant;
    double soma = 0.0;

    cout<<"Informe o tamanho do vetor: ";
    cin>>quant;
    cout<<"____________________________\n";

    int *vet = new int[quant];
    criaVetor(quant, vet);

    for(int i = 0; i < quant; i++){
        cout<<i+1<<"º valor: "<<vet[i]<<endl;
    }
    delete[] vet;
    cout<<"------------------------\n";
}

void criaVetor(int quant, int *vet){
    int i = 0;
    for(i; i < quant; i++){
        cout<<"Agora digite o "<<i+1<<"º valor: ";
        cin>>*vet;
        vet++;
    }
    vet -= i;
    cout<<"\n------------------------\n";
}
