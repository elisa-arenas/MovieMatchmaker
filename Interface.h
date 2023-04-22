#ifndef MOVIEMATCHMAKER_INTERFACE_H
#define MOVIEMATCHMAKER_INTERFACE_H
#endif //MOVIEMATCHMAKER_INTERFACE_H


#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
using namespace std;


class Interface{
    string category;
    string algorithm;
    sf::RenderWindow window;
public:
    Interface interface();
    sf::RenderWindow createWindow();
    void setCategory(string category);
    void setAlgorithm(string algorithm);
    string getCategory();
    string getAlgorithm();

    //window that loads all results


    //to start over/reset input
    void resetWindow(sf::RenderWindow& window);
};