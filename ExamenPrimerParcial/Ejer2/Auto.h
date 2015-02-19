//
//  Auto.h
//  PrimerParcialEje2
//
//  Created by Santiago Rodriguez Fernandez on 19/02/15.
//  Copyright (c) 2015 Santiago Rodriguez Fernandez. All rights reserved.
//

#ifndef __PrimerParcialEje2__Auto__
#define __PrimerParcialEje2__Auto__

#include <stdio.h>
#include <string>
#include <iostream>

class Auto{
private:
    int codigo;
    std::string marca;
    int modelo;
    int kilom;
public:
    
    Auto(): Auto(0,"",0,0){}
    
    Auto(int c, std::string ma, int mo, int ki): codigo(c), marca(ma), modelo(mo), kilom(ki){}
    
    int getCodigo(){return codigo;}
    std::string getMarca(){return marca;}
    int getModelo(){return modelo;}
    int getKilom(){return kilom;}
    
    void setCodigo(int _codigo){codigo = _codigo;}
    void setMarca(std::string _marca){marca = _marca;}
    void setModelo(int _modelo){modelo = _modelo;}
    void setkilom(int _kilom){kilom = _kilom;}
    
    friend std::ostream & operator <<(std::ostream &, Auto &);
};

#endif /* defined(__PrimerParcialEje2__Auto__) */
