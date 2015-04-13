#include <iostream>
#include "Persona.h"
#include "OrderedLinkedList.h"


using namespace vcn;

int main(int argc, char **argv)
{
    
    OrderedLinkedList<Persona> listaUp(true);
    OrderedLinkedList<Persona> listaDown(false);
    
    int opc = 0;
    int cont = 0;
    std::string nombre, apellidos;
    
    int dia;
    int mes;
    int Año;
    int edad;
    
    vcn::Node<Persona> * holder;
    
    while (opc != 6)
    {
        std::cout << "Eliga una opcion\n1.- Agrega una persona\n2.- Buscar\n3.- Borrar Persona\n4.- Imprimir lista de personas\n5.- Borrar todo\n6.- Salir" << std::endl;
        std::cin >> opc;
        switch (opc)
        {
            case 1:
                std::cout << "Nombre: ";
                std::cin >> nombre;
                std::cout << "Apellidos: ";
                std::cin >> apellidos;
                std::cout << "Edad: ";
                std::cin >> edad;
                std::cout << "Año de nacimiento: ";
                std::cin >> Año;
                std::cout << "Mes de nacimiento: ";
                std::cin >> mes;
                std::cout << "Dia de nacimiento: ";
                std::cin >> dia;
                
                listaUp.insert(Persona(nombre, apellidos, edad, Año, mes, dia));
                listaDown.insert(Persona(nombre, apellidos, edad, Año, mes, dia));
                break;
            case 2:
                if (listaUp.empty())
                {
                    std::cout << "La lista esta vacia" << std::endl;
                    break;
                }
                std::cout << "Ingrese el nombre que desea buscar: ";
                std::cin >> nombre;
                while (cont < listaUp.size())
                {
                    holder = listaUp.at(cont);
                    if (holder->getInfo().getNombre() == nombre)
                    {
                        std::cout << holder->getInfo();
                        std::cout << "Posicion: " << cont << std::endl << std::endl;
                    }
                    ++cont;
                }
                cont = 0;
                break;
            case 3:
                int pos;
                std::cout << "Dame la posicion a eliminar: ";
                std::cin >> pos;
                holder = listaUp.remove(pos);
                delete holder;
                holder = nullptr;
                holder = listaDown.remove(listaDown.size() - pos - 1);
                delete holder;
                holder = nullptr;
                
                break;
            case 4:
                std::cout << "1. Ascendente\n2. Descendente" << std::endl;
                std::cin >> opc;
                if (opc == 1)
                {
                    std::cout << listaUp;
                }
                else
                {
                    std::cout << listaDown;
                }
                opc = 4;
                
                break;
            case 5:
                listaUp.clear();
                listaDown.clear();
                
                break;
            case 6:
                std::cout << "Adios" << std::endl;
                break;
            default:
                std::cout << "No es valida esa opcion " << std::endl;
                break;
        }
    }
    
    
    
    return 0;
}