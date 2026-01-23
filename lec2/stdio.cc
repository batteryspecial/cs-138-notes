#include <iostream>
#include <string>
using namespace std;

int main (int argc, char* argv[]){
    cout << "Hello world" << endl;
    cout << "pi is approx. " << 22/double(7) << endl;

    string name;
    int age;
    cout << "What's your name and age? ";
    cin >> name >> age; // reads next two input tokens

    if (age < 0) {
        cerr << "Error, age must be non-negative.\n";
    }
}
