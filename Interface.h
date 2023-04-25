#ifndef MOVIEMATCHMAKER_INTERFACE_H
#define MOVIEMATCHMAKER_INTERFACE_H
#endif //MOVIEMATCHMAKER_INTERFACE_H

#include <iostream>
#include <string>
#include <vector>
#include "MoviesList.h"
#include <SFML/Graphics.hpp>
using namespace std;


class Interface{
    string category;
    string algorithm;
    string input;
    sf::RenderWindow window;
    string duration;
public:
    //window that asks for user preferences
    void createWindow(MoviesList &Movies);

    //window that loads all results
    void resultsWindow(MoviesList &Movies);
};