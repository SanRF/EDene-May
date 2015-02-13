//
//  main.cpp
//  Tarea2_3
//
//  Created by Santiago Rodriguez Fernandez on 12/02/15.
//  Copyright (c) 2015 Santiago Rodriguez Fernandez. All rights reserved.
//

#include <iostream>
#include <string>
#include "Libro.h"
#include "BusGen.h"


int IngresaValor();

int main(int argc, char **argv)
{
    Libro orden[10];
    orden[0] = Libro("Si", "Digimon", "Del", 223, 13, 1930);
    orden[1] = Libro("Tu", "El", "Di", 13, 100, 1920);
    orden[2] = Libro("Lo", "Cielo", "Gi", 220, 12, 1123);
    orden[3] = Libro("Deseas", "Alcanzar", "Mo", 1, 78, 1989);
    orden[4] = Libro("Puedes", "Y", "Oooo", 14, 123, 1810);
    orden[5] = Libro("Volar", "Las", "On", 56, 398, 1942);
    orden[6] = Libro("Situ", "Estrellas", "Wow", 100, 100, 1752);
    orden[7] = Libro("Quieres", "Tocar", "La", 12, 45, 1642);
    orden[8] = Libro("100 Anios de soledad", "GG NO RE", "Machu", 4, 178, 3423);
    orden[9] = Libro("Gabiota", "Sera", "Mario", 20, 180, 1489);
    int seleccion = 0;
    while(seleccion != 5)
    {
        std::cout << "Bienvenido, eliga una de las siguientes opciones\n1.- Por titulo \n2.- Por edicion \n3.- Por anio de publicacion \n4.- Imprimir arreglo \nSeleccione '5' para salir" << std::endl;
        seleccion = IngresaValor();
        switch(seleccion)
        {
            case 1:
                seleccion = 0;
                while(seleccion != 7)
                {
                    std::cout << "Eliga una de las opciones de ordenamiento \n1.- Insercion ascendente \n2.- Insercion descendente \n3.- Burbuja ascendente \n4.- Burbuja descendente \n5. Seleccion ascendente \n6.- Seleccion descendiente \n7.- Salir" << std::endl;
                    seleccion = IngresaValor();
                    switch(seleccion)
                    {
                        case 1:
                            Ordenamiento<Libro>::insercion(orden, 10, [] (Libro a, Libro b) {return a.getTitulo() > b.getTitulo();});
                            std::cout << "Se ordeno el arreglo" << std::endl;
                            seleccion = 7;
                            break;
                        case 2:
                            Ordenamiento<Libro>::insercion(orden, 10, [] (Libro a, Libro b) {return a.getTitulo() < b.getTitulo();});
                            std::cout << "Se ordeno el arreglo" << std::endl;
                            seleccion = 7;
                            break;
                        case 3:
                            Ordenamiento<Libro>::burbuja(orden, 10, [] (Libro a, Libro b) {return a.getTitulo() > b.getTitulo();});
                            std::cout << "Se ordeno el arreglo" << std::endl;
                            seleccion = 7;
                            break;
                        case 4:
                            Ordenamiento<Libro>::burbuja(orden, 10, [] (Libro a, Libro b) {return a.getTitulo() < b.getTitulo();});
                            std::cout << "Se ordeno el arreglo" << std::endl;
                            seleccion = 7;
                            break;
                        case 5:
                            Ordenamiento<Libro>::seleccion(orden, 10, [] (Libro a, Libro b) {return a.getTitulo() > b.getTitulo();});
                            std::cout << "Se ordeno el arreglo" << std::endl;
                            seleccion = 7;
                            break;
                        case 6:
                            Ordenamiento<Libro>::seleccion(orden, 10, [] (Libro a, Libro b) {return a.getTitulo() < b.getTitulo();});
                            std::cout << "Se ordeno el arreglo" << std::endl;
                            seleccion = 7;
                            break;
                        case 7:
                            break;
                    }
                }
                seleccion = 0;
                break;
            case 2:
                seleccion = 0;
                while(seleccion != 7)
                {
                    std::cout << "Eliga una de las opciones de ordenamiento \n1.- Insercion ascendente \n2.- Insercion descendente \n3.- Burbuja ascendente \n4.- Burbuja descendente \n5. Seleccion ascendente \n6.- Seleccion descendiente \n7.- Salir" << std::endl;
                    seleccion = IngresaValor();
                    switch(seleccion)
                    {
                        case 1:
                            Ordenamiento<Libro>::insercion(orden, 10, [] (Libro a, Libro b) {return a.getEdicion() > b.getEdicion();});
                            std::cout << "Se ordeno el arreglo" << std::endl;
                            seleccion = 7;
                            break;
                        case 2:
                            Ordenamiento<Libro>::insercion(orden, 10, [] (Libro a, Libro b) {return a.getEdicion() < b.getEdicion();});
                            std::cout << "Se ordeno el arreglo" << std::endl;
                            seleccion = 7;
                            break;
                        case 3:
                            Ordenamiento<Libro>::burbuja(orden, 10, [] (Libro a, Libro b) {return a.getEdicion() > b.getEdicion();});
                            std::cout << "Se ordeno el arreglo" << std::endl;
                            seleccion = 7;
                            break;
                        case 4:
                            Ordenamiento<Libro>::burbuja(orden, 10, [] (Libro a, Libro b) {return a.getEdicion() < b.getEdicion();});
                            std::cout << "Se ordeno el arreglo" << std::endl;
                            seleccion = 7;
                            break;
                        case 5:
                            Ordenamiento<Libro>::seleccion(orden, 10, [] (Libro a, Libro b) {return a.getEdicion() > b.getEdicion();});
                            std::cout << "Se ordeno el arreglo" << std::endl;
                            seleccion = 7;
                            break;
                        case 6:
                            Ordenamiento<Libro>::seleccion(orden, 10, [] (Libro a, Libro b) {return a.getEdicion() < b.getEdicion();});
                            std::cout << "Se ordeno el arreglo" << std::endl;
                            seleccion = 7;
                            break;
                        case 7:
                            break;
                    }
                }
                seleccion = 0;
                break;
            case 3:
                seleccion = 0;
                while(seleccion != 7)
                {
                    std::cout << "Eliga una de las opciones de ordenamiento \n1.- Insercion ascendente \n2.- Insercion descendente \n3.- Burbuja ascendente \n4.- Burbuja descendente \n5. Seleccion ascendente \n6.- Seleccion descendiente \n7.- Salir" << std::endl;
                    seleccion = IngresaValor();
                    switch(seleccion)
                    {
                        case 1:
                            Ordenamiento<Libro>::insercion(orden, 10, [] (Libro a, Libro b) {return a.getAnPub() > b.getAnPub();});
                            std::cout << "Se ordeno el arreglo" << std::endl;
                            seleccion = 7;
                            break;
                        case 2:
                            Ordenamiento<Libro>::insercion(orden, 10, [] (Libro a, Libro b) {return a.getAnPub() < b.getAnPub();});
                            std::cout << "Se ordeno el arreglo" << std::endl;
                            seleccion = 7;
                            break;
                        case 3:
                            Ordenamiento<Libro>::burbuja(orden, 10, [] (Libro a, Libro b) {return a.getAnPub() > b.getAnPub();});
                            std::cout << "Se ordeno el arreglo" << std::endl;
                            seleccion = 7;
                            break;
                        case 4:
                            Ordenamiento<Libro>::burbuja(orden, 10, [] (Libro a, Libro b) {return a.getAnPub() < b.getAnPub();});
                            std::cout << "Se ordeno el arreglo" << std::endl;
                            seleccion = 7;
                            break;
                        case 5:
                            Ordenamiento<Libro>::seleccion(orden, 10, [] (Libro a, Libro b) {return a.getAnPub() > b.getAnPub();});
                            std::cout << "Se ordeno el arreglo" << std::endl;
                            seleccion = 7;
                            break;
                        case 6:
                            Ordenamiento<Libro>::seleccion(orden, 10, [] (Libro a, Libro b) {return a.getAnPub() < b.getAnPub();});
                            std::cout << "Se ordeno el arreglo" << std::endl;
                            seleccion = 7;
                            break;
                        case 7:
                            break;
                    }
                }
                seleccion = 0;
                break;
            case 4:
                for(int i = 0; i < 10; i++)
                {
                    std::cout << orden[i] << std:: endl;
                }
                break;
            case 5:
                break;
        }
    }
    
    
    
    
    return 0;
}

int IngresaValor()
{
    int zeit;
    std::cin >> zeit;
    while(!std::cin)
    {
        std::cout << "Entrada no valida, por favor entre un numero" << std::endl;
        std::cin.clear();
        std::cin.sync();
        std::cin >> zeit;
    }
    return zeit;
}