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
    std::string *m_strings;
    size_t m_count;
public:
    Text();
    explicit Text(std::string fileName);
    Text(const Text &text);
    Text(const Text &&text);
    Text &operator=(const Text &text);
    Text &&operator=(Text &&text);
    size_t size() const;
};
}


#endif //W3_TEXT_H
