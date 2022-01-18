#pragma once
#include "Libraries.h"
#include "Date.h"

class Student
{
	char* surname;
	char* name;
	char* patronymic;
	char* adress;
	char* phone;
	int* marks = nullptr;
	int counterMarks = 0; // изначально оценок нет
	int* coursework;
	int counterCoursework = 0; // курсовая
	int* exam = nullptr;
	int counterExam = 0; // экзамен
	Date d;

public:
	Student(const char* surname, const char* name, const char* patronymic);
	Student(char* surname, char* name, char* patronymic, Date date);
	Student(char* surname, char* name, char* patronymic, Date date, char* adress);
	Student(const char* surname, const char* name, const char* patronymic, Date date, const char* adress, const char* phone);
	Student(const Student& original);

	~Student();

	void SetDate(unsigned short day, unsigned short month, unsigned short year);
	void SetAdress(char* adress);
	void SetPhone(char* phone);
	void SetMark(int value);
	void SetCoursework(int value);
	void SetExam(int value);
	void SetShow(const char* surname, const char* name, const char* patronymic, Date date, const char* adress, const char* phone);

	const char* const GetAdress() const;
	const char* const GetPhone() const;
	const char* const GetSurname() const;
	const char* const GetName() const;
	const char* const GetPatronymic() const;
	int GetExam();
	bool operator > (Student& second);
	bool operator < (Student& second);
	Student& operator += (int marks);	
	bool operator == (Student& second);	
	bool operator != (Student& second);	
	void Print();

private:
	void SetSurname(char* surname);
	void SetName(char* name);
	void SetPatronymic(char* patronymic);
};

