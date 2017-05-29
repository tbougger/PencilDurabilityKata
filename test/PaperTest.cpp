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
   PRINT_RESULTS();
}

void PaperTest::constructorSetsText()
{
   FUNCTION_NAME;

   Paper paper( "Setting initial text" );
   TEST_COMPARE( "Setting initial text", paper.getText() );
}

void PaperTest::appendAddsTextAtTheEnd()
{
   FUNCTION_NAME;

   Paper paper( "Initial text" );
   paper.append( " + added more text" );
   TEST_COMPARE( "Initial text + added more text", paper.getText() );
}
