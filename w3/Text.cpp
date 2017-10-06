#include <iostream>
#include <fstream>
#include <vector>
#include "Text.h"

using namespace std;

w3::Text::Text()
{
    m_lines = nullptr;
    m_lineCount = 0;
}

w3::Text::Text(const std::string fileName)
{
    std::fstream fs(fileName);
    if (fs.fail()) return;

    // get line count
    int count = 0;
    std::string line;
    while (getline(fs, line)) {
        count++;
    }
    m_lineCount = static_cast<size_t>(count);

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
    if (this != &text) {
        if (m_lines) {
            delete[] m_lines;
            m_lines = nullptr;
            m_lineCount = 0;
        }

        if (text.m_lines) {
            m_lineCount = text.m_lineCount;
            m_lines = new string[m_lineCount];

            for (int i = 0; i < m_lineCount; ++i) {
                m_lines[i] = text.m_lines[i];
            }
        }
    }

    return *this;
}

w3::Text &&w3::Text::operator=(w3::Text &&text) noexcept
{
    if (this != &text) m_lines = text.m_lines;
    return std::move(*this);
}

size_t w3::Text::size() const
{
    return m_lineCount;
}

w3::Text::~Text()
{
    delete[] *m_lines;
}
