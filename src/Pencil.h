#pragma once

#include <iostream>

#include "Paper.h"

class Pencil
{
public:
   Pencil();
   Pencil( int durability, int length, int eraser );
   virtual ~Pencil();

   void write( const std::string &text, Paper &paper );
   int getDurability();
   int getLength();
   int getEraser();
   bool isDull();
   void sharpen();
   void erase( const std::string& text, Paper& paper );

private:
   int m_durability;
   int m_maxDurability;
   int m_length;
   int m_eraser;

   char write( char character );
   bool isWhitespace( char character );
   bool isCapitalLetter( char character );

};
