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
   void pencilHasDefaultDurabilityDefaultLengthDefualtEraser();
   void constructorSetsDurabilityLengthAndEraser();
   void durabililtyDecreasesWhenWriting();
   void pencilWritesSpacesWhenDull();
   void pencilWritesSpacesAfterBecomingDull();
   void whitespaceDoesNotDecreaseDurability();
   void capitalLettersDecreaseDurabilityByTwo();
   void sharpeningPencilRestoresDurabilityAndDecreasesLength();
   void pencilsWithZeroLengthCannotBeSharpened();
   void eraserRemovesTextIfFoundFromPaperStartingAtTheEnd();
   void eraserDurabilityDecreasesWithUse();
   void eraserDurabilityDoesNotDecreaseWithWhitespace();
   void eraserDoesNotEraseWhenDurabilityIsZero();
   void editOverwritesWhitespaceOnThePaper();
   void editWritesOnTopOfExistingText();
   void cannotWriteCapitalLettersWhenDurabilityIsOne();
};
