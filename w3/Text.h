//
// Created by Dominic Nunes on 2017-09-29.
//


#ifndef W3_TEXT_H
#define W3_TEXT_H

#include <iostream>
#include <vector>

namespace w3
{
class Text
{
private:
//    std::vector<std::string> m_lines;
    std::string *m_lines;
    size_t m_lineCount;
public:
    Text();
    explicit Text(std::string fileName);
    Text(const Text &text);
    Text(const Text &&text) noexcept;
    Text &operator=(const Text &text);
    Text &&operator=(Text &&text) noexcept;
    size_t size() const;
    virtual ~Text();
};
}


#endif //W3_TEXT_H
