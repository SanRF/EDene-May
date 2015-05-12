//
//  main.cpp
//  AI
//
//  Created by Jonathan Ginsburg on 5/2/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include "City.h"
#include "Road.h"
#include <iostream>
#include <unistd.h>
#include <time.h>
#include "Graph.h"
#include "Helper.h"

Graph<City, Road> map;
std::vector<std::string> currentSession;

void parse(std::vector<std::string> args);

std::string buildString(std::vector<std::string> args, int low, int high){
    std::string name = "";
    for (int i = low; i < high; ++i) {
        name.append(args[i]);
        if (i != high-1) {
            name.append(" ");
        }
    }
    return name;
}

std::string buildString(std::vector<std::string> args, int low){
    std::string name = "";
    for (int i = low; i < args.size(); ++i) {
        name.append(args[i]);
        if (i != args.size()-1) {
            name.append(" ");
        }
    }
    return name;
}

void remove(std::vector<std::string> args){
    if (args.size() == 1) {
        Helper::print("Incomplete command.");
        Helper::print("Type: remove help (for displaying options)");
    }
    else if (args[1] == "help") {
        Helper::print("remove cities (removes all cities and all highways)");
        Helper::print("remove city [City's name] (removes the indicated city)");
        Helper::print("remove current_session (erases the command history of the current session)");
        Helper::print("remove road [Road's origin] , [Road's destination] (removes all highways)");
        Helper::print("remove roads (removes all highways)");
    }
    else if (args[1] == "cities"){
        map.clear();
    }
    else if (args[1] == "city"){
        if (args.size() <= 2) {
            Helper::print("Missing data. Please type: remove city [City's name]");
            return;
        }
        map.removeVertex({buildString(args, 2)});
    }
    else if (args[1] == "roads"){
        map.disconnectAll();
    }
    else if (args[1] == "road"){
        if (args.size() <= 2) {
            Helper::print("Missing data. Please type: remove road [Road's origin] , [Road's destination]");
            return;
        }
        int comma = -1;
        
        for (int i = 2; i < args.size(); ++i) {
            if (args[i] == ",") {
                comma = i;
            }
        }
        try {
            map.removeEdge(map.getEdge({*map.getVertex(buildString(args, 2, comma))->getInfo(), *map.getVertex(buildString(args, comma + 1))->getInfo()}, *map.getVertex(buildString(args, 2, comma))->getInfo(), *map.getVertex(buildString(args, comma + 1))->getInfo()));
        } catch (const char * exception) {
            Helper::print(exception);
        }

    }
    else if (args[1] == "current_session"){
        currentSession.clear();
    }
}

void show(std::vector<std::string> args){
    if (args.size() == 1) {
        Helper::print("Incomplete command.");
        Helper::print("Type: show help (for displaying options)");
    }
    else if (args[1] == "help") {
        Helper::print("current_session (shows all commands in the current session except for save and load)");
        Helper::print("show cities (shows all cities)");
        Helper::print("show roads (shows all highways)");
    }
    else if (args[1] == "cities"){
        Helper::print("Printing all cities:");
        for (int i = 0; i < map.getVertices()->size(); ++i) {
            std::cout << "\t" << i+1 << ") " << *(*map.getVertices())[i]->getInfo() << "." << std::endl;
        }
    }
    else if (args[1] == "roads"){
        Helper::print("Printing all roads:");
        for (int i = 0; i < map.getEdges()->size(); ++i) {
            std::cout << "\t" << i+1 << ") " << *(*map.getEdges())[i] << "." << std::endl;
        }
    }
    else if (args[1] == "current_session"){
        Helper::print("Current session history commands:");
        for (int i = 0; i < currentSession.size(); ++i) {
            std::cout << "\t" << currentSession[i] << std::endl;
        }
    }
}

