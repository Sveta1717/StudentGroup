//� ����� Student �������� ���������� += int, ��� ��������� ������ � �������� �������.
 // � ����� ����������� �������� � > �, �<�, � == �, � != � ��� ��������� ���� ��������� �� ������� ������.
 //� ����� Group �������� ���������� += Student, ��� ��������� �������� � ������.
 // � ����� ����������� �������� �>�, � < �, � == �, � != � ��� ��������� ���� ����� �� ���������� ���������.

#include "Groups.h"

Group::Group() // ����������� �� ���������
{
	this->course = 1;
	SetShow("��� - 121", "�������", 1);
}

Group::Group(unsigned int size) // ����������� � ����� ����������
{
	this->course = 1;
	GroupSize = size;
	SetShow("��� - 121", "���������� ��", 1);
}

Group:: ~Group() // ����������
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

void Group::AddStudent(const char* surname, const char* name, const char* patronymic) // ��������� ��������
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

void Group::DeleteStudent() //�������� ��������
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
	strcpy_s(temp.GroupName, 99, "��� �����");

	temp.Specialization = new char[100];
	strcpy_s(temp.Specialization, 99, "���������� ��");

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

void Group::Delete_exam(int n) // �������� ���, ��� �� ���� �������
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
		cout << "��������� " << (*students[i]).GetSurname()
			<< "�" << "\n\n";
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
//	int temp = rand() % 10;	// ���������� �������
//
//	switch (temp)
//	{
//	case 0: return "������";
//	case 1: return "������";
//	case 2: return "�������";
//	case 3: return "��������";
//	case 4: return "��������";
//	case 5: return "�������";
//	case 6: return "�����������";
//	case 7: return "�������";
//	case 8: return "����������";
//	case 9: return "��������";
//	}
//}
//
//string Group::GetName()
//{
//	int temp = rand() % 10;	// ���������� �����			
//	switch (temp)
//	{
//	case 0: return "���������";
//	case 1: return "���������";
//	case 2: return "������";
//	case 3: return "������";
//	case 4: return "�����";
//	case 5: return "����";
//	case 6: return "��������";
//	case 7: return "����";
//	case 8: return "����";
//	case 9: return "�������";
//	}
//}
//
//string Group::GetPatronymic()
//{
//	int temp = rand() % 10; // ���������� ��������
//	switch (temp)
//	{
//	case 0: return "��������";
//	case 1: return "����������";
//	case 2: return "������������";
//	case 3: return "��������";
//	case 4: return "�������������";
//	case 5: return "������������";
//	case 6: return "�����������";
//	case 7: return "����������";
//	case 8: return "�������������";
//	case 9: return "�������";
//	}
//}

int Group::GetExam()
{
	int temp = rand() % 7; // ���������� ������
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
void Group::Sort()  // ���������� �������
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
	cout << "������: " << GroupName << "\n";
	cout << "�������������: " << Specialization << "\n";
	cout << "����: " << course << "\n\n";
	Sort();
	for (int i = 0; i < GroupSize; i++)
	{
		cout << i + 1 << ". " << (*students[i]).GetSurname() << " "
			<< (*students[i]).GetName() << " "
			<< (*students[i]).GetPatronymic() << " "
			<< "  /������� " << this->GetExam() << "\n";
	}
	cout << "\n";
}

