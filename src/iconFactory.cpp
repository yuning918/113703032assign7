// TODO implementation
#include <iostream>
#include <string>
#include <vector>
#include "iconFactory.h"
#include "icon.h"

using namespace std;

Icon iconFactory::createTop(){
	string a = " ";
    vector<vector<Cell>> show(4, vector<Cell>(4, Cell(CYAN, a)));
    return show;
}

Icon iconFactory::createLeft(){
	string a = " ";
    vector<vector<Cell>> show(2, vector<Cell>(2, Cell(GREEN, a)));
    return show;
}

Icon iconFactory::createPlayer(){
    string a = "P";
    vector<vector<Cell>> show(4, vector<Cell>(3, Cell(RED, a)));
    return show;
}

Icon iconFactory::createSquat(){
    string a = "P";
    vector<vector<Cell>> show(2, vector<Cell>(3, Cell(RED, a)));
    return show;
}
