#include <typeinfo>

#include "PencilTest.h"
#include "Pencil.h"
#include "Paper.h"

PencilTest::PencilTest()
{
}

PencilTest::~PencilTest()
{
}

void PencilTest::run()
{
   pencilWritesOnPaper();
   pencilAppendsToPaper();
   pencilHasDefaultDurabilityDefaultLengthDefualtEraser();
   constructorSetsDurabilityLengthAndEraser();
   durabililtyDecreasesWhenWriting();
   pencilWritesSpacesWhenDull();
   pencilWritesSpacesAfterBecomingDull();
   whitespaceDoesNotDecreaseDurability();
   capitalLettersDecreaseDurabilityByTwo();
   sharpeningPencilRestoresDurabilityAndDecreasesLength();
   pencilsWithZeroLengthCannotBeSharpened();
   eraserRemovesTextIfFoundFromPaperStartingAtTheEnd();
   eraserDurabilityDecreasesWithUse();
   eraserDurabilityDoesNotDecreaseWithWhitespace();
   eraserDoesNotEraseWhenDurabilityIsZero();
   editOverwritesWhitespaceOnThePaper();
   editWritesOnTopOfExistingText();
   PRINT_RESULTS();
}

void PencilTest::pencilWritesOnPaper()
{
   FUNCTION_NAME;

   Pencil pencil;
   Paper paper;

   pencil.write( "Pencil writes on paper", paper );
   TEST_STRING_COMPARE( "Pencil writes on paper", paper.getText() );
}

void PencilTest::pencilAppendsToPaper()
{
   FUNCTION_NAME;

   Paper paper( "Existing Text" );
   Pencil pencil;
   
   pencil.write( " - Pencil appends to paper", paper );
   TEST_STRING_COMPARE( "Existing Text - Pencil appends to paper", paper.getText() );
}

void PencilTest::pencilHasDefaultDurabilityDefaultLengthDefualtEraser()
{
   FUNCTION_NAME;

   Pencil pencil;
   TEST_INT_COMPARE( 40000, pencil.getDurability() );
   FUNCTION_NAME;
   TEST_INT_COMPARE( 100, pencil.getLength() );
   FUNCTION_NAME;
   TEST_INT_COMPARE( 20000, pencil.getEraser() );
}

void PencilTest::constructorSetsDurabilityLengthAndEraser()
{
   FUNCTION_NAME;

   Pencil pencil( 100, 25, 50 );
   TEST_INT_COMPARE( 100, pencil.getDurability() );
   FUNCTION_NAME;
   TEST_INT_COMPARE( 25, pencil.getLength() );
   FUNCTION_NAME;
   TEST_INT_COMPARE( 50, pencil.getEraser() );
}

void PencilTest::durabililtyDecreasesWhenWriting()
{
   FUNCTION_NAME;

   Pencil pencil( 100, 10, 50 );
   Paper paper;

   pencil.write( "Durability decreases as you write", paper );
   TEST_INT_COMPARE( 70, pencil.getDurability() );
}

void PencilTest::pencilWritesSpacesWhenDull()
{
   FUNCTION_NAME;

   Pencil pencil( 0, 10, 50 );
   Paper paper;

   pencil.write( "Pencil writes spaces when dull", paper );
   TEST_STRING_COMPARE( "                              ", paper.getText() );
}

void PencilTest::pencilWritesSpacesAfterBecomingDull()
{
   FUNCTION_NAME;

   Pencil pencil( 10, 100, 50 );
   Paper paper;

   pencil.write( "Pencil writes spaces after becoming dull", paper );
   TEST_STRING_COMPARE( "Pencil wri                              ", paper.getText() );
}

void PencilTest::whitespaceDoesNotDecreaseDurability()
{
   FUNCTION_NAME;

   Pencil pencil( 100, 10, 50 );
   Paper paper;

   pencil.write( "\nWhitespace does not decrease\ndurability     .", paper );
   TEST_INT_COMPARE( 63, pencil.getDurability() );
}

