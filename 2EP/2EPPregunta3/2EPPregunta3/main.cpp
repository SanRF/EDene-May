
//  Created by Santiago Rodriguez Fernandez on 26/03/15.
//  Copyright (c) 25 Santiago Rodriguez Fernandez. All rights reserved.
//

#include <iostream>
#include "Stack.h"
#include <string>

using namespace vcn;

void verificar(Stack<int> * brack, std::string ecuacion, int size);
void adelante(Stack<int> * brack, std::string ecuacion, int size);
void atras(Stack<int> * brack, std::string ecuacion, int size);
void abs(Stack<int> *brack, std::string ecuacion, int firstComp, int secondComp,
         int updateVar(int), std::string primero, std::string segundo);


/*int main(int argc, const char * argv[]) {
    std::string ecuacion;
    std::string cChar;
    Stack<int> * brack = new Stack<int>;
    
    std::cout << "Escribe tu ecuacion: " << std::endl;
    getline(std::cin, ecuacion);
    
    int size = (int) ecuacion.length();
    
    verificar(brack, ecuacion, size);
    
    
    if(brack->empty()){
        std::cout << "La ecuacion esta balanceada " << std::endl;
    }else{
        std::cout << "La ecuacion no esta balanceada " << std::endl;
    }
    
    
    delete brack;
    return 0;
}

void verificar(Stack<int> * brack, std::string ecuacion, int size){
    adelante(brack, ecuacion, size);
    atras(brack, ecuacion, size);
}

void adelante(Stack<int> * brack, std::string ecuacion, int size){
    abs(brack, ecuacion, 0, size, [](int a){ return ++a;}, "(", ")");
}

void atras(Stack<int> * brack, std::string ecuacion, int size){
    abs(brack, ecuacion, size, 0, [](int a){ return --a;}, ")", "(");
}

void abs(Stack<int> *brack, std::string ecuacion, int firstComp, int secondComp,
         int updateVar(int), std::string primero, std::string segundo){
    std::string cChar;
    for(int i = firstComp; i >= secondComp; i = updateVar(i)){
        cChar = ecuacion[i];
        
        if(cChar.compare(primero) == 0){
            brack->push(1);
        }else if (cChar.compare(segundo) == 0){
            brack->pop();
        }
    }
}*/

struct node
{
    int *data;
    struct node *nextNode;
};

struct node *list = NULL;

void push(int s)
{
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    (*newNode).data = &s;
    (*newNode).nextNode = NULL;
    
    if (list != NULL)
    {
        (*newNode).nextNode = list;
    }
    
    list = newNode;
} // end push


void printStack()

{
    
    struct node *tmp = list;
    int *s;
    if (list != NULL)
    {
        while (tmp != NULL)
        {
            *s = *(*tmp).data;
            printf("%d", (*tmp).data);
            tmp = (*tmp).nextNode;
            
        }
        
    }
    
    
    
    else
        
    {
        
        printf("Nothing in stack.\n");
        
    }
    
} // end printStack



int pop()

{
    
    struct node *tmp = list;
    
    int *s;
    
    if(list != NULL)
    {
        s = (*list).data;
        list =(*list).nextNode;
        free(tmp);
    }
    return *s;

} // end pop
int main(int argc, char *argv[])
{
    std::string ecuacion;
    std::string cChar;
    Stack<int> * brack = new Stack<int>;
    
    std::cout << "Escribe tu ecuacion: " << std::endl;
    getline(std::cin, ecuacion);
    
    int size = (int) ecuacion.length();
    
    verificar(brack, ecuacion, size);
    
    
    if(brack->empty()){
        std::cout << "La ecuacion esta balanceada " << std::endl;
    }else{
        std::cout << "La ecuacion no esta balanceada " << std::endl;
    }
    
    
    delete brack;
    
    char input[256];
    int count = 0;
    int i = 0;
    
    printf("\n\Vuelve a escribir tu ecuacion: ");
    printf("\n(Cuando termines pon un ?)");
    
    scanf("%s\n", input);
    
    while (input[i] != '\0')
    {
        if (input[i] == '+')
        {
            int num2 = pop();
            int num1 = pop();
            push(num1 + num2);
            i++;
        } // end if
        if (input[i] == '-')
        {
            int num2 = pop();
            int num1 = pop();
            push(num1 - num2);
            i++;
        } // end if
        if (input[i] == '/')
        {
            int num2 = pop();
            int num1 = pop();
            push(num1 / num2);
            i++;
        } // end if
        if (input[i] == '*')
        {
            int num2 = pop();
            int num1 = pop();
            push(num1 * num2);
            i++;
        } // end if
        if (input[i] == ' ')
        {
            i++;
        } // end if
        
        else
        {
            push (atoi(input));
            count++;
            scanf("%s", input);
        }
        
    }
    
    printf("\nYour exp<b></b>ression = ");
    printStack();
    
    scanf("%s", input);
    
    scanf("%i", i);
    
    
    
    return 0;
    
}

void verificar(Stack<int> * brack, std::string ecuacion, int size){
    adelante(brack, ecuacion, size);
    atras(brack, ecuacion, size);
}

void adelante(Stack<int> * brack, std::string ecuacion, int size){
    abs(brack, ecuacion, 0, size, [](int a){ return ++a;}, "(", ")");
}

void atras(Stack<int> * brack, std::string ecuacion, int size){
    abs(brack, ecuacion, size, 0, [](int a){ return --a;}, ")", "(");
}

void abs(Stack<int> *brack, std::string ecuacion, int firstComp, int secondComp,
         int updateVar(int), std::string primero, std::string segundo){
    std::string cChar;
    for(int i = firstComp; i >= secondComp; i = updateVar(i)){
        cChar = ecuacion[i];
        
        if(cChar.compare(primero) == 0){
            brack->push(1);
        }else if (cChar.compare(segundo) == 0){
            brack->pop();
        }
    }
}


