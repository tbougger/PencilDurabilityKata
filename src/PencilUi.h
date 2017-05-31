#pragma once

#include <iostream>
#include <vector>
#include <cstdlib>

#include "Paper.h"
class Pencil;

class PencilUi
{

public:
   PencilUi();
   virtual ~PencilUi();

   int run();

private:

   Pencil *m_pencil;
   Paper m_paper;

   bool mainMenu();
   void displayStats();
   void printPage();
   void createPencil();
   void write();
   void erase();
   void edit();
   void sharpen();
   int promptNumber( int minVal, int maxVal = 0 );
   std::string promptString();
   void pressEnterToContinue();
   void clearScreenPrintStats();
};