void add(std::vector<std::string> args){
    if (args.size() == 1) {
        Helper::print("Incomplete command.");
        Helper::print("Type: add help (for displaying options)");
    }
    else if (args[1] == "help") {
        Helper::print("add city [City's name] [City's Latitude] , [City's Longitude] (adds a city)");
        Helper::print("add road [Road's length] [Road's origin] , [Road's destination] (adds a road)");
        Helper::print("add roadsym [Road's length] [Road's origin] , [Road's destination] (adds roads from origin to destination and from destination to origin)");
    }
    else if (args[1] == "city"){
        if (args.size() == 2) {
            Helper::print("Missing name of the city . Please type: add city [City's name] [City's Latitude] , [City's Longitude]");
            return;
        }
        
        int comma = -1;
        
        for (int i = 2; i < args.size(); ++i) {
            if (args[i] == ",") {
                comma = i;
            }
        }
        
        if (comma == -1) {
            Helper::print("Please type: add city [City's name] [City's Latitude] , [City's Longitude]");
            return;
        }
        try {
            std::string nameOfCity = buildString(args, 2, comma - 1);
            std::string latitude = buildString(args, comma - 1, comma);
            std::string longitude = buildString(args, comma + 1, comma + 2);
            map.addVertex({nameOfCity, Helper::stringToLongDouble(latitude), Helper::stringToLongDouble(longitude)});
        }
        catch (const char * exception)
        {
            Helper::print(exception);
        }
    }
    else if (args[1] == "road"){
        if (args.size() <= 2) {
            Helper::print("Missing data. Please type: add road [Road's origin] , [Road's destination]");
            return;
        }
        
        int comma = -1;
        
        for (int i = 2; i < args.size(); ++i) {
            if (args[i] == ",") {
                comma = i;
            }
        }
        try {
            map.addEdge({*map.getVertex(buildString(args, 2, comma))->getInfo(), *map.getVertex(buildString(args, comma + 1))->getInfo()}, *map.getVertex(buildString(args, 2, comma))->getInfo(), *map.getVertex(buildString(args, comma + 1))->getInfo());
        } catch (const char * exception) {
            Helper::print(exception);
        }
    }
    else if (args[1] == "roadsym"){
        if (args.size() <= 2) {
            Helper::print("Missing data. Please type: add road [Road's origin] , [Road's destination]");
            return;
        }
        
        int comma = -1;
        
        for (int i = 2; i < args.size(); ++i) {
            if (args[i] == ",") {
                comma = i;
            }
        }
        std::string exceptionMessage = "";
        try {
            map.addEdge({*map.getVertex(buildString(args, 2, comma))->getInfo(), *map.getVertex(buildString(args, comma + 1))->getInfo()}, *map.getVertex(buildString(args, 2, comma))->getInfo(), *map.getVertex(buildString(args, comma + 1))->getInfo());
        } catch (const char * exception) {
            exceptionMessage = exception;
        }
        if (exceptionMessage != "") {
            exceptionMessage = "true";
        }
        try {
            map.addEdge({*map.getVertex(buildString(args, 2, comma))->getInfo(), *map.getVertex(buildString(args, comma + 1))->getInfo()}, *map.getVertex(buildString(args, comma + 1))->getInfo(), *map.getVertex(buildString(args, 2, comma))->getInfo());
        } catch (const char * exception) {
            exceptionMessage = exception;
        }
        if (exceptionMessage == "true" || exceptionMessage == "Vertex already exists...") Helper::print("At least one vertex already existed...");
    }
}


void connectAll(){
    for (int i = 0; i < map.getVertices()->size(); ++i) {
        Vertex<City, Road> * currentVertex = (*map.getVertices())[i];
        for (int j = 0; j < map.getVertices()->size(); ++j) {
            if (j == i) continue;
            try {
                map.addEdge({*currentVertex->getInfo(), *(*map.getVertices())[j]->getInfo()}, *currentVertex->getInfo(), *(*map.getVertices())[j]->getInfo());
            } catch (const char * exception) {
                std::cout << exception << std::endl;
            }
            
        }
    }
}

void connect(std::vector<std::string> args){
    if (args.size() == 1) {
        Helper::print("Incomplete command.");
        Helper::print("Type: connect help (for displaying options)");
    }
    else if (args[1] == "help") {
        Helper::print("connect all (connects all cities)");
    }
    else if (args[1] == "all") {
        connectAll();
    }
}

void parse(std::vector<std::string> args){
    if (args[0] == "help") {
        Helper::print("add (adds information)");
        Helper::print("connect all (connects all cities)");
        Helper::print("load (loads a session of commands)");
        Helper::print("quit");
        Helper::print("remove (removes information)");
        Helper::print("save (saves current session of commands)");
        Helper::print("search (looks for a path between cities)");
        Helper::print("show (displays information)");
        Helper::print("check ");
    }
    else if (args[0] == "show"){
        show(args);
    }
    else if (args[0] == "add"){
        add(args);
    }
    else if (args[0] == "remove"){
        remove(args);
    }
    else if (args[0] == "connect"){
        connect(args);
    }
    /*else if (args[0] == "check"){
        checkIfComplete(args);
    }*/
}

bool prompt(){
    std::string input = Helper::readLine(">>> ");
    std::vector<std::string> args = Helper::split(input, ' ');
    if (args[0] == "save" || args[0] == "load") {
        parse(args);
        return true;
    }
    else currentSession.push_back(input);
    if (args[0] == "quit") return false;
    else {
        parse(args);
        return true;
    }
};

bool checkIfComplete(){
    if(map.getVertices()->size() == 0 || map.getEdges()->size() == 0){
        return false;
    }
    else if (map.getEdges()->size() != 0){
        for (int i = 0; i < map.getVertices()->size(); ++i) {
            Vertex<City, Road> * currentVertex = (*map.getVertices())[i];
            for (int j = 0; j < map.getVertices()->size(); ++j) {
                if (j == i) continue;
                try {
                    map.addEdge({*currentVertex->getInfo(), *(*map.getVertices())[j]->getInfo()}, *currentVertex->getInfo(), *(*map.getVertices())[j]->getInfo());
                } catch (const char * exception) {
                    std::cout << exception << std::endl;
                }
                
            }
            return true;
        }
    
    /*for (int i = 0; i < map.getVertices()->size(); ++i) {
        Vertex<City, Road> * currentVertex = (*map.getVertices())[i];
        for (int j = 0; j < map.getVertices()->size(); ++j) {
            if (j == i) continue;
            try {
                map.addEdge({*currentVertex->getInfo(), *(*map.getVertices())[j]->getInfo()}, *currentVertex->getInfo(), *(*map.getVertices())[j]->getInfo());
            } catch (const char * exception) {
                std::cout << exception << std::endl;
            }
            
        }
    }*/
    }
    return true;
};

int main(int argc, const char * argv[]) {
    Helper::print("Welcome to the road helper V 1.0 by Jonathan Ginsburg and Santiago Rodriguez.");
    Helper::print("Type help for all commands available.");
    while (prompt()) {}
    return 0;
}

