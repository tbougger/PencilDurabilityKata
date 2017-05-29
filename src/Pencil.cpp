#include "Pencil.h"

Pencil::Pencil()
{
}

Pencil::~Pencil()
{
}

void Pencil::write( std::string text, Paper &paper )
{
   paper.append( text );
}
