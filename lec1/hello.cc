#include <iostream>             // Access o C++ IO streams (cin, cout, cerr)
#include <string>               // Access to C++ string class

using namespace std;            // Saces some typing, except in interface files

// Global variables
const string kidDrink = "67juice";
string adultDrink = "21coffee";

int main() {
    int age = 100;

    // Notice how we use >> for two purposes
    cout << "21>>3 == " << (21 >> 3) << endl;

    cout << "How old are you, eh? ";
    cin >> age;
    while (age > 0) {
        if (age == 62) {
            adultDrink = "beer"; // Sneaky, changes global var!
        }
        cout << "I'll get you some ";
        if (age < 18) {
            cout << kidDrink << endl;
        } 
        else {
            cout << adultDrink << endl;
        }
        cout << "How old are you, eh? ";
        cin >> age;
    }
}

