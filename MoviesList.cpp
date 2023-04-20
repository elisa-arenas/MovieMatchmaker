
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

    while(up < down)
    {
        for (int j = up; j < high; j++)
        {
            if(movies[up].rating > pivot)
                break;
            up++;
        }
        for (int j = high; j > low; j--)
        {
            if(movies[down].rating < pivot)
                break;
            down--;
        }
        if(up < down)
            swap(movies[up], movies[down]);
    }
    swap(movies[low], movies[down]);
    return down;
}


int MoviesList::getSize() {
    return movies.size();
}

void MoviesList::printMovies() {
    for (int i = 0; i < movies.size(); i++){
        cout << movies[i].title << " " << movies[i].rating << endl;
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

void MoviesList::addMovies() {
    ifstream inFile;
    inFile.open("movielens.csv");

    string ignore;

    getline(inFile, ignore);  //  first line with col titles

    string lineFromFile;

        while (getline(inFile, lineFromFile)) {
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
            while (getline(genreStream, genre1, '|')) {  //  getting each genre seperated by '|'
                genres.push_back(genre1);
            }


            getline(stream, ignore, ',');
            getline(stream, ignore, ','); // ignoring userID

            string ratingTemp;
            getline(stream, ratingTemp, ',');
            double rating = stod(ratingTemp);

            getline(stream, ignore);  // ignoring timestamp

            Movie movieObj(title, year, genres, rating);

            bool duplicate = false;

            for (int i = 0; i < movies.size(); i ++){
                if (movies[i].title == movieObj.title){
                    movies[i].count++;
                    movies[i].rating += movieObj.rating;
                    duplicate = true;
                    break;
                }

            }
            if (!duplicate){
                movies.push_back(movieObj);
            }



    }

    // setting correct rating averages
    for (int i = 0; i < movies.size(); i ++){
        movies[i].rating = (movies[i].rating / movies[i].count);
        }


}



