#include "Student.h"

Date::Date(unsigned short d, unsigned short m, unsigned short y)
{
	day = d;
	month = m;
	year = y;
}

void Date::SetDay(unsigned short day)
{
	if (((month = 1 && day < 32) || (month = 3 && day < 32) || // показываем сколько дней в месяцах
		(month = 4 && day < 31) || (month = 5 && day < 32) || (month = 6 && day < 31) ||
		(month = 7 && day < 32) || (month = 8 && day < 32) || (month = 9 && day < 31) ||
		(month = 10 && day < 32) || (month = 11 && day < 31) || (month = 12 && day < 32)) &&
		((month = 2 && day < 29) && (year % 4 != 0 && year % 100 == 0 || year % 400 != 0) || // показываем февраль в обычный год
			(month = 2 && day < 30) && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0))) // февраль в високосном году
	{
		this->day = day;
	}
}

void Date::SetMonth(unsigned short month)
{
	if (month < 13)
		this->month = month;
}

void Date::SetYear(unsigned short year)
{
	if (year > 1930 || year < 2012) // вряд ли кто моложе или старше студент :)
		this->year = year;
}

const unsigned short Date::GetDay() const
{
	return day;
}

const unsigned short Date::GetMonth() const
{
	return month;
}

const unsigned short Date::GetYear() const
{
	return year;
}

Student::Student(const char* surname, const char* name, const char* patronymic)
{
	this->surname = new char[100];
	strcpy_s(this->surname, 99, surname);

	this->name = new char[100];
	strcpy_s(this->name, 99, name);

	this->patronymic = new char[100];
	strcpy_s(this->patronymic, 99, patronymic);

	adress = new char[100];
	strcpy_s(adress, 99, "address");

	phone = new char[100];
	strcpy_s(phone, 99, "phone");

	counterMarks = 0;
	counterCoursework = 0;
	counterExam = 0;

	marks = new int[counterMarks];
	for (int i = 0; i < counterMarks; i++)
		marks[i] = 0;

	coursework = new int[counterCoursework];
	for (int i = 0; i < counterCoursework; i++)
		coursework[i] = 0;

	exam = new int[counterExam];
	for (int i = 0; i < counterExam; i++)
		exam[i] = 0;
}

Student::Student(char* surname, char* name, char* patronymic, Date date)
{
	SetShow(surname, name, patronymic, date, adress, phone);
}

Student::Student(char* surname, char* name, char* patronymic, Date date, char* adress)
{
	SetShow(surname, name, patronymic, date, adress, phone);
}

Student::Student(const char* surname, const char* name, const char* patronymic, Date date, const char* adress, const char* phone) // главный конструктор
{
	SetShow(surname, name, patronymic, date, adress, phone);
}

Student::Student(const Student& original)
{
	surname = new char[100];
	strcpy_s(surname, 99, original.surname);

	name = new char[100];
	strcpy_s(name, 99, original.name);

	patronymic = new char[100];
	strcpy_s(patronymic, 99, original.patronymic);

	name = new char[100];
	strcpy_s(name, 99, original.name);

	adress = new char[100];
	strcpy_s(adress, 99, original.adress);

	phone = new char[100];
	strcpy_s(phone, 99, original.phone);

	counterMarks = original.counterMarks;
	counterCoursework = original.counterCoursework;
	counterExam = original.counterExam;

	marks = new int[counterMarks];
	for (int i = 0; i < counterMarks; i++)
		marks[i] = original.marks[i];

	coursework = new int[counterCoursework];
	for (int i = 0; i < counterCoursework; i++)
		coursework[i] = original.coursework[i];

	exam = new int[counterExam];
	for (int i = 0; i < counterExam; i++)
		exam[i] = original.exam[i];
}

Student::~Student() // деструктор
{
	if (surname != nullptr)delete[]surname;
	if (name != nullptr) delete[]name;
	if (patronymic != nullptr)delete[]patronymic;
	if (adress != nullptr)delete[]adress;
	if (phone != nullptr)delete[]phone;
	if (marks != nullptr)delete[]marks;
	if (coursework != nullptr)delete[]coursework;
	if (exam != nullptr)delete[]exam;
}

void Student::SetDate(unsigned short day, unsigned short month, unsigned short year)
{
	d.SetDay(day);
	d.SetMonth(month);
	d.SetYear(year);
}

