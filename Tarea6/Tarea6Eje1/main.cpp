//
//  main.cpp
//  Tarea6Eje1
//
//  Created by Santiago Rodriguez Fernandez on 30/04/15.
//  Copyright (c) 2015 Santiago Rodriguez Fernandez. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>
#include "Contenedor.h"


int main(){
    
    std::stack<Contenedor> pola;
    std::stack<Contenedor> palo;
    
    int ser;
    
    while(ser != 4){
        
        std::cout << "Elija una opcion: \n 1.- Crear un contenedor \n 2.- Imprimir pila \n 3.- Imprimir almacen \n 4.- Salir" << std::endl;
        std::cin >> ser;
        switch(ser){
            case 1:{
                std::cout << "Nombre del contenedor" << std::endl;
                std::string nombre;
                std::cin >> nombre;
                std::cout << "Numero del contenedor" << std::endl;
                int id;
                std::cin >> id;
                std::cout << "Cuantos articulos deseas meter ?" << std::endl;
                int cantidad;
                std::cin >> cantidad;
                Contenedor contenedor(nombre, 0, id);
                for(int i = 0; i < cantidad; ++i){
                    std::cout << "Nombre de la prenda" << std::endl;
                    std::string prend;
                    std::cin >> prend;
                    std::cout << "Cantidad" << std::endl;
                    int cant;
                    std::cin >> cant;
                    std::cout << "precio por unidad" << std::endl;
                    double precio;
                    std::cin >> precio;
                    Prenda prenda(prend, precio, cant);
                    contenedor.agregarPrenda(prenda);
                }
                std::cout << contenedor.getPrecio() << std::endl;
                double x;
                x = contenedor.getPrecio();
                contenedor.setPrecio(x);
                if(pola.size() < 20){
                    pola.push(contenedor);
                }else if(pola.size() > 20 && palo.size() < 20 ){
                    palo.push(contenedor);
                }else{
                    std::cout << "ya no puedes meter mas contenedores" << std::endl;
                }
            }
                break;
                
            case 2:{
                std::cout << "que pila deseas ver?\n 1 o 2" << std::endl;
                int opi;
                std::cin >> opi;
                if( opi == 1){
                    while( !pola.empty()){
                        std::cout << pola.top() << std::endl;
                        pola.top().imprimeLista();
                        pola.pop();
                    }
                    
                }else if (opi == 2){
                    while( !palo.empty()){
                        std::cout << palo.top() << std::endl;
                        palo.pop();
                    }
                }else{
                    std::cout << "pon una opcion existente" << std::endl;
                }
            }
                break;
                
            case 3:
                
                while( !pola.empty()){
                    std::cout << pola.top() << std::endl;
                    pola.pop();
                }
                
                while( !palo.empty()){
                    std::cout << palo.top() << std::endl;
                    palo.pop();
                }
                break;
                
            default:
                std::cout << "Pon una opcion correcta" << std::endl;
                break;
        }
    }
    
    return 0;
}