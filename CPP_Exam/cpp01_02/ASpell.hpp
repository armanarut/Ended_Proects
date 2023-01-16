#ifndef ASpell_HPP
#define ASpell_HPP
#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell
{
public:
    ASpell() {}
    ASpell(const std::string& name, const std::string& effects)
        :name(name), effects(effects){}
    ASpell(const ASpell& obj) {*this = obj;}
    ASpell& operator=(const ASpell& obj) { 
        this->name = obj.name;
        this->effects = obj.effects;
        return *this; }
    virtual ~ASpell() {}

    const std::string& getName() const { return this->name;}
    const std::string& getEffects() const { return this->effects;}

    void launch(const ATarget& obj) const;
    
    virtual ASpell* clone() = 0;

protected:
    std::string name;
    std::string effects;

};

#endif
