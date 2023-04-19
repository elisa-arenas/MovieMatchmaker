#ifndef MOVIEMATCHMAKER_INTERFACE_H
#define MOVIEMATCHMAKER_INTERFACE_H
#endif //MOVIEMATCHMAKER_INTERFACE_H


#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
using namespace std;


class Interface{
    sf::RenderWindow window;
public:
    //constructor creates new window
    Interface(sf::RenderWindow window);


    //maybe use this to customize window
    void initializeWindow(sf::RenderWindow& window);


    //to start over/reset input
    void resetWindow(sf::RenderWindow& window);
};