#include <iostream>
using namespace std;
#include <cstring>
#include <fstream>
#include "lista.hpp"

bool addAmigoL(Lista *listaUsuariosRede, int ID1, int ID2){
    No *usuario1 = buscaL(listaUsuariosRede, ID1);
    No *usuario2 = buscaL(listaUsuariosRede, ID2);

    if(ID1 == ID2){
        return false;
    }
    else if(buscaL(listaUsuariosRede, ID2) && buscaL(listaUsuariosRede, ID1)){
        if(buscaL(usuario1->dado->amigos, ID2)||buscaL(usuario2->dado->amigos, ID1)){
            return false;
        }
        else if(!insereOrdenadoL(usuario1->dado->amigos, usuario2->dado) ||
           !insereOrdenadoL(usuario2->dado->amigos, usuario1->dado)){
            return false;
        }else{
            ofstream escreve("saida.txt", ios::app);
            escreve<<"Os usuários "<<usuario1->dado->nome<<" ("<<usuario1->dado->ID<<") e "<<usuario2->dado->nome<<" ("<<usuario2->dado->ID<<") se tornaram amigos"<<endl;
            escreve.close();

            usuario1->dado->amigos->tamanho++;
            usuario2->dado->amigos->tamanho++;
            return true;
        }
    }else{
        return false;
    }
}

bool removerAmigoL(Lista *listaUsuariosRede, int ID1, int ID2){
    No *usuario1 = buscaL(listaUsuariosRede, ID1);
    No *usuario2 = buscaL(listaUsuariosRede, ID2);

    if(buscaL(listaUsuariosRede, ID2) && buscaL(listaUsuariosRede, ID1)){
        if(removeL(usuario1->dado->amigos, usuario2->dado) && removeL(usuario2->dado->amigos, usuario1->dado)){
            ofstream escreve("saida.txt", ios::app);
            escreve<<"Os usuários "<<usuario1->dado->nome<<" ("<<usuario1->dado->ID<<") e "<<usuario2->dado->nome<<" ("<<usuario2->dado->ID<<") não são mais amigos"<<endl;
            escreve.close();

            usuario1->dado->amigos->tamanho--;
            usuario2->dado->amigos->tamanho--;
            return true;

        }else{
            return false;
        }
    }else{
        return false;
    }
}

bool removerUsuarioRedeL(Lista *listaUsuariosRede, int ID1){
    No *usuario = buscaL(listaUsuariosRede, ID1);

    if(buscaL(listaUsuariosRede, ID1)){
        No *n = usuario->dado->amigos->inicio;
        while (n){
            if(buscaL(listaUsuariosRede, ID1) && buscaL(listaUsuariosRede, n->dado->ID)){
                No *usuario1 = buscaL(listaUsuariosRede, ID1);
                No *usuario2 = buscaL(listaUsuariosRede, n->dado->ID);
                removeL(usuario1->dado->amigos, usuario2->dado);
                removeL(usuario2->dado->amigos, usuario1->dado);
            }
            n=n->prox;
        }
        ofstream escreve("saida.txt", ios::app);
        escreve<<"O usuário "<<usuario->dado->nome<<" ("<<usuario->dado->ID<<") foi excluído da rede."<<endl;
        usuario->dado->amigos->tamanho--;

        removeL(listaUsuariosRede, usuario->dado);
        escreve.close();
        delete usuario;
        return true;
    }else{
        return false;
    }
}

bool imprimirAmigosL(Lista *lista, int ID){
    No *usuario = buscaL(lista, ID);

    if(!buscaL(lista, ID)){
        return false;
    }else{
        ofstream escreve("saida.txt",ios::app);
        escreve<<"Amigos de "<<usuario->dado->nome<<" ("<<usuario->dado->ID<<"): ";
        No *n = usuario->dado->amigos->inicio;
        while(n){
            escreve<<n->dado->nome<<" ("<<n->dado->ID<<") ";
            n = n->prox;
            if(n){
                escreve<<", ";
            }
        }
        escreve<<"\n";
        escreve.close();
        return true;
    }
}

