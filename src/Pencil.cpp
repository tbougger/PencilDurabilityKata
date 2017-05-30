#include "Pencil.h"

Pencil::Pencil() : m_durability( 40000 ), m_length( 100 )
{
}

Pencil::Pencil( int durability, int length ) : m_durability( durability ), m_length( length )
{
}

Pencil::~Pencil()
{
}

int Pencil::getDurability()
{
   return m_durability;
}

int Pencil::getLength()
{
   return m_length;
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
   else if ( isCapitalLetter( character ) )
   {
      m_durability -= ( m_durability > 1 ) ? 2 : 1;
   }
   else if ( !isWhitespace( character ) )
   {
      --m_durability;
   }

   return character;
}

bool Pencil::isDull()
{
   return ( 0 == m_durability );
}

bool Pencil::isWhitespace( char character )
{
   return ( character == ' ' || character == '\n' );
}

bool Pencil::isCapitalLetter( char character )
{
   const static std::string caps = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
   return ( caps.find( character ) != std::string::npos );
}