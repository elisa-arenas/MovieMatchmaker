#include "Movie.h"

Movie::Movie(string &_title, int &_year, vector<string> &_genres, double &_rating) {
    title = _title;
    year = _year;
    genres = _genres;
    rating = _rating;

}

string Movie::getTitle() {
    return title;
}
