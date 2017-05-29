#pragma once

#include <iostream>

#define FUNCTION_NAME std::cout << __func__ << " - ";

class UnitTest
{
public:
   UnitTest();
   virtual ~UnitTest();
   virtual void run() = 0;

protected:
   void TEST_COMPARE( std::string expected, std::string actual );
   void PRINT_RESULTS();

   int m_testCount;
   int m_passed;
};
