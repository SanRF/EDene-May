//
//  Persona.h
//  Listas
//
//  Created by Santiago Rodriguez Fernandez on 06/03/15.
//  Copyright (c) 2015 Santiago Rodriguez Fernandez. All rights reserved.
//

#ifndef __Listas__Persona__
#define __Listas__Persona__

#include <iostream>
#include <stdio.h>

class Persona
{
private:
    std::string nombre, apellidos;
    int edad;
    int año, mes, dia;
    
public:
    Persona() {}
    Persona(std::string nom, std::string ape, int ed, int añ, int me, int di) : nombre(nom), apellidos(ape), edad(ed), año(añ), mes(me), dia(di){}
    
    ~Persona() {}
    
    std::string getNombre() {return nombre;}
    std::string getApellidos() {return apellidos;}
    int getEdad() {return edad;}
    int getAño() {return año;}
    int getMes() {return mes;}
    int getDia() {return dia;}
    
    friend std::ostream & operator << (std::ostream&, Persona);
    bool operator <(Persona);
    bool operator >(Persona);
};

#endif /* defined(__Listas__Persona__) */
