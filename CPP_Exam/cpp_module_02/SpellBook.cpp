#include "SpellBook.hpp"

void SpellBook::learnSpell(ASpell* obj)
{
    if (obj)
        book.insert(std::pair<std::string, ASpell*>(obj->getName(), obj->clone()));
}
void SpellBook::forgetSpell(const std::string& spell_name)
{
    ASpell* spell = book[spell_name];
    if (spell)
        delete spell;
    book.erase(spell_name);
}
ASpell* SpellBook::createSpell(const std::string& spell_name)
{
    ASpell* spell = book[spell_name];
    if (spell)
        return spell->clone();
    else
        return NULL;
}