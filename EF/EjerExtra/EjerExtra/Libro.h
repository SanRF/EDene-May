//
//  Libro.h
//  LinkedList
//
//  Created by Vicente Cubells Nonell on 24/02/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#ifndef __LinkedList__Libro__
#define __LinkedList__Libro__

#include <iostream>

namespace vcn {
    
    class Libro {
        std::string nombre;
        int numPag;
        int altura;
    public:
        
        Libro() : Libro("", 0, 0) { }
        
        Libro(std::string _nombre, int _numPag, int _altura)
        : nombre(_nombre), numPag(_numPag), altura(_altura)
        {}
        
        friend std::ostream & operator <<(std::ostream & os, const Libro &);
    };

}
#endif /* defined(__LinkedList__Libro__) */
