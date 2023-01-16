#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void ):materias(), materias_learned(0)
{
    // std::cout << "MateriaSource: Default created!" << std::endl;
}

MateriaSource::MateriaSource( const MateriaSource& other )
{
    // std::cout << "MateriaSource: Copy constructor called!" << std::endl;
    *this = other;
}

MateriaSource::~MateriaSource( void )
{
    // std::cout << "MateriaSource destroyed!" << std::endl;
    for (int i = 0; i < materias_learned; i++)
        delete this->materias[i];
}

MateriaSource& MateriaSource::operator =( const MateriaSource& other )
{
    // std::cout << "MateriaSource: Copy operator called!" << std::endl;
    this->materias_learned = other.materias_learned;
    for (int i = 0; i < materias_learned; i++) {
        delete this->materias[i];
        this->materias[i] = other.materias[i];
    }
    return *this;
}

void MateriaSource::learnMateria( AMateria* materia)
{
    if (materias_learned < materias_count)
        materias[materias_learned++] = materia->clone();
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
        if (this->materias[i]->getType() == type)
            return this->materias[i]->clone();
    return 0;
}