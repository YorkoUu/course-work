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
		if (not((str[i] >= (char)'�' && str[i] <= (char)'�') || (str[i] >= (char)'�' && str[i] <= (char)'�'))) { return false; };
		i++;
	}
	return true;
}
void Student::FillName() {
	while (1){
		cout << "������� ������� ��������: ";
		cin >> Name.surname;
		if (OnlyLett(Name.surname)) { break; }
		else { cout << "�� ������� ����� ������!" << endl; }
	}
	while (1) {
		cout << "\n������� ��� ��������: ";
		cin >> Name.name;
		if (OnlyLett(Name.name)) { break; }
		else { cout << "�� ������� ����� ������!" << endl; }
	}
	while (1) {
		cout << "\n������� �������� ��������: ";
		cin >> Name.secondname;
		if (OnlyLett(Name.secondname)) { break; }
		else { cout << "�� ������� ����� ������!" << endl; }
	}

}
void Student::FillDate() {
	cout << "��������� ���� �������� ��������: " << endl;
day:cout << "����: ";
	cin >> Birthday.day;
	if (Birthday.day < 1 || Birthday.day > 31) { cout << "�� ������� ����� ������!"; goto day; }
month:cout << "\n�����: ";
	cin >> Birthday.month;
	if ((Birthday.month < 1 || Birthday.month > 12) || (Birthday.month % 2 == 0 && Birthday.month != 2 && Birthday.day > 30) || (Birthday.month == 2 && Birthday.day > 28)) { cout << "�� ������� ����� ������!"; goto month; }
year:cout << "\n���: ";
	cin >> Birthday.year;
	if (Birthday.year < 1900) { cout << "�� ������� ����� ������!"; goto year; }
}
void Student::FillSex() {
	string temp;
	while (1) {
		cout << "������� ��� ��������(� - �������/ � - ��������): ";
		cin >> temp;
		if (temp == "�") { Sex = true; break; }
		else if (temp == "�") { Sex = false; break; }
		else { cout << "�� ������� ����� ������!\n"; }
	};
}
void Student::FillInstitute() {
	cout << "������� ��� ����������� ��������: ";
	cin >> Institute.year;
	cout << "\n������� ��������� ��������: ";
	cin >> Institute.faculty;
	cout << "\n������� ������� ��������: ";
	cin >> Institute.departament;
	cout << "\n������� ������ ��������: ";
	cin >> Institute.group;
	cout << "\n������� ����� �������� ������ ��������: ";
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
	cout << "1. ������� �������\n2. �����\n";
	cin >> menu;
	switch (menu) {
	case 1:
		while (1) {
			cout << "����� ������� �� ������ �������?(1 - 9): ";
			cin >> sim;
			if (sim < 1 || sim > 8) { cout << "\n�� ������� ����� ������!"; }
			else { break; };
		};
	sub:while (1) {
			while (1) {
				system("cls");
				cout << "������� �������� ��������: ";
				cin >> Program.subjects[sim][sub];
				if (OnlyLett(Program.subjects[sim][sub])) { sub++; break; }
				else { cout << "�� ������� ����� ������!"; }
			}
			while (1) {
				cout << "������� ������ �� ������ ������ �� ���� �������: ";
				cin >> Program.marks[sim][sub];
				if (Program.marks[sim][sub] < 2 || Program.marks[sim][sub] > 5) { cout << "�� ������� ����� ������!"; }
				else { break; };
			};
			cout << "1. �������� ��� ���� ������� \n";
			cout << "2. �������� ������ \n";
			cout << "3. ����� \n";

			cin >> temp;
			switch (temp) {
			case 1:
				goto sub; break;
			case 2:
				//  ��������� ������
			case 3:
				goto prog; break;
			default:
				cout << "������� 1, 2 ��� 3";
			}
		};
	break;
	case 2:
		return;
	default:
		cout << "������� 1 ��� 2";
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
		fw << "�������";
	}
	else { fw << "�������"; }
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