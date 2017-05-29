#include "UnitTest.h"
#include <iostream>

UnitTest::UnitTest() : m_testCount(0), m_passed(0)
{
}

UnitTest::~UnitTest()
{
}

void UnitTest::TEST_COMPARE( std::string expected, std::string actual )
{
   m_testCount++;
   if (actual.compare(expected) == 0)
   {
      std::cout << "Failed" << std::endl
                << "Expected:  " << expected << std::endl
                << "  Actual:  " << actual << std::endl;
   }
   else
   {
      std::cout << "Passed" << std::endl;
      m_passed++;
   }
}

void UnitTest::PRINT_RESULTS()
{
   std::cout << "-------------------------------------------------------------------" << std::endl
             << "Total Number of Tests: " << m_testCount << std::endl
             << "Tests Passed: " << m_passed << std::endl
             << "Tests Failed: " << m_testCount - m_passed << std::endl
             << "-------------------------------------------------------------------" << std::endl
             << std::endl;
}
