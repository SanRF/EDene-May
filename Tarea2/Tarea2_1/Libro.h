//
//  Libro.h
//  Tarea2_1
//
//  Created by Santiago Rodriguez Fernandez on 12/02/15.
//  Copyright (c) 2015 Santiago Rodriguez Fernandez. All rights reserved.
//

#ifndef __Tarea2_1__Libro__
#define __Tarea2_1__Libro__

#include <stdio.h>
#include <iostream>
#include <string>

class Libro{
private:
    std::string titulo;
    std::string autor;
    int numPag;
    std::string editorial;
    int edicion;
    int anPub;
    
public:
    
    Libro();
    Libro(std::string, std::string, int, int, std::string, int);

    std::string getTitulo(){return titulo;}
    void setTitulo(std::string _titulo){titulo = _titulo;}
    
    std::string getAutor(){return autor;}
    void setAutor(std::string _autor){autor = _autor;}
    
    std::string getEditorial(){return editorial;}
    void setEditorial(std::string _editorial){editorial = _editorial;}
    
    int getNumPag(){return numPag;}
    void setNumPag(int _numPag){numPag = _numPag;}
    
    int getEdicion(){return edicion;}
    void setEdicion(int _edicion){edicion = _edicion;}
    
    int getAnPub(){return anPub;}
    void setAnPub(int _anPub){anPub = _anPub;}
    
    bool operator == (Libro &);
    bool operator > (Libro &);
    
    friend std::ostream & operator << (std::ostream &, Libro &);
    
    friend std::ostream & operator <<(std::ostream &, Libro &);

    
};
#endif /* defined(__Tarea2_1__Libro__) */
