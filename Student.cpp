#include <iostream>
#include <cstring>
#include <string>
#include "Struct.h"
#include "Windows.h"
#include "fstream"
#include "Student.h"
#define split for(int i = 0; i < 90; i++) {cout << "-";}; cout << "\n";

using namespace std;
ofstream fw;
ifstream fin;

int len(char* str) {
	int i = 0;
	while (str[i] != '\0') { i++; }
	return i;
}

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
	cout << "\n������� ���������(��������) ��������: ";
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
			strcpy_s(Program.subjects[sim_t][sub_t], "None");
			Program.marks[sim_t][sub_t] = -1;
		}
	}

	unsigned short sub;
	short menu;
prog:
	cout << "1. ������� ������\n2. �����\n";
	cin >> menu;
	switch (menu) {
	case 1:
		while (1) {
			cout << "����� ������ �� ������ �������?(1 - 9): ";
			cin >> sim;
			sim = sim - 1;
			if (sim < 0 || sim > 8) { cout << "\n�� ������� ����� ������!"; }
			else { break; };
		};
		while (1) {
		sub = 0;
sub:		while (1) {
				system("cls");
				cout << "������� �������� ��������: ";
				cin >> Program.subjects[sim][sub];
				if (OnlyLett(Program.subjects[sim][sub])) { break; }
				else { cout << "�� ������� ����� ������!"; }
			}
mark:		while (1) {
				cout << "������� ������ �� ������ ������ �� ���� �������: ";
				cin >> Program.marks[sim][sub];
				if (Program.marks[sim][sub] < 2 || Program.marks[sim][sub] > 5) { cout << "�� ������� ����� ������!"; }
				else { break; };
			};
			while (1) {
				cout << "1. �������� ��� ���� ������� \n";
				cout << "2. �������� ������ \n";
				cout << "3. ����� \n";

				cin >> temp;
				switch (temp) {
				case 1:
					sub++; goto sub; break;
				case 2:
					sub--; goto mark; break;
				case 3:
					goto prog; break;
				default:
					cout << "������� 1, 2 ��� 3\n"; cin.clear();
				}
			}
		};
	break;
	case 2:
		break;
	default:
		cout << "������� 1 ��� 2\n"; cin.clear(); goto prog;
	}
	
}

void Student::AddStud() {
	fw.open("StudentsData.txt", ios_base::app);
	FillName();
	FillDate();
	FillSex();
	FillInstitute();
	FillProgram();
	fw << Name.surname << " " << Name.name << " " << Name.secondname << "\n";
	fw << Birthday.day << " " << Birthday.month << " " << Birthday.year << "\n";
	fw << Sex << " ";
	fw << Institute.year << " " << Institute.faculty << " " << Institute.departament << " " << Institute.group << " " << Institute.numcard << "\n";
	for (short sim_t = 0; sim_t < 9; sim_t++) {
		fw << sim_t + 1 << ")\n";
		for (short sub_t = 0; sub_t < 10; sub_t++) {
			fw << Program.subjects[sim_t][sub_t] << " " << Program.marks[sim_t][sub_t] << "\n";
		}

	}
	fw << "--END--\n";
	fw.close();
}


//---- class  Drow
int Student::DrowName() {
	cout << Name.surname << " " << Name.name << " " << Name.secondname;
	return 46 - (len(Name.surname) + len(Name.name) + len(Name.secondname));
}
void Student::DrowDate() {
	if (Birthday.day > 9) cout << Birthday.day; else cout << "0" << Birthday.day;
	cout << ".";
	if (Birthday.month > 9) cout << Birthday.month; else cout << "0" << Birthday.month;
	cout << ".";
	cout << Birthday.year;
}
void Student::DrowSex() {
	if (Sex == 1) {
		cout << "������� ";
	}
	else { cout << "������� "; }
}
void Student::DrowProgram() {

}

void Student::DrowStuds() {

	ifstream fr("StudentsData.txt");
	int stud_count = 1;
	fr >> Name.surname; fr >> Name.name; fr >> Name.secondname;
	fr >> Birthday.day; fr >> Birthday.month; fr >> Birthday.year;
	fr >> Sex; fr >> Institute.year; fr >> Institute.faculty; fr >> Institute.departament; fr >> Institute.group; fr >> Institute.numcard;
	split;
	cout << "|     | ��� "; cout.width(30); cout << "| "; cout.width(DrowName()); cout << "|" << endl;
	cout << "|     | ���� �������� "; cout.width(20); cout << "| "; DrowDate(); cout.width(38); cout << "|" << endl;
	cout << "|  " << stud_count << "  | ��� "; cout.width(30); cout << " | "; DrowSex(); cout.width(41); cout << " | " << endl;
	cout << "|     | ��� ����������� "; cout.width(18); cout << "| "; cout << Institute.year; cout.width(44); cout << "|" << endl;
	cout << "|     | ���������(��������) "; cout.width(14); cout << "| "; cout << Institute.faculty; cout.width(48 - len(Institute.faculty)); cout << "|" << endl;
	cout << "|     | ������� "; cout.width(26); cout << "| "; cout << Institute.departament; cout.width(48 - len(Institute.departament)); cout << "|" << endl;
	cout << "|     | ������ "; cout.width(27); cout << "| "; cout << Institute.group; cout.width(48 - len(Institute.group)); cout << "|" << endl;
	cout << "|     | ����� �������� ������ "; cout.width(12); cout << "| "; cout << Institute.numcard; cout.width(48 - len(Institute.numcard)); cout << "|" << endl;
	split;
	string temp;
	while (getline(fr, temp)) {

	}





}