#ifndef ATarget_HPP
#define ATarget_HPP
#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
public:
    ATarget() {}
    ATarget(const std::string& type)
        :type(type) {}
    ATarget(const ATarget& obj);
    ATarget& operator=(const ATarget& obj) { return *this; }
    virtual ~ATarget() {}

    const std::string& getType() const { return type;}

    void getHitBySpell(const ASpell& obj) const;

    virtual ATarget* clone() = 0;

protected:
    std::string type;

};

#endif