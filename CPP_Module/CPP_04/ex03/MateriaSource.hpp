#pragma once
#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
private:
    const static int materias_count = 4;
    AMateria *materias[MateriaSource::materias_count];
    int materias_learned;

public:
    MateriaSource( void );
    MateriaSource ( const MateriaSource& other );
    ~MateriaSource();

    MateriaSource& operator =( const MateriaSource& other );

    void learnMateria(AMateria* materia);
    AMateria* createMateria(std::string const & type);
};

#endif