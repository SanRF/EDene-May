//
//  Contenedor.h
//  Tarea6Eje1
//
//  Created by Santiago Rodriguez Fernandez on 30/04/15.
//  Copyright (c) 2015 Santiago Rodriguez Fernandez. All rights reserved.
//

#ifndef __Tarea6Eje1__Contenedor__
#define __Tarea6Eje1__Contenedor__

#include <stdio.h>
#include <iostream>
#include <string>
#include <list>
#include "Prenda.h"


class Contenedor{
private:
    std::string nombre;
    int numero;
    double precio;
    std::list<Prenda> prendas;
public:
    Contenedor() : Contenedor("", 0, 0){}
    Contenedor(std::string _nombre, double _precio, int _numero) : nombre(_nombre), precio(_precio), numero(_numero){}
    
    std::string getNombre();
    int getNumero();
    double getPrecio();
    void agregarPrenda(Prenda prenda);
    void setPrecio(double precio);
    int getSizeLista();
    void imprimeLista();
    std::list<Prenda> getLista();
    
    friend std::ostream & operator << (std::ostream & os, const Contenedor & contenedor);
};

#endif /* defined(__Tarea6Eje1__Contenedor__) */
