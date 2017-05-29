#pragma once

#include <iostream>

class Paper
{
public:
   Paper();
   Paper( std::string text );
   virtual ~Paper();

   std::string getText();
   void append( std::string text );

private:
   std::string m_text;
};
