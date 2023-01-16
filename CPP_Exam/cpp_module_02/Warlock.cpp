#include "Warlock.hpp"


Warlock::Warlock(const std::string& name, const std::string& title)
:name(name), title(title)
{
    std::cout << getName() << ": This looks like another boring day." << std::endl;
}


Warlock::~Warlock()
{
    std::cout << getName() << ": My job here is done!" << std::endl;
}

void Warlock::introduce() const
{
    std::cout << getName() << ": I am " << getName()<< ", "
        << getTitle() << "!" << std::endl;
}

void Warlock::learnSpell(ASpell* obj)
{
    book.learnSpell(obj);
}
void Warlock::forgetSpell(const std::string& spell_name)
{
    book.forgetSpell(spell_name);
}
void Warlock::launchSpell(const std::string& spell_name, const ATarget& obj)
{
    ASpell* spell = book.createSpell(spell_name);
    if (spell)
        spell->launch(obj);
}