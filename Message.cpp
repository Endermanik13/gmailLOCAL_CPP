#include "Message.h"

Message::Message(string sender, string receiver, string msg)
{
    from = sender;
    to = receiver;
    content = msg;
}

void Message::displayMessage() const
{
    cout << "��: " << from << endl;
    cout << "����: " << to << endl;
    cout << "���������: " << content << endl;
}

string Message::getSender() const
{
    return from;
}

string Message::getReceiver() const
{
    return to;
}

string Message::getContent() const
{
    return content;
}
