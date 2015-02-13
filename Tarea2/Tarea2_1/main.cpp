//
//  main.cpp
//  Tarea2_1
//
//  Created by Santiago Rodriguez Fernandez on 12/02/15.
//  Copyright (c) 2015 Santiago Rodriguez Fernandez. All rights reserved.
//

#include <iostream>
#include "Libro.h"
#include <string>
#include "BusquedaG.h"

template<typename T>
void  crear(T[], std::string, std::string, int , int, std::string, int, int pos, int size);

template <typename T>
void imprimeArreglo(T[], int);

int* nuevaBusqueda(int*, int&);

template <typename T>
void pull(T[], int, int);

int main(int argc, const char * argv[]) {
    // insert code here...
    const int tam = 10;
    
    int *pos2 = new int[tam];
    int Encontrado = 0;
    
    Libro m[tam];
    int pos = 0;
    int seleccion;
    
    do{
        std::cout << "Bienvenido, seleccione una de las siguientes opciones" << std::endl;
        std::cout << "1.- Agregar Libro \n2.- Imprime Biblioteca \n3.- Busca Libro por autor \n4.- Buscar libros antes de una fecha \n5.- Buscar libros despues de una fecha \n6.- Buscar por nombre de la editorial \n7.- Buscar entre dos fechas \n8.- Borra un libro \nSeleccione '0' para salir" << std::endl;
        std::cin >> seleccion;
        std::cin.ignore();
        
        switch (seleccion) {
            case 1:{
                std::string titu;
                std::string autor;
                std::string edito;
                
                int edici = 0;
                int numer = 0;
                int anP = 0;
                
                std::cout << "Escribe el titulo del libro: " << std::endl;
                std::getline (std::cin, titu);
                std::cout << "Escribe el autor del libro: " << std::endl;
                std::getline (std::cin, autor);
                std::cout << "Escribe la editorial del libro: " << std::endl;
                std::getline (std::cin, edito);
                std::cout << "Escribe la edicion del libro: " << std::endl;
                std::cin >> edici;
                std::cout << "Escribe el numero de paginas" << std::endl;
                std::cin >> numer;
                std::cout << "Escribe el año de publicacion: " << std::endl;
                std::cin >> anP;
                
                crear(m, titu, autor, numer, edici, edito, anP, pos, tam);
                pos++;
            }
                break;
                
            case 2:{
                imprimeArreglo<Libro>(m, tam);
            }
                break;
              
            case 3:
            {
                std::cout << "Entre el nombre del autor que se quiere buscar: ";
                
                std::string titulo;
                
                std::getline (std::cin, titulo);
                
                Libro m2[tam];
                
                pos2 = nuevaBusqueda(pos2, Encontrado);
                
                pos2 = Busqueda<Libro, std::string>::busquedaSecuencialPosicion(m, titulo, tam, pos2, Encontrado, [](Libro a, std::string b){return a.getAutor() == b; });
                
                for (int i = 0; i < Encontrado; i++)
                {
                    m2[i] = m[pos2[i]];
                }
                imprimeArreglo<Libro>(m2, tam);
            }
                break;
            case 4:
            {
                std::cout << "Ingresa la fecha con la cual quieres buscar libros despues de ese año: " << std::endl;
                int fecha;
                std::cin >> fecha;
                Libro m2[tam];
                
                pos2 = nuevaBusqueda(pos2, Encontrado);
                pos2 = Busqueda<Libro, int>::busquedaSecuencialPosicion(m, fecha, tam, pos2, Encontrado, [](Libro a, int b){return a.getAnPub() < b; });
                
                for (int i = 0; i < Encontrado; i++)
                {
                    m2[i] = m[pos2[i]];
                }
                imprimeArreglo<Libro>(m2, tam);
            }
                break;
            case 5:
            {
                std::cout << "Ingresa la fecha con la cual quieres buscar libros despues de ese año: " << std::endl;
                int date;
                std::cin >> date;
                Libro m2[tam];
                
                pos2 = nuevaBusqueda(pos2, Encontrado);
                pos2 = Busqueda<Libro, int>::busquedaSecuencialPosicion(m, date, tam, pos2, Encontrado, [](Libro a, int b){return a.getAnPub() > b; });
                for (int i = 0; i < Encontrado; i++)
                {
                    m2[i] = m[pos2[i]];
                }
                imprimeArreglo<Libro>(m2, tam);
                
            }
                break;
            case 6:
            {
                std::cout << "Entre el nombre de la editorial del libro a buscar: ";
                
                std::string titulo;
                
                std::getline(std::cin, titulo);
                
                Libro m2[tam];
                
                pos2 = nuevaBusqueda(pos2, Encontrado);
                
                pos2 = Busqueda<Libro, std::string>::busquedaSecuencialPosicion(m, titulo, tam, pos2, Encontrado, [](Libro a, std::string b){return a.getEditorial() == b; });
                
                for (int i = 0; i < Encontrado; i++)
                {
                    m2[i] = m[pos2[i]];
                }
                imprimeArreglo<Libro>(m2, tam);
            }
                break;
            case 7:
            {
                std::cout << "Pon la fecha para buscar libros despues de un año: " << std::endl;
                int date1;
                std::cout << "Pon la fecha para buscar antes de un año: " << std::endl;
                int date2;
                std::cin >> date1;
                std::cin >> date2;
                Libro m2[tam];
                
                pos2 = nuevaBusqueda(pos2, Encontrado);
                pos2 = Busqueda<Libro, int>::busquedaSecuencial(m, date1, tam, pos2, Encontrado, date2, [](Libro a, int b, int c){return (a.getAnPub() > b && a.getAnPub() < c); });
                for (int i = 0; i < Encontrado; i++)
                {
                    m2[i] = m[pos2[i]];
                }
                imprimeArreglo<Libro>(m2, tam);
            }
                break;
            case 8:
            {
                int erase;
                std::cout << "Escribe la posicion del libro que deseas eliminar: " << std::endl;
                std::cin >> erase;
                pull(m, erase, tam);
                
            }
                
            default:
                break;
            }
        }
    while (seleccion !=0);
    
    return 0;
}

template < typename T>
void crear(T arreglo[], std::string tit, std::string au, int num, int ed, std::string edi, int añ, int pos, int size)
{
    if (pos < size)
    {
        arreglo[pos] = Libro(tit, au, num, ed, edi, añ);
        pos++;
    }
}

template <typename T>
void pull(T arreglo[], int pos, int size)
{
    T temp;
    for (int i = pos; i < size; i++)
    {
        //arreglo[i - 1] = 0;
        temp = arreglo[i];
        arreglo[i - 1] = temp;
    }
    pos--;
    
}

template <typename T>
void imprimeArreglo(T v[], int longitud)
{
    for (int i = 0; i < longitud; ++i) {
        std::cout << v[i] << " ";
    }
    
    std::cout << std::endl;
}

int* nuevaBusqueda(int* encontrados, int &posEncontrados)
{
    int* encontradosNuevo = new int[10];
    posEncontrados = 0;
    delete[] encontrados;
    encontrados = encontradosNuevo;
    encontradosNuevo = NULL;
    return encontrados;
}


