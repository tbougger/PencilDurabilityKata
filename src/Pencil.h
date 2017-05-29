#pragma once

#include <iostream>

#include "Paper.h"

class Pencil
{
public:
   Pencil();
   virtual ~Pencil();

   void write( std::string text, Paper &paper );

};
