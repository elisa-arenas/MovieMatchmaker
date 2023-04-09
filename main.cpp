#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Movie.h"

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
        }
        else if(sortInput == "Quick" || sortInput == "quick") {
            cout << "Beginning Quick Sort by Year...." << endl;
        }
    }
    // GENRE
    else if (typeInput == "Genre" || typeInput == "genre") {
        cout << "Please Choose a Sorting Algorithm: Shell Sort or Quick Sort" << endl;
        cin >> sortInput;
        if (sortInput == "Shell" || sortInput == "shell") {
            cout << "Beginning Shell Sort by Genre...." << endl;
        }
        else if(sortInput == "Quick" || sortInput == "quick") {
            cout << "Beginning Quick Sort by Genre...." << endl;
        }
    }

    ifstream inFile("movielens.csv");
    string lineFromFile;

    getline(inFile, lineFromFile);

    while(getline(inFile, lineFromFile)){

        stringstream stream(lineFromFile);
        string ignore;
        getline(stream, ignore, ',');
        string ignore2;
        getline(stream, ignore2, ',');

        string movie;
        getline(stream, movie, ',');

        string yearTemp;
        getline(stream, yearTemp, ',');
        int year = stoi(yearTemp);

        vector<string> genres;
        string genre;
        getline(stream, genre, '|');
        genres.push_back(genre);


        string ratingTemp;
        getline(stream, ratingTemp, ',');
        double rating = (double)stoi(ratingTemp);

        string time;
        getline(stream, time);

        Movie movie1(movie, year, genres, rating);

        for(int i=0; i<5; i++){
            //cout << movie1.getTitle() << endl;
        }

    }

    return 0;
}