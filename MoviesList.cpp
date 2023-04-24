
#include "MoviesList.h"
#include <fstream>
#include <sstream>

void MoviesList::quickSort(int low, int high) {// sorting by rating. assuming list is of chosen genre or year
    if (low < high)  //  code from prof aman's slides on sorting, slide 122
    {
        int pivot = partition(low, high);
        quickSort(low, pivot - 1);
        quickSort(pivot + 1, high);
    }


}

int MoviesList::partition(int low, int high) {
    double pivot = movies[low].rating; //  code from prof aman's slides on sorting, slide 122
    int up = low, down = high;

    while (up < down) {
        for (int j = up; j < high; j++) {
            if (movies[up].rating > pivot)
                break;
            up++;
        }
        for (int j = high; j > low; j--) {
            if (movies[down].rating < pivot)
                break;
            down--;
        }
        if (up < down)
            swap(movies[up], movies[down]);
    }
    swap(movies[low], movies[down]);
    return down;
}


int MoviesList::getSize() {
    return movies.size();
}

void MoviesList::printMovies() {  // testing purposes
    for (auto & movie : movies) {
        cout << movie.title << " " << movie.year << " ";

        auto genreIt = movie.genres.begin();
        for (genreIt; genreIt != movie.genres.end(); genreIt++){
            cout << *genreIt << " ";
        }
        cout << movie.rating << endl;
    }

}

void MoviesList::shellSort(int size) {
    // pulled from aman's lecture 6, slide 74

    // set the initial value of gap to n / 2
    int gap = size / 2;

    while (gap > 0) {
        // for each array element from position gap to the last element
        for (int i = gap; i < size; i++) {
            double key = movies[i].rating;
            int j;
            for (j = i; j >= gap && movies[j - gap].rating > key; j -= gap) {
                // insert this element where it belongs in its subarray
                movies[j].rating = movies[j - gap].rating;
            }
            movies[j].rating = key;
        }
        // else gap = gap / 2
        gap /= 2;
    }
}

void MoviesList::addMovies(const string &userGenre,const string &userYear) {
    ifstream inFile;
    inFile.open("movielens.csv");

    string ignore;

    getline(inFile, ignore);  //  first line with col titles

    string lineFromFile;

    while (getline(inFile, lineFromFile)) {
        stringstream stream(lineFromFile);

        getline(stream, ignore, ',');  // ignoring #
        getline(stream, ignore, ','); // ignoring movieID

        getline(stream, ignore, '"'); // chopping off " before title
        string title;
        getline(stream, title, '"');  //  read up until " then chop off comma
        getline(stream, ignore, ',');

        string yearString;
        getline(stream, yearString, ',');
        int year = stoi(yearString);

        getline(stream, ignore, '"'); // chopping off " at start of genres
        string allGenres;
        getline(stream, allGenres, '"'); // chopping off " at end of genres

        stringstream genreStream(allGenres);
        unordered_set<string> genres;
        string genre1;
        while (getline(genreStream, genre1, '|')) {  //  getting each genre seperated by '|'
            genres.insert(genre1);
        }

        getline(stream, ignore, ',');
        getline(stream, ignore, ','); // ignoring userID

        string ratingTemp;
        getline(stream, ratingTemp, ',');
        double rating = stod(ratingTemp);

        getline(stream, ignore);  // ignoring timestamp

        Movie movieObj(title, year, genres, rating);

        bool duplicate = false;

        for (auto & movie : movies) {
            if (movie.title == movieObj.title) {
                movie.count++;
                movie.rating += movieObj.rating;
                duplicate = true;
                break;
            }

        }
        if (!duplicate) {  //  this could be simplified but it works
            if (movieObj.genres.find(userGenre) != genres.end()) {
                if (userYear.empty()) {
                    movies.push_back(movieObj);  // if user wants rec based on genre
                }
                else if (yearString == userYear) {
                    movies.push_back(movieObj);  //  if user wants rec based on genre AND year
                }
            }

            // if user wants a recommendation based on year
            else if (yearString == userYear && userGenre.empty()) {
                movies.push_back(movieObj);
            }

        }


    }

    // setting correct rating averages
    for (auto & movie : movies) {
        movie.rating = (movie.rating / movie.count);
    }


}

string MoviesList::getMovieRecTitle(int index) {
    return movies[index].title;
}

string MoviesList::getMovieRecRating(int index) {
    return std::to_string(movies[index].rating).substr(0, 4);
}




