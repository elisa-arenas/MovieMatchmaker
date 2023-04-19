#include "Movie.h"

class MoviesList {
private:
    vector<Movie> movies;

public:
    int getSize();

    void quickSort(int low, int high);

    int partition(int low, int high);

    void printMovies();  // just for testing rn, only prints title and rating

    void shellSort(int size);

    void addMovies();

};




