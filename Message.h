#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
class Message {
    string from;
    string to;
    string content;

public:
    Message(string sender, string receiver, string msg);

    void displayMessage() const;

    string getSender() const;

    string getReceiver() const;

    string getContent() const;
};



