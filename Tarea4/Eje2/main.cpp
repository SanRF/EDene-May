#include<iostream>
#include<string.h>
#include"Node.h"
#include"CircularLinkedList.h"
using namespace std;
using namespace vcn;


void imprimir(CircularLinkedList<bool>* computaor, string str)
{
    for (int i = 0; i < computaor->size(); i++)
        if (computaor->at(i)->getInfo())
            cout << str << " ";
        else
            cout << "." <<  " ";
    cout << endl << endl;
    
}


int main()
{
    
    
    CircularLinkedList<bool> * computaor = new CircularLinkedList<bool>();
    int numcomputaor = 0;
    cout << "Numero de computaor: ";
    cin >> numcomputaor;
    for (int i = 0; i < numcomputaor-1; i++){
        computaor->LinkedList::insert(false,0);
    }
    computaor->LinkedList::insert(true,0);
    
    cout << "Configuracion inicial" << endl;
    imprimir(computaor,"t");
    Node<bool> * node = computaor->at(true);
    int Token = computaor->LinkedList::at(node)-1;
    
    
    cout << "Enviar un mensaje desde la computadora: ";
    int prin,fin;
    cin >> prin;
    cout << "Enviar un mensaje hacia la computadora: ";
    cin >> fin;
    prin--;
    fin--;
    
    cout << endl;
    for (int i = 0; i < computaor->size(); i++)
        cout << i+1 << " ";
    cout << endl;
    
    imprimir(computaor,"#");
    while (Token%computaor->size() != prin){
        computaor->at(Token%computaor->size())->setInfo(false);
        computaor->at((Token+1)%computaor->size())->setInfo(true);
        imprimir(computaor,"#");
        Token++;
    }
    
    imprimir(computaor,"s");
    while (Token%computaor->size() != fin){
        computaor->at(Token%computaor->size())->setInfo(false);
        computaor->at((Token+1)%computaor->size())->setInfo(true);
        imprimir(computaor,"s");
        Token++;
    }
    
    return 0;
    
}
