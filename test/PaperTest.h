#pragma once

#include "UnitTest.h"

class PaperTest : public UnitTest
{
public:
   PaperTest();
   ~PaperTest();

   void run();

private:
   void constructorSetsText();
   void appendAddsTextAtTheEnd();
   void replaceChangesThePaperText();
};
