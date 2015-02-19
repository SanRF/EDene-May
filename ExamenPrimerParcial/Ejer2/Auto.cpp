//
//  Auto.cpp
//  PrimerParcialEje2
//
//  Created by Santiago Rodriguez Fernandez on 19/02/15.
//  Copyright (c) 2015 Santiago Rodriguez Fernandez. All rights reserved.
//

#include "Auto.h"

std::ostream & operator <<(std::ostream & os, Auto & vehiculo)
{
    os << "El codigo del auto es:" << vehiculo.getCodigo() << std::endl << "La marca de tu auto es: " << vehiculo.getMarca() << std::endl << "El modelo de tu auto es: " << vehiculo.getModelo()<<std::endl << "Su kilometraje es de: " << vehiculo.getKilom()<< "\n" << std::endl;
    
    return os;
}