#include <iostream>
#include <cstdlib>
#include <ctime>

bool Laberinto(int **, int, int, int);

void imprime(int **, int, int);

int main(){
    srand(time(NULL));
    int dimension;
    int ** m;
    
    std::cout << "Dime la dimension de tu matriz: " << std::endl;
    std::cin >> dimension;
    std::cout << "Los '0' son paredes y los '1' son casillas disponibles" << std::endl;
    std::cout << "Se empieza en la posicion (0,0)" << std::endl << std::endl;
    
    m = new int*[dimension];
    
    for (int a = 0; a < dimension; a++){
        m[a] = new int[dimension];
    }
    
    for(int a = 0; a < dimension; a++){
        for(int b = 0; b < dimension; b++){
            m[a][b] = rand()%2;
        }
    }
    
    imprime(m,dimension,dimension);
    bool siExiste = Laberinto(m,dimension,0,0);
    if(siExiste){
        std::cout << "Si tiene solucion" << std::endl;
    }
    else{
        std::cout << "No tiene solucion" << std::endl;
    }

    return 0;
}

bool Laberinto(int** m, int dimension, int row, int col)
{
        int valor = m[row][col];
        if(valor == 1 && row == dimension-1 && col == dimension-1){ // Comprueba en la pos final
            return true;
        }
        else if(m[row][col+1] == 1){
            std::cout << "Derecha" << std::endl;
            return Laberinto(m, dimension, row, col+1); //Salta a la derecha
        }
        else if(m[row+1][col] == 1){
            std::cout << "Abajo" << std::endl;
            return Laberinto(m, dimension, row+1, col); //Salta para abajo
        }
        else{
            return false;
        }
}

void imprime(int **m, int fil, int col){
    for(int a = 0; a < fil; a++){
        for(int b = 0; b < col; b++){
            std::cout << m[a][b] << ", ";
        }
        std::cout << std::endl;
    }
}