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

void Pencil::write( const std::string &text, Paper &paper )
{
   std::string pencilText = text;
   for( std::string::iterator it = pencilText.begin(); it != pencilText.end(); ++it )
   {
      *it = write( *it );
   }

   paper.append( pencilText );
}

char Pencil::write( char character )
{
   if( isDull() )
   {
      return ' ';
   }
   else
   {
      --m_durability;
   }

   return character;
}

bool Pencil::isDull()
{
   return ( 0 == m_durability );
}

