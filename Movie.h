#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Movie {
public:
    string title;
    int year;
    unordered_set<string> genres;
    double rating;
    int count;

    Movie(string &_title, int &_year, unordered_set<string> &_genres, double &_rating);
};


