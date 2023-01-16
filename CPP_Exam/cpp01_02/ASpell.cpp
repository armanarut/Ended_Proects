#include "ASpell.hpp"

void ASpell::launch(const ATarget& obj) const{
    obj.getHitBySpell(*this);
}