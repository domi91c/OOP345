#include "Notifications.h"

using namespace std;

w5::Notifications::Notifications()
{
    _messages.clear();
}

w5::Notifications::Notifications(const w5::Notifications &notifications)
    : Notifications()
{
    _messages = notifications._messages;
}

w5::Notifications &w5::Notifications::operator=(const w5::Notifications &notifications)
{
    if (this != &notifications) {
        _messages = notifications._messages;
    }
    return *this;
}

w5::Notifications::Notifications(w5::Notifications &&notifications)
{
    _messages = notifications._messages;
    notifications._messages.clear();
}

w5::Notifications &&w5::Notifications::operator=(w5::Notifications &&notifications)
{
    if (this != &notifications) {
        _messages = move(notifications._messages);
    }
    return move(*this);
}

w5::Notifications::~Notifications()
{
    _messages.clear();
}

void w5::Notifications::operator+=(const w5::Message &message)
{
    _messages.push_back(message);
}

void w5::Notifications::display(ostream &os) const
{
    for (auto message = _messages.begin(); message != _messages.end(); ++message) {
        message->display(os);
    }
}
