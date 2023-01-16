#include "ATarget.hpp"


void ATarget::getHitBySpell(const ASpell& obj) const {
    std::cout << type << " has been " << obj.getEffects() << "!" << std::endl;
}