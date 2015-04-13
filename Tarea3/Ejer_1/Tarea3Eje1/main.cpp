//
//  main.cpp
//  Tarea3Eje1
//
//  Created by Santiago Rodriguez Fernandez on 13/04/15.
//  Copyright (c) 2015 Santiago Rodriguez Fernandez. All rights reserved.
//

#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace vcn;

int main()
{
    LinkedList<int> * inip = new LinkedList<int>();
    LinkedList<int> * ultip = new LinkedList<int>();
    int primer = 0;
    int ult = 0;
    int s = 0;
    int res;
    int cont = 0;
    
    
    std::cout << "Indica el inicio del rango?" << std::endl;
    std::cin >> primer;
    std::cout << "Indica el final del rango?" << std::endl;
    std::cin >> ult;
    std::cout << "Cuantos primos quieres imprimir" << std::endl;
    std::cin >> s;
    
    res = ult - primer;
    while (primer < ult && cont < s)
    {
        int cont = 0;
        if (primer == 0)
        {
            cont = 1;
        }
        else if (primer == 1)
        {
            cont = 1;
        }
        else
        {
            for (int i = 2; i < primer; i++)
            {
                if (primer%i == 0)
                {
                    cont++;
                    break;
                }
            }
        }
        if (cont == 0)
        {
            inip->insertFront(primer);
            cont++;
        }
        primer++;
    }
    
    std::cout << *inip << std::endl;
    std::cout << *ultip << std::endl;
    return 0;
    
}