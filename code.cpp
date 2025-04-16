#include <iostream>
#include <vector>

using namespace std;

class Gmail {
    string name;
    string gmailn;

public:
    Gmail(string userName, string userEmail) {
        name = userName;
        gmailn = userEmail;
    }

    void displayInfo() const {
        cout << "Имя пользователя: " << name << endl;
        cout << "Почта: " << gmailn << endl;
    }

    string getName() const {
        return name;
    }

    string getEmail() const {
        return gmailn;
    }
};

int main() {
    vector<Gmail> users;
    setlocale(0, "RU");

    while (true) {
        cout << endl << "----------------------" << endl;
        cout << "   Gmail - Почта" << endl;
        cout << "----------------------" << endl;
        cout << "[1] Создать почту" << endl;
        cout << "[2] Написать сообщение" << endl;
        cout << "[3] Посмотреть сохранённые почты" << endl;
        cout << "[4] Сохранить данные" << endl;
        cout << "[0] Выйти из программы" << endl;
        cout << "----------------------" << endl;
        cout << "Выберите опцию: ";
        char opt;
        cin >> opt;

        if (opt == '0') {
            system("cls");
            cout << "----------------------" << endl;
            cout << "| Выход из программы |" << endl;
            cout << "----------------------" << endl << endl << endl;
            break;
        }
        else if (opt == '1') {
            string name;
            string gmailname;
            system("cls");
            cout << "-------------------------" << endl;
            cout << "     Создание почты" << endl;
            cout << "-------------------------" << endl;
            cout << "Введите имя пользователя: ";
            cin >> name;
            cout << endl << "Введите имя почты (без @gmail.com): ";
            cin >> gmailname;
            users.push_back(Gmail(name, gmailname + "@gmail.com"));
            system("cls");
            cout << "--------------------------" << endl;
            cout << "| Почта успешно создана! |" << endl;
            cout << "--------------------------" << endl;
            cout << "Имя пользователя: " << name << endl;
            cout << "Почта " << name << ": " << gmailname << "@gmail.com" << endl;
            cout << "--------------------------" << endl;
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
        else {
            system("cls");
            cout << "----------------------------------------" << endl;
            cout << "| Неверная опция, попытайтесь ещё раз! |" << endl;
            cout << "----------------------------------------" << endl << endl;
        }
    }

    return 0;
}
