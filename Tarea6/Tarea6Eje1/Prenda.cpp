//
//  Prenda.cpp
//  Tarea6Eje1
//
//  Created by Santiago Rodriguez Fernandez on 30/04/15.
//  Copyright (c) 2015 Santiago Rodriguez Fernandez. All rights reserved.
//

#include "Prenda.h"

std::string Prenda::getNombre(){
    return nombre;
}

double Prenda::getPrecio(){
    return precio;
}

std::ostream & operator << (std::ostream & os,  const Prenda & prenda)
{
    os << "Prenda: " << prenda.nombre << "\nCantidad: " << prenda.cantidad <<  "\nPrecio unitario: $" << prenda.precio << "\n   " << std::endl;
    
    return os;
}