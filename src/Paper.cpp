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

void Paper::set( const std::string& text )
{
   m_text = text;
}
