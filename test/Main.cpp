#include <iostream>

#include "PencilTest.h"
#include "PaperTest.h"

int main( int argc, const char * argv[] ) 
{
   std::cout << "PencilTest suite" << std::endl;
   PencilTest pencilTest;
   pencilTest.run();

   std::cout << "PaperTest suite" << std::endl;
   PaperTest paperTest;
   paperTest.run();
   
   return 0;
}

