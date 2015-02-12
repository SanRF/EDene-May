//
//  main.cpp
//  Tarea2.2
//
//  Created by Santiago Rodriguez Fernandez on 11/02/15.
//  Copyright (c) 2015 Santiago Rodriguez Fernandez. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include "BusquedaGen.h"


char RandGen()
{
    static const char alphanu[] =
    "0123456789"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz";
    
    int stringLength = sizeof(alphanu) - 1;
    return alphanu[rand() % stringLength];
}

void fill(std::string list[], int size)
{
    std::string arre;
    for (int i = 0; i < size; i++)
    {
        for (int a = 0; a <5; a++)
        {
            arre += RandGen();
        }
        
        list[i] = arre;
        arre.clear();
    }
}

void printArreglo(std::string lista[], int size)
{
    for (int a = 0; a < size; a++)
    {
        std::cout << lista[a] << std::endl;
    }
}

int main()
{
    
    int csc;
    const int size = 1000;
    std::string lista[size];
    
    do{
        std::cout << "Selecciona una de las siguientes opciones: " << std::endl;
        std::cout << "1.- Rellenar el arreglo: " << std::endl;
        std::cout << "2.- Imprimir el arreglo: " << std::endl;
        std::cout << "3.- Seleccionar ordenamiento por burbuja de manera ascendente: " << std::endl;
        std::cout << "4.- Seleccionar ordenamiento por burbuja de manera descendente: " << std::endl;
        std::cout << "5.- Seleccionar ordenamiento por insercion de manera ascendente: " << std::endl;
        std::cout << "6.- Seleccionar ordenamiento por insercion de manera descendente: " << std::endl;
        std::cout << "7.- Seleccionar ordenamiento por seleccion de manera ascendente: " << std::endl;
        std::cout << "8.- Seleccionar ordenamiento por seleccion de manera descendente: " << std::endl;
        std::cout << "Presione '0' para salir." << std::endl;
        std::cin >> csc;
        
        switch (csc) {
            case 1:{
                fill(lista, size);
            }
                break;
            
            case 2:{
                printArreglo(lista, size);
            }
                break;
                
            case 3:{
                Ordenamiento<std::string>::burbuja(lista, size, Ordenamiento<std::string>::asc);
            }
                break;
                
            case 4:{
                Ordenamiento<std::string>::burbuja(lista, size, Ordenamiento<std::string>::desc);
            }
                break;
                
            case 5:{
                Ordenamiento<std::string>::insercion(lista, size, Ordenamiento<std::string>::asc);
            }
                break;
                
            case 6:{
                Ordenamiento<std::string>::insercion(lista, size, Ordenamiento<std::string>::desc);
            }
                break;
            
            case 7:{
                Ordenamiento<std::string>::seleccion(lista, size, Ordenamiento<std::string>::asc);
            }
                break;
                
            case 8:{
                Ordenamiento<std::string>::seleccion(lista, size, Ordenamiento<std::string>::desc);
            }
                break;
            default: std::cout << "Esa no es una opcion valida" << std::endl;
                break;
        }
    }
        while(csc!=0);
    
    return 0;
}
