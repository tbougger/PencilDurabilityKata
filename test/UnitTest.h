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
   void TEST_STRING_COMPARE( std::string expected, std::string actual );
   void TEST_INT_COMPARE( int expected, int actual );
   void PRINT_RESULTS();

   int m_testCount;
   int m_passed;

private:
   bool TEST_COMPARE( bool result );   
};
