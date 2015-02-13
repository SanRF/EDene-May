//
//  Libro.cpp
//  Tarea2_3
//
//  Created by Santiago Rodriguez Fernandez on 12/02/15.
//  Copyright (c) 2015 Santiago Rodriguez Fernandez. All rights reserved.
//

#include "Libro.h"

#include "Libro.h"

std::ostream & operator << (std::ostream & os, Libro & libro)
{
    os << "Titulo: " << libro.getTitulo() << ";" << " Autor: " << libro.getAutor() << ";" << " Editorial: " << libro.getEditorial() << std::endl;
    os << "Anio de publicacion: " << libro.getAnPub() << ";" << " Numero de edicion: " << libro.getEdicion() << ";" << " Numero de paginas: " << libro.getPaginas() << std::endl;
    return os;
}

bool Libro::operator == (const Libro & libro)
{
    if (titulo == libro.titulo)
        return true;
    else
        return false;
}