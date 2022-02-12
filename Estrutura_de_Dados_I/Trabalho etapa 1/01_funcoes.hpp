#include "01_estruturas.hpp"
#include "01_fila_pessoas.hpp"
#include "01_fila_empresas.hpp"
#include "01_pilha_doacao.hpp"
#include "01_pilha_objetos.hpp"
using namespace std;

int totalPessoas = 0, masculino = 0, feminino = 0, deficientes = 0, gestantes = 0, totalEmpresas = 0, especialistaLivros = 0, especialistaEquipamentos = 0, pessoasPrioridade = 0;

void incluirPessoa(FilaPessoa *filaPessoa, FilaPessoa *filaPessoaPrioritaria){
    Pessoa p1;
    bool teste = false;
    string teste2;
    cout<<"DIGITE SEU NOME COMPLETO: ";
    getline(cin, p1.nomeCompleto);
    fflush(stdin);
    totalPessoas++;
    do{
        cout<<"DIGITE SEU SEXO: ( feminino / masculino ): ";
        getline(cin, p1.sexo);
        fflush(stdin);
        if(p1.sexo == "feminino"){
            teste = true;
            feminino++;
        }else if(p1.sexo == "masculino"){
            teste = true;
            masculino++;
        }else{
            cout<<"OPS, VOCÊ ERROU..TENTE DE NOVO."<<endl;
            teste = false;
        }
    }while(teste == false);
    do{
        cout<<"DIGITE SEU CPF: ";
        getline(cin, p1.cpf);
        fflush(stdin);
        if(p1.cpf.size() == 11){
            teste = true;
        }else{
            cout<<"DIGITE UMA RESPOSTA VÁLIDA!"<<endl;
            teste = false;
        }
    }while(teste == false);
    cout<<"DIGITE SUA IDADE: ";
    cin>>p1.idade;
    fflush(stdin);
    do{
        cout<<"POSSUI ALGUMA DEFICIENCIA? ( S / N ): ";
        getline(cin, teste2);
        fflush(stdin);
        if(teste2 == "s" || teste2 =="S"){
            p1.deficienteFisico = true;
            teste = true;
            deficientes++;
        }else if(teste2 == "n" || teste2 =="N"){
            p1.deficienteFisico = false;
            teste = true;
        }else{
            cout<<"OPS, VOCÊ ERROU..TENTE DE NOVO."<<endl;
            teste = false;
        }
    }while(teste == false);
    do{
        cout<<"SE ENCONTRA GESTANTE? ( S / N ): ";
        getline(cin, teste2);
        fflush(stdin);
        if(teste2 == "s" || teste2 == "S"){
            p1.gestante = true;
            teste = true;
            gestantes++;
        }else if(teste2 == "n" || teste2 == "N"){
            p1.gestante = false;
            teste = true;
        }else{
            cout<<"OPS, VOCÊ ERROU..TENTE DE NOVO."<<endl;
            teste = false;
        }
    }while(teste == false);
    if(p1.idade > 65 || p1.deficienteFisico == true || p1.gestante == true){
        enfileiraFpessoa(*(&filaPessoaPrioritaria), p1);
        system("cls");
        cout<<"\n\n\tPESSOA INCLUSA NA FILA PRIORITÁRIA!"<<endl;
        getchar();
    }else{
        enfileiraFpessoa(*(&filaPessoa),p1);
        system("cls");
        cout<<"\n\n\tPESSOA INCLUSA!"<<endl;
        getchar();
    }
}

