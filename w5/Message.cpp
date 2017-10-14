#include "Message.h"

using namespace std;

w5::Message::Message(ifstream &in, char c)
{
    string line;
    getline(in, line, c);
    istringstream is(line);
    // get user name
    is >> _user;
    // if @ is found, get reply
    if ((int) line.find('@') > 0) {
        is >> _reply;
    }
    // get rest of line
    is.ignore(); // ignore space before tweet
    getline(is, _tweet);

    is.clear();

    if (!(_tweet.empty())) {
        cout << "Message " << endl;
        cout << " User  : ";
        cout << _user << endl;

        if (!(_reply.empty())) {
            cout << " Reply : ";
            cout << _reply << endl;
        }
        cout << " Tweet : ";
        cout << _tweet << endl;
    }
}

bool w5::Message::empty() const
{
    return _user.empty() || _tweet.empty();
}

void w5::Message::display(ostream &os) const
{
    os << "Message" << endl;
    os << " User  : " << _user << endl;
    if (!_reply.empty()) {
        os << " Reply : " << _reply << endl;
    }
    os << " Tweet : " << _tweet << endl;
    os << endl;
}