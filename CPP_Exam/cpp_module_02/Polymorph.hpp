#pragma once

#include <iostream>
#include "ASpell.hpp"

class Polymorph : public ASpell
{
public:
    Polymorph() {name = "Polymorph"; effects = "turned into a critter"; }
    Polymorph(const std::string& name, const std::string& effects)
        :ASpell(name, effects){}
    Polymorph(const Polymorph& obj) {}
    Polymorph& operator=(const Polymorph& obj) { return *this; }
    ~Polymorph() {}

    Polymorph* clone() { return new Polymorph(name, effects); }
};