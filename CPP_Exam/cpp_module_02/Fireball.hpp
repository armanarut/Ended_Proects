#pragma once

#include <iostream>
#include "ASpell.hpp"

class Fireball : public ASpell
{
public:
    Fireball() {name = "Fireball"; effects = "burnt to a crisp"; }
    Fireball(const std::string& name, const std::string& effects)
        :ASpell(name, effects){}
    Fireball(const Fireball& obj) {}
    Fireball& operator=(const Fireball& obj) { return *this; }
    ~Fireball() {}

    Fireball* clone() { return new Fireball(name, effects); }
};