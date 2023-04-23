#include "Movie.h"

Movie::Movie(string &_title, int &_year, unordered_set<string> &_genres, double &_rating) {
    title = _title;
    year = _year;
    genres = _genres;
    rating = _rating;
    count = 1;

}

string Movie::getTitle() {
    return title;
}
