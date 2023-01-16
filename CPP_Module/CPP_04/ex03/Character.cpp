#include "Character.hpp"

Character::Character( void ):
    name(),
    materias(),
    materias_floor(),
    materias_unequiped(0)
{
    // std::cout << "Character: Default created!" << std::endl;
}

Character::Character( std::string name ):
    name(name),
    materias(),
    materias_floor(),
    materias_unequiped(0)
{
    // std::cout << "Character: " << name << " created!" << std::endl;
}

Character::Character( const Character& other )
{
    // std::cout << "Character: Copy constructor called!" << std::endl;
    *this = other;
}

Character::~Character( void )
{
    // std::cout << "Character: " << name << " destroyed!" << std::endl;
    for (int i = 0; i < this->materias_count; i++)
        if (this->materias[i])
            delete this->materias[i];
    for (int i = 0; i < this->materias_unequiped; i++)
        if (this->materias_floor[i])
            delete this->materias_floor[i];
}

Character& Character::operator =( const Character& other )
{
    // std::cout << "Character: Copy operator called!" << std::endl;
    this->name = other.name;
    for (int i = 0; i < this->materias_count; i++) {
        if (this->materias[i])
            delete this->materias[i];
        this->materias[i] = other.materias[i];
    }
    return *this;
}

std::string const& Character::getName() const
{
    return this->name;
}

void Character::equip(AMateria* m)
{
    for (int i = 0; i < this->materias_count; i++) {
        if (!materias[i]) {
            this->materias[i] = m;
            return ;
        }
    }
    std::cout << "Character: " << this->getName() << "'s Inventary is full!" << std::endl;
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx <= this->materias_count) {
        if (materias[idx]) {
            if (this->materias_unequiped < 10) {
                this->materias_floor[this->materias_unequiped++] = this->materias[idx];
                this->materias[idx] = NULL;
            }
            else std::cout << "Character: no place in " << this->getName() << "'s floor!" << std::endl;
        }
        else std::cout << "Character: " << this->getName() << ": slot " << idx << " is empty!" << std::endl;
    }
    else std::cout << "Character: " << this->getName() << "'s Inventary is empty!" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < this->materias_count) {
        if (materias[idx]) {
            this->materias[idx]->use(target);
            delete this->materias[idx];
            materias[idx] = NULL;
        }
        else std::cout << "Character: " << this->getName() << ": slot " << idx << " is empty!" << std::endl;
    }
    else std::cout << "Character: " << this->getName() << ": wrong idx!" << std::endl;
}

std::ostream &operator << ( std::ostream &ostream, const ICharacter& other )
{
    ostream << other.getName();
    return ostream;
}