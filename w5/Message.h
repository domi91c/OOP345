#ifndef W5_MESSAGE_H
#define W5_MESSAGE_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

namespace w5
{
class Message
{
    std::string _user;
    std::string _reply;
    std::string _tweet;
public:
    Message(std::ifstream &in, char c);
    bool empty() const;
    void display(std::ostream &) const;
};
}

#endif
