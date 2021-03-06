#include <iostream>
#include <string>
#include <fstream>
#include "Text.h"

using namespace std;

namespace w3
{
Text::Text()
{
    m_lines = nullptr;
    m_lineCount = 0;
}

Text::Text(const string fileName)
{
    fstream fs(fileName);
    if (fs.fail()) return;

    // get line count
    int count = 0;
    string line;
    while (getline(fs, line)) {
        count++;
    }
    m_lineCount = count;

    // go back to start of file
    fs.clear();
    fs.seekg(0, ios::beg);

    // get lines from file
    m_lines = new string[m_lineCount];
    for (int i = 0; i < m_lineCount; ++i) {
        getline(fs, m_lines[i]);
    }

    fs.close();
}

Text::Text(const Text &text)
{
    *this = text;
}

Text::Text(const Text &&text) noexcept
{
    *this = text;
}

Text &Text::operator=(const Text &text)
{
    if (this != &text) {
        if (text.m_lines) {
            m_lineCount = text.m_lineCount;
            m_lines = new string[m_lineCount];
            for (int i = 0; i < m_lineCount; ++i) m_lines[i] = text.m_lines[i];
        }
    }

    return *this;
}

Text &&Text::operator=(Text &&text) noexcept
{
    return move(*this);
}

size_t Text::size() const
{
    return m_lineCount;
}

Text::~Text()
{
    delete[] m_lines;
}
}
