#pragma once
#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "Fireball.hpp"
#include "Polymorph.hpp"

class SpellBook
{
public:
    SpellBook() {}
    virtual ~SpellBook() {}

    void learnSpell(ASpell* obj);
    void forgetSpell(const std::string& spell_name);
    ASpell* createSpell(const std::string& spell_name);


private:
    std::map<std::string, ASpell*> book;

    SpellBook(const SpellBook& obj);
    SpellBook& operator=(const SpellBook& obj);
};