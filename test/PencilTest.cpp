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
   pencilHasDefaultDurabilityAndDefaultLength();
   constructorSetsDurabilityAndLength();
   durabililtyDecreasesWhenWriting();
   pencilWritesSpacesWhenDull();
   pencilWritesSpacesAfterBecomingDull();
   whitespaceDoesNotDecreaseDurability();
   capitalLettersDecreaseDurabilityByTwo();
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

void PencilTest::pencilHasDefaultDurabilityAndDefaultLength()
{
   FUNCTION_NAME;

   Pencil pencil;
   TEST_INT_COMPARE( 40000, pencil.getDurability() );
   FUNCTION_NAME;
   TEST_INT_COMPARE( 100, pencil.getLength() );
}

void PencilTest::constructorSetsDurabilityAndLength()
{
   FUNCTION_NAME;

   Pencil pencil( 100, 25 );
   TEST_INT_COMPARE( 100, pencil.getDurability() );
   FUNCTION_NAME;
   TEST_INT_COMPARE( 25, pencil.getLength() );
}

void PencilTest::durabililtyDecreasesWhenWriting()
{
   FUNCTION_NAME;

   Pencil pencil( 100, 100 );
   Paper paper;

   pencil.write( "Durability decreases as you write", paper );
   TEST_INT_COMPARE( 70, pencil.getDurability() );
}

void PencilTest::pencilWritesSpacesWhenDull()
{
   FUNCTION_NAME;

   Pencil pencil( 0, 100 );
   Paper paper;

   pencil.write( "Pencil writes spaces when dull", paper );
   TEST_STRING_COMPARE( "                              ", paper.getText() );
}

void PencilTest::pencilWritesSpacesAfterBecomingDull()
{
   FUNCTION_NAME;

   Pencil pencil( 10, 100 );
   Paper paper;

   pencil.write( "Pencil writes spaces after becoming dull", paper );
   TEST_STRING_COMPARE( "Pencil wri                              ", paper.getText() );
}

void PencilTest::whitespaceDoesNotDecreaseDurability()
{
   FUNCTION_NAME;

   Pencil pencil( 100, 100 );
   Paper paper;

   pencil.write( "\nWhitespace does not decrease\ndurability     .", paper );
   TEST_INT_COMPARE( 63, pencil.getDurability() );
}

void PencilTest::capitalLettersDecreaseDurabilityByTwo()
{
   FUNCTION_NAME;

   Pencil pencil( 100, 100 );
   Paper paper;

   pencil.write( "CapitalLettersDecreaseDurabilityByTwo", paper );
   TEST_INT_COMPARE( 57, pencil.getDurability() );
}