void incluirEmpresa(FilaEmpresa *filaEmpresa, FilaEmpresa *filaEmpresaPrioritaria){
    Empresa p1;
    bool teste = false;
    cout<<"DIGITE O NOME DA EMPRESA: ";
    getline(cin, p1.nomeEmpresa);
    fflush(stdin);
    totalEmpresas++;
    do{
        cout<<"DIGITE O CNPJ: ";
        getline(cin, p1.cnpj);
        fflush(stdin);
        if(p1.cnpj.size() == 14){
            teste = true;
        }else{
            cout<<"OPS, VOCÊ ERROU..TENTE DE NOVO."<<endl;
            teste = false;
        }
    }while(teste == false);
    do{
        cout<<"DIGITE O TIPO: ( livro / equipamento ): ";
        getline(cin, p1.tipo);
        fflush(stdin);
        if(p1.tipo == "livro"){
            teste = true;
            especialistaLivros++;
        }else if(p1.tipo == "equipamento"){
            teste = true;
            especialistaEquipamentos++;
        }else{
            cout<<"OPS, VOCÊ ERROU..TENTE DE NOVO."<<endl;
            teste = false;
        }
    }while(teste == false);
    if(p1.tipo == "livro"){
        enfileiraFempresa(*(&filaEmpresaPrioritaria), p1);
        system("cls");
        cout<<"\n\n\tEMPRESA INCLUSA NA FILA PRIORITÁRIA!"<<endl;
        getchar();
    }else{
        enfileiraFempresa(*(&filaEmpresa), p1);
        system("cls");
        cout<<"\n\n\tEMPRESA INCLUSA!"<<endl;
        getchar();
    }
}

void atenderPessoa(FilaPessoa *filaPessoa, PilhaFichaDoacaoObjetos *pilhaFichaDoacaoObjetos, PilhaObjeto *pilhaLivros, PilhaObjeto *pilhaEquipamentos, FilaPessoa *filaPessoaPrioritarias){
    FichaDoacaoObjetos fichaDoacaoObjetos;
    Pessoa informacao;
    Objeto objeto;
    bool teste = false;
    if(!vaziaFpessoa(filaPessoaPrioritarias)){
        desenfileiraFPessoa(*(&filaPessoaPrioritarias), &informacao);
        fichaDoacaoObjetos.pessoa = informacao;
        do{
            cout<<"DIGITE O TIPO: ( livro / equipamento ): ";
            getline(cin, objeto.tipo);
            fflush(stdin);
            if(objeto.tipo == "livro" || objeto.tipo == "equipamento"){
                teste = true;
            }else{
                cout<<"OPS, VOCÊ ERROU..TENTE DE NOVO."<<endl;
                teste = false;
            }
        }while(teste == false);
        cout<<"DIGITE A DESCRIÇÃO: ";
        getline(cin, objeto.descricao);
        fflush(stdin);
        fichaDoacaoObjetos.objeto = objeto;
        empilharFichaDoacaoObjetos(*(&pilhaFichaDoacaoObjetos), fichaDoacaoObjetos);
        if(objeto.tipo == "livro"){
            empilharObjeto(*(&pilhaLivros), objeto);
        }else if(objeto.tipo == "equipamento"){
            empilharObjeto(*(&pilhaEquipamentos), objeto);
        }
        ofstream escreve("doacao.txt", ios::app);
        escreve<<fichaDoacaoObjetos.pessoa.nomeCompleto<<"#"<<fichaDoacaoObjetos.pessoa.sexo<<"#"<<fichaDoacaoObjetos.pessoa.cpf<<"#"<<fichaDoacaoObjetos.pessoa.idade<<"#DEF_"<<fichaDoacaoObjetos.pessoa.deficienteFisico<<"#GEST_"<<fichaDoacaoObjetos.pessoa.gestante<<"#OBJ_"<<objeto.tipo<<"#"<<objeto.descricao<<endl;
        escreve.close();
        system("cls");
        cout<<"\n\n\tDOAÇÃO EFETUADA!"<<endl;
        getchar();
    }else if(!vaziaFpessoa(filaPessoa)){
        desenfileiraFPessoa(*(&filaPessoa), &informacao);
        fichaDoacaoObjetos.pessoa = informacao;
        do{
            cout<<"DIGITE O TIPO: ( livro / equipamento ): ";
            getline(cin, objeto.tipo);
            fflush(stdin);
            if(objeto.tipo == "livro" || objeto.tipo == "equipamento"){
                teste = true;
            }else{
                cout<<"OPS, VOCÊ ERROU..TENTE DE NOVO."<<endl;
                teste = false;
            }
        }while(teste == false);
        cout<<"DIGITE A DESCRIÇÃO: ";
        getline(cin, objeto.descricao);
        fflush(stdin);
        fichaDoacaoObjetos.objeto = objeto;
        empilharFichaDoacaoObjetos(*(&pilhaFichaDoacaoObjetos), fichaDoacaoObjetos);
        if(objeto.tipo == "livro"){
            empilharObjeto(*(&pilhaLivros), objeto);
        }else if(objeto.tipo == "equipamento"){
            empilharObjeto(*(&pilhaEquipamentos), objeto);
        }
        ofstream escreve("doacao.txt", ios::app);
        escreve<<fichaDoacaoObjetos.pessoa.nomeCompleto<<"#"<<fichaDoacaoObjetos.pessoa.sexo<<"#"<<fichaDoacaoObjetos.pessoa.cpf<<"#"<<fichaDoacaoObjetos.pessoa.idade<<"#DEF_"<<fichaDoacaoObjetos.pessoa.deficienteFisico<<"#GEST_"<<fichaDoacaoObjetos.pessoa.gestante<<"#OBJ_"<<objeto.tipo<<"#"<<objeto.descricao<<endl;
        escreve.close();
        system("cls");
        cout<<"\n\n\tDOAÇÃO EFETUADA!"<<endl;
        getchar();
    }else{
        system("cls");
        cout<<"\n\n\tSEM MAIS PESSOAS..."<<endl;
        getchar();
    }
}

