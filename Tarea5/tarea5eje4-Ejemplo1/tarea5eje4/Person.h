//
//  Person.h
//  tarea5eje4
//
//  Created by Santiago Rodriguez Fernandez on 23/04/15.
//  Copyright (c) 2015 Santiago Rodriguez Fernandez. All rights reserved.
//

#ifndef __tarea5eje4__Person__
#define __tarea5eje4__Person__

#include <stdio.h>
#include <string>
#include <cctype>
#include <iostream>

class Person {
private:
    std::string name;
    std::string birthday;
    std::string marital;
    std::string deathday;
public:
    // Constructors
    Person();
    Person(std::string);
    Person(std::string, std::string);
    Person(std::string, std::string, std::string);
    Person(std::string, std::string, std::string, std::string);
    
    // Setters
    void setName(std::string);
    void setBirthday (std::string);
    void setMarital(std::string);
    void setDeathday(std::string);
    
    // Getters
    std::string getName();
    std::string getBirthday();
    std::string getMaritalStatus();
    std::string getDeathday();
    
};



#endif /* defined(__tarea5eje4__Person__) */
