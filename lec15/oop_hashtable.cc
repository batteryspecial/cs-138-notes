#include "oop_hashtable.hh"

int main (int argc, char* argv[]) {
    HashTable t {100};
    t.insert("Bob", 12345678);
    t.insert("Carole", 55555678);
    t.insert("Ted", 87654321);
    t.insert("Alice", 55555555);
    t.print();

    if (t.lookup(12345678)) {
        cout << "Found Bob!" << '\n';
    }
    if (t.lookup(44444444)) {
        cout << "Still waiting for Godot" << '\n';
    }

    t.remove(55555555);
    cout << t.lookup(55555555) << '\n';

    return 0;
}