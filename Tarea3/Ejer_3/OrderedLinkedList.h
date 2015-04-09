//
//  OrderedLinkedList.h
//  Listas
//
//  Created by Santiago Rodriguez Fernandez on 06/03/15.
//  Copyright (c) 2015 Santiago Rodriguez Fernandez. All rights reserved.
//

#ifndef __Listas__OrderedLinkedList__
#define __Listas__OrderedLinkedList__

#include <stdio.h>
#include "LinkedList.h"

namespace effm
{
    template <class T>
    class OrderedLinkedList : public vcn::LinkedList<T>
    {
    private:
        using vcn::LinkedList<T>::insertBack;
        using vcn::LinkedList<T>::insertFront;
        bool orden;
        
    public:
        OrderedLinkedList(bool _orden) : orden(_orden) {}
        void insert(T);
        
    };
    
    template<class T>
    void OrderedLinkedList<T>::insert(T element)
    {
        if(vcn::LinkedList<T>::empty())
        {
            vcn::LinkedList<T>::insert(element, 0);
        }
        else
        {
            int i = 0;
            if(orden)
            {
                while(i < vcn::LinkedList<T>::size() && element < vcn::LinkedList<T>::at(i)->getInfo())
                {
                    ++i;
                }
                vcn::LinkedList<T>::insert(element, i);
            }
            else
            {
                while(i < vcn::LinkedList<T>::size() && element > vcn::LinkedList<T>::at(i)->getInfo())
                {
                    ++i;
                }
                vcn::LinkedList<T>::insert(element, i);
            }
        }
    }
}
#endif /* defined(__Listas__OrderedLinkedList__) */
