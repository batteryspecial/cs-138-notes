#ifndef CHILD_H
#define CHILD_H
#include <string>
#include "Balloon.h"

class Child {
    public:
        Child (std::string name,
        std::string bColour);
        virtual ~Child();
        void speak() const;
    private:
        std::string name;
        Balloon* pb;
};

#endif /* CHILD_H */