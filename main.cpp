/*
    Aluno: Carlos Alberto Rodrigues dos Santos.
    Matricula: 205190110.
    Observação: feito individualmente.
*/

#include <cstdlib>
#include <iostream>
#include <ArrayList.h>

using namespace std;
int main()
{
    ArrayList<string> minhaLista = ArrayList<string>();

    //Pergunta se a lista ta vazia
    cout<<"esta vazia: "<<minhaLista.isEmpty()<<endl;
    //Retorna o tamanho da lista vazia
    cout<<"tamanho: "<<minhaLista.size()<<endl;

    //Exibi a lista vazia
    minhaLista.print();

    //Adicionando elementos na lista
    minhaLista.add("carlos");
    minhaLista.add("ana");
    minhaLista.add("joao");
    minhaLista.add("joaquim");
    minhaLista.add("cristina");
    minhaLista.add("rafael");

    //Adicionando elementos em determinados indices
    minhaLista.add("mari",2);
    minhaLista.add("vitoria", 5);

    //Exibi a lista completa
    minhaLista.print();

    //Retorna o tamanho da lista preenchida
    cout<<"tamanho: "<<minhaLista.size()<<endl;

    //remover elemento da lista pelo indice
    minhaLista.remove(6);
    minhaLista.print();

    //remover elemento da lista
    minhaLista.remove("mari");
    minhaLista.print();
    cout<<"tamanho: "<<minhaLista.size()<<endl;

    //Pergunta se a lista ta vazia
    cout<<"esta vazia: "<<minhaLista.isEmpty()<<endl;

    //Limpando a lista
    //minhaLista.clear();
    minhaLista.print();

    //pegando elementos da lista
    try {
        cout<< "elemento procurado: "<<minhaLista.get(5)<<endl;
    }
    catch (const char* ex) {
        cout<<ex<<endl;
    }

    //pegando o indice de um elemento
    cout<<"index do elemento: "<<minhaLista.indexOf("rafael")<<endl;


    return 0;
}
