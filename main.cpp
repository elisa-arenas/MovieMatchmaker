#include <iostream>
#include <string>
#include "MoviesList.h"
#include "Interface.h"
using namespace std;

int main() {
    Interface interface;
    string input = interface.createWindow();
    cout << input << endl;  // category algorithm
    string typeInput = input.substr(0, input.find(" "));
    string sortInput = input.substr(typeInput.size()+1);

    MoviesList allMovies; // from testing quickSort
    allMovies.addMovies();  // PASS IN GENRE, YEAR ("" for year if only sorting my genre and vice versa)

    if(typeInput == "year" && sortInput == "shell"){
        cout << "Beginning Shell Sort by Year...." << endl;
        //shell sort
        allMovies.shellSort(allMovies.getSize());
        //display results in new window
        interface.resultsWindow(typeInput, sortInput);
        allMovies.printMovies();
    }
    else if(typeInput == "year" && sortInput == "quick"){
        cout << "Beginning Quick Sort by Year...." << endl;
        //quick sort
        allMovies.quickSort(0,allMovies.getSize()-1);
        //display results in new window
        interface.resultsWindow(typeInput, sortInput);
        allMovies.printMovies();
    }
    else if(typeInput == "genre" && sortInput == "shell"){
        cout << "Beginning Shell Sort by Genre...." << endl;
        //shell sort
        allMovies.shellSort(allMovies.getSize());
        //display results in new window
        interface.resultsWindow(typeInput, sortInput);
        allMovies.printMovies();
    }
    else if(typeInput == "genre" && sortInput == "quick"){
        cout << "Beginning Quick Sort by Genre...." << endl;
        //quick sort
        allMovies.quickSort(0,allMovies.getSize()-1);
        //display results in new window
        interface.resultsWindow(typeInput, sortInput);
        allMovies.printMovies();
    }
    return 0;
}