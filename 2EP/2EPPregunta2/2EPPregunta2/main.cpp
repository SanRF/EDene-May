//
//  main.cpp
//  2EPPregunta2
//
//  Created by Santiago Rodriguez Fernandez on 09/04/15.
//  Copyright (c) 2015 Santiago Rodriguez Fernandez. All rights reserved.
//

#include <string>
#include "Node.h"
#include "Computadora.h"
#include "LinkedList.h"

using namespace vcn;

int main(int argc, const char * argv[]) {
    
    /* Crear un Node entero */
    Node<int> first(1);
    
    /* Visualizar todos los tipos de nodos */
    std::cout << first << std::endl;
    
    /* Demostrar el uso de la clase genércia LinkedList<T> */
    
    /* Declaración de una lista de enteros */
    LinkedList<int> numeros;
    
    /* Determinar el tamaño */
    std::cout  << "Size = " << numeros.size() << std::endl;
    
    /* Determinar si la lista está vacía */
    std::cout  << "Empty = " << (numeros.empty() ? "true" : "false") << std::endl;
    
    /* Insertar elemento en la lista */
    numeros.insert(5, 0);
    numeros.insert(4, 0);
    numeros.insert(3, 0);
    numeros.insert(5, 0);
    
    
    /* Obtener el primer elemento */
    std::cout  << "First = " << numeros << std::endl;
    
    /* Imprimir el contenido de la lista */
    std::cout << numeros << std::endl;
    
    LinkedList<int> nameros;
    
    for(int i = 0 ; i < numeros.size() ; ++i){
        int pos = numeros.size()-i;
        if((Node<int> * node = numeros.at(pos)) == (Node<int> * node = numeros.at(i)){
        Node<int> * node = numeros.at(pos);
        }
    }
    
    numeros.clear();
    
}