void atenderEmpresa(FilaEmpresa *filaEmpresa, FilaEmpresa *filaEmpresaPrioritarias, PilhaObjeto *pilhaLivros, PilhaObjeto *pilhaEquipamentos){
    Empresa empresa;
    Objeto objeto;
    int valor = 0;
    string teste;
    if(!vaziaFempresa(filaEmpresaPrioritarias)){
        desenfileiraFempresa(*(&filaEmpresaPrioritarias), &empresa);
        cout<<"QUANTIDADE A SER RETIRADA: ";
        cin>>valor;
        fflush(stdin);
        do{
            cout<<"TIPO DE CARGA DA FILA PRIORITÁRIA: ";
            getline(cin, teste);
            fflush(stdin);
        }while(teste != empresa.tipo);
        if(teste == empresa.tipo){
            for(int i = 0; i < valor; i++){
                if(desempilharObjeto(*(&pilhaLivros), &objeto)){
                ofstream escreve("retiradas.txt", ios::app);
                escreve<<empresa.nomeEmpresa<<"#"<<empresa.cnpj<<"#TRANS_"<<empresa.tipo<<"#OBJ_"<<objeto.tipo<<"#"<<objeto.descricao<<endl;
                escreve.close();
                system("cls");
                cout<<"\n\n\tRETIRADA DE LIVROS EFETUADA!"<<endl;
                getchar();
                }else{
                    system("cls");
                    cout<<"\n\n\tOPS, ESTOQUE DE LIVROS VAZIO..."<<endl;
                    getchar();
                }
            }
        }else{
            system("cls");
            cout<<"\n\n\tOPS, TIPO ERRADO.."<<endl;
            getchar();
        }
    }else if(!vaziaFempresa(filaEmpresa)){
        desenfileiraFempresa(*(&filaEmpresa), &empresa);
        cout<<"QUANTIDADE A SER RETIRADA: ";
        cin>>valor;
        fflush(stdin);
        do{
            cout<<"TIPO DE CARGA DA FILA NÃO PRIORITÁRIA: ";
            getline(cin, teste);
            fflush(stdin);
        }while(teste != empresa.tipo);
        if(teste == empresa.tipo){
            for(int i = 0; i < valor; i++){
                if(desempilharObjeto(*(&pilhaEquipamentos), &objeto)){
                ofstream escreve("retiradas.txt", ios::app);
                escreve<<empresa.nomeEmpresa<<"#"<<empresa.cnpj<<"#TRANS_"<<empresa.tipo<<"#OBJ_"<<objeto.tipo<<"#"<<objeto.descricao<<endl;
                escreve.close();
                system("cls");
                cout<<"\n\n\tRETIRADA DE EQUIPAMENTOS EFETUADA!"<<endl;
                getchar();
                }else{
                    system("cls");
                    cout<<"\n\n\tOPS, ESTOQUE DE EQUIPAMENTOS VAZIO..."<<endl;
                    getchar();
                }
            }
        }else{
            system("cls");
            cout<<"\n\n\tOPS, TIPO ERRADO.."<<endl;
            getchar();
        }
    }else{
        system("cls");
        cout<<"\n\n\tSEM MAIS EMPRESAS..."<<endl;
        getchar();
    }
}

