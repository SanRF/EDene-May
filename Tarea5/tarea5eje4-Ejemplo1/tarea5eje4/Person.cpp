//
//  Person.cpp
//  tarea5eje4
//
//  Created by Santiago Rodriguez Fernandez on 23/04/15.
//  Copyright (c) 2015 Santiago Rodriguez Fernandez. All rights reserved.
//

#include "Person.h"

// Constructors
Person::Person() {
    name = birthday = marital = deathday = "";
}
Person::Person(std::string na) {
    name = na;
}
Person::Person(std::string na, std::string bi) {
    name = na;
    birthday = bi;
}
Person::Person(std::string na, std::string bi, std::string ma) {
    name = na, birthday = bi; marital = ma;
}
Person::Person(std::string na, std::string bi, std::string ma, std::string de) {
    name = na; birthday = bi; marital = ma; deathday = de;
}

// Setters
void Person::setName(std::string a) {
    name = a;
}
void Person::setBirthday(std::string b) {
    birthday = b;
}
void Person::setMarital(std::string c) {
    marital = c;
}
void Person::setDeathday(std::string de) {
    deathday = de;
}

// Getters
std::string Person::getName() {
    return name;
}
std::string Person::getBirthday() {
    return birthday;
}
std::string Person::getMaritalStatus() {
    return marital;
}
std::string Person::getDeathday() {
    return deathday;
}