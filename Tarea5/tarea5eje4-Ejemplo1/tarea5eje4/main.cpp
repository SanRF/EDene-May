//
//  main.cpp
//  tarea5eje4
//
//  Created by Santiago Rodriguez Fernandez on 23/04/15.
//  Copyright (c) 2015 Santiago Rodriguez Fernandez. All rights reserved.
//

#include <string>
#include <cctype>
#include <iostream>
#include "Family.h"
#include "Person.h"

const std::string q = "QUIT";

std::string getInput();
int getNumOfFamilies(std::string);
void setupEachFamilyInput(std::string, Family &);

int main() {
    std::string input = getInput();
    int numOfFamilies = getNumOfFamilies(input);
    
    std::string *inputOfFamilies;
    Family *families;
    inputOfFamilies = new std::string[numOfFamilies];
    families = new Family[numOfFamilies];
    
    for (int i=0; i<numOfFamilies; i++) {
        int posOfBreakLine = input.find('\n');
        inputOfFamilies[i] = input.substr(0, posOfBreakLine);
        input.erase(0, posOfBreakLine + 1);
    }
    
    // now process each family input
    for (int i = 0; i < numOfFamilies; i++) {
        setupEachFamilyInput(inputOfFamilies[i], families[i]);
    }
    
    std::cout << "+--------- Family Tree ---------+" << std::endl << std::endl;
    
    { 
        Person *heads;
        heads = new Person[numOfFamilies];
        for (int i=0; i < numOfFamilies; i++) {
            heads[i] = families[i].getHead(); // collect all heads
        }
        
        for (int i=0; i < numOfFamilies; i++) {
            families[i].displayWithoutChild();
            
            for (int j=0; j < numOfFamilies; j++) {
                if (families[i].hasChild(heads[j])) {
                    Family fam = families[i];
                    Person chi = heads[j];
                    
                    std::cout << "\t" << chi.getName() << " ("
                    << chi.getBirthday() << ")" << std::endl;
                }
            }
            
            std::cout << std::endl;
        }
    }
    
    std::cout << "+--------- DONE ---------+" << std::endl;
    std::cout << std::endl;
    return 0;
};

std::string getInput() {
    std::string input;
    std::string line;
    while (line != q) {
        getline(std::cin, line);
        if (line != q) {
            input = input + line + "\n";
        }
    }
    return input;
}
int getNumOfFamilies(std::string s) {
    int n = 0;
    for (int i=0; i < s.length() - 1; i++) {
        if ( (s[i+1] == '\n') ) n++;
    }
    return n;
}
void setupEachFamilyInput(std::string familyInput, Family &fa) {
    Family eachFamily;
    Person head;

    int pos = familyInput.find(" ");
    std::string headName = familyInput.substr(0, pos);
    familyInput.erase(0, pos + 1);
    head.setName(headName);
    
    pos = familyInput.find(" ");
    std::string headBirthday = familyInput.substr(0, pos);
    familyInput.erase(0, pos+1);
    head.setBirthday(headBirthday);
    
    pos = familyInput.find(" ");
    std::string headMarital = familyInput.substr(0, pos);
    familyInput.erase(0, pos+1);
    head.setMarital(headMarital);
    
    eachFamily.addHead(head);
    Person spouse;
    
    if (head.getMaritalStatus() == "M") {
        // spouse name
        pos = familyInput.find(" ");
        std::string spouseName = familyInput.substr(0, pos);
        familyInput.erase(0, pos+1);
        spouse.setName(spouseName);
        
        // spouse birthday
        pos = familyInput.find(" ");
        std::string spouseBirthday = familyInput.substr(0, pos);
        familyInput.erase(0, pos+1);
        spouse.setBirthday(spouseBirthday);
        
        eachFamily.addSpouse(spouse);
    }
    else if (head.getMaritalStatus() == "S") {
    }

    if (familyInput[familyInput.length() - 1] == ' ') {
        familyInput.erase((familyInput.length() - 1), 1);
    }
    
    if (familyInput.length() == 1) {
    }
    else
    {
        
        int num = 0;
        for (int i = 0; i < familyInput.length(); i++)
        {
            if (familyInput[i] == ' ') {
                num++;
            }
        }
        
        std::string *remainingItems;
        remainingItems = new std::string[num];
        
        for (int i = 0; i < num; i++)
        {
            int pos = familyInput.find(" ");
            remainingItems[i] = familyInput.substr(0, pos);
            familyInput.erase(0, pos + 1);
        }
        
        for (int i = 0; i < num; i++) {
            std::string str = remainingItems[i];
            if (isdigit(str[0])) {
                head.setDeathday(str);
                eachFamily.replaceHead(head);
            } else {
                Person child(str);
                eachFamily.addChild(child);
            }
        }
        
    }

    fa = eachFamily;
}
