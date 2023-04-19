#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "MoviesList.h"
#include "Interface.h"
using namespace std;


int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "The Movie Matchmaker!");
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(300, 200));
    rectangle.setPosition(sf::Vector2f(220, 50)); // set position to (200, 200)
    rectangle.setFillColor(sf::Color::Green); // set fill color to red
    rectangle.setOutlineColor(sf::Color::White); // set outline color to blue
    rectangle.setOutlineThickness(2); // set outline thickness to 2 pixels




    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                window.close();
        }


        window.clear();
        window.draw(rectangle);
        window.display();
    }

    cout << "Welcome to the Movie Matchmaker!" << endl;
    cout << "--------------------------------" << endl;
    cout << "Here We Will Return a Sorted Selection of Movie Recommendations!" << endl;
    cout << "Please Choose a Sorting Category: Year or Genre" << endl;

    string typeInput;
    string sortInput;
    cin >> typeInput;
    MoviesList allMovies; // from testing quickSort
    allMovies.addMovies();

    // YEAR
    if (typeInput == "Year" || typeInput == "year") {
        cout << "Please Choose a Sorting Algorithm: Shell Sort or Quick Sort" << endl;
        cin >> sortInput;
        if (sortInput == "Shell" || sortInput == "shell") {
            cout << "Beginning Shell Sort by Year...." << endl;
        } else if (sortInput == "Quick" || sortInput == "quick") {
            cout << "Beginning Quick Sort by Year...." << endl;
        }
    }
        // GENRE
    else if (typeInput == "Genre" || typeInput == "genre") {
        cout << "Please Choose a Sorting Algorithm: Shell Sort or Quick Sort" << endl;
        cin >> sortInput;
        if (sortInput == "Shell" || sortInput == "shell") {
            cout << "Beginning Shell Sort by Genre...." << endl;
            // shell sort

        } else if (sortInput == "Quick" || sortInput == "quick") {
            cout << "Beginning Quick Sort by Genre...." << endl;
            // quick sort
            allMovies.quickSort(0,allMovies.getSize()-1);
            allMovies.printMovies();
        }
    }
    allMovies.shellSort(allMovies.getSize());
    allMovies.printMovies();
    return 0;
}