void mostrarPessoas(FilaPessoa *filaPessoa, FilaPessoa *filaPessoaPrioritaria){
    cout<<" PESSOAS PRIORITÁRIAS: \n\n";
    mostraFpessoa(*(&filaPessoaPrioritaria));
    cout<<"\n\n PESSOAS NÃO PRIORITÁRIAS: \n\n";
    mostraFpessoa(*(&filaPessoa));
}

void mostrarEmpresas(FilaEmpresa *filaEmpresa, FilaEmpresa *filaEmpresaPrioritaria){
    cout<<" EMPRESAS PRIORITÁRIAS: \n\n";
    mostraFempresa(*(&filaEmpresaPrioritaria));
    cout<<"\n\n EMPRESAS NÃO PRIORITÁRIAS: \n\n";
    mostraFempresa(*(&filaEmpresa));
}

void contagemUnificadaPessoas(){
    cout<<"--------------------------------"<<endl;
    cout<<" TOTAL DE PESSOAS:        "<<totalPessoas<<"\n--------------------------------"<<endl;
    cout<<" QUANT. SEXO FEMININO:    "<<feminino<<"\n--------------------------------"<<endl;
    cout<<" QUANT. SEXO MASCULINO:   "<<masculino<<"\n--------------------------------"<<endl;
    cout<<" QUANT. DEFICIÊNTES:      "<<deficientes<<"\n--------------------------------"<<endl;
    cout<<" QUANT. GESTANTES:        "<<gestantes<<"\n--------------------------------"<<endl;
}

void contagemUnificadaEmpresas(){
    cout<<"-------------------------------------------------"<<endl;
    cout<<" TOTAL DE EMPRESAS:                         "<<totalEmpresas<<"\n-------------------------------------------------"<<endl;
    cout<<" ESPECIALISTA EM ENTREGA DE LIVROS:         "<<especialistaLivros<<"\n-------------------------------------------------"<<endl;
    cout<<" ESPECIALISTA EM ENTREGA DE EQUIPAMENTOS:   "<<especialistaEquipamentos<<"\n-------------------------------------------------"<<endl;
}

void imprimeEstoque(PilhaObjeto *pilhaObjetoCopia){
    PilhaObjeto objetoCopia;
    Objeto copia;
    int aux = 0;
    while(!vaziaObjeto(*(&pilhaObjetoCopia))){
        desempilharObjeto(*(&pilhaObjetoCopia), &copia);
        empilharObjeto(&objetoCopia, copia);
    }
    while(!vaziaObjeto(&objetoCopia)){
        desempilharObjeto(&objetoCopia, &copia);
        aux++;
        cout<<aux<<"º - "<<copia.tipo<<" - "<<copia.descricao<<endl;
        empilharObjeto(*(&pilhaObjetoCopia), copia);
    }
    aux = 0;
    desalocarObjeto(&objetoCopia);
}

void listarDoacoesRecebidas(){
    FilaPessoa filaDoacaoPessoas;
    Objeto objetoDoado;
    Pessoa doador;
    float media = 0.0;
    char informacao[40];
    int doadores = 0, prioritarios = 0;
    ifstream ler("doacao.txt", ios::in);
    cout<<" LISTA DE DOADORES: "<<endl;
    while(!ler.fail()){
        ler.getline(informacao, 40, '#');
        doador.nomeCompleto = informacao;
        if(doador.nomeCompleto == ""){
            break;
        }
        cout<<"\n---------------------------------------------------------------------"<<endl;
        cout<<" DOADOR:                          "<<doador.nomeCompleto<<endl;
        ler.getline(informacao, 40, '#');
        doador.sexo = informacao;
        cout<<" SEXO:                            "<<doador.sexo<<endl;
        ler.getline(informacao, 40, '#');
        doador.cpf = informacao;
        cout<<" CPF:                             "<<doador.cpf<<endl;
        ler.getline(informacao, 40, 'DEF_');
        doador.idade = atoi(informacao);
        cout<<" IDADE:                           "<<doador.idade<<endl;
        ler.getline(informacao, 40, '#GEST_');
        doador.deficienteFisico = atoi(informacao);
        cout<<" DEFICIENTE (sim = 1)  (não = 0): "<<doador.deficienteFisico<<endl;
        ler.getline(informacao, 40, '#OBJ_');
        doador.gestante = atoi(informacao);
        cout<<" GESTANTE (sim = 1)  (não = 0):   "<<doador.gestante<<endl;
        ler.getline(informacao, 40, '#');
        objetoDoado.tipo = informacao;
        cout<<" TIPO DE DOAÇÃO:                  "<<objetoDoado.tipo<<endl;
        ler.getline(informacao, 40, '\n');
        objetoDoado.descricao = informacao;
        cout<<" DESCRIÇÃO:                       "<<objetoDoado.descricao<<endl;
        enfileiraFpessoa(&filaDoacaoPessoas, doador);
        cout<<"\n---------------------------------------------------------------------"<<endl;
        doadores++;
    }
    while(desenfileiraFPessoa(&filaDoacaoPessoas, &doador)){
        media += doador.idade;
        if(doador.idade > 65 || doador.deficienteFisico == true || doador.gestante == true){
            prioritarios++;
        }
    }
    cout<<"___________________________________________________\n"<<endl;
    cout<<" QUANT. DE DOAÇÕES FEITAS:          "<<doadores<<endl;
    cout<<" QUANT. DE PESSOAS COM PRIORIDADE:  "<<prioritarios<<endl;
    cout<<" IDADE MÉDIA DOS DOADORES:          "<<media/doadores<<endl;
    cout<<"___________________________________________________"<<endl;
    getchar();
    destroiFpessoa(&filaDoacaoPessoas);
    ler.close();
}

