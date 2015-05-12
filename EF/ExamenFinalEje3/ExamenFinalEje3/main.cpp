//
//  main.cpp
//
//  Created by Santiago Rodriguez Fernandez on 23/04/15.
//  Copyright (c) 2015 Santiago Rodriguez Fernandez. All rights reserved.
//

#include <iostream>
#include "BinaryTree.h"
#include <string>

using namespace vcn;

void preO(std::string first){
    
    BinaryTree<char> arbol;
    
    BNode<char> * raiz = new BNode<char>(first[0]);
    BNode<char> * hijo1 = new BNode<char>(first[1]);
    BNode<char> * nieto1 = new BNode<char>(first[2]);
    BNode<char> * tat1 = new BNode<char>(first[3]);
    BNode<char> * tat2 = new BNode<char>(first[4]);
    BNode<char> * hijo2 = new BNode<char>(first[5]);
    BNode<char> * nieto2 = new BNode<char>(first[6]);
    BNode<char> * tata3 = new BNode<char>(first[7]);
    BNode<char> * tita1 = new BNode<char>(first[8]);
    BNode<char> * tata4 = new BNode<char>(first[9]);
    BNode<char> * nieto3 = new BNode<char>(first[10]);
    BNode<char> * tata5 = new BNode<char>(first[11]);
    BNode<char> * tita2 = new BNode<char>(first[12]);
    
    arbol.insert(nullptr,raiz);
    arbol.insert(raiz,hijo1);
    arbol.insert(raiz,hijo2);
    arbol.insert(hijo1,nieto1);
    arbol.insert(nieto1,tat1);
    arbol.insert(nieto1,tat2);
    arbol.insert(hijo2,nieto2);
    arbol.insert(nieto2,tata3);
    arbol.insert(tata3,tita1);
    arbol.insert(nieto2,tata4);
    arbol.insert(hijo2,nieto3);
    arbol.insert(nieto3,tata5);
    arbol.insert(tata5,tita2);
    
    std::cout << "Arbol Pre-Orden " << std::endl;
    arbol.preOrder();
    std::cout << std::endl;
    
    std::cout << "Arbol En-Orden " << std::endl;
    arbol.inOrder();
    std::cout << std::endl;
    /*arbol.reflexion();
    
    std::cout << "Reflexion " << std::endl;
    arbol.preOrder();
    std::cout << std::endl;*/
}

void enO(std::string first){
    
    BinaryTree<char> arbol;
    
    BNode<char> * raiz = new BNode<char>(first[0]);
    BNode<char> * hijo1 = new BNode<char>(first[1]);
    BNode<char> * nieto1 = new BNode<char>(first[2]);
    BNode<char> * tat1 = new BNode<char>(first[3]);
    BNode<char> * tat2 = new BNode<char>(first[4]);
    BNode<char> * hijo2 = new BNode<char>(first[5]);
    BNode<char> * nieto2 = new BNode<char>(first[6]);
    BNode<char> * tata3 = new BNode<char>(first[7]);
    BNode<char> * tita1 = new BNode<char>(first[8]);
    BNode<char> * tata4 = new BNode<char>(first[9]);
    BNode<char> * nieto3 = new BNode<char>(first[10]);
    BNode<char> * tata5 = new BNode<char>(first[11]);
    BNode<char> * tita2 = new BNode<char>(first[12]);
    
    arbol.insert(nullptr,raiz);
    arbol.insert(raiz,hijo1);
    arbol.insert(raiz,hijo2);
    arbol.insert(hijo1,nieto1);
    arbol.insert(nieto1,tat1);
    arbol.insert(nieto1,tat2);
    arbol.insert(hijo2,nieto2);
    arbol.insert(nieto2,tata3);
    arbol.insert(tata3,tita1);
    arbol.insert(nieto2,tata4);
    arbol.insert(hijo2,nieto3);
    arbol.insert(nieto3,tata5);
    arbol.insert(tata5,tita2);
    
    std::cout << "Arbol EN-orden " << std::endl;
    arbol.preOrder();
    std::cout << std::endl;
    
    /*arbol.reflexion();
     
     std::cout << "Reflexion " << std::endl;
     arbol.preOrder();
     std::cout << std::endl;*/
}
int main(int argc, const char * argv[]) {
    
    
    std::string first = "GEAIBMCLDFKJH";
    std::string second = "IABEGLDCFMKHJ";
    
    preO(first);
    enO(second);
}
