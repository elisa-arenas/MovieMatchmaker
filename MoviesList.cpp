
#include "MoviesList.h"

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

void MoviesList::addMovie(Movie movieObj) {
    movies.push_back(movieObj);
}

int MoviesList::getSize() {
    return movies.size();
}

void MoviesList::printMovies() {
    for (int i = 0; i < movies.size(); i++){
        cout << movies[i].title << " " << movies[i].rating << endl;
    }

}



