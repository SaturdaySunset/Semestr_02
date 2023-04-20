#include <iostream>
#include <windows.h>

using namespace std;

struct MyDate {
	unsigned short day;
	unsigned short month;
	unsigned short year;
};

struct Record {
	char name[10];
	unsigned short product_count;
	unsigned long salary;
	float percentage;
	struct MyDate date[3];
};

void PrintLine(int x) {
	switch (x) {
	case 0:
		cout << '+';
		cout.width(130);
		cout.fill('-');
		cout << right << '+' << endl; break;

	case 1:
		cout << '|';
		cout.width(130);
		cout.fill('-');
		cout << right << '|' << endl; break;
	}
}

void PrintDate(unsigned short day, unsigned short month, unsigned short year)
{
	cout << "|";

	if (day > 9) { cout.width(2); cout << left << day << left << "."; }
	else { cout.width(1); cout << left << "0"; cout.width(1); cout << left << day << left << "."; }

	if (month > 9) { cout.width(2); cout.fill(' '); cout << left << month << left << "."; }
	else { cout.width(1); cout << left << "0"; cout.width(1); cout << left << month << left << "."; }

	cout.width(4); cout << left << year; cout.width(15); cout << right << "|" << endl;
}

void PrintTable(struct Record* records) {
	PrintLine(0);

	cout.width(130); cout.fill(' '); cout << left << "|Фирмы - производители СКБД"; cout << '|' << endl;

	PrintLine(1);

	cout.width(20); cout.fill(' '); cout << left << "|Фирма";
	cout.width(35); cout.fill(' '); cout << left << "|Количество продуктов";
	cout.width(25); cout.fill(' '); cout << left << "|Объём продажи($)";
	cout.width(25); cout.fill(' '); cout << left << "|Часть рынка(%)";
	cout.width(25); cout.fill(' '); cout << left << "|Дата основания" << "|" << endl;

	PrintLine(1);

	for (int i = 0; i < 3; i++) {
		cout << "|"; cout.width(19); cout.fill(' '); cout << left << records[i].name;
		cout << "|"; cout.width(34); cout.fill(' '); cout << left << records[i].product_count;
		cout << "|"; cout.width(24); cout.fill(' '); cout << left << records[i].salary;
		cout << "|"; cout.width(24); cout.fill(' '); cout << left << records[i].percentage;
		PrintDate(records[i].date->day, records[i].date->month, records[i].date->year);
		PrintLine(1);
	}
	cout.width(130); cout.fill(' '); cout << left << "|Примечание: по данным Gartner Group за 1999г"; cout << left << '|' << endl;
	PrintLine(0);
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	struct MyDate date[3] = { {01,02,2010}, {02,03,2020}, {12,12,2012} };

	struct Record records[3] = {
		{ "Oracle", 1, 2488000000, 31.1, date[0]},
		{ "IBM", 3, 2392000000, 29.9, date[1]},
		{ "Microsoft", 2, 1048000000, 13.1, date[2]}
	};

	PrintTable(records);
}