void Student::SetAdress(char* adress)
{
	if (adress == nullptr)
		return;
	if (strlen(adress) < 1)
		return;

	if (this->adress != nullptr)
		delete[]this->adress;

	this->adress = new char[strlen(adress) + 1];
	strcpy_s(this->adress, strlen(adress) + 1, adress);
}

void Student::SetPhone(char* phone)
{
	if (phone == nullptr)
		return;
	if (strlen(phone) != 10)
		return;

	if (this->phone != nullptr) delete[] this->phone;
	this->phone = new char[strlen(phone) + 1];
	strcpy_s(this->phone, strlen(phone) + 1, phone);
}

void Student::SetMark(int value)
{
	if (value < 1 || value>12)
		return;
	int* temp = new int[counterMarks + 1];
	for (int i = 0; i < counterMarks; i++)
		temp[i] = this->marks[i];
	temp[counterMarks] = value;
	counterMarks++;
	delete[]marks;
	marks = temp;
}

void Student::SetCoursework(int value)
{
	if (value < 1 || value>12)
		return;
	int* temp = new int[counterCoursework + 1];
	for (int i = 0; i < counterCoursework; i++)
		temp[i] = this->coursework[i];
	temp[counterCoursework] = value;
	counterCoursework++;
	delete[]coursework;
	coursework = temp;
}

void Student::SetExam(int value)
{
	if (value < 1 || value>12)
		return;
	int* temp = new int[counterExam + 1];
	for (int i = 0; i < counterExam; i++)
		temp[i] = this->exam[i];
	temp[counterExam] = value;
	counterExam++;
	delete[]exam;
	exam = temp;
}

const char* const Student::GetAdress() const
{
	return adress;
}

const char* const Student::GetPhone() const
{
	return phone;
}

void Student::Print()
{
	cout << "Фамилия " << surname << "\n";
	cout << "Имя: " << name << "\n";
	cout << "Отчество: " << patronymic << "\n";
	cout << "Дата рождения " << d.GetDay() << "." << d.GetMonth() << "." << d.GetYear() << "\n";
	cout << "Адрес: " << adress << "\n";
	cout << "Телефон: " << phone << "\n";
	cout << "Зачет: ";
	if (counterMarks > 0)
	{
		for (int i = 0; i < counterMarks; i++)
		{
			cout << marks[i];
		}

	}
	cout << "\nКурсовая: ";

	if (counterCoursework > 0)
	{
		for (int i = 0; i < counterCoursework; i++)
		{
			cout << coursework[i];
		}
	}
	cout << "\nЭкзамен: ";
	if (counterExam > 0)
	{
		for (int i = 0; i < counterExam; i++)
		{
			cout << exam[i];
		}
	}
	cout << "\n\n";
}

void Student::SetShow(const char* surname, const char* name, const char* patronymic, Date date, const char* adress, const char* phone)
{
	SetSurname(this->surname);
	SetName(this->name);
	SetSurname(this->surname);
	SetPatronymic(this->patronymic);
	//Date;
	SetAdress(this->adress);
	SetPhone(this->phone);
}

void Student::SetSurname(char* surname)
{
	this->surname = new char[100];
	strcpy_s(this->surname, 99, surname);
}

void Student::SetName(char* name)
{
	this->name = new char[100];
	strcpy_s(this->name, 99, name);
}

void Student::SetPatronymic(char* patronymic)
{
	this->patronymic = new char[100];
	strcpy_s(this->patronymic, 99, patronymic);
}

const char* const Student::GetSurname() const
{
	return surname;
}

const char* const Student::GetName() const
{
	return name;
}

const char* const Student::GetPatronymic() const
{
	return patronymic;
}

int Student::GetExam()
{
	return counterExam;
}

bool Student::operator > (Student& second)
{
	if (this->GetSurname() > second.GetSurname())
	{
		return true;
	}
	return false;
}

bool Student::operator < (Student& second)
{
	if (this->GetSurname() < second.GetSurname())
	{
		return true;
	}
	return false;
}

Student& Student::operator += (int marks)
{
	SetMark(marks);
	return *this;
}

bool Student::operator == (Student& second)
{
	if (this->GetExam() == second.GetExam())
	{
		return true;
	}
	return false;
}

bool Student::operator != (Student& second)
{
	if (this->GetExam() != second.GetExam())
	{
		return true;
	}
	return false;
}



