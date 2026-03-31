// File: "Balloon.h"
#ifndef BALLOON_H
#define BALLOON_H
#include <string>

class Balloon {
    public:
    Balloon(std::string colour);
    void speak () const;
    private:
    std::string colour;
};

#endif /* BALLOON_H */