//
//  Contenedor.cpp
//  Tarea6Eje1
//
//  Created by Santiago Rodriguez Fernandez on 30/04/15.
//  Copyright (c) 2015 Santiago Rodriguez Fernandez. All rights reserved.
//

#include "Contenedor.h"

void Contenedor::setPrecio(double precio){
    this->precio = precio;
}

void Contenedor::agregarPrenda(Prenda prenda){
    prendas.push_back(prenda);
}

std::string Contenedor::getNombre(){
    return nombre;
}

int Contenedor::getNumero(){
    return numero;
}

double Contenedor::getPrecio(){
    for(auto mar: prendas){
        precio += mar.getPrecio();
    }
    return precio;
}


std::ostream & operator << (std::ostream & os,  const Contenedor & contenedor)
{
    os << "Contenedor: " << contenedor.nombre << ", No " << contenedor.numero << "\nTotal: " << contenedor.precio << std::endl;
    
    return os;
}


int Contenedor::getSizeLista(){
    return prendas.size();
}

void Contenedor::imprimeLista(){
    for(auto mar : prendas){
        std::cout << mar << std::endl;
    }
}

std::list<Prenda> Contenedor::getLista(){
    return prendas;
}