#include <iostream> // char vs. string
#include <string>
using namespace std;

int main (int argc, char* argv[]){
    string tree = "pine";
    string fruit = "apple";
    cout << tree + "apple" << endl;
    string f = tree + fruit;
    if ("pineapple" == f) {
        cout << "yup, the same" << endl; // they are the same
    }
    int n = f.length(); // "length()" ignores trailing zero
    cout << "Beyond the " << f[0] << f.at(4) << f.substr(n-2) << endl;

    // Output: Beyond the pale
    // Beware, this "+" performs integer addition
    cout << "Beyond the " << f[0] + f.at(4) << endl;
    // Output: Beyond the 209
}