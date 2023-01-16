#pragma once

#include <iostream>
#include "ATarget.hpp"

class Dummy : public ATarget
{
public:
    Dummy(){type = "Target Practice Dummy";}
    Dummy(const std::string& type)
        :ATarget(type) {}
    Dummy(const Dummy& obj) {}
    Dummy& operator=(const Dummy& obj) { return *this; }
    ~Dummy() {}

    Dummy* clone(){return new Dummy(type);}

};