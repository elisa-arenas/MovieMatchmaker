#include <iostream>
#include <string>


using namespace std;


int main() {
    cout << "Welcome to the Movie Matchmaker!" << endl;
    cout << "--------------------------------" << endl;
    cout << "Here We Will Return a Sorted Selection of Movie Recommendations!" << endl;
    cout << "Please Choose a Sorting Category: Year or Genre" << endl;
    string typeInput;
    string sortInput;
    cin >> typeInput;
    if (typeInput == "Year" || typeInput == "year") {
        cout << "Please Choose a Sorting Algorithm: Shell Sort or Quick Sort";
        cin >> sortInput;
        if (sortInput == "Shell Sort" || sortInput == "shell sort") {
            cout << "Begin Shell Sort by Year...." << endl;
        } else if (typeInput == "Genre" || typeInput == "genre") {
            cout << "Please Choose a Sorting Algorithm: Shell Sort or Quick Sort";
            cin >> sortInput;
            if (sortInput == "Shell Sort" || sortInput == "shell sort") {
                cout << "Begin Shell Sort by Genre...." << endl;
            }
            return 0;
        }
    }
}