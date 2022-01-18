//В класс Student добавить перегрузку += int, что добавляет оценку в домашние задания.
 // А также перегрузить операции « > », «<», « == », « != » для сравнения двух студентов по средним баллам.
 //В класс Group добавить перегрузку += Student, что добавляет студента в группу.
 // А также перегрузить операции «>», « < », « == », « != » для сравнения двух групп по количеству студентов.

#include "Groups.h"

Group::Group() // конструктор по умолчанию
{
	this->course = 1;
	SetShow("СБУ - 121", "Базовый", 1);
}

Group::Group(unsigned int size) // конструктор с одним параметром
{
	this->course = 1;
	GroupSize = size;
	SetShow("СПУ - 121", "Разработка ПО", 1);
}

Group:: ~Group() // деструктор
{
	if (students != nullptr)delete[]students;
	if (GroupName != nullptr)delete[]GroupName;
	if (Specialization != nullptr)delete[]Specialization;
}

void Group::SetGroupName(char* GroupName)
{
	if (this->GroupName)

		return;
	this->GroupName = new char[100];
	strcpy_s(this->GroupName, 99, GroupName);
}

void Group::SetSpecialization(char* Specialization)
{
	if (this->Specialization)
		return;
	this->Specialization = new char[100];
	strcpy_s(this->Specialization, 99, Specialization);
}

void Group::SetCourse(int course)
{
	if (course < 1 || course > 6) return;
	this->course = course;
}

void Group::SetGroupSize(unsigned int GroupSize)
{
	this->GroupSize = 2 + rand() % 15;
}

Group Group::operator+=(const char* surname)
{
	AddStudent(surname, " ", " ");	
	return *this;	
}

bool Group::Group::operator>(Group& second)
{
	if (this->GroupSize > second.GroupSize)
	{
		return true;
	}
	return false;
}

bool Group::operator<(Group& second)
{
	if (this->GroupSize < second.GroupSize)
	{
		return true;
	}
	return false;
}

bool Group::operator==(Group& second)
{
	if (this->GroupSize == second.GroupSize)
	{
		return true;
	}
	return false;
}

bool Group::operator!=(Group& second)
{
	if (this->GroupSize != second.GroupSize)
	{
		return true;
	}
	return false;
}

void Group::ChangesGroup()
{
	Student* temp;
	int number;
	int quality;
	for (int i = 0; i < GroupSize; i++)
	{
		number = 1;
		for (int j = i + 1; j < GroupSize; j++)
		{
			quality = strcmp(students[number]->GetSurname(), students[j]->GetSurname());
			if (quality == 0)
			{
				quality = strcmp(students[number]->GetName(), students[j]->GetName());
			}
			if (quality > 0)
			{
				number = j;
			}
		}
	}
}

void Group::AddStudent(const char* surname, const char* name, const char* patronymic) // добавляем студента
{
	Student** temp = new Student * [GroupSize + 1];

	for (int i = 0; i < GroupSize; i++)
	{
		temp[i] = students[i];
	}

	Student* s = new Student(surname, name, patronymic);
	temp[GroupSize] = s;

	delete[] students;
	students = temp;
	GroupSize++;
	Sort();
}

void Group::DeleteStudent() //удаление студента
{
	Student** temp = new Student * [this->GroupSize - 1];

	for (int i = 0; i < GroupSize; i++)
	{
		temp[i - 1] = this->students[i];
	}

	delete[]this->students;
	this->students = temp;
	this->GroupSize--;
	Sort();
}

Group Group::MergeGroups(const Group& first, const Group& second)
{
	Group temp;

	temp.GroupSize = (first.GroupSize + second.GroupSize);

	temp.students = new Student * [temp.GroupSize];

	for (int i = 0; i < first.GroupSize; i++)
	{
		temp.students[i] = new Student(*first.students[i]);
	}
	for (int j = 0; j < second.GroupSize; j++)
	{
		temp.students[first.GroupSize + j] = new Student(*second.students[j]);
	}

	temp.GroupName = new char[100];
	strcpy_s(temp.GroupName, 99, "СПУ общая");

	temp.Specialization = new char[100];
	strcpy_s(temp.Specialization, 99, "Разработка ПО");

	temp.course = 1;

	return temp;
}

