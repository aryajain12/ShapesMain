#pragma once
#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "GeometricShapes.h"
#include <iostream>
#include <string>
#include <map>
#include<vector>
using namespace std;

class MenuOption {
public:
    int number;
    string label;

    MenuOption(int num, string l);
};


class Operations {
public:
    void run();
    Operations();
private:
    map<string, GeometricShapes*> shapeMap;

    vector<MenuOption> MAIN_MENU_OPTIONS;
    vector<MenuOption> SUB_MENU_OPTIONS;


    void displayMainMenu();
    void manage2DShapes();
    void manage3DShapes();
    void addShape2d(int choice);
    void addShape3d(int choice);
    void updateShape();
    void deleteShape();
    void searchShape();
    void displayAllShapes();
};


#endif //OPERATIONS_H
