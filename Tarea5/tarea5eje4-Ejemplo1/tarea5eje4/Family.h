//
//  Family.h
//  tarea5eje4
//
//  Created by Santiago Rodriguez Fernandez on 23/04/15.
//  Copyright (c) 2015 Santiago Rodriguez Fernandez. All rights reserved.
//

#ifndef __tarea5eje4__Family__
#define __tarea5eje4__Family__

#include <stdio.h>
#include "Person.h"
#include <string>
#include <cctype>
#include <iostream>

class Family {
private:
    /*
     Family Tree includes: possible 1 spouse, and one or many children
     spouse is considerred 'horizontal' with the 'head' (or root)
     children is consider 'vertical' stacked
     */
    struct PersonNode {
        Person person;
        struct PersonNode *spouse;
        struct PersonNode *child;
    };
    PersonNode *head;
    int numOfChildren;
public:
    Family();
    void addHead(Person);
    Person getHead();
    void replaceHead(Person);
    void addSpouse(Person);
    Person getSpouse();
    bool hasSpouse();
    void addChild(Person);
    bool hasChild();
    bool hasChild(Person);
    int getNumOfChildren();
    // Person getChild(string);
    void displayVersionOne();
    void displayWithoutChild();
    
};
#endif /* defined(__tarea5eje4__Family__) */
