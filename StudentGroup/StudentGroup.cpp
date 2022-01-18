#include "Groups.h"

int main()
{
	setlocale(0, "UKR");
	srand(time(0));

	Group* a = new Group();
	cout << "Группа 1\n";
	a->AddStudent("Тузик", "Пусинда", "Игоревна");
	a->AddStudent("Мурка", "Кира", "Альбертовна");
	a->operator+=("Шарик");
	a->PrintGroup();

	Student s1("Ваня", "Ванечка", "Ванятко");
	s1.Print();
	Student s2 = s1;
	s2.Print();
	cout << "Добавление оценок\n";
	s1.operator+=(11);
	s1.Print();
	//cout << "Копия первой группы\n";
	//cout << "___________________\n\n";
	//Group* c = a;
	//c->PrintGroup(); // копия группы a	
	//cout << "----------------\n\n";
	//cout << "Группа с новыми студентами\n";
	//cout << "________________________\n\n";
	//Group* b = new Group();
	//cout << "\nГруппа 2\n";
	//b->AddStudent("Шарик", "Филип", "Филиппович");
	//b->AddStudent("Мурзик", "Гаврила", "Никитич");
	//b->AddStudent("Барсик", "Иван", "Тимофеевич");
	//b->PrintGroup();
	//cout << "----------------\n\n";
	//cout << "Удалили одного студента\n";
	//cout << "________________________\n\n";
	//b->DeleteStudent(); // удалили студента
	//b->PrintGroup();
	//cout << "----------------\n\n";	
	//cout << "Слияние групп\n";
	//cout << "________________________\n\n";
	//Group result = Group::MergeGroups(*a, *b);
	//result.PrintGroup();	
	
	cout << "\n\n";
}


