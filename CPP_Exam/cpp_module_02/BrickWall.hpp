#pragma once

#include <iostream>
#include "ATarget.hpp"

class BrickWall : public ATarget
{
public:
    BrickWall(){type = "Inconspicuous Red-brick Wall";}
    BrickWall(const std::string& type)
        :ATarget(type) {}
    BrickWall(const BrickWall& obj) {}
    BrickWall& operator=(const BrickWall& obj) { return *this; }
    ~BrickWall() {}

    BrickWall* clone(){return new BrickWall(type);}

};