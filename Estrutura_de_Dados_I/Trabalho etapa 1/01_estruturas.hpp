#include <iomanip>
#ifndef _HPP_ESTRUTURAS
#define _HPP_ESTRUTURAS
using namespace std;

struct Pessoa{

    string nomeCompleto;
    string sexo;
    string cpf;
    int idade;
    bool deficienteFisico;
    bool gestante;

};

struct Empresa{

    string nomeEmpresa;
    string cnpj;
    string tipo;

};

struct Objeto{

    string tipo;
    string descricao;

};

struct Doacao{

    Pessoa pessoa;
    Objeto objeto;

};

#endif
