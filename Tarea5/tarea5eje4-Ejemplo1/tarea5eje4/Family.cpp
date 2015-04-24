//
//  Family.cpp
//  tarea5eje4
//
//  Created by Santiago Rodriguez Fernandez on 23/04/15.
//  Copyright (c) 2015 Santiago Rodriguez Fernandez. All rights reserved.
//

#include "Family.h"

Family::Family() {
    head = NULL;
    numOfChildren = 0;
}

void Family::addHead(Person p) {
    PersonNode *newNode;
    newNode = new PersonNode;
    newNode->person = p;
    newNode->spouse = newNode->child = NULL;
    
    if (!head) { head = newNode; }
    else {std::cout << "Family already had a head."; }
}

Person Family::getHead() {
    if (head) return head->person;
    else std::cout << "The Family is empty";
    return head->person;
}

void Family::replaceHead(Person p) {
    PersonNode *newNode;
    newNode = new PersonNode;
    newNode->person = p;
    newNode->spouse = head->spouse;
    newNode->child = head->child;
    
    head = newNode;
}

void Family::addSpouse(Person p) {
    PersonNode *newNode;
    
    newNode = new PersonNode;
    newNode->person = p;
    newNode->spouse = newNode->child = NULL;
    
    if (!(head->spouse)) {
        head->spouse = newNode;
    } else { std::cout << "Spouse already existed."; }
}

Person Family::getSpouse() {
    if (head->spouse) return head->spouse->person;
    else std::cout << "Spouse not exists.";
    return head->spouse->person;
}

bool Family::hasSpouse() {
    if (head->spouse) return true;
    else return false;
}

void Family::addChild(Person p) {
    PersonNode *newNode;
    PersonNode * nodePtr;
    
    newNode = new PersonNode;
    newNode->person = p;
    newNode->spouse = newNode->child = NULL;
    
    if (!(head->child)) {
        head->child = newNode;
        numOfChildren++;
    } else {
        nodePtr = head->child;
        while (nodePtr->child) {
            nodePtr = nodePtr->child;
        }
        nodePtr->child = newNode;
        numOfChildren++;
    }
}

bool Family::hasChild() {
    if (head->child) return true;
    else return false;
}

bool Family::hasChild(Person p) {
    PersonNode *nodePtr;
    nodePtr = head;
    bool b = false;
    while (nodePtr->child) {
        if ( nodePtr->child->person.getName() == p.getName() ) {
            b = true;
        }
        nodePtr = nodePtr->child;
    }
    return b;
}

int Family::getNumOfChildren() {
    return numOfChildren;
}

//Person Family::getChild(string na) {
//  Person p;
//  PersonNode *nodePtr;
//  nodePtr = head;
//  while (nodePtr->child) {
//      if ( (nodePtr->child->person).getName() == na ) {
//          p = nodePtr->child->person;
//          return p;
//      }
//      nodePtr = nodePtr->child;
//  }
//  return NULL; // not found
//}

void Family::displayVersionOne() {
    displayWithoutChild();
    
    PersonNode *nodePtr;
    nodePtr = head;
    
    while (nodePtr->child) {
        std::cout << "\t" << (nodePtr->child->person).getName() << std::endl;
        nodePtr = nodePtr->child;
    }
    
    std::cout << std::endl;
}

void Family::displayWithoutChild() {
    PersonNode *nodePtr;
    nodePtr = head;
    std::cout << nodePtr->person.getName();
    std::cout << " (" << nodePtr->person.getBirthday();
    if (nodePtr->person.getDeathday() != "") {
        std::cout << " - " << nodePtr->person.getDeathday();
    }
    std::cout << ")";
    
    if (hasSpouse()) {
        std::cout << " x ";
        std::cout << nodePtr->spouse->person.getName();
        std::cout << " (" << nodePtr->spouse->person.getBirthday() << ")";
    }
    
    // extra info
    if (getNumOfChildren() == 0) {
        //
    } else if (getNumOfChildren() == 1) {
        std::cout << std::endl << "\t*";
        std::cout << " This family has one child:";
    } else if (getNumOfChildren() > 1) {
        std::cout << std::endl << "\t*";
        std::cout << " This family has " << getNumOfChildren() << " children:";
    }
    
    
    std::cout << std::endl;
}