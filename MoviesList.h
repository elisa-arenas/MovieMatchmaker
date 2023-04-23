#include "Movie.h"

class MoviesList {
private:
    vector<Movie> movies;

public:
    int getSize();

    void quickSort(int low, int high);

    int partition(int low, int high);

    void printMovies();  // just for testing rn

    void shellSort(int size);

    void addMovies(const string &userGenre, const string &userYear);

};




