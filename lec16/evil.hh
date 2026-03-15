#include <string>
using namespace std;

class Monster {
    friend class EvilGenius;
public:
    // This acts as the default ctor because of the default argument
    Monster(std::string type = "skibidi") : type_str(type) {}
    
    // Virtual destructor is good practice for inheritance
    virtual ~Monster() {}

    virtual std::string get_type() const {
        return type_str;
    }

private:
    std::string type_str; 
};

class EvilGenius {
public:
    EvilGenius();
    EvilGenius(string name, Monster pet);
    EvilGenius(string name, const Monster &pet);
    virtual ~EvilGenius();

private:
    string name;
    Monster pet; // Assume creating a Monster is some work
};