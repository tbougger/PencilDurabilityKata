#pragma once

#include <iostream>

#include "Paper.h"

class Pencil
{
public:
   Pencil();
   Pencil( int durability );
   virtual ~Pencil();

   void write( std::string text, Paper &paper );
   int getDurability();

private:
   int m_durability;
};
