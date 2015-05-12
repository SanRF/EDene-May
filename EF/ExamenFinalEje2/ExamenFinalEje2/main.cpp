//
//  main.cpp
//  ExamenFinalEje2
//
//  Created by Santiago Rodriguez Fernandez on 12/05/15.
//  Copyright (c) 2015 Santiago Rodriguez Fernandez. All rights reserved.
//

#include <iostream>

#define N 12

void imprimeMatriz(int m[N][N]);
int dibujaMatriz(int m[N][N], int f, int i, int j, int r); //F es el numero de pasos

int main(int argc, const char * argv[])
{
    
    int matriz[N][N] = {0};
    
    
    std::cout << " ------- Matriz -------------" << std::endl;
    dibujaMatriz(matriz, 2, 4, 4, 8);
    
    std::cout << std::endl;
    
    imprimeMatriz(matriz);
    
    
    return 0;
}


void imprimeMatriz(int m[N][N])
{
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << m[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

int dibujaMatriz(int m[N][N], int f, int i, int j, int r)
{
    if (f == 0) {
        return m[N][N];
    }
    
    if (f == 1) {
        for (i = 4; i < r; ++i) {
            for (j = 4 ; j < r; ++j) {
                m[i][j] = 1;
            }
        }
        return m[N][N];
    }
    
    if(f == 2){
        return dibujaMatriz(m, f+1, i, j, r);
    }
    
    if(f == 3 ){
        for (i = 4; i < r; ++i) {
            for (j = 4 ; j < r; ++j) {
                m[i][j] = 1;
            }
        }
        for (i = 1; i < 3; ++i) {
            for (j = 1 ; j < 3; ++j) {
                m[i][j] = 1;
            }
        }
        for (i = 5; i < 7; ++i) {
            for (j = 1 ; j < 3; ++j) {
                m[i][j] = 1;
            }
        }
        
        for (i = 5; i < 7; ++i) {
            for (j = 9 ; j < 11; ++j) {
                m[i][j] = 1;
            }
        }
        
        
        for (i = 9; i < 11; ++i) {
            for (j = 1 ; j < 3; ++j) {
                m[i][j] = 1;
            }
        }
        
        for (i = 9; i < 11; ++i) {
            for (j = 5 ; j < 7; ++j) {
                m[i][j] = 1;
            }
        }
        
        for (i = 9; i < 11; ++i) {
            for (j = 9 ; j < 11; ++j) {
                m[i][j] = 1;
            }
        }
        
        
        for (i = 1; i < 3; ++i) {
            for (j = 5 ; j < 7; ++j) {
                m[i][j] = 1;
            }
        }
        
        for (i = 1; i < 3; ++i) {
            for (j = 9 ; j < 11; ++j) {
                m[i][j] = 1;
            }
        }

        
        return m[N][N];
    }
    if (f == 5) {
        for (i = 0; i < 12; ++i) {
            for (j = 0 ; j < 12; ++j) {
                m[i][j] = 1;
            }
        }
        return m[N][N];
    }
    
    else {
        return dibujaMatriz(m, f=5 , i,j, r);
    }
}
