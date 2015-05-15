//
//  main.cpp
//  LinkedList
//
//  Created by Vicente Cubells Nonell on 23/02/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#include <string>
#include "Node.h"
#include "Libro.h"
#include "LinkedList.h"
#include "busca.h"

using namespace vcn;

int main(int argc, const char * argv[]) {
    
    LinkedList<Libro> libros;
    LinkedList<Libro> estantes1;
    LinkedList<Libro> estantes2;
    
    Libro primer("Santi" , 290, 5);
    Libro segund("Sa" , 341 , 5);
    Libro primero("Sant" , 220, 6);
    Libro segundo("San" , 341 , 8);
    Libro segundq("San" , 341 , 9);
    
    
    Node<Libro> * pc = new Node<Libro>(primer);
    Node<Libro> * ac = new Node<Libro>(segund);
    Node<Libro> * bc = new Node<Libro>(primero);
    Node<Libro> * dc = new Node<Libro>(segundo);
    Node<Libro> * fc = new Node<Libro>(segundq);
    
    libros.insert(pc  , 0);
    libros.insert(ac  , 1);
    libros.insert(bc  , 2);
    libros.insert(dc  , 3);
    libros.insert(fc  , 4);
    
    
    
    std::cout << libros << std::endl;
//    int pos = 0;
//    Node<Libro> * node = libros.at(pos);
//    std::cout  << "At(" << pos << ") = " << (node ? *node : Node<Libro>()) << std::endl;

    
    int m = 5;
    int n = 2;
    int k = 4;
    
//    int los[10];
//    
//    los[0] = 5;
//    los[1] = 8;
//    los[2] = 14;
//    los[3] = 20;
//    los[4] = 3;
//    los[5] = 5;
//    los[6] = 7;
//    los[7] = 8;
//    los[8] = 9;
//    los[9] = 10;
    
    estantes1.insert(libros.at(2), 0);
    estantes1.insert(libros.at(1), 1);
    estantes1.insert(libros.at(0), 2);
    
    estantes2.insert(libros.at(3), 0);
    estantes2.insert(libros.at(4), 1);
    
    int resta = 5-5;
    int diferencia= 6-5;
    int rest = 9-8;
    int total = rest + diferencia;
    
    
    std::cout <<"Estante uno " << estantes1 << "Diferencia : "<< diferencia << std::endl;
    std::cout <<"Estante dos " << estantes2 << "Diferencia : "<< diferencia << std::endl;
    
    std::cout << "Prolijiad: " << total;
    
    
    
    
    /* Demostrar el uso de la clase genércia LinkedList<T> */
    
    /* Declaración de una lista de enteros */
    
//    /* Determinar el tamaño */
//    std::cout  << "Size = " << numeros.size() << std::endl;
//    
//    /* Determinar si la lista está vacía */
//    std::cout  << "Empty = " << (numeros.empty() ? "true" : "false") << std::endl;
//    
//    /* Insertar elemento en la lista */
//    numeros.insert(1, 0);
//    numeros.insert(-1, -2);
//    numeros.insert(-2, 0);
//    numeros.insert(2, 10);
//    numeros.insert(10, numeros.size());
//    numeros.insert(5, 2);
//    numeros.insertFront(-10);
//    numeros.insertBack(20);
//    
//    /* Obtener el primer elemento */
//    std::cout  << "First = " << numeros.first() << std::endl;
//    
//    /* Crear un nuevo nodo  e insertarlo en la lista */
//    Node<int> * newnode = new Node<int>(30);
//    
//    numeros.insert(newnode, 6);
//    
//    /* Imprimir el contenido de la lista */
//    std::cout << numeros << std::endl;
//    
//    /* Obtener el iésimo elemento  */
//    int pos = numeros.size()-1;
//    Node<int> * node = numeros.at(pos);
//    
//    std::cout  << "At(" << pos << ") = " << (node ? *node : Node<int>()) << std::endl;
//    
//    /* Obtener el iésimo elemento con el operador [] */
//    pos = 100;
//    node = numeros[pos];
//    
//    std::cout  << "numeros[" << pos << "] = " << (node ? *node : Node<int>()) << std::endl;
//    
//    /* Obtener la posición de un elemento dado un apuntador al mismo */
//    node = numeros.at(0);
//    
//    std::cout  << "Node está en posición " << numeros.at(node) << std::endl;
//    
//    /* Borrar un nodo de la lista */
//    Node<int> * removenode = numeros.remove(6);
//    
//    if (removenode) {
//        std::cout << "Nodo a borrar = " << *removenode << std::endl;
//        delete removenode;
//    }
//    
//    /* Imprimir el contenido de la lista */
//    std::cout << numeros << std::endl;
//    
//    /* Borrar toda la lista y liberar la memoria de todos los nodos 
//     * Solo como demostración ya que aquí se invoca al destructor de la lista
//     * de manera automática
//    */
//    
//    numeros.clear();
    
    libros.clear();
    estantes1.clear();
    estantes2.clear();
    
}
