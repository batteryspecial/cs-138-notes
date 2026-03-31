#include <iostream>
#include <string>
#include <deque>
using namespace std;

void print (const deque<string> & d) {
    cout << "Printing d:\n";
    for (size_t i=0; i<d.size(); i++) {
        cout << "d["<< i << "] = " << d.at(i) << '\n';
    }
    cout << '\n';
}

int main (int argc, char* argv[]){
    deque<string> d {};
    // O(1)
    d.push_back("alpha");
    d.push_back("beta");
    d.push_back("gamma");
    d.push_front("upsilon");
    d.push_front("zeta");
    print(d);

    // also O(1)
    cout << d.front() << " " << d.at(0) << endl;
}