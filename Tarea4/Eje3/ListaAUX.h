//
//  ListaAUX.h
//  Tarea4.Eje3
//
//  Created by Santiago Rodriguez Fernandez on 26/03/15.
//  Copyright (c) 2015 Santiago Rodriguez Fernandez. All rights reserved.
//

#ifndef Tarea4_Eje3_ListaAUX_h
#define Tarea4_Eje3_ListaAUX_h

#include <iostream>
#include "CircularLinkedList.h"

template <class T>
class ListaAUX : public CircularLinkedList<T> {
public:
    
    ListaAUX() : CircularLinkedList<T>()
    {
    }
    
    ~ListaAUX(){
        clear();
    }
    
    void insert(T value, int pos) override;
    Node<T> * remove(int pos) override;
    void clear() override;
    
    template <class Tn>
    friend std::ostream & operator <<(std::ostream &, ListaAUX<Tn> *&);
    
    
};

template <class T>
void ListaAUX<T>::clear()
{
    Node<T> * aux;
    
    while (this->_first != this->_last) {
        aux = this->_first;
        this->_first = this->_first->getNext();
        this->_first->setBefore(aux->getBefore());
        aux->setNext(nullptr);
        aux->setBefore(nullptr);
        delete aux;
    }
    
    if (this->_last)
    {
        this->_last->setNext(nullptr);
        this->_last->setBefore(nullptr);
        delete this->_last;
    }
    
    this->_first = this->_last = nullptr;
    
    this->_size = 0;
}

template <class T>
void ListaAUX<T>::insert(T value, int pos)
{
    if (pos < 0 || pos > this->_size) {
        return;
    }
    
    if (pos == 0)
    {
        if(this->_size==0)
        {
            Node<T> * nuevo = new Node<T>(value);
            this->_first = this->_last = nuevo;
            this->_first->setNext(nuevo);
            this->_first->setBefore(nuevo);
        }
        else
        {
            Node<T> * nuevo = new Node<T>(value);
            nuevo->setNext(this->_first);
            nuevo->setBefore(this->_last);
            this->_first->setBefore(nuevo);
            this->_last->setNext(nuevo);
            this->_first = nuevo;
        }
    }
    else if (pos == (this->_size - 1)) {
        
        Node<T> * nuevo = new Node<T>(value);
        nuevo->setNext(this->_last);
        nuevo->setBefore(this->_last->getBefore());
        this->_last->getBefore()->setNext(nuevo);
        this->_last->setBefore(nuevo);
        
    }
    else if(pos == this->_size)
    {
        Node<T> * nuevo = new Node<T>(value);
        nuevo->setBefore(this->_last);
        nuevo->setNext(this->_first);
        this->_last->setNext(nuevo);
        this->_first->setBefore(nuevo);
        this->_last = nuevo;
    }
    else
    { /* Insertar en cualquier otra posición */
        Node<T> * anterior = this->at(pos)->getBefore();
        Node<T> * nuevo = new Node<T>(value);
        nuevo->setNext(anterior->getNext());
        nuevo->setBefore(anterior);
        anterior->getNext()->setBefore(nuevo);
        anterior->setNext(nuevo);
    }
    
    ++this->_size;
}

template <class T>
Node<T> * ListaAUX<T>:: remove(int pos)
{
    if (pos < 0 || pos >= this->_size) {
        return nullptr;
    }
    
    Node<T> * eliminado = nullptr;
    
    /* Borra al _first */
    if (pos == 0) {
        eliminado = this->_first;
        
        if (this->_size == 1) {
            this->_first->setNext(nullptr);
            this->_first->setBefore(nullptr);
            this->_first = this->_last = nullptr;
        }
        else {
            this->_first = this->_first->getNext();
            this->_last->setNext(this->_first);
            this->_first->setBefore(this->_last);
        }
    }
    else { /* Borrar en cualquier otra posición */
        Node<T> * prev = this->at(pos)->getBefore();
        
        if (prev->getNext() == this->_last) {
            this->_last = prev;
            eliminado = this->_last->getNext();
            this->_last->setNext(this->_first);
            this->_first->setBefore(this->_last);
            eliminado->setNext(nullptr);
            eliminado->setBefore(nullptr);
        }
        else
        {
            eliminado = prev->getNext();
            eliminado->getBefore()->setNext(eliminado->getNext());
            eliminado->getNext()->setBefore(eliminado->getBefore());
            eliminado->setNext(nullptr);
            eliminado->setBefore(nullptr);
        }
    }
    --this->_size;
    return eliminado;
}

template <class T>
std::ostream & operator <<(std::ostream & os, ListaAUX<T> *& lista)
{
    
    for (auto p : *lista)
    {
        os << p << std::endl;
    }
    
    return os;
}


#endif
