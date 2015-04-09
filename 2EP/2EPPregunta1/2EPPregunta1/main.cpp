//
//  main.cpp
//  2EPPregunta1
//
//  Created by Santiago Rodriguez Fernandez on 09/04/15.
//  Copyright (c) 2015 Santiago Rodriguez Fernandez. All rights reserved.
//

#include <iostream>
#include "Stack.h"


using namespace vcn;

int main(int argc, const char * argv[])
{
    int number;
    Stack<char> * stack = new Stack<char>();
    std::string bin;
    char holder=' ';
    std::cin>>number;
    while(number!=0)
    {
        holder=number%2+'0';
        bin=holder+bin;
        number/=2;
        stack->push(holder);
    }
    //std::cout<<bin;
    std::cout << *stack << std::endl;
    return 0;
}

