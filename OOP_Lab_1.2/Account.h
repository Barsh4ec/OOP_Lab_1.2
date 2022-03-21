#pragma once
#include <string>
using namespace std;

class Account
{
private:
	string secondname;
	int no;
	double percent;
	double summa;
public:
	string getSecondame() const { return secondname; }
	int getNo() const { return no; }
	double getPercent() const { return percent; }
	double getSumma() const { return summa; }

	void setSecondname(string);
	bool setNo(int);
	bool setPercent(double);
	bool setSumma(double);

	void Display();
	bool Init(int no, double percent, double summa);
	string Read(string);
	int Read(int);
	void ChangeOwner();
	void GetMoney();
	void AddMoney();
	void MakePercent();
	void ToDollar();
	void ToEuro();
	void Propys();
};

