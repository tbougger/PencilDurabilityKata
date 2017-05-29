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
   m_testCount++;
   if (actual.compare(expected) == 0)
   {
      std::cout << "Passed" << std::endl;
      m_passed++;
   }
   else
   {
      std::cout << "Failed" << std::endl
                << "Expected:  " << expected << std::endl
                << "  Actual:  " << actual << std::endl;
   }
}

void UnitTest::TEST_INT_COMPARE( int expected, int actual )
{
   m_testCount++;
   if ( actual == expected )
   {
      std::cout << "Passed" << std::endl;
      m_passed++;
   }
   else
   {
      std::cout << "Failed" << std::endl
                << "Expected:  " << expected << std::endl
                << "  Actual:  " << actual << std::endl;
   }
}

void UnitTest::PRINT_RESULTS()
{
   std::cout << "Tests Complete:" << std::endl
             << "Number of Tests: " << m_testCount << std::endl
             << "Passed: " << m_passed << std::endl
             << "Failed: " << m_testCount - m_passed << std::endl << std::endl;
}
