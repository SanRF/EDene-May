//
//  Persona.cpp
//  Tarea6Eje2
//
//  Created by Santiago Rodriguez Fernandez on 30/04/15.
//  Copyright (c) 2015 Santiago Rodriguez Fernandez. All rights reserved.
//

#include "Persona.h"
void Persona::setTiempoS(int tiempo){
    this->ts += tiempo;
}

void Persona::setTiempoR(int tiempo){
    this->tr += tiempo;
}

int Persona::getTiempoR(){
    return tr;
}

int Persona::getTiempoS(){
    return ts;
}

int Persona::calTiempoR(Persona persona){
    int x = persona.getTiempoR();
    int porcentaje = (x * 100) / 1440;
    return porcentaje;
}

int Persona::calTiempoS(Persona persona){
    int x = calTiempoR(persona);
    int porcentaje = 100 - x;
    return porcentaje;
}

std::string Persona::getApellido(){
    return apellidos;
}

std::string Persona::getNombre(){
    return nombre;
}

void Persona::imprimeLista(){
    for(auto mar : amigos){
        std::cout << mar << std::endl;
    }
    
}

int Persona::getSizeList(){
    return amigos.size();
}

std::list<Persona> Persona::getLista(){
    return amigos;
}

bool Persona::operator >(Persona & persona)
{
    if (apellidos > persona.apellidos) {
        
        return true;
    }
    else if (apellidos == persona.apellidos) {
        
        if (nombre < persona.nombre) {
            return true;
        }
        else {
            return false;
        }
    }
    
    return false;
}
/*
 bool Persona::operator <(Persona & persona)
 {
 return edad < persona.edad;
 }
 */
std::ostream & operator << (std::ostream & os,  const Persona & persona)
{
    os << persona.nombre << "  "<< persona.apellidos << "\n Tiempo de Relacion: " << persona.tr << "\n Tiempo de Soledad: " << persona.ts << std::endl;
    
    return os;
}

bool Persona::operator  == (Persona & persona){
    if(persona.nombre == nombre && persona.apellidos == apellidos){
        return true;
    }else {
        return false;
    }
}


void Persona::agregarAmigo(Persona persona){
    amigos.push_back(persona);
}
