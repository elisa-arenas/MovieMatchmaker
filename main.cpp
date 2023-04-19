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
        } else if (sortInput == "Quick" || sortInput == "quick") {
            cout << "Beginning Quick Sort by Genre...." << endl;
        }
    }

    MoviesList allMovies; // from testing quickSort

    ifstream inFile;
    inFile.open("movielens.csv");

    if (!inFile.is_open()) {
        cout << "Failed to open file." << endl;
        return 1;
    }
    string ignore;

    getline(inFile, ignore);  //  first line with col titles

    string lineFromFile;

    while(getline(inFile, lineFromFile)){
        stringstream stream(lineFromFile);

        string ignore;
        getline(stream, ignore, ',');  // ignoring #
        getline(stream, ignore, ','); // ignoring movieID

        getline(stream, ignore, '"'); // chopping off " before title
        string title;
        getline(stream, title, '"');  //  read up until " then chop off comma
        getline(stream, ignore, ',');

        string yearTemp;
        getline(stream, yearTemp, ',');
        int year = stoi(yearTemp);

        getline(stream, ignore, '"'); // chopping off " at start of genres
        string allGenres;
        getline(stream, allGenres, '"'); // chopping off " at end of genres

        stringstream genreStream(allGenres);
        vector<string> genres;
        string genre1;
        while (getline(genreStream, genre1, '|')){  //  getting each genre seperated by '|'
            genres.push_back(genre1);
        }


        getline(stream, ignore, ',');
        getline(stream, ignore, ','); // ignoring userID

        string ratingTemp;
        getline(stream, ratingTemp, ',');
        double rating = stod(ratingTemp);

        getline(stream, ignore);  // ignoring timestamp

        Movie movieObj(title, year, genres, rating);
        allMovies.addMovie(movieObj);

    }

      /*   allMovies.quickSort(0,allMovies.getSize()-1); FROM TESTING
         allMovies.printMovies();*/

    return 0;
}