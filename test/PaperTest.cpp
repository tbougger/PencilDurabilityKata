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
   replaceChangesThePaperText();
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

void PaperTest::replaceChangesThePaperText()
{
   FUNCTION_NAME;

   Paper paper( "This is the text on the page" );
   paper.replace( 12, "word" );
   TEST_STRING_COMPARE( "This is the word on the page", paper.getText() );
   paper.replace( 24, "book" );
   FUNCTION_NAME;
   TEST_STRING_COMPARE( "This is the word on the book", paper.getText() );
}
