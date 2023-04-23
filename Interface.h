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
public:
    Interface interface();
    void createWindow(MoviesList &Movies);
    void setCategory(string category);
    void setAlgorithm(string algorithm);
    void setInput(string input);
    string getCategory();
    string getAlgorithm();
    string getInput();

    //window that loads all results
    void resultsWindow(MoviesList &Movies);

    //to start over/reset input
    void resetWindow(sf::RenderWindow& window);
};