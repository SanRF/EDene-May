#include <iostream>
#include <cmath>

void CrearMatriz(int **, int, int, int);

void imprime(int **, int, int);

int main(){
    int dimension;
    int ** m;
    
    std::cout << "Dime la dimension de tu matriz de n*n: " << std::endl;
    std::cin >> dimension;
    
    m = new int*[dimension];
    
    for (int a = 0; a < dimension; a++){
        m[a] = new int[dimension];
    }
    
    CrearMatriz(m,dimension,0,0);
    imprime(m,dimension,dimension);
    
    return 0;
}

void CrearMatriz(int ** m, int dimension, int fil, int col){
    if(fil == dimension-1 && col == dimension-1){
        m[fil][col] = pow(2,dimension-1);
    }
    else if(fil == dimension-1){
        m[fil][col] = pow(2,col);
        CrearMatriz(m, dimension, 0, col+1);
    }
    else{
        if(fil<col){
            m[fil][col] = pow(2,fil);
        }
        else{
            m[fil][col] = pow(2,col);
        }
        CrearMatriz(m, dimension, fil+1, col);
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