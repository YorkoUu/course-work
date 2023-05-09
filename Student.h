#pragma once
#include <iostream>
#include "Struct.h"
#include "Windows.h"

using namespace std;

class Student {
protected:
	Name Name;
	Date Birthday;
	bool Sex;
	Institute Institute;
	SProgram Program;
	//friend class Fill;
	//friend class Drow;
public:
	void AddStud();

	bool OnlyLett(char* x);
	void FillName();
	void FillDate();
	void FillSex();
	void FillInstitute();
	void FillProgram();
};

//Надо реализовать Fill


class Drow : protected Student {
	void DrowName();
	void DrowDate();
	void DrowSex();
	void DrowInstitute();
	void DrowProgram();
};