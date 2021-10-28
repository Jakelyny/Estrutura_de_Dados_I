#ifndef _HPP_FUNCIONARIO
#define _HPP_FUNCIONARIO

#include <cstring>
#include <string>
#include <iostream>


struct Funcionario
{
    int codigo;
    std::string nome;
    int idade;
    float salario;
    Funcionario() // construtor
    {
        codigo = 0;
        nome="";
        idade = 0;
        salario = 0.0f;
    }

    Funcionario(int cod, std::string nam, int ida, float sal) // construtor
    {
        codigo = cod;
        nome= nam;
        idade = ida;
        salario = sal;
    }

    //operadores usados na busca e remoção de nós
    bool operator!=(const Funcionario& f)
    {
        if(codigo != f.codigo)
            return true;
        if(nome != f.nome)
            return true;
        if(idade != f.idade)
            return true;
        if(salario != f.salario)
            return true;

        return false;
    }

    bool operator==(const Funcionario& f)
    {
        if(codigo != f.codigo)
            return false;
        if(nome != f.nome)
            return false;
        if(idade != f.idade)
            return false;
        if(salario != f.salario)
            return false;

        return true;
    }

    //operador usado na ordenação
    bool operator > (const Funcionario& f)
    {
        if(strcmpi(nome.c_str(), f.nome.c_str()) > 0 )
            return true;
        else
            return false;
    }

};


/// quando cout receber uma struct No
std::ostream& operator<<(std::ostream& os, const Funcionario &f)
{
    /// cout << n
    return os << "[" << f.codigo << ", " << f.nome << ", " <<  f.idade << ", " <<  f.salario << "]";
}


#endif // _HPP_FUNCIONARIO



