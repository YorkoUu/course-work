#include <iostream>
#include "Struct.h"
#include "Windows.h"
#include "fstream"
#include "Student.h"

using namespace std;
ofstream fw;
ifstream fin;

//--- Add 
bool Student::OnlyLett(char* str) {
	int i = 0;
	while (str[i] != '\0') {
		if (not((str[i] >= (char)'А' && str[i] <= (char)'Я') || (str[i] >= (char)'а' && str[i] <= (char)'я'))) { return false; };
		i++;
	}
	return true;
}
void Student::FillName() {
	while (1){
		cout << "Введите Фамилию студента: ";
		cin >> Name.surname;
		if (OnlyLett(Name.surname)) { break; }
		else { cout << "Вы неверно ввели данные!" << endl; }
	}
	while (1) {
		cout << "\nВведите Имя студента: ";
		cin >> Name.name;
		if (OnlyLett(Name.name)) { break; }
		else { cout << "Вы неверно ввели данные!" << endl; }
	}
	while (1) {
		cout << "\nВведите Отчество студента: ";
		cin >> Name.secondname;
		if (OnlyLett(Name.secondname)) { break; }
		else { cout << "Вы неверно ввели данные!" << endl; }
	}

}
void Student::FillDate() {
	cout << "Введитете дату рождения студента: " << endl;
day:cout << "День: ";
	cin >> Birthday.day;
	if (Birthday.day < 1 || Birthday.day > 31) { cout << "Вы неверно ввели данные!"; goto day; }
month:cout << "\nМесяц: ";
	cin >> Birthday.month;
	if ((Birthday.month < 1 || Birthday.month > 12) || (Birthday.month % 2 == 0 && Birthday.month != 2 && Birthday.day > 30) || (Birthday.month == 2 && Birthday.day > 28)) { cout << "Вы неверно ввели данные!"; goto month; }
year:cout << "\nГод: ";
	cin >> Birthday.year;
	if (Birthday.year < 1900) { cout << "Вы неверно ввели данные!"; goto year; }
}
void Student::FillSex() {
	string temp;
	while (1) {
		cout << "Введите пол студента(М - мужской/ Ж - женскиий): ";
		cin >> temp;
		if (temp == "М") { Sex = true; break; }
		else if (temp == "Ж") { Sex = false; break; }
		else { cout << "Вы неверно ввели данные!\n"; }
	};
}
void Student::FillInstitute() {
	cout << "Введите год поступления студента: ";
	cin >> Institute.year;
	cout << "\nВведите факультет студента: ";
	cin >> Institute.faculty;
	cout << "\nВведите кафедру студента: ";
	cin >> Institute.departament;
	cout << "\nВведите группу студента: ";
	cin >> Institute.group;
	cout << "\nВведите номер зачётной книжки студента: ";
	cin >> Institute.numcard;
}
void Student::FillProgram() {
	unsigned short sim;
	short temp;
	for (short sim_t = 0; sim_t < 9; sim_t++) {
		for (short sub_t = 0; sub_t < 10; sub_t++) {
			*Program.subjects[sim_t][sub_t] = 'None';
			Program.marks[sim_t][sub_t] = -1;
		}
	}

	unsigned short sub = 0;
	short menu;
prog:
	cout << "1. Выбрать семестр\n2. Назад\n";
	cin >> menu;
	switch (menu) {
	case 1:
		while (1) {
			cout << "Какой семестр вы хотите выбрать?(1 - 9): ";
			cin >> sim;
			if (sim < 1 || sim > 8) { cout << "\nВы неверно ввели данные!"; }
			else { break; };
		};
	sub:while (1) {
			while (1) {
				system("cls");
				cout << "Введите название предмета: ";
				cin >> Program.subjects[sim][sub];
				if (OnlyLett(Program.subjects[sim][sub])) { sub++; break; }
				else { cout << "Вы неверно ввели данные!"; }
			}
			while (1) {
				cout << "Введите оценку по итогам сессии за этот предмет: ";
				cin >> Program.marks[sim][sub];
				if (Program.marks[sim][sub] < 2 || Program.marks[sim][sub] > 5) { cout << "Вы неверно ввели данные!"; }
				else { break; };
			};
			cout << "1. Добавить ещё один предмет \n";
			cout << "2. Изменить оценку \n";
			cout << "3. Назад \n";

			cin >> temp;
			switch (temp) {
			case 1:
				goto sub; break;
			case 2:
				//  Изменение оценки
			case 3:
				goto prog; break;
			default:
				cout << "Введите 1, 2 или 3";
			}
		};
	break;
	case 2:
		return;
	default:
		cout << "Введите 1 или 2";
	}
	
}

void Student::AddStud() {
	fw.open("StudentData.txt", ios_base::ate);
	FillName();
	fw << Name.surname << " " << Name.name << " " << Name.secondname << "\n";
	FillDate();
	fw << Birthday.day << "." << Birthday.month << "." << Birthday.year << "\n";
	FillSex();
	if (Sex == 1) {
		fw << "Мужской";
	}
	else { fw << "Женский"; }
	FillInstitute();
	fw << Institute.year << " " << Institute.faculty << " " << Institute.departament << " " << Institute.group << " " << Institute.numcard << "\n";
	FillProgram();
	for (short sim_t = 0; sim_t < 9; sim_t++) {
		fw << sim_t + 1 << ")\n";
		for (short sub_t = 0; sub_t < 10; sub_t++) {
			if (Program.subjects[sim_t][sub_t] != "None") {
				fw << Program.subjects << " " << Program.marks << "\n";
			}
		}

	}
	fw.close();
}


//---- class  Drow
void Drow::DrowName() {

}
void Drow::DrowDate() {
	if (Birthday.day > 9) cout << Birthday.day; else cout << "0" << Birthday.day;
	cout << ".";
	if (Birthday.month > 9) cout << Birthday.month; else cout << "0" << Birthday.month;
	cout << ".";
	cout << Birthday.year;
}
void Drow::DrowSex() {

}
void Drow::DrowInstitute() {

}
void Drow::DrowProgram() {

}