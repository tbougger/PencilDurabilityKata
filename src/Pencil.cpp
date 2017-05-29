#include "Pencil.h"

Pencil::Pencil() : m_durability( 40000 )
{
}

Pencil::Pencil( int durability ) : m_durability( durability )
{
}

Pencil::~Pencil()
{
}

int Pencil::getDurability()
{
   return m_durability;
}

void Pencil::write( std::string text, Paper &paper )
{
   paper.append( text );
}
