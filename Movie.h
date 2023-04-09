//
// Created by Sara Smith on 4/9/2023.
//
#include <string>
#include <vector>
using namespace std;

class Movie {
private:
    string title;
    int year;
    vector<string> genres;
    double rating;


public:
    Movie(string &_title, int &_year, vector<string> &_genres, double &_rating);


};