void PencilTest::capitalLettersDecreaseDurabilityByTwo()
{
   FUNCTION_NAME;

   Pencil pencil( 100, 10, 50);
   Paper paper;

   pencil.write( "CapitalLettersDecreaseDurabilityByTwo", paper );
   TEST_INT_COMPARE( 57, pencil.getDurability() );
}

void PencilTest::sharpeningPencilRestoresDurabilityAndDecreasesLength()
{
   FUNCTION_NAME;

   Pencil pencil( 100, 10, 50 );
   Paper paper;

   pencil.write( "Writing Something", paper );
   pencil.sharpen();
   TEST_INT_COMPARE( 100, pencil.getDurability() );
   FUNCTION_NAME;
   TEST_INT_COMPARE( 9, pencil.getLength() );
}

void PencilTest::pencilsWithZeroLengthCannotBeSharpened()
{
   FUNCTION_NAME;

   Pencil pencil( 100, 0, 50 );
   Paper paper;

   pencil.write( "Writing Something", paper );
   pencil.sharpen();
   TEST_INT_COMPARE( 82, pencil.getDurability() );
}

void PencilTest::eraserRemovesTextIfFoundFromPaperStartingAtTheEnd()
{
   FUNCTION_NAME;

   Pencil pencil;
   Paper paper( "This is the text on the paper" );

   pencil.erase( "the", paper );
   TEST_STRING_COMPARE( "This is the text on     paper", paper.getText() );
   FUNCTION_NAME;
   pencil.erase( "the", paper );
   TEST_STRING_COMPARE( "This is     text on     paper", paper.getText() );
   FUNCTION_NAME;
   pencil.erase( "the", paper );
   TEST_STRING_COMPARE( "This is     text on     paper", paper.getText() );
}

void PencilTest::eraserDurabilityDecreasesWithUse()
{
   FUNCTION_NAME;

   Pencil pencil(100, 100, 5 );
   Paper paper( "This is the text on the paper" );

   pencil.erase( "the", paper );
   TEST_INT_COMPARE( 2, pencil.getEraser() );
}

void PencilTest::eraserDurabilityDoesNotDecreaseWithWhitespace()
{
   FUNCTION_NAME;

   Pencil pencil(100, 100, 20 );
   Paper paper( "This is the text on the paper" );

   pencil.erase( "This is the text", paper );
   TEST_INT_COMPARE( 7, pencil.getEraser() );
}

void PencilTest::eraserDoesNotEraseWhenDurabilityIsZero()
{
   FUNCTION_NAME;

   Pencil pencil( 100, 100, 5 );
   Paper paper( "This is the text on the paper" );

   pencil.erase( "the", paper );
   TEST_STRING_COMPARE( "This is the text on     paper", paper.getText() );
   FUNCTION_NAME;
   pencil.erase( "the", paper );
   TEST_STRING_COMPARE( "This is t   text on     paper", paper.getText() );
   FUNCTION_NAME;
   TEST_INT_COMPARE( 0, pencil.getEraser() );
   FUNCTION_NAME;
   pencil.erase( "the", paper );
   TEST_STRING_COMPARE( "This is t   text on     paper", paper.getText() );
}

void PencilTest::editOverwritesWhitespaceOnThePaper()
{
   FUNCTION_NAME;

   Pencil pencil(100, 100, 20 );
   Paper paper( "This is the      on the paper" );

   pencil.edit( 12, "TEXT", paper );
   TEST_STRING_COMPARE( "This is the TEXT on the paper", paper.getText() );
}

void PencilTest::editWritesOnTopOfExistingText()
{
   FUNCTION_NAME;

   Pencil pencil(100, 100, 20 );
   Paper paper( "This is the      on the paper" );

   pencil.edit( 8, "aaa TEXT bb", paper );
   TEST_STRING_COMPARE( "This is @@@ TEXT @@ the paper", paper.getText() );
}