void verificarDoacoesCPF(){
    Objeto objetoDoado;
    Pessoa doador;
    string CPF;
    char informacao[40];
    int doacaoCPF = 0;

    cout<<"DIGITE O CPF PARA SABER SUAS DOAÇÕES: ";
    getline(cin, CPF);
    ifstream ler("doacao.txt", ios::in);
    while(!ler.fail()){
        ler.getline(informacao, 40, '#');
        doador.nomeCompleto = informacao;
        if(doador.nomeCompleto == ""){
            break;
        }
        ler.getline(informacao, 40, '#');
        doador.sexo = informacao;
        ler.getline(informacao, 40, '#');
        doador.cpf = informacao;
        ler.getline(informacao, 40, 'DEF_');
        doador.idade = atoi(informacao);
        ler.getline(informacao, 40, '#GEST_');
        doador.deficienteFisico = atoi(informacao);
        ler.getline(informacao, 40, '#OBJ_');
        doador.gestante = atoi(informacao);
        ler.getline(informacao, 40, '#');
        objetoDoado.tipo = informacao;
        ler.getline(informacao, 40, '\n');
        objetoDoado.descricao = informacao;
        if(doador.cpf == CPF){
            doacaoCPF++;
        }
    }
    system("cls");
    cout<<"\n\n\t O CPF "<<doador.cpf<<" POSSUI "<<doacaoCPF<<" DOAÇÕES FEITAS.."<<endl;
    ler.close();
}

void listarRetiradas(){
    Objeto objetoRetirado;
    Empresa empresaDado;
    char informacao[40];
    ifstream ler("retiradas.txt", ios::in);
    cout<<" LISTA DE TODAS AS RETIRADAS: "<<endl;
    while(!ler.fail()){
        ler.getline(informacao, 40, '#');
        empresaDado.nomeEmpresa = informacao;
        if(empresaDado.nomeEmpresa == ""){
            break;
        }
        cout<<"\n-----------------------------------------------------------"<<endl;
        cout<<" EMPRESA:            "<<empresaDado.nomeEmpresa<<endl;
        ler.getline(informacao, 40, '#TRANS_');
        empresaDado.cnpj = informacao;
        cout<<" CNPJ:               "<<empresaDado.cnpj<<endl;
        ler.getline(informacao, 40, '#OBJ_');
        empresaDado.tipo = informacao;
        cout<<" ESPECIALIDADE:      "<<empresaDado.tipo<<endl;
        ler.getline(informacao, 40, '#');
        objetoRetirado.tipo = informacao;
        cout<<" TIPO:               "<<objetoRetirado.tipo<<endl;
        ler.getline(informacao, 40, '\n');
        objetoRetirado.descricao = informacao;
        cout<<" DESCRIÇÃO:          "<<objetoRetirado.descricao<<endl;
        cout<<"\n-----------------------------------------------------------"<<endl;
    }
    ler.close();
}









