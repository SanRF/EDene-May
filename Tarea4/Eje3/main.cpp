//
//  main.cpp
//  Tarea4.Eje3
//
//  Created by Santiago Rodriguez Fernandez on 26/03/15.
//  Copyright (c) 2015 Santiago Rodriguez Fernandez. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include "ListaAUX.h"

std::string temp;


void menu();
void abrirArchivo();
void cargar(std::fstream &file, ListaAUX<ListaAUX<std::string> *> &texto);
void insertar();
void deleteLine();
void guardar();
void irAlPrincipio();
void irAlFinal();

ListaAUX<std::string>* getLines(std::string ruta, int line);
ListaAUX<std::string> * strToRow(std::string linea);
void printText(ListaAUX<ListaAUX<std::string> *> & texto);

ListaAUX<ListaAUX<std::string>*>  cpu;

int lineas;
int x=0;
int y=0;
int main(int argc, const char * argv[]) {
    
    
    menu();
    
    
    
    
    
    return 0;
}


void menu()
{
    int opcion=-10;
    while (opcion !=0)
    {
        std::cout << "Elige una opcion: " << std::endl;
        std::cout << std::endl;
        std::cout << "1.- Abrir Archivo" << std::endl;
        std::cout << "2.- Insertar linea" << std::endl;
        std::cout << "3.- Borrar linea" << std::endl;
        std::cout << "4.- Ir al inicio de una linea" << std::endl;
        std::cout << "5.- Ir al final de una linea" << std::endl;
        std::cout << "6.- Mostrar Documento" << std::endl;
        std::cout << "7.- Guardar Cambios" << std::endl;
        std::cout << "0.- Salir" << std::endl;
        std::cin >> opcion;
        std::cout << std::endl;
        switch (opcion)
        {
            case 1:abrirArchivo();
                break;
            case 2:insertar();
                break;
            case 3:deleteLine();
                break;
            case 6:printText(cpu);
                break;
            case 4:irAlPrincipio();
                break;
            case 5:irAlFinal();
                break;
            case 7:guardar();
                break;
            case 0:
                opcion=0;
                break;
            default:
                break;
        }
    }
    
}

void cargar(std::fstream &file, ListaAUX<ListaAUX<std::string> *> &texto)
{
    std::string temp;
    while (getline(file, temp))
    {
        
        ListaAUX<std::string> * linea = new ListaAUX<std::string>;
        linea = strToRow(temp);
        cpu.insertBack(linea);
    }
}
ListaAUX<std::string> * strToRow(std::string linea)
{
    int i = 0;
    char charAux = linea[i];
    ListaAUX<std::string> * line = new ListaAUX<std::string>;
    std::string temp;
    while (charAux) {
        if (charAux == ' ') {
            line->insertBack(temp);
            temp = "";
        }
        else
            temp += charAux;
        charAux = linea[++i];
    }
    line->insertBack(temp);
    return line;
    
}

void abrirArchivo()
{
    std::cout << "El nombre del archivo precreado para probar el ejercicio se llama Test.txt, solo ingrese ese nombre para probar" << std::endl;
    std::string nombre;
    std::cout << "Dame la dirección y el nombre del archivo para abrir"<< std::endl;
    std::cin >> nombre;
    std::fstream doc;
    doc.open (nombre);
    
    if (doc.is_open())
    {
        cargar(doc, cpu);
        std::cout << "El archivo se cargo correctamenta" << std::endl;
    }
    else
    {
        std::cout << "El archivo no se pudo abrir" << std::endl;
    }
    doc.close();
    
}

void printText(ListaAUX<ListaAUX<std::string> *> & texto)
{
    for (int i=0; i<texto.size(); i++)
    {
        std::cout << *cpu.at(i)->getInfo() << std::endl;
        
    }
    
}



void insertar()
{
    std::string LineaNueva;
    std::cout << "Escriba lo que queire que diga la linea" << std::endl;
    std::cin.ignore();
    std::getline(std::cin, LineaNueva);
    
    cpu.insert(strToRow(LineaNueva), y);
    
    
}


void deleteLine()
{
    int pos;
    cpu.at(y);
}

void guardar()
{
    std::fstream doc;
    doc.open ("Test.txt");
    for(int i=0; i<cpu.size(); i++)
    {
        for(int z=0; z<(cpu.at(i)->getInfo()->size()); z++)
        {
            doc<<cpu.at(i)->getInfo()->at(z)->getInfo() << " ";
        }
        doc<<std::endl;
    }
    
    doc.close();
}
void irAlPrincipio()
{
    int pos=-1;
    while (pos>cpu.size()+1 || pos<1)
    {
        std::cout << "¿A qué renglón quiere irse?" << std::endl;
        std::cin >> pos;
    }
    y=pos-1;
    x=0;
    std::cout << "La primera palabra de ese rengón es: " << cpu.at(pos-1)->getInfo()->at(0)->getInfo() << std::endl;
}

void irAlFinal()
{
    int pos=-1;
    int palabras;
    while (pos>cpu.size()+1 || pos<1)
    {
        std::cout << "¿A qué renglón quieres ir?" << std::endl;
        std::cin >> pos;
    }
    palabras=cpu.at(pos-1)->getInfo()->size();
    y=pos-1;
    x=palabras-2;
    std::cout << "La ultima palabra de ese renglón es: " << cpu.at(pos-1)->getInfo()->at(palabras-2)->getInfo() << std::endl;
}