bool imprimirMediaIdadeAmigosL(Lista *lista, int ID){
    No *usuario = buscaL(lista, ID);
    float soma = 0.0, contador = 0;

    if(!buscaL(lista, ID)){
        return false;
    }else{
        ofstream escreve("saida.txt",ios::app);
        escreve<<"Média de idade dos amigos de "<<usuario->dado->nome<<" ("<<usuario->dado->ID<<"): ";
        No *n = usuario->dado->amigos->inicio;
        for(int i = 0; n != nullptr; i++){
            soma += n->dado->idade;
            contador++;
            n = n->prox;
            if(n == nullptr){
                escreve<<(soma/contador);
            }
        }
        escreve<<"\n";
        escreve.close();
        return true;
    }
}

bool imprimirAmigosEmComumL(Lista *lista, int ID1, int ID2, int sexo){
    if(ID1 == ID2){
            return false;
    }else if(buscaL(lista, ID2) || buscaL(lista, ID1)){
        No *usuario1 = buscaL(lista, ID1);
        No *usuario2 = buscaL(lista, ID2);
        No *listaAmigos1 = usuario1->dado->amigos->inicio;
        No *listaAmigos2 = usuario2->dado->amigos->inicio;

        ofstream escreve("saida.txt",ios::app);
        switch(sexo)
        {
            case 2:
                escreve<<"Amigos em comum entre "<<usuario1->dado->nome<<" ("<<usuario1->dado->ID<<") e "<<usuario2->dado->nome<<" ("<<usuario2->dado->ID<<") (todos os sexos): ";
                while(listaAmigos1){
                    listaAmigos2 = usuario2->dado->amigos->inicio;
                    while(listaAmigos2){
                        if((listaAmigos1->dado->ID == listaAmigos2->dado->ID)){
                            escreve<<listaAmigos1->dado->nome<<" ("<<listaAmigos1->dado->ID<<") ";
                            if(listaAmigos1){
                                escreve<<", ";
                            }
                        }
                         listaAmigos2 = listaAmigos2->prox;
                    }
                    listaAmigos1 = listaAmigos1->prox;
                }
                listaAmigos1 = usuario1->dado->amigos->inicio;
                listaAmigos2 = usuario2->dado->amigos->inicio;
                escreve<<"\n";
                return true;
                break;

            case 1:
                escreve<<"Amigos em comum entre "<<usuario1->dado->nome<<" ("<<usuario1->dado->ID<<") e "<<usuario2->dado->nome<<" ("<<usuario2->dado->ID<<") (sexo feminino): ";
                while(listaAmigos1){
                    listaAmigos2 = usuario2->dado->amigos->inicio;
                    while(listaAmigos2){
                        if((listaAmigos1->dado->ID == listaAmigos2->dado->ID) && (listaAmigos1->dado->sexo == 1) && (listaAmigos2->dado->sexo == 1)){
                            escreve<<listaAmigos1->dado->nome<<" ("<<listaAmigos1->dado->ID<<") ";
                            if(listaAmigos1){
                                escreve<<", ";
                            }
                        }
                         listaAmigos2 = listaAmigos2->prox;
                    }
                    listaAmigos1 = listaAmigos1->prox;
                }
                listaAmigos1 = usuario1->dado->amigos->inicio;
                listaAmigos2 = usuario2->dado->amigos->inicio;
                escreve<<"\n";
                return true;
                break;

            case 0:
                escreve<<"Amigos em comum entre "<<usuario1->dado->nome<<" ("<<usuario1->dado->ID<<") e "<<usuario2->dado->nome<<" ("<<usuario2->dado->ID<<") (sexo masculino): ";
                while(listaAmigos1){
                    listaAmigos2 = usuario2->dado->amigos->inicio;
                    while(listaAmigos2){
                        if((listaAmigos1->dado->ID == listaAmigos2->dado->ID) && (listaAmigos1->dado->sexo == 0) && (listaAmigos2->dado->sexo == 0)){
                            escreve<<listaAmigos1->dado->nome<<" ("<<listaAmigos1->dado->ID<<") ";
                            if(listaAmigos1){
                                escreve<<", ";
                            }
                        }
                         listaAmigos2 = listaAmigos2->prox;
                    }
                    listaAmigos1 = listaAmigos1->prox;
                }
                listaAmigos1 = usuario1->dado->amigos->inicio;
                listaAmigos2 = usuario2->dado->amigos->inicio;
                escreve<<"\n";
                return true;
                break;

        }
        escreve.close();
    }else{
        return false;
    }
}

