#include <iostream>
#include <vector>
#include <string>
#include <clocale>
#include <locale>
#include <Windows.h>
#include <fstream>
#include "Gmail.h"
#include "Message.h"

using namespace std;
void saveUsers(const vector<Gmail>& users) {
    ofstream outFile("users.txt");
    if (outFile.is_open()) {
        for (const auto& user : users) {
            outFile << user.getName() << "|" << user.getEmail() << endl;
        }
        outFile.close();
    }
}

void loadUsers(vector<Gmail>& users) {
    ifstream inFile("users.txt");
    if (inFile.is_open()) {
        string line, name, email;
        while (getline(inFile, line)) {
            size_t pos = line.find("|");
            if (pos != string::npos) {
                name = line.substr(0, pos);
                email = line.substr(pos + 1);
                users.push_back(Gmail(name, email));
            }
        }
        inFile.close();
    }
}

void saveMessages(const vector<Message>& messages) {
    ofstream outFile("messages.txt");
    if (outFile.is_open()) {
        for (const auto& msg : messages) {
            outFile << msg.getSender() << "|" << msg.getReceiver() << "|" << msg.getContent() << endl;
        }
        outFile.close();
    }
}

void loadMessages(vector<Message>& messages) {
    ifstream inFile("messages.txt");
    if (inFile.is_open()) {
        string line, from, to, content;
        while (getline(inFile, line)) {
            size_t pos1 = line.find("|");
            size_t pos2 = line.find("|", pos1 + 1);
            if (pos1 != string::npos && pos2 != string::npos) {
                from = line.substr(0, pos1);
                to = line.substr(pos1 + 1, pos2 - pos1 - 1);
                content = line.substr(pos2 + 1);
                messages.push_back(Message(from, to, content));
            }
        }
        inFile.close();
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    vector<Gmail> users;
    vector<Message> messages;

    loadUsers(users);
    loadMessages(messages);
    cout << "Версия: 0.2" << endl;
    while (true) {
        cout << endl << "----------------------" << endl;
        cout << "   Gmail - Почта" << endl;
        cout << "----------------------" << endl;
        cout << "[1] Создать почту" << endl;
        cout << "[2] Написать сообщение" << endl;
        cout << "[3] Посмотреть сохранённые почты" << endl;
        cout << "[4] Просмотреть письма" << endl;
        cout << "[5] Очистить почту" << endl;
        cout << "[6] Сохранить данные" << endl;
        cout << "[0] Выйти из программы" << endl;
        cout << "----------------------" << endl;
        cout << "Выберите опцию: ";
        char opt;
        cin >> opt;
        cin.ignore();

        if (opt == '0') {
            system("cls");
            cout << "----------------------" << endl;
            cout << "| Выход из программы |" << endl;
            cout << "----------------------" << endl << endl << endl;
            break;
        }
        else if (opt == '1') {
            string name, gmailname;
            system("cls");
            cout << "-------------------------" << endl;
            cout << "     Создание почты" << endl;
            cout << "-------------------------" << endl;
            cout << "Введите имя пользователя: ";
            getline(cin, name);
            cout << endl << "Введите имя почты (без @gmail.com): ";
            getline(cin, gmailname);
            users.push_back(Gmail(name, gmailname + "@gmail.com"));
            system("cls");
            cout << "--------------------------" << endl;
            cout << "| Почта успешно создана! |" << endl;
            cout << "--------------------------" << endl;
            cout << "Имя пользователя: " << name << endl;
            cout << "Почта: " << gmailname << "@gmail.com" << endl;
            cout << "--------------------------" << endl;
        }
        else if (opt == '2') {
            system("cls");
            if (users.empty()) {
                cout << "---------------------------------" << endl;
                cout << "| Нет почт для отправки писем! |" << endl;
                cout << "---------------------------------" << endl;
                continue;
            }

            cout << "-------------------------" << endl;
            cout << "     Отправка письма" << endl;
            cout << "-------------------------" << endl;
            cout << "Выберите отправителя (0 для отмены):" << endl;
            for (size_t i = 0; i < users.size(); ++i) {
                cout << "[" << i + 1 << "] " << users[i].getEmail() << endl;
            }
            int senderChoice;
            cin >> senderChoice;
            cin.ignore();
            if (senderChoice == 0) {
                system("cls");
                cout << "-----------------------------" << endl;
                cout << "| Отправка письма отменена |" << endl;
                cout << "-----------------------------" << endl;
                continue;
            }
            if (senderChoice < 1 || senderChoice >(int)users.size()) {
                system("cls");
                cout << "--------------------------------" << endl;
                cout << "| Неверный выбор отправителя! |" << endl;
                cout << "--------------------------------" << endl;
                continue;
            }

            cout << endl << "Выберите получателя (0 для отмены):" << endl;
            for (size_t i = 0; i < users.size(); ++i) {
                cout << "[" << i + 1 << "] " << users[i].getEmail() << endl;
            }
            int receiverChoice;
            cin >> receiverChoice;
            cin.ignore();
            if (receiverChoice == 0) {
                system("cls");
                cout << "-----------------------------" << endl;
                cout << "| Отправка письма отменена |" << endl;
                cout << "-----------------------------" << endl;
                continue;
            }
            if (receiverChoice < 1 || receiverChoice >(int)users.size()) {
                system("cls");
                cout << "--------------------------------" << endl;
                cout << "| Неверный выбор получателя! |" << endl;
                cout << "--------------------------------" << endl;
                continue;
            }

            cout << endl << "Введите сообщение: ";
            string content;
            getline(cin, content);

            messages.push_back(Message(users[senderChoice - 1].getEmail(),
                users[receiverChoice - 1].getEmail(),
                content));
            system("cls");
            cout << "-----------------------------" << endl;
            cout << "| Письмо успешно отправлено |" << endl;
            cout << "-----------------------------" << endl;
        }
        else if (opt == '3') {
            system("cls");
            cout << "-------------------------" << endl;
            cout << "     Список почт" << endl;
            cout << "-------------------------" << endl;

            if (users.empty()) {
                cout << "Нет сохранённых почтовых аккаунтов." << endl;
            }
            else {
                for (const auto& user : users) {
                    user.displayInfo();
                    cout << "-------------------------" << endl;
                }
            }
        }
        else if (opt == '4') {
            system("cls");
            if (users.empty()) {
                cout << "---------------------------------" << endl;
                cout << "| Нет почт для просмотра писем! |" << endl;
                cout << "---------------------------------" << endl;
                continue;
            }

            cout << "-------------------------" << endl;
            cout << "     Просмотр писем" << endl;
            cout << "-------------------------" << endl;
            cout << "Выберите почту (0 для отмены):" << endl;
            for (size_t i = 0; i < users.size(); ++i) {
                cout << "[" << i + 1 << "] " << users[i].getEmail() << endl;
            }
            int emailChoice;
            cin >> emailChoice;
            cin.ignore();
            if (emailChoice == 0) {
                system("cls");
                cout << "-----------------------------" << endl;
                cout << "| Просмотр писем отменён |" << endl;
                cout << "-----------------------------" << endl;
                continue;
            }
            if (emailChoice < 1 || emailChoice >(int)users.size()) {
                system("cls");
                cout << "--------------------------------" << endl;
                cout << "| Неверный выбор почты! |" << endl;
                cout << "--------------------------------" << endl;
                continue;
            }

            system("cls");
            cout << "-------------------------" << endl;
            cout << " Письма для " << users[emailChoice - 1].getEmail() << endl;
            cout << "-------------------------" << endl;
            bool hasMessages = false;
            for (const auto& msg : messages) {
                if (msg.getReceiver() == users[emailChoice - 1].getEmail()) {
                    msg.displayMessage();
                    cout << "-------------------------" << endl;
                    hasMessages = true;
                }
            }
            if (!hasMessages) {
                cout << "Нет писем для этой почты." << endl;
            }
        }
        else if (opt == '5') {
            system("cls");
            if (users.empty()) {
                cout << "---------------------------------" << endl;
                cout << "| Нет почт для очистки писем! |" << endl;
                cout << "---------------------------------" << endl;
                continue;
            }

            cout << "-------------------------" << endl;
            cout << "     Очистка писем" << endl;
            cout << "-------------------------" << endl;
            cout << "Выберите почту (0 для отмены):" << endl;
            for (size_t i = 0; i < users.size(); ++i) {
                cout << "[" << i + 1 << "] " << users[i].getEmail() << endl;
            }
            int emailChoice;
            cin >> emailChoice;
            cin.ignore();
            if (emailChoice == 0) {
                system("cls");
                cout << "-----------------------------" << endl;
                cout << "| Очистка писем отменена |" << endl;
                cout << "-----------------------------" << endl;
                continue;
            }
            if (emailChoice < 1 || emailChoice >(int)users.size()) {
                system("cls");
                cout << "--------------------------------" << endl;
                cout << "| Неверный выбор почты! |" << endl;
                cout << "--------------------------------" << endl;
                continue;
            }

            vector<Message> tempMessages;
            for (const auto& msg : messages) {
                if (msg.getReceiver() != users[emailChoice - 1].getEmail()) {
                    tempMessages.push_back(msg);
                }
            }
            messages = tempMessages;
            system("cls");
            cout << "-----------------------------" << endl;
            cout << "| Письма успешно очищены |" << endl;
            cout << "-----------------------------" << endl;
        }
        else if (opt == '6') {
            system("cls");
            saveUsers(users);
            saveMessages(messages);
            cout << "-----------------------------" << endl;
            cout << "| Данные успешно сохранены |" << endl;
            cout << "-----------------------------" << endl;
        }
        else {
            system("cls");
            cout << "----------------------------------------" << endl;
            cout << "| Неверная опция, попытайтесь ещё раз! |" << endl;
            cout << "----------------------------------------" << endl << endl;
        }
    }
    return 0;
}