#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "MoviesList.h"
using namespace std;


int main() {
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
            allMovies.shellSort(allMovies.getSize());
            allMovies.printMovies();
        } else if (sortInput == "Quick" || sortInput == "quick") {
            cout << "Beginning Quick Sort by Genre...." << endl;
            // quick sort
            allMovies.quickSort(0,allMovies.getSize()-1);
            allMovies.printMovies();
        }
    }

    return 0;
}

//
//#include <SFML/Graphics.hpp>
//
//
//int main(){
//    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
//    sf::CircleShape shape(100.f);
//    shape.setFillColor(sf::Color::Green);
//
//
//    while(window.isOpen()){
//        sf::Event event;
//        while(window.pollEvent(event)){
//            if(event.type == sf::Event::Closed)
//                window.close();
//        }
//
//
//        window.clear();
//        window.draw(shape);
//        window.display();
//    }
//    return 0;
//}
