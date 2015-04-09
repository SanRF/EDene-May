//
//  Persona.cpp
//  Listas
//
//  Created by Santiago Rodriguez Fernandez on 06/03/15.
//  Copyright (c) 2015 Santiago Rodriguez Fernandez. All rights reserved.
//

#include "Persona.h"

std::ostream & operator << (std::ostream & os, Persona per)
{
    os << "Nombre: " << per.nombre << " Apellidos: " << per.apellidos << std::endl;
    os << "Edad: " << per.edad << std::endl;
    os << "Fecha de nacimiento: " << per.año << "/" << per.mes << "/" << per.dia << std::endl;
    return os;
}

bool Persona::operator <(Persona per)
{
    if(apellidos == per.getApellidos())
    {
        if(nombre > per.nombre)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(apellidos > per.getApellidos())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Persona::operator >(Persona per)
{
    if(apellidos == per.getApellidos())
    {
        if(nombre < per.nombre)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(apellidos < per.getApellidos())
    {
        return true;
    }
    else
    {
        return false;
    }
}
