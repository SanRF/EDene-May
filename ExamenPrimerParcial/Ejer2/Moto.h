//
//  Moto.h
//  PrimerParcialEje2
//
//  Created by Santiago Rodriguez Fernandez on 19/02/15.
//  Copyright (c) 2015 Santiago Rodriguez Fernandez. All rights reserved.
//

#ifndef __PrimerParcialEje2__Moto__
#define __PrimerParcialEje2__Moto__

#include <stdio.h>
#include <string>
#include <iostream>

class Moto{
private:
    int codigo;
    std::string marca;
    int modelo;
    int kilom;
    int cilind;
    int precio;
public:
    
    Moto(): Moto(0,"",0,0,0,0){}
    
    Moto(int c, std::string ma, int mo, int ki, int ci, int pre): codigo(c), marca(ma), modelo(mo), kilom(ki), cilind(ci), precio(pre){}
    
    int getCodigo(){return codigo;}
    std::string getMarca(){return marca;}
    int getModelo(){return modelo;}
    int getKilom(){return kilom;}
    int getCilindraje(){return cilind;}
    int getPrecio(){return precio;}
    
    void setCodigo(int _codigo){codigo = _codigo;}
    void setMarca(std::string _marca){marca = _marca;}
    void setModelo(int _modelo){modelo = _modelo;}
    void setkilom(int _kilom){kilom = _kilom;}
    
    friend std::ostream & operator <<(std::ostream &, Moto &);
};


#endif /* defined(__PrimerParcialEje2__Moto__) */
