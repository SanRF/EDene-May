#include <iostream>
#include "LinkedList.h"
#include <string>
#include <time.h>
#include <stdlib.h>

using namespace vcn;

int main(int argc, const char * argv[])
{
    srand(time(nullptr));
    
    float aleat;
    
    LinkedList<float> lista;
    LinkedList<float> list;
    LinkedList<float> lista2;
    
    int tam;
    int cont = 0;
    int temo;
    
    bool test;
    
    std::cout << "Cantidad de numeros en la primera lista" << std::endl;
    std::cin >> tam;
    std::cout << "Cantidad de numeros en la segunda lista" << std::endl;
    std::cin >> temo;
    
    for (int i = 0; i < tam; i++)
    {
        aleat = rand() % 100;
        aleat = aleat / 10;
        
        lista.insert(aleat, i);
    }
    
    for (int j = 0; j < temo; j++)
    {
        aleat = rand() % 100;
        aleat = aleat / 10;
        
        list.insert(aleat, j);
    }
    
    
    std::cout << lista << std::endl;
    std::cout << list << std::endl;
    
    std::cout << "Seleccione\n1. Union\n2. Interseccion\n3. Resta lista1-lista2\n4. Resta lista2-lista1\n5. Multiplicacion" << std::endl;
    
    int cho;
    std::cin >> cho;
    
    switch (cho)
    {
        case 1:
            for (auto i : lista)
            {
                lista2.insertBack(i.getInfo());
            }
            for (auto j : list)
            {
                cont = 0;
                test = true;
                while (test == true && cont < lista2.size())
                {
                    if (j.getInfo() == lista2.at(cont)->getInfo())
                    {
                        test = false;
                        break;
                    }
                    ++cont;
                }
                if (test)
                {
                    lista2.insertBack(j.getInfo());
                }
            }
            std::cout << std::endl << lista2 << std::endl;
            break;
        case 2:
            for (auto i : lista)
            {
                for (auto j : list)
                {
                    if (i.getInfo() == j.getInfo())
                    {
                        lista2.insertBack(i.getInfo());
                        break;
                    }
                }
                cont++;
            }
            std::cout << lista2 << std::endl;
            break;
        case 3:
            for (auto i : lista)
            {
                cont = 0;
                for (auto j : list)
                {
                    if (i.getInfo() == j.getInfo())
                    {
                        cont = -1;
                        break;
                    }
                }
                if (cont != -1)
                {
                    lista2.insertBack(i.getInfo());
                }
            }
            std::cout << lista2 << std::endl;
            break;
        case 4:
            for (auto i : list)
            {
                cont = 0;
                for (auto j : lista)
                {
                    if (i.getInfo() == j.getInfo())
                    {
                        cont = -1;
                        break;
                    }
                }
                if (cont != -1)
                {
                    lista2.insertBack(i.getInfo());
                }
            }
            std::cout << lista2 << std::endl;
            break;
        case 5:
            for (auto i : lista)
            {
                float a = 1;
                for (auto j : list)
                {
                    a = i.getInfo() * j.getInfo();
                    lista2.insertBack(a);
                }
            }
            std::cout << lista2 << std::endl;
            break;
    }
    
    
    return 0;
}