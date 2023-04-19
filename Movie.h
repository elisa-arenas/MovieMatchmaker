#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Movie {
public:  //  currently public for sake of testing
    string title;
    int year;
    vector<string> genres;
    double rating;



    Movie(string &_title, int &_year, vector<string> &_genres, double &_rating);
    string getTitle();


};


