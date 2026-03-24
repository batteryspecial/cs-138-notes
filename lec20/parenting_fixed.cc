#include <iostream>
using namespace std;

// Final, correct version
class Parent {
    public:
        Parent(string name);
        virtual ~Parent();
        virtual void speak() const; // must be virtual
        string getName() const; // no need to be virtual
    private:
        string name;
};

Parent::Parent(string name) : name{name} {
    cout << name << " is born" << endl;
}
Parent::~Parent() {}

void Parent::speak() const {
    cout << "Hi, I'm " << name << endl;
}
string Parent::getName() const { // won't be overridden
    return name;
}
