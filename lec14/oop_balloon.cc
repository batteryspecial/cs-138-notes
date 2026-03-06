#include "oop_balloon.hh"

int main (int argc, char* argv[]) {
    Balloon rb {"red"};
    rb.speak();

    Balloon cb {};
    cb.speak();

    Balloon* gb = new Balloon{"green"};
    gb->speak();

    Balloon* ob = gb;
    ob->speak();
    // static error
    //ob->colour = "blue";
    gb->speak(); 

    delete gb;

    delete ob; // run-time error
}