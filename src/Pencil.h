#pragma once

#include <iostream>

#include "Paper.h"

class Pencil
{
public:
   Pencil();
   Pencil( int durability );
   virtual ~Pencil();

   void write( const std::string &text, Paper &paper );
   int getDurability();
   bool isDull();

private:
   int m_durability;

   char write( char character );

};
