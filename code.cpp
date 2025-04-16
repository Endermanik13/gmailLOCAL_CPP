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
	void displayInfo() {
		cout << "Name: " << name << endl;
		cout << "Email: " << gmailn << endl;
	}

	string getName() {
		return name;
	}
};
int main() {
	setlocale(0, "RU");
	while (true) {
		cout << "----------------------" << endl;
		cout << "   Gmail - Почта" << endl;
		cout << "----------------------" << endl;
		cout << "[1] Создать почту" << endl;
		cout << "[2] Написать сообщение" << endl;
		cout << "[3] Сохранить данные" << endl;
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
			cout << endl << "Введите имя почты (без gmail.com): ";
			cin >> gmailname;
			vector <Gmail> user;
			user.push_back(Gmail("test","test"));
			
			
			
		}
		else {
			system("cls");
			cout << "----------------------------------------" << endl;
			cout << "| Неверная опция, попытайтесь ещё раз! |" << endl;
			cout << "----------------------------------------" << endl << endl;
		}
	}
}
