#include <iostream>

#define d 3
#define a 2

int MovimientosPosibles(int Fil, int Col, int FilaActual, int ColActual);

int main(){
    
    int Fil;
    int Col;
    
    std::cout << "Bienvenido al programa! Tu pieza solamente se puede mover 3 a la derecha y 2 para abajo: " << std::endl;
    std::cout << "Dime cuantas filas quieres: " << std::endl;
    std::cin >> Fil;
    std::cout << "Dime cuantas columnas quieres: " << std::endl;
    std::cin >> Col;
    
    std::cout << "El numero total de movimientos posibles es: " << MovimientosPosibles(Fil,Col,0,0) << std::endl;
    
    return 0;
}

int MovimientosPosibles(int Fil, int Col, int FilaActual, int ColActual){
    if (FilaActual >= Fil || ColActual >= Col){
        return 0;
    }
    else if (FilaActual == Fil-1 && ColActual == Col-1){
        return 1;
    }
    else{
        return MovimientosPosibles(Fil, Col, FilaActual + a, ColActual) + MovimientosPosibles(Fil, Col, FilaActual, ColActual + d);
    }
}