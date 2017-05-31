#include "Pencil.h"

Pencil::Pencil() : m_durability( 40000 ), m_length( 100 ), m_eraser( 20000 )
{
   m_maxDurability = m_durability;
}

Pencil::Pencil( int durability, int length, int eraser ) : m_durability( durability ), m_length( length ), m_eraser( eraser )
{
   m_maxDurability = durability;
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

int Pencil::getEraser()
{
   return m_eraser;
}

void Pencil::write( std::string pencilText, Paper &paper )
{
   for( std::string::iterator it = pencilText.begin(); it != pencilText.end(); ++it )
   {
      write( *it );
   }
   paper.append( pencilText );
}

void Pencil::write( char& character )
{
   if( isDull() )
   {
      character = ' ';
   }
   else if ( isCapitalLetter( character ) )
   {
      if( m_durability == 1 )
      {
         character = ' ';
      }
      else
      {
         m_durability -= 2;
      }
   }
   else if ( !isWhitespace( character ) )
   {
      --m_durability;
   }
}

bool Pencil::isDull()
{
   return !m_durability;
}

bool Pencil::isWhitespace( char character )
{
   return ( character == ' ' || character == '\n' || character == '\r' );
}

bool Pencil::isCapitalLetter( char character )
{
   return ( character >= 'A' && character <= 'Z' );
}

void Pencil::sharpen()
{
   if( m_length > 0 )
   {
      m_durability = m_maxDurability;
      --m_length;
   }
}

void Pencil::erase( std::string eraseText, Paper& paper )
{
   std::size_t found = paper.getText().rfind( eraseText );
   if( found != std::string::npos )
   {
      for( std::string::reverse_iterator rit = eraseText.rbegin(); rit != eraseText.rend(); ++rit )
      {
         erase( *rit );
      }
      paper.replace( found, eraseText );
   }
}

void Pencil::erase( char& character )
{
   if( m_eraser > 0 && !isWhitespace( character ) )
   {
      --m_eraser;
      character = ' ';
   }
}

void Pencil::edit( std::size_t position, std::string editText, Paper& paper )
{
   if( position + editText.length() <= paper.getText().length() )
   {
      for( std::size_t i = 0; i < editText.length(); ++i )
      {
         overWrite( editText.at( i ), paper.getText().at( position + i ) );
      }
      paper.replace( position, editText );
   }
}

void Pencil::overWrite( char& character, char existing)
{
   if ( isDull() )
   {
      character = existing;
   }
   else if( !isWhitespace( existing ) )
   {
      --m_durability;
      character = '@';
   }
   else
   {
      write( character );
   }
}