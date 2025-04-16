#include <iostream>
using namespace std;
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
		else {
			system("cls");
			cout << "----------------------------------------" << endl;
			cout << "| Неверная опция, попытайтесь ещё раз! |" << endl;
			cout << "----------------------------------------" << endl << endl;
		}
	}
}
