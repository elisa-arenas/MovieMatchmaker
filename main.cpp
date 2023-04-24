#include "Interface.h"
using namespace std;

int main() {

    Interface interface;
    MoviesList allMovies; // returns movies that will be used for sorting
    interface.createWindow(allMovies);
    interface.resultsWindow(allMovies);

    return 0;
}