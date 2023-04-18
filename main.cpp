#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Movie.h"
using namespace std;

/*NOTES: CURRENTLY AN ISSUE AT LINE 11738, SAYING INVALID ARGUMENT FOR STOD
 * REASON: TITLE AT LINE 11739 DOESN'T HAVE "" AROUND IT, BUT ITS BECAUSE THE USER GAVE NO ANSWER FOR TITLE, AND THE INPUT IS NA.
 * SHOULD WE JUST DELETE THESE LINES FROM THE CSV LOL THIS IS WEIRD TO DEAL WITH. I THINK ITS JUST 7 LINES.
 * IM CHILL WITH THAT IF YALL ARE. I THINK THE PARSING WILL BE GOOD AFTER WE DEAL WITH THAT!*/

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

      /*  cout << movieObj.title << " " << movieObj.year <<" ";
        for (int i = 0; i < movieObj.genres.size(); i++){
            cout << movieObj.genres[i] << " ";
        }
        cout << rating << endl;*/

    }

    return 0;
}