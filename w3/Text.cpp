#include <iostream>
#include <fstream>
#include "Text.h"

w3::Text::Text()
{
    m_strings = nullptr;

}

w3::Text::Text(const std::string fileName)
{
    std::fstream fs(fileName);
    if (fs.fail()) return;
    std::string line;
    while (getline(fs, line)) {
        m_strings.push_back(line);
    }
    fs.close();
}

w3::Text::Text(const w3::Text &text)
{
    *this = text;
}

w3::Text::Text(const w3::Text &&text)
{
    *this = text;
}

w3::Text &w3::Text::operator=(const w3::Text &text)
{
    if (this != &text) m_strings = text.m_strings;
    return *this;
}

w3::Text &&w3::Text::operator=(w3::Text &&text)
{
    if (this != &text) m_strings = text.m_strings;
    return std::move(*this);
}

size_t w3::Text::size() const
{
    return m_strings.size();
}
