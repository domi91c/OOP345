#ifndef W5_NOTIFICATIONS_H
#define W5_NOTIFICATIONS_H
#include <vector>
#include "Message.h"

namespace w5
{
class Notifications
{
    std::vector<Message> _messages;
public:
    Notifications collect(std::ifstream &in, char recDelim);
    Notifications();
    Notifications(const Notifications &);
    Notifications &operator=(const Notifications &);
    Notifications(Notifications &&);
    Notifications &&operator=(Notifications &&);
    ~Notifications();
    void operator+=(const Message &msg);
    void display(std::ostream &os) const;
};
}

#endif
