#include "UnitTest.h"
#include <iostream>

UnitTest::UnitTest() : m_testCount(0), m_passed(0)
{
}

UnitTest::~UnitTest()
{
}

void UnitTest::TEST_STRING_COMPARE( std::string expected, std::string actual )
{
   if ( !TEST_COMPARE( actual.compare(expected) == 0 ) )
   {
      std::cout << "Expected:  " << expected << std::endl
                << "  Actual:  " << actual << std::endl;
   }
}

void UnitTest::TEST_INT_COMPARE( int expected, int actual )
{
   if ( !TEST_COMPARE( actual == expected ) )
   {
      std::cout << "Expected:  " << expected << std::endl
                << "  Actual:  " << actual << std::endl;
   }
}

bool UnitTest::TEST_COMPARE( bool result )
{
   m_testCount++;
   if ( result )
   {
      std::cout << "Passed" << std::endl;
      m_passed++;
   }
   else
   {
      std::cout << "Failed" << std::endl;
   }

   return result;
}

void UnitTest::PRINT_RESULTS()
{
   std::cout << "Tests Complete:" << std::endl
             << "Number of Tests: " << m_testCount << std::endl
             << "Passed: " << m_passed << std::endl
             << "Failed: " << m_testCount - m_passed << std::endl << std::endl;
}
