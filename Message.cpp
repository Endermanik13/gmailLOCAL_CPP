#include "Message.h"

Message::Message(string sender, string receiver, string msg)
{
    from = sender;
    to = receiver;
    content = msg;
}

void Message::displayMessage() const
{
    cout << "От: " << from << endl;
    cout << "Кому: " << to << endl;
    cout << "Сообщение: " << content << endl;
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
