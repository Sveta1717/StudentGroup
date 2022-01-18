#pragma once
#include "Libraries.h"
#include "Date.h"
#include "Student.h"
class Group
{
	Student** students = nullptr; //  указатель на студентов
	unsigned int GroupSize = 0; // количество человек в группе
	char* GroupName = nullptr; // название группы
	char* Specialization = nullptr; // специализация группы
	unsigned int course; // номер курса

public:
	Group(); // конструктор по умолчанию	
	Group(unsigned int size); // конструктор с одним параметром	
	//Group(const Group& original); // конструктор с параметром типа Group	
	~Group(); // деструктор	

	void SetGroupName(char* GroupName);
	void SetSpecialization(char* Specialization);
	void SetCourse(int course);
	void SetGroupSize(unsigned int GroupSize);
	void ChangesGroup();
	void AddStudent(const char* surname, const char* name, const char* patronymic);
	static Group MergeGroups(const Group& first, const Group& second);
	void DeleteStudent();
	void RelocationStudent(Group* out, int PosStudent);
	void Delete_exam(int n);

	const char* const GetGroupName() const;
	const char* const GetSpecialization() const;
	const int const GetCourse() const;
	const int const GetGroupSize() const;
	Group operator+=(const char* surname);
	
	bool operator>(Group& second);
	
	bool operator<(Group& second);
	
	bool operator==(Group& second);
	
	bool operator!=(Group& second);
	
	
	int GetExam();
	void Sort();

	void SetShow(const char* GroupName, const char* Specialization, unsigned int Course);
	void PrintGroup();

	Group(const Group& original) // конструктор копирования 
	{
		GroupSize = original.GroupSize;

		GroupName = new char[100];
		strcpy_s(GroupName, 99, original.GroupName);

		students = new Student * [original.GroupSize];
		for (int i = 0; i < original.GroupSize; i++)
			students[i] = original.students[i];

		Specialization = new char[100];
		strcpy_s(Specialization, 99, original.Specialization);

		course = original.course;
	}
};

