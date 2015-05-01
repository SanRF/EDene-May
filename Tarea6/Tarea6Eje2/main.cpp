//
//  main.cpp
//  Tarea6Eje2
//
//  Created by Santiago Rodriguez Fernandez on 30/04/15.
//  Copyright (c) 2015 Santiago Rodriguez Fernandez. All rights reserved.
//

#include <iostream>
#include <string>
#include <list>
#include "Persona.h"

void navega(Persona persona);


std::list<Persona> personas;

int main(){
    int ter;
    while(ter != 3){
        std::cout << " 1. Iniciar sesion\n 2. Registrarte\n 3. Salir" << std::endl;
        std::cin >> ter;
        if (ter == 1){
            //inicia sesion
            std::cout << "Nombre: " ;
            std::string nombre;
            std::cin.ignore();
            getline(std::cin,nombre);
            
            std::cout << "Apellido: " ;
            std::string apellido;
            std::cin >> apellido;
            
        }else if(ter == 2){
            //Registrate
            std::cout << "Nombre: " ;
            std::string nombre;
            std::cin.ignore();
            getline(std::cin,nombre);
            
            std::cout << "Apellido: " ;
            std::string apellido;
            std::cin >> apellido;
            
            Persona persona(nombre, apellido, 0, 0);
            personas.push_back(persona);
            
            int op;
            while(op != 6){
                std::cout << "1. Persona Nueva \n2. Tienes un nuevo amigo" << std::endl;
                std::cout << "3.- Quieres saber tus porcentajes de tiempo" << std::endl;
                std::cout << "6. Salir" << std::endl;
                std::cin >> op;
                switch(op){
                    case 1:{
                        
                    }
                        break;
                        
                    case 2:{
                        std::cout << "Nombre de tu amigo: " ;
                        std::string nombre;
                        std::cin.ignore();
                        getline(std::cin,nombre);
                        
                        std::cout << "Apellido de tu amigo: " ;
                        std::string apellido;
                        std::cin >> apellido;
                        
                        Persona amigo;
                        
                        int whila = 0;
                        bool registrado = false;
                        while (whila != 666){
                            for (auto tor : personas){
                                if( tor.getNombre() == nombre && tor.getApellido() == apellido){
                                    amigo = tor;
                                    registrado = true;
                                }
                            }
                            if(!registrado){
                                std::cout << "No existe esa persona" << std::endl;
                                whila = 666;
                                break;
                            }
                        }
                        
                        std::cout << "Tiempo que pasaste con tu amigo (en minutos)" << std::endl;
                        int minutos;
                        std::cin >> minutos;
                        
                        persona.agregarAmigo(amigo);
                        persona.setTiempoR(minutos);
                        amigo.setTiempoR(minutos);
                        persona.setTiempoS(1440 - minutos);
                        amigo.setTiempoS(1440 - minutos);
                        
                        
                    }
                        break;
                        
                    case 3:{
                        std::cout << "Nombre: " ;
                        std::string nombre;
                        std::cin.ignore();
                        getline(std::cin,nombre);
                        
                        std::cout << "Apellido: " ;
                        std::string apellido;
                        std::cin >> apellido;
                        
                        Persona amigo;
                        
                        int whila = 0;
                        bool registrado = false;
                        while (whila != 666){
                            for (auto tor : personas){
                                if( tor.getNombre() == nombre && tor.getApellido() == apellido){
                                    amigo = tor;
                                    registrado = true;
                                }
                            }
                            if(!registrado){
                                std::cout << "No existe esa persona" << std::endl;
                                whila = 666;
                                break;
                            }
                        }
                        std::cout << "porcentaje de relacion: " << amigo.calTiempoR(amigo)<< std::endl;
                        std::cout << "Porcentaje soledad: " << amigo.calTiempoS(amigo) << std::endl;
                    }
                        break;
                        
                    default:
                        std::cout << "Pon una opcion correcta" << std::endl;
                        break;
                }
            }
        }else if(ter == 3){
        }else{
            std::cout << "pon una opcion real" << std::endl;
        }
        
    }
    
    return 0;
}
