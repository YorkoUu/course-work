#include <iostream>
#include <fstream>
#include <Windows.h>
#include <stdlib.h>
#include "Struct.h"
#include "Student.h"

using namespace std;

int MainMenu() {
	short menu;
	cout << "Главное меню:\n";
	cout << "1. Добавить запись\n";
	cout << "2. Вывод данных\n";
	cout << "3. Изменение данных\n";
	cout << "4. Удалить запись\n";
	cout << "5. Выполнить вариант\n";
	cout << "6. Выход\n\n";
	cout << "Выберите действие (число от 1 до 6): ";
	cin >> menu;
	if (menu < 1 || menu > 6) {
		system("cls");
		cout << "Вы неверно ввели данные!";
		system("pause");
		MainMenu();
	}
	system("cls");
	return menu;
}

int main() {
	SetConsoleCP(1251); SetConsoleOutputCP(1251);
	Student student;

	while (1){
		system("pause");
		switch (MainMenu()) {
		case 1:
			student.AddStud(); break;
		case 2:
			student.DrowStuds(); break;
		case 6:
			return 0;
		}
		


	}
	//Тест
	/*
	int n;
	cout << "Сколько вы хотите добавить студентов?" << endl;
	cin >> n;
	system("cls");
	Student* students = new Student[n];
	for (int i = 0; i < n; i++) { 
		students[i].FillStud();
		system("cls");
	};
	delete[] students;
	*/

}