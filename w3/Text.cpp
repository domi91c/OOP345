#include <iostream>
#include <fstream>
#include <vector>
#include "Text.h"

using namespace std;

w3::Text::Text()
{
    m_lines.clear();
}

w3::Text::Text(const std::string fileName)
{
    std::fstream fs(fileName);
    if (fs.fail()) return;
    // check number of lines
    int count = 0;
    std::string line;
    while (getline(fs, line)) {
        count++;
    }
    cout << "line count: " << count << endl;
    fs.close();
}

w3::Text::Text(const w3::Text &text)
{
    *this = text;
}

w3::Text::Text(const w3::Text &&text) noexcept
{
    *this = text;
}

w3::Text &w3::Text::operator=(const w3::Text &text)
{
    if (this != &text) m_lines = text.m_lines;
    return *this;
}

w3::Text &&w3::Text::operator=(w3::Text &&text) noexcept
{
    if (this != &text) m_lines = text.m_lines;
    return std::move(*this);
}

size_t w3::Text::size() const
{
    return m_lines.size();
}
