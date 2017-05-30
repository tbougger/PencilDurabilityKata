#include "Paper.h"

Paper::Paper()
{
}

Paper::Paper( const std::string& text ) : m_text( text )
{
}

Paper::~Paper()
{
}

const std::string& Paper::getText()
{
    return m_text;
}

void Paper::append( const std::string& text )
{
    m_text += text;
}

void Paper::replace( std::size_t position, const std::string& text )
{
   if( position + text.length() <= m_text.length() )
   {
      m_text.replace( position, text.length(), text );
   }
}
