#include <stdlib.h>

#include "PencilUi.h"
#include "Pencil.h"

PencilUi::PencilUi() : m_pencil( NULL )
{
}

PencilUi::~PencilUi()
{
   if( m_pencil != NULL )
   {
      delete m_pencil;
   }
}

int PencilUi::run()
{
   bool exit = false;
   while ( !exit )
   {
      exit = mainMenu();
   }
   
   return 0;
}

bool PencilUi::mainMenu()
{
   bool exit = false;
   clearScreenPrintStats();
   std::cout << "Main Menu:" << std::endl << "----------" << std::endl
             << "  1) Print Page" << std::endl
             << "  2) Create Pencil" << std::endl
             << "  3) Write" << std::endl
             << "  4) Erase" << std::endl
             << "  5) Edit" <<  std::endl
             << "  6) Sharpen Pencil" <<  std::endl
             << "  7) Exit" << std::endl << "----------" << std::endl
             << "Choose an Option:" << std::endl;

   int option = promptNumber( 1, 7 );

   switch( option )
   {
   case 1:
      printPage();
      break;
   case 2:
      createPencil();
      break;
   case 3:
      write();
      break;
   case 4:
      erase();
      break;
   case 5:
      edit();
      break;
   case 6:
      sharpen();
      break;
   case 7:
   default:
      exit = true;
      break;
   }
   
   return exit;
}

void PencilUi::displayStats()
{
   int durability = 0;
   int length = 0;
   int eraser = 0;
   if ( m_pencil != NULL )
   {
      durability = m_pencil->getDurability();
      length = m_pencil->getLength();
      eraser = m_pencil->getEraser();
   }

   std::cout << "Pencil Stats: Durability = " << durability << "  Length = " << length << "  Eraser = " << eraser;
   std::cout << std::endl << "--------------------------------------------" << std::endl;
}

void PencilUi::printPage()
{
   clearScreenPrintStats();

   std::cout << m_paper.getText() << std::endl << std::endl;
   pressEnterToContinue();
}

void PencilUi::createPencil()
{
   clearScreenPrintStats();
   std::cout << "Enter Pencil Durability" << std::endl;
   int durability = promptNumber( 0 );

   std::cout << "Enter Pencil Length" << std::endl;
   int length = promptNumber( 0 );

   std::cout << "Enter Eraser Durability" << std::endl;
   int eraser = promptNumber( 0 );

   if( m_pencil != NULL )
   {
      delete m_pencil;
   }
   m_pencil = new Pencil( durability, length, eraser );
   clearScreenPrintStats();
   std::cout << "Pencil Created" << std::endl;
   pressEnterToContinue();
}

void PencilUi::write()
{
   clearScreenPrintStats();
   std::cout << "Enter text to write:" << std::endl;
   std::string text = promptString();
   if( m_pencil != NULL )
   {
      m_pencil->write( text, m_paper );
      std::cout << "Text Written!" << std::endl;
   }
   else
   {
      std::cout << "You must create a pencil first" << std::endl;
   }

   pressEnterToContinue();
}

void PencilUi::erase()
{
   clearScreenPrintStats();
   std::cout << "Enter text to erase:" << std::endl;
   std::string text = promptString();
   if( m_paper.getText().find( text ) == std::string::npos )
   {
      std::cout << "Text not found on Page" << std::endl;
   }
   else if( m_pencil != NULL )
   {
      m_pencil->erase( text, m_paper );
      std::cout << "Text Erased!" << std::endl;
   }
   else
   {
      std::cout << "You must create a pencil first" << std::endl;
   }

   pressEnterToContinue();
}

void PencilUi::edit()
{
   clearScreenPrintStats();
   std::cout << "Enter position in text start editing:" << std::endl;
   int position = promptNumber( 0, m_paper.getText().length() );
   std::cout << "Enter new text to insert:" << std::endl;
   std::string text = promptString();
   if( position + text.length() > m_paper.getText().length() )
   {
      std::cout << "Text is too long to insert at stating position" << std::endl;
   }
   if( m_pencil != NULL )
   {
      m_pencil->edit( position, text, m_paper );
      std::cout << "Text Inserted!" << std::endl;
   }
   else
   {
      std::cout << "You must create a pencil first" << std::endl;
   }

   pressEnterToContinue();
}

void PencilUi::sharpen()
{
   clearScreenPrintStats();
   if( m_pencil != NULL )
   {
      m_pencil->sharpen();
      std::cout << "Pencil Sharpened!" << std::endl;
   }
   else
   {
      std::cout << "You must create a pencil first" << std::endl;
   }
   pressEnterToContinue();
}

int PencilUi::promptNumber( int minVal, int maxVal )
{
   int number = 0;
   std::string text;
   bool isValidNumber = false;

   while( !isValidNumber )
   {
      std::getline( std::cin, text );
      if( !text.empty() && ( text.find_first_not_of( "0123456789" ) == std::string::npos ) )
      {
         number = atoi( text.c_str() );
         
         if( ( number < minVal || number > maxVal ) && maxVal != 0 )
         {
            std::cout << "Please enter a Number between " << minVal << " and " << maxVal << std::endl;
         }
         else
         {
            isValidNumber = true;
         }
      }
      else
      {
         std::cout << "Please enter a Number" << std::endl;
      }
   }
   return number;
}

std::string PencilUi::promptString()
{
   std::string text;
   std::getline( std::cin, text );
   return text;
}

void PencilUi::pressEnterToContinue()
{
   std::cout << "Press Enter to Continue..." << std::endl;
   std::string enter;
   std::getline( std::cin, enter );
}

void PencilUi::clearScreenPrintStats()
{
   std::system("clear");
   displayStats();
}