#ifndef _HPP_FUNCIONARIO
#define _HPP_FUNCIONARIO

#include <cstring>
#include <string>
#include <iostream>


struct Animal
{
    int codigo;
    int idade;
    float peso;
    Animal() // construtor
    {
        codigo = 0;
        idade = 0;
        peso = 0.0f;
    }

    Animal(int cod, int ida, float pes) // construtor
    {
        codigo = cod;
        idade = ida;
        peso = pes;
    }

    Animal(const Animal &a) // construtor, cria um cópia
    {
        codigo = a.codigo;
        idade = a.idade;
        peso = a.peso;
    }

    //operadores usados na busca e remoção de nós
    bool operator!=(const Animal& a)
    {
        if(codigo != a.codigo)
            return true;
        if(idade != a.idade)
            return true;
        if(peso != a.peso)
            return true;

        return false;
    }

    bool operator==(const Animal& a)
    {
        if(codigo != a.codigo)
            return false;
        if(idade != a.idade)
            return false;
        if(peso != a.peso)
            return false;

        return true;
    }



};


/// quando cout receber uma struct No
std::ostream& operator<<(std::ostream& os, const Animal &a)
{
    /// cout << n
    return os << "[" << a.codigo << ", " <<  a.idade << ", " <<  a.peso << "]";
}


#endif // _HPP_FUNCIONARIO