int main(void){

    setlocale(LC_ALL, "Portuguese");
    Lista *listaUsuariosRede = new Lista();
    ifstream ler("entrada.txt", ios::in);
    string leitura;

    while (!ler.fail()){
        ler>>leitura;
        if(leitura == "addUsuario"){
            int ID;
            int idade;
            int sexo;
            string nome;
            ler>>ID;
            ler>>idade;
            ler>>sexo;
            ler>>nome;

            Usuario *novoUsr = new Usuario(ID, idade, sexo, nome);
            if(!buscaL(listaUsuariosRede, ID)){
                ofstream escreve("saida.txt", ios::app);
                escreve<<"O usuário "<<nome<<" ("<<ID<<") foi adicionado na rede."<<endl;
                escreve.close();
                insereOrdenadoL(listaUsuariosRede, novoUsr);
            }else{
                ofstream escreve("saida.txt", ios::app);
                escreve<<"Erro ao adicionar o usuário "<<nome<<" ("<<ID<<"). O ID 30 já existe!"<<endl;
                escreve.close();

            }
        }else if(leitura == "addAmigo"){
            int ID1;
            int ID2;
            ler>>ID1;
            ler>>ID2;
            if(addAmigoL(listaUsuariosRede, ID1, ID2) == false){
                ofstream escreve("saida.txt", ios::app);
                escreve<<"Erro ao criar amizade dos usuários com IDs "<<ID1<<" e "<<ID2<<"!"<<endl;
                escreve.close();

            }
        }else if(leitura == "removerAmigo"){
            int ID1;
            int ID2;
            ler>>ID1;
            ler>>ID2;
            if(removerAmigoL(listaUsuariosRede, ID1, ID2) == false){
                ofstream escreve("saida.txt", ios::app);
                escreve<<"Erro ao remover a amizade. Não existe amizade entre os usuários com IDs "<<ID1<<" e "<<ID2<<"!"<<endl;
                escreve.close();

            }
        }else if(leitura == "removerUsuario"){
            int ID1;
            ler>>ID1;
            if(removerUsuarioRedeL(listaUsuariosRede, ID1) == false){
                ofstream escreve("saida.txt", ios::app);
                escreve<<"Erro ao excluir o usuário com ID "<<ID1<<". O usuário não existe!"<<endl;
                escreve.close();

            }
        }else if(leitura == "imprimirUsuarios"){
            imprimirUsuariosL(listaUsuariosRede);

        }else if(leitura == "imprimirAmigos"){
            int ID;
            ler>>ID;
            if(imprimirAmigosL(listaUsuariosRede, ID) == false){
                ofstream escreve("saida.txt", ios::app);
                escreve<<"Erro ao imprimir amigos do usuário com ID "<<ID<<". O usuário não existe!"<<endl;
                escreve.close();

            }
        }else if(leitura == "imprimirMediaIdadeAmigos"){
            int ID;
            ler>>ID;
            if(imprimirMediaIdadeAmigosL(listaUsuariosRede, ID) == false){
                ofstream escreve("saida.txt", ios::app);
                escreve<<"Erro ao imprimir a média de idade dos amigos do usuário com ID "<<ID<<"!"<<endl;
                escreve.close();

            }
        }else if(leitura =="imprimirAmigosEmComum"){
            int ID1;
            int ID2;
            int sexo;
            ler>>ID1;
            ler>>ID2;
            ler>>sexo;

            if(imprimirAmigosEmComumL(listaUsuariosRede ,ID1, ID2, sexo) == false){
                ofstream escreve("saida.txt", ios::app);
                escreve<<"Erro ao imprimir amigos em comum dos usuários com IDs "<<ID1<<" e "<<ID2<<"!"<<endl;
                escreve.close();

            }
        }
    }
    delete listaUsuariosRede;
    return EXIT_SUCCESS;
}


