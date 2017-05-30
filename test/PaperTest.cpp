#include <typeinfo>

#include "PaperTest.h"
#include "Paper.h"

PaperTest::PaperTest()
{
}

PaperTest::~PaperTest()
{
}

void PaperTest::run()
{
   constructorSetsText();
   appendAddsTextAtTheEnd();
   setReplacesThePaperText();
   PRINT_RESULTS();
}

void PaperTest::constructorSetsText()
{
   FUNCTION_NAME;

   Paper paper( "Setting initial text" );
   TEST_STRING_COMPARE( "Setting initial text", paper.getText() );
}

void PaperTest::appendAddsTextAtTheEnd()
{
   FUNCTION_NAME;

   Paper paper( "Initial text" );
   paper.append( " + added more text" );
   TEST_STRING_COMPARE( "Initial text + added more text", paper.getText() );
}

void PaperTest::setReplacesThePaperText()
{
   FUNCTION_NAME;

   Paper paper( "Initial text" );
   paper.set( "New Page" );
   TEST_STRING_COMPARE( "New Page", paper.getText() );
}
