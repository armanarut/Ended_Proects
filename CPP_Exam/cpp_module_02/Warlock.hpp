#pragma once

#include <iostream>
#include <map>
#include "SpellBook.hpp"
#include "ATarget.hpp"

class Warlock
{
public:
    Warlock(const std::string& name, const std::string& title);
    ~Warlock();

    void introduce() const;
    void learnSpell(ASpell* obj);
    void forgetSpell(const std::string& spell_name);
    void launchSpell(const std::string& spell_name, const ATarget& obj);

    const std::string& getName() const { return name;}
    const std::string& getTitle() const { return title;}
    void setTitle(const std::string& title) { this->title = title; }

private:
    std::string name;
    std::string title;
    SpellBook book;

    Warlock();
    Warlock(const Warlock& obj);
    Warlock& operator=(const Warlock& obj);
};