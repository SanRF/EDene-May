//
//  Libro.h
//  Tarea2_3
//
//  Created by Santiago Rodriguez Fernandez on 12/02/15.
//  Copyright (c) 2015 Santiago Rodriguez Fernandez. All rights reserved.
//

#ifndef __Tarea2_3__Libro__
#define __Tarea2_3__Libro__

#include <iostream>

class Libro
{
protected:
    std::string titulo;
    std::string autor;
    std::string editorial;
    int anio;
    int edicion;
    int paginas;
    
public:
    Libro() : Libro("", "", "", 0, 0, 0) {}
    Libro(std::string _titulo, std::string _autor, std::string _editorial, int _anio, int _edicion, int _paginas) : titulo(_titulo), autor(_autor), editorial(_editorial), anio(_anio), edicion(_edicion), paginas(_paginas) {}
    
    void setTitulo(std::string _titulo) {titulo = _titulo;}
    void setAutor(std::string _autor) {autor = _autor;}
    void setEditorial(std::string _editorial) {editorial = _editorial;}
    void setAnio(int _anio) {anio = _anio;}
    void setEdicion(int _edicion) {edicion = _edicion;}
    void setPaginas(int _paginas) {paginas = _paginas;}
    
    std::string getTitulo() {return titulo;}
    std::string getAutor() {return autor;}
    std::string getEditorial() {return editorial;}
    int getAnPub() {return anio;}
    int getEdicion() {return edicion;}
    int getPaginas() {return paginas;}
    
    friend std::ostream & operator << (std::ostream &, Libro &);
    bool operator == (const Libro &);
    
};

#endif /* defined(__Tarea2_3__Libro__) */
