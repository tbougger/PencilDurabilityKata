#pragma once

#include <iostream>

#include "Paper.h"

class Pencil
{
public:
   Pencil();
   Pencil( int durability, int length );
   virtual ~Pencil();

   void write( const std::string &text, Paper &paper );
   int getDurability();
   int getLength();
   bool isDull();
   void sharpen();

private:
   int m_durability;
   int m_maxDurability;
   int m_length;

   char write( char character );
   bool isWhitespace( char character );
   bool isCapitalLetter( char character );

};
