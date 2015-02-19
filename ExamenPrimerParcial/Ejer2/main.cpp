//
//  main.cpp
//  PrimerParcialEje2
//
//  Created by Santiago Rodriguez Fernandez on 19/02/15.
//  Copyright (c) 2015 Santiago Rodriguez Fernandez. All rights reserved.
//

#include <iostream>
#include "Auto.h"
#include "Camioneta.h"
#include "Moto.h"

template <typename T>
void imprimeArreglo(T[], int);

int main()
{
    Auto coches[3];
    Camioneta autos[3];
    Moto motos[3];
    
    coches[0] = Auto(123,"Toyota",1990,0000);
    coches[1] = Auto(234,"Mitsu",1990,0000);
    coches[2] = Auto(345,"Honda",1990,0000);
    imprimeArreglo<Auto>(coches, 3);
    
    autos[0] = Camioneta(453,"Ford",1990,0000,"4x4");
    autos[1] = Camioneta(564,"Chevrolet",1990,0000,"4x2");
    autos[2] = Camioneta(231,"Honda",1990,0000,"AWD");
    imprimeArreglo<Camioneta>(autos, 3);
    
    motos[0] = Moto(673,"Ford",1990,0000,150, 2000);
    motos[1] = Moto(124,"Chevrolet",1990,0000,250, 4000);
    motos[2] = Moto(831,"Honda",1990,0000,350, 5000);
    imprimeArreglo<Moto>(motos, 3);
    
    
}

template <typename T>
void imprimeArreglo(T v[], int longitud)
{
    for (int i = 0; i < longitud; ++i) {
        std::cout << v[i] << " ";
    }
    
    std::cout << std::endl;
}