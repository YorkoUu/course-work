#pragma once
struct Name {
	char surname[20];
	char name[20];
	char secondname[20];
};

struct Date {
	unsigned short day;
	unsigned short month;
	unsigned short year;
};

struct Institute {
	unsigned short year;
	char faculty[7];
	char departament[10];
	char group[10];
	char numcard[7];
};

struct SProgram {
	char subjects[9][10][30];
	short marks[9][10];
};