#pragma once

#include <iostream>

#include "Paper.h"

class Pencil
{
public:
   Pencil();
   Pencil( int durability, int length, int eraser );
   virtual ~Pencil();

   void write( std::string pencilText, Paper &paper );
   int getDurability();
   int getLength();
   int getEraser();
   bool isDull();
   void sharpen();
   void erase( std::string text, Paper& paper );
   void edit( std::size_t position, std::string text, Paper& paper );

private:
   int m_durability;
   int m_maxDurability;
   int m_length;
   int m_eraser;

   void write( char& character );
   void erase( char& character );
   void overWrite( char& character, char existing );
   bool isWhitespace( char character );
   bool isCapitalLetter( char character );

};
