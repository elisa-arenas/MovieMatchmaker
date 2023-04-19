#include "Movie.h"

class MoviesList {
private:
    vector<Movie> movies;

public:
    void addMovie(Movie movieObj);

    int getSize();

    void quickSort(int low, int high);

    int partition(int low, int high);

    void printMovies();  // just for testing rn, only prints title and rating

};




