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
   pencilHasDefaultDurability();
   constructorSetsDurability();
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

void PencilTest::pencilHasDefaultDurability()
{
   FUNCTION_NAME;

   Pencil pencil;
   TEST_INT_COMPARE( 40000, pencil.getDurability() );
}

void PencilTest::constructorSetsDurability()
{
   FUNCTION_NAME;

   Pencil pencil( 100 );
   TEST_INT_COMPARE( 100, pencil.getDurability() );
}

