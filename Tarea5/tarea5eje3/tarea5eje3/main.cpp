//
//  main.cpp
//  tarea5eje3
//
//  Created by Santiago Rodriguez Fernandez on 23/04/15.
//  Copyright (c) 2015 Santiago Rodriguez Fernandez. All rights reserved.
//

#include <iostream>
#include "BinaryTree.h"

using namespace vcn;

int main(int argc, const char * argv[]) {
    
    BinaryTree<int> arbol;
    
    BNode<int> * yon = new BNode<int>(6);
    BNode<int> * san = new BNode<int>(5);
    BNode<int> * ich = new BNode<int>(2);
    BNode<int> * cero = new BNode<int>(0);
    BNode<int> * nii = new BNode<int>(4);
    BNode<int> * gor = new BNode<int>(7);
    BNode<int> * rok = new BNode<int>(8);
    
    arbol.insert(nullptr,cero);
    arbol.insert(cero,ich);
    arbol.insert(cero,nii);
    arbol.insert(ich,san);
    arbol.insert(ich,yon);
    arbol.insert(nii,gor);
    arbol.insert(nii,rok);
    
    std::cout << "Arbol " << std::endl;
    arbol.preOrder();
    
    if (arbol.simetria())
        std::cout << "Es simetrico" << std::endl;
    else
        std::cout << "No es simetrico" << std::endl << std::endl;
    
    /*arbol.reflexion();
    
    std::cout << "Reflexion " << std::endl;
    arbol.preOrder();
    std::cout << std::endl;*/
    
    BinaryTree<int> arbol2;
    
    BNode<int> * noq = new BNode<int>(4);
    BNode<int> * now = new BNode<int>(4);
    BNode<int> * noe = new BNode<int>(2);
    BNode<int> * nor = new BNode<int>(0);
    BNode<int> * noy = new BNode<int>(2);
    BNode<int> * nou = new BNode<int>(4);
    BNode<int> * noi = new BNode<int>(4);
    
    arbol2.insert(nullptr,nor);
    arbol2.insert(nor,noe);
    arbol2.insert(nor,noy);
    arbol2.insert(noe,noq);
    arbol2.insert(noe,now);
    arbol2.insert(noy,nou);
    arbol2.insert(noy,noi);
    
    std::cout << "Arbol " << std::endl;
    arbol2.preOrder();
    
    if (arbol2.simetria())
        std::cout << "Es simetrico" << std::endl;
    else
        std::cout << "No es simetrico" << std::endl;
    
    
    
}
