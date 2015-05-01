//
//  Prenda.h
//  Tarea6Eje1
//
//  Created by Santiago Rodriguez Fernandez on 30/04/15.
//  Copyright (c) 2015 Santiago Rodriguez Fernandez. All rights reserved.
//

#ifndef __Tarea6Eje1__Prenda__
#define __Tarea6Eje1__Prenda__

#include <stdio.h>
#include <iostream>
#include <string>

class Prenda{
private:
    double precio;
    std::string nombre;
    int cantidad;
public:
    Prenda() : Prenda("", 0, 0){}
    Prenda(std::string _nombre, double _precio, int _cantidad) : nombre(_nombre), precio(_precio), cantidad(_cantidad){}
    std::string getNombre();
    double getPrecio();
    friend std::ostream & operator << (std::ostream & os, const Prenda & prenda);
    
};

#endif /* defined(__Tarea6Eje1__Prenda__) */
