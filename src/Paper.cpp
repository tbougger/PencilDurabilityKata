#include "Paper.h"

Paper::Paper()
{
}

Paper::Paper( std::string text ) : m_text( text )
{
}

Paper::~Paper()
{
}

std::string Paper::getText()
{
    return m_text;
}

void Paper::append( std::string text )
{
    m_text += text;
}
