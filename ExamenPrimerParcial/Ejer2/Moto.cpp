//
//  Moto.cpp
//  PrimerParcialEje2
//
//  Created by Santiago Rodriguez Fernandez on 19/02/15.
//  Copyright (c) 2015 Santiago Rodriguez Fernandez. All rights reserved.
//

#include "Moto.h"

std::ostream & operator <<(std::ostream & os, Moto & vehiculo)
{
    os << "El codigo del Moto es:" << vehiculo.getCodigo() << std::endl << "La marca de tu Moto es: " << vehiculo.getMarca() << std::endl << "El modelo de tu Moto es: " << vehiculo.getModelo()<<std::endl << "Su kilometraje es de: " << vehiculo.getKilom()<< std::endl << "El cilindraje es: " << vehiculo.getCilindraje() << std::endl<< "El prcio de tu moto en pesos: "  << vehiculo.getPrecio() << "\n" << std::endl;
    
    return os;
}