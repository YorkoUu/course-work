#include <iostream>
#include <fstream>
#include <Windows.h>
#include <stdlib.h>
#include "Struct.h"
#include "Student.h"

using namespace std;

int MainMenu() {
	short menu;
	cout << "������� ����:\n";
	cout << "1. �������� ������\n";
	cout << "2. ����� ������\n";
	cout << "3. ��������� ������\n";
	cout << "4. ������� ������\n";
	cout << "5. ��������� �������\n";
	cout << "6. �����\n\n";
	cout << "�������� �������� (����� �� 1 �� 6): ";
	cin >> menu;
	if (menu < 1 || menu > 6) {
		system("cls");
		cout << "�� ������� ����� ������!";
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
	//����
	/*
	int n;
	cout << "������� �� ������ �������� ���������?" << endl;
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