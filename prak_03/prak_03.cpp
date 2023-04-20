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
	struct MyDate date;
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

	if (day > 9) { cout.width(2); cout << left << day << left << "."; }
	else { cout.width(1); cout << left << "0"; cout.width(1); cout << left << day << left << "."; }

	if (month > 9) { cout.width(2); cout.fill(' '); cout << left << month << left << "."; }
	else { cout.width(1); cout << left << "0"; cout.width(1); cout << left << month << left << "."; }

	cout.width(4); cout << left << year;
}

void PrintTable(struct Record* records) {
	PrintLine(0);

	cout.width(130); cout.fill(' '); cout << left << "|Фирмы - производители СКБД"; cout << left << '|' << endl;

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

		cout << "|";
		PrintDate(records[i].date.day, records[i].date.month, records[i].date.year);
		cout.width(15); cout << right << "|" << endl;

		PrintLine(1);
	}
	cout.width(130); cout.fill(' '); cout << left << "|Примечание: по данным Gartner Group за 1999г"; cout << left << '|' << endl;
	PrintLine(0);
}

void PrintTable_adress(struct Record* A, struct Record* B) {
	cout << '+';
	cout.width(148);
	cout.fill('-');
	cout << right << '+' << endl;

	cout.width(20); cout.fill(' '); cout << left << "|Адрес А[i]";
	cout.width(52); cout.fill(' '); cout << left << "|Значение A[i]";
	cout.width(20); cout.fill(' '); cout << left << "|Адрес В[i]";
	cout.width(56); cout.fill(' '); cout << left << "|Значение В[i]" << "|" << endl;

	cout << '+';
	cout.width(148);
	cout.fill('-');
	cout << right << '+' << endl;

	for (int i = 0; i < 3; i++) {
		cout << "|"; cout.width(19); cout.fill(' '); cout << left << &A[i];

		cout << "|"; cout.width(12); cout.fill(' '); cout << left << A[i].name;
		cout.width(5); cout.fill(' '); cout << left << A[i].product_count;
		cout.width(15); cout.fill(' '); cout << left << A[i].salary;
		cout.width(8); cout.fill(' '); cout << left << A[i].percentage;
		PrintDate(A[i].date.day, A[i].date.month, A[i].date.year); cout << ' ';

		cout << "|"; cout.width(19); cout.fill(' '); cout << left << &B[i];

		cout << "|"; cout.width(13); cout.fill(' '); cout << left << B[i].name;
		cout.width(6); cout.fill(' '); cout << left << B[i].product_count;
		cout.width(16); cout.fill(' '); cout << left << B[i].salary;
		cout.width(9); cout.fill(' '); cout << left << B[i].percentage;
		PrintDate(B[i].date.day, B[i].date.month, B[i].date.year); cout << ' ' << '|';

		cout << endl;

		cout << '+';
		cout.width(148);
		cout.fill('-');
		cout << right << '+' << endl;
	}


}
void MinMax(struct Record* records)
{
	unsigned short min, max, nmin, nmax;

	min = max = records[0].date.month;
	nmin = nmax = 0;

	for (int i = 1; i < 3; i++)
	{
		if (records[i].date.month < min)
		{
			min = records[i].date.month;
			nmin = i;
		};

		if (records[i].date.month > max)
		{
			max = records[i].date.month;
			nmax = i;
		};
	};

	struct Record bufer = records[nmin];
	records[nmin] = records[nmax];
	records[nmax] = bufer;
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

	cout << endl << "Таблица до обработки:" << endl << endl;
	PrintTable(records);

	MinMax(records);

	cout << endl << "Таблица после обработки:" << endl << endl;
	PrintTable(records);

	Record* A;
	int table_count = 3;
	A = (Record*)malloc(table_count * sizeof(Record));
	for (int i = 0; i < table_count; i++)
		A[i] = records[i];

	cout << endl << "Содержимое динамического массива А:" << endl << endl;
	PrintTable(A);

	Record* B;
	table_count = 10;
	B = (Record*) new Record[table_count];
	for (int i = 0; i < table_count; i++)
		B[i] = records[i];

	cout << endl << "Содержимое динамического массива B:" << endl << endl;
	PrintTable(B);

	cout << endl << "Адреса первых элементов в массивах:" << endl << endl << "Адрес records[0] = " << left << &records[0] << endl << "Адрес A[0] = " << left << &A[0] << endl << "Адрес B[0] = " << left << &B[0] << endl;

	PrintTable_adress(A, B);

	cout << endl << "sizeof(Record) = " << sizeof(Record);

	free(A);
	delete[]B;
}