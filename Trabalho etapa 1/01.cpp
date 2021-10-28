#include <bits/stdc++.h>
#include "01_funcoes.hpp"
#include "01_estruturas.hpp"
#include "01_fila_pessoas.hpp"
#include "01_fila_empresas.hpp"
#include "01_pilha_doacao.hpp"
#include "01_pilha_objetos.hpp"
using namespace std;

main(){
    setlocale(LC_ALL, "Portuguese");
    char menu;
    FilaPessoa filaPessoa;
    inicializaFpessoa(&filaPessoa);
    FilaPessoa filaPessoaPrioritaria;
    inicializaFpessoa(&filaPessoaPrioritaria);
    FilaEmpresa filaEmpresa;
    inicializaFempresa(&filaEmpresa);
    FilaEmpresa filaEmpresaPrioritaria;
    inicializaFempresa(&filaEmpresaPrioritaria);
    PilhaFichaDoacaoObjetos pilhaFichaDoacaoObjetos;
    inicializaFichaDoacaoObjetos(&pilhaFichaDoacaoObjetos);
    PilhaObjeto pilhaLivros;
    inicializaObjeto(&pilhaLivros);
    PilhaObjeto pilhaEquipamentos;
    inicializaObjeto(&pilhaEquipamentos);

    do{
        system("cls");
        cout<<" ******************************** MENU *************************************"<<endl;
        cout<<" | a - Incluir pessoa na fila de doação                                    |"<<endl;
        cout<<" | b - Incluir empresa na fila de retirada                                 |"<<endl;
        cout<<" | c - Atender uma pessoa da fila                                          |"<<endl;
        cout<<" | d - Atender uma empresa da fila                                         |"<<endl;
        cout<<" | e - Listar todas as pessoas das filas                                   |"<<endl;
        cout<<" | f - Listar todas as empresas das filas                                  |"<<endl;
        cout<<" | g - Listar informações sobre as filas de pessoas de forma unificada     |"<<endl;
        cout<<" | h - Listar informações sobre as filas de empresas de forma unificada    |"<<endl;
        cout<<" | i - Listar o estoque de equipamentos na ordem em que eles foram doados  |"<<endl;
        cout<<" | j - Listar o estoque de livros na ordem em que eles foram doados        |"<<endl;
        cout<<" | k - Listar todas as doações já recebidas pela ONG                       |"<<endl;
        cout<<" | l - Verificar o número de doações realizadas por um determinado CPF     |"<<endl;
        cout<<" | m - Listar todas as retiradas realizadas                                |"<<endl;
        cout<<" | n - Encerrar programa                                                   |"<<endl;
        cout<<" ***************************************************************************"<<endl;
        cout<<"\nDigite a opção desejada: ";
        cin>>menu;
        fflush(stdin);
        switch(menu){
            case 'a':
                system("cls");
                incluirPessoa(&filaPessoa, &filaPessoaPrioritaria);
                getchar();
                break;
            case 'b':
                system("cls");
                incluirEmpresa(&filaEmpresa, &filaEmpresaPrioritaria);
                getchar();
                break;
            case 'c':
                system("cls");
                atenderPessoa(&filaPessoa, &pilhaFichaDoacaoObjetos, &pilhaLivros, &pilhaEquipamentos, &filaPessoaPrioritaria);
                getchar();
                break;
            case 'd':
                system("cls");
                atenderEmpresa(&filaEmpresa, &filaEmpresaPrioritaria, &pilhaLivros, &pilhaEquipamentos);
                getchar();
                break;
            case 'e':
                system("cls");
                mostrarPessoas(&filaPessoa, &filaPessoaPrioritaria);
                getchar();
                break;
            case 'f':
                system("cls");
                mostrarEmpresas(&filaEmpresa, &filaEmpresaPrioritaria);
                getchar();
                break;
            case 'g':
                system("cls");
                contagemUnificadaPessoas();
                getchar();
                break;
            case 'h':
                system("cls");
                contagemUnificadaEmpresas();
                getchar();
                break;
            case 'i':
                system("cls");
                cout<<"ESTOQUE DE EQUIPAMENTOS EM ORDEM DE DOAÇÃO: "<<endl;
                imprimeEstoque(&pilhaEquipamentos);
                getchar();
                break;
            case 'j':
                system("cls");
                cout<<"ESTOQUE DE LIVROS EM ORDEM DE DOAÇÃO: "<<endl;
                imprimeEstoque(&pilhaLivros);
                getchar();
                break;
            case 'k':
                system("cls");
                listarDoacoesRecebidas();
                getchar();
                break;
            case 'l':
                system("cls");
                verificarDoacoesCPF();
                getchar();
                break;
            case 'm':
                system("cls");
                listarRetiradas();
                getchar();
                break;
            case 'n':
                system("cls");
                cout<<"\n\n\t ENCERRANDO PROGRAMA..."<<endl;
                getchar();
                break;
        }
    }while(menu != 'n');
}



