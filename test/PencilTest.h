#pragma once

#include "UnitTest.h"

class PencilTest : public UnitTest
{
public:
   PencilTest();
   ~PencilTest();

   void run();

private:
   void pencilWritesOnPaper();
   void pencilAppendsToPaper();
   void pencilHasDefaultDurability();
   void constructorSetsDurability();
   void durabililtyDecreasesWhenWriting();
};
