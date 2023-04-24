#include <iostream>
#include <string>
#include "Interface.h"
using namespace std;

int main() {

    Interface interface;
    MoviesList allMovies; // from testing quickSort
    interface.createWindow(allMovies);
    interface.resultsWindow(allMovies);
    //cout << input << endl;  // category input algorithm
    //TODO: parsing doesn't always work, idk why but the input from the user will always be in the format above
    //parsing works correctly for year inputs but not genre input
//    string typeInput = input.substr(0, input.find(" "));
//    string userInput = input.substr(typeInput.size()+1, input.find(" ")+1);
//    string sortInput = input.substr(userInput.size() + typeInput.size() + 1);
//
//    cout << "Category: " <<  typeInput << endl;
//    cout << "Input: " <<  userInput << endl;
//    cout << "Sort: " <<  sortInput << endl;

   // allMovies.addMovies();  // PASS IN GENRE, YEAR ("" for year if only sorting by genre and vice versa)

   /* if(typeInput == "year" && sortInput == "shell"){
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
    }*/
    return 0;
}