void Group::RelocationStudent(Group* exit, int n)
{
	Student** temp = new Student * [this->GroupSize + 1];
	for (int i = 0; i < this->GroupSize; i++)
		temp[i] = this->students[i];
	temp[this->GroupSize] = new Student(*exit->students[n - 1]);

	delete[]this->students;
	this->students = temp;
	this->GroupSize++;
	ChangesGroup();
	exit->DeleteStudent();

}

void Group::Delete_exam(int n) // удаление тех, кто не сдал экзамен
{
	n = this->GetGroupSize();
	for (int i = 0; i < n; i++)
	{
		if (GetExam() == 0)
		{
			i++;
			DeleteStudent();
			GroupSize--;
		}
		cout << "Отчислить " << (*students[i]).GetSurname()
			<< "а" << "\n\n";
	}
}

const char* const Group::GetGroupName() const
{
	return this->GroupName;
}

const char* const Group::GetSpecialization() const
{
	return this->Specialization;
}

const int const Group::GetCourse() const
{
	return this->course;
}

const int const Group::GetGroupSize() const
{
	return this->GroupSize;
}

//string Group::GetSurname()
//{
//	int temp = rand() % 10;	// генерируем фамилии
//
//	switch (temp)
//	{
//	case 0: return "Иванов";
//	case 1: return "Петров";
//	case 2: return "Сидоров";
//	case 3: return "Дмитриев";
//	case 4: return "Георгиев";
//	case 5: return "Романов";
//	case 6: return "Александров";
//	case 7: return "Сергеев";
//	case 8: return "Владимиров";
//	case 9: return "Николаев";
//	}
//}
//
//string Group::GetName()
//{
//	int temp = rand() % 10;	// генерируем имена			
//	switch (temp)
//	{
//	case 0: return "Александр";
//	case 1: return "Станислав";
//	case 2: return "Сергей";
//	case 3: return "Виктор";
//	case 4: return "Роман";
//	case 5: return "Юрий";
//	case 6: return "Владимир";
//	case 7: return "Олег";
//	case 8: return "Иван";
//	case 9: return "Дмитрий";
//	}
//}
//
//string Group::GetPatronymic()
//{
//	int temp = rand() % 10; // генерируем отчества
//	switch (temp)
//	{
//	case 0: return "Олегович";
//	case 1: return "Викторович";
//	case 2: return "Владимирович";
//	case 3: return "Иванович";
//	case 4: return "Александрович";
//	case 5: return "Вячеславович";
//	case 6: return "Анатольевич";
//	case 7: return "Витальевич";
//	case 8: return "Владиславович";
//	case 9: return "Юрьевич";
//	}
//}

int Group::GetExam()
{
	int temp = rand() % 7; // генерируем оценку
	switch (temp)
	{
	case 0: return 0;
	case 1: return 7;
	case 2: return 8;
	case 3: return 9;
	case 4: return 10;
	case 5: return 11;
	case 6: return 12;
	}
}
void Group::Sort()  // сортировка фамилий
{
	for (int i = 0; i < GroupSize; i++)
	{
		for (int j = GroupSize - 1; j > i; j--)
		{
			if ((*students[i]) < (*students[j]))
			{
				swap(students[i], students[j]);
			}
		}
	}
}

void Group::SetShow(const char* GroupName, const char* Specialization, unsigned int Course)
{
	this->GroupName = new char[100];
	strcpy_s(this->GroupName, 99, GroupName);

	this->Specialization = new char[100];
	strcpy_s(this->Specialization, 99, Specialization);

	Course = Course;
}

void Group::PrintGroup()
{
	cout << "Группа: " << GroupName << "\n";
	cout << "Специализация: " << Specialization << "\n";
	cout << "Курс: " << course << "\n\n";
	Sort();
	for (int i = 0; i < GroupSize; i++)
	{
		cout << i + 1 << ". " << (*students[i]).GetSurname() << " "
			<< (*students[i]).GetName() << " "
			<< (*students[i]).GetPatronymic() << " "
			<< "  /Экзамен " << this->GetExam() << "\n";
	}
	cout << "\n";
}

