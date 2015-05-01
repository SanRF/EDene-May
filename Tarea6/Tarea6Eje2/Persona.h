//
//  Persona.h
//  Tarea6Eje2
//
//  Created by Santiago Rodriguez Fernandez on 30/04/15.
//  Copyright (c) 2015 Santiago Rodriguez Fernandez. All rights reserved.
//

#ifndef __Tarea6Eje2__Persona__
#define __Tarea6Eje2__Persona__

#include <stdio.h>
#include <iostream>
#include <string>
#include <ostream>
#include <list>

class Persona {
private:
    std::string nombre;
    std::string apellidos;
    int tr;
    int ts;
    std::list<Persona> amigos;
    
public:
    Persona() : Persona("", "", 0, 0) {}
    Persona(std::string _nombre, std::string _apellidos , int _tr, int _ts) : nombre(_nombre), apellidos(_apellidos), tr(_tr), ts(_ts){}
    
    int getTiempoR();
    void setTiempoR(int tiempo);
    int getTiempoS();
    void setTiempoS(int tiempo);
    std::string getNombre();
    std::string getApellido();
    Persona relacionMasEstable();
    int calTiempoS(Persona persona);
    int calTiempoR(Persona persona);
    
    
    bool operator >(Persona & persona);
    bool operator <(Persona & persona);
    bool operator  == (Persona & persona);
    
    void agregarAmigo(Persona persona);
    void imprimeLista();
    int getSizeList();
    std::list<Persona> getLista();
    
    friend std::ostream & operator << (std::ostream & os, const Persona & persona);
    
};
#endif /* defined(__Tarea6Eje2__Persona__) */
