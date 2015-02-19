//
//  Camioneta.cpp
//  PrimerParcialEje2
//
//  Created by Santiago Rodriguez Fernandez on 19/02/15.
//  Copyright (c) 2015 Santiago Rodriguez Fernandez. All rights reserved.
//

#include "Camioneta.h"

std::ostream & operator <<(std::ostream & os, Camioneta & vehiculo)
{
    os << "El codigo del camioneta es:" << vehiculo.getCodigo() << std::endl << "La marca de tu camioneta es: " << vehiculo.getMarca() << std::endl << "El modelo de tu camioneta es: " << vehiculo.getModelo()<<std::endl << "Su kilometraje es de: " << vehiculo.getKilom()<< std::endl << "Su tipo de traccion: " << vehiculo.getMotor() << "\n" << std::endl;
    
    return os;
}