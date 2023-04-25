#include "Movie.h"

class MoviesList {
private:
    vector<Movie> movies;

public:
    int getSize();  //  returns size of vector movies

    void quickSort(int low, int high);  //  quick sorting algorithm to sort movies by user rating

    int partition(int low, int high);  //  for use in quick sort, partitions vector based on pivot

    void printMovies();  // prints attributes for each movie, for testing purposes

    void shellSort(int size);  // shell sorting algorithm to sort movies by user rating

    void addMovies(const string &userGenre, const string &userYear);  //  adds movies to vector based on user's input

    string getMovieRecTitle(int index);  //  returns title of movie at certain index

    string getMovieRecRating(int index);  //  returns rating of movie at certain index



};




