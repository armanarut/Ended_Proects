#pragma once

#include <iostream>
#include "ASpell.hpp"

class Fwoosh : public ASpell
{
public:
    Fwoosh() {name = "Fwoosh"; effects = "fwooshed"; }
    Fwoosh(const std::string& name, const std::string& effects)
        :ASpell(name, effects){}
    Fwoosh(const Fwoosh& obj) {}
    Fwoosh& operator=(const Fwoosh& obj) { return *this; }
    ~Fwoosh() {}

    Fwoosh* clone() { return new Fwoosh(name, effects); }
};