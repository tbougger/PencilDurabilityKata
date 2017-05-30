#pragma once

#include <iostream>

class Paper
{
public:
   Paper();
   Paper( const std::string& text );
   virtual ~Paper();

   const std::string& getText();
   void append( const std::string& text );
   void set( const std::string& text );

private:
   std::string m_text;
};
