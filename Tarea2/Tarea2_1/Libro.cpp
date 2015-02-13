//
//  Libro.cpp
//  Tarea2_1
//
//  Created by Santiago Rodriguez Fernandez on 12/02/15.
//  Copyright (c) 2015 Santiago Rodriguez Fernandez. All rights reserved.
//

#include "Libro.h"

Libro::Libro() : Libro(" ", " ", 0, 0, "", 0)
{
    
}


Libro::Libro(std::string tit, std::string aut, int nump, int edic, std::string edito, int anp) : titulo(tit), autor(aut), numPag(nump), edicion(edic), editorial(edito), anPub(anp){

}

std::ostream & operator <<(std::ostream & os, Libro & libro)
{
    os << libro.getTitulo() << " "<< libro.getAutor()  << " " << libro.getEdicion() << " " << libro.getEditorial() << " " << libro.getNumPag()<< " " << libro.getAnPub() << " " << std::endl;
    
    return os;
}
