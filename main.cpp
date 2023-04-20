#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "MoviesList.h"
#include "Interface.h"
using namespace std;
sf::RenderWindow* createWindow();

int main() {
    sf::RenderWindow* window = createWindow();

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