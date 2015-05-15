//
//  Libro.cpp
//  LinkedList
//
//  Created by Vicente Cubells Nonell on 24/02/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#include "Libro.h"


namespace vcn {
    
    std::ostream & operator <<(std::ostream & os, const Libro & c)
    {
        os << "Nombre : " << c.nombre << std::endl;
        os << "Paginas : " << c.numPag << std::endl;
        os << "Altura : " << c.altura << std::endl;
        
        return os;
    }

}