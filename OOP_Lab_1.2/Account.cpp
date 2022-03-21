#include "Account.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <iomanip>
#include <math.h>
using namespace std;

void Account::setSecondname(string value)
{
	secondname = value;
}

bool Account::setNo(int value)
{
	if (value > 0)
	{
		no = value;
		return true;
	}
	else
	{
		no = 0;
		return false;
	}
}

bool Account::setPercent(double value)
{
	if (value > 0)
	{
		percent = value;
		return true;
	}
	else
	{
		percent = -value;
		return false;
	}
}

bool Account::setSumma(double value)
{
	if (value >= 0)
	{
		summa = value;
		return true;
	}
	else
	{
		summa = -value;
		return false;
	}
}

bool Account::Init(int no, double percent, double summa)
{
	return setNo(no) && setPercent(percent) && setSumma(summa);
}

string Account::Read(string prizvysche) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "������ ������� ��������: "; cin >> prizvysche;
	return prizvysche;
}

int Account::Read(int nomer) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "������ ����� ����������� �������: "; cin >> nomer;
	return nomer;
}

void Account::Display()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "������� �������:" << fixed << setprecision(2) << getSecondame() << endl;
	cout << "��� ������:" << getSumma() << endl;

}

void Account::ChangeOwner()
{
	string prizvysche;
	int nomer;
	setSecondname(Read(prizvysche));
	setNo(Read(nomer));
	setSumma(0);
	setPercent(5);
}

void Account::GetMoney()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double getmoney;
	do
	{
		cout << "������ ���� ������:" << endl; cin >> getmoney;
	} while (getmoney > summa);
	summa -= getmoney;
	cout << "�� ������ ����� �����!" << endl;
}

void Account::AddMoney()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double addmoney;
	do
	{
		cout << "������ ���� ����������:" << endl; cin >> addmoney;
	} while (addmoney < 0);
	summa += addmoney;
	cout << "�� ������ ��������� ������!" << endl;
}

void Account::MakePercent()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int no;
	do {
		cout << "�� ������ ������ ���������� " << percent << "% �� ��� ������?" << endl;
		cout << "[1] - ���" << endl;
		cout << "[2] - ͳ" << endl;
		cout << "������ ��������: "; cin >> no;
		cout << endl;

		switch (no)
		case 1:
		{
			summa += summa * (percent / 100);
			cout << "�� ������ ���������� �������!" << endl;
		}
			break;
		cout << endl;
	} while (no != 2);
}

void Account::ToDollar()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int no;
	do {
		cout << "�� ������ ������ ��������� " << summa << "���. � �������?" << endl;
		cout << "[1] - ���" << endl;
		cout << "[2] - ͳ" << endl;
		cout << "������ ��������: "; cin >> no;
		cout << endl;

		switch (no)
		case 1:
		{
			summa *= 0.033;
		}
		break;
		cout << endl;
	} while (no != 2);
	cout << "�� ������ �������� ����� � �������!" << endl;
}

void Account::ToEuro()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int no;
	do {
		cout << "�� ������ ������ ��������� " << summa << "���. � ����?" << endl;
		cout << "[1] - ���" << endl;
		cout << "[2] - ͳ" << endl;
		cout << "������ ��������: "; cin >> no;
		cout << endl;

		switch (no)
		case 1:
		{
			summa *= 0.030;
		}
		break;
		cout << endl;
	} while (no != 2);
	cout << "�� ������ �������� ����� � ����!" << endl;
}

void Account::Propys()
{

	double x = summa;
	double frac = 0;
	double integral = 0;
	frac = modf(x, &integral);
	int numb = integral;

	//������, ��� ����������� �������, � ������� ���������(�����,�������,�������...)
	int osn[11] = { 0,1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000 };

	//������ ���������
	string basis[11][10] = {
		{"","","","","","","","","",""},
		{"","����","���","���","������","�'���","�����","��","���","������"},
		{"","������","��������","��������","�����","�'�������","���������","�������","��������","���'������"},
		{"","���","����","������","���������","�'�����","�������","�����","������","���'�����"},
		{"","����","��","���","������","�'���","�����","��","���","���'���"},
		{"","������","��������","��������","�����","�'�������","���������","�������","��������","���'������"},
		{"","���","����","������","���������","�'�����","�������","������","������","���'�����"},
		{"","����","���","���","������","�'���","�����","��","���","���'���"},
		{"","������","��������","��������","�����","�'�������","����������","�������","��������","���'������"},
		{"","���","����","������","���������","�'�����","�������","�����","������","���'�����"},
		{"","����","���","��� ","������","�'���","�����","��","���","���'���"} };

	//������ ���������
	string termination[10][10] = {
		{"","","","�����","","","�������","","","�������"},
		{"","","","������","","","������","","","������"},
		{"","","","������","","","�������","","","�������"},
		{"","","","������","","","�������","","","�������"},
		{"","","","������","","","�������","","","�������"},
		{"","","","�����","","","�������","","","�������"},
		{"","","","�����","","","�������","","","�������"},
		{"","","","�����","","","�������","","","�������"},
		{"","","","�����","","","�������","","","�������"},
		{"","","","�����","","","�������","","","�������"} };

	string dec[10] = { "������","����������","����������","����������","������������","�'���������","�����������","���������","����������","���'���������" };
	string result;

	if (!numb) {
		result = "���� ";
	}
	int n1 = numb;
	int cnt = 0;

	//������� ���������� ���� � �����
	while (numb) {
		numb /= 10;
		cnt++;
	}
	int cile = 0;

	//�������
	while (n1) {
		if (!((cnt + 1) % 3)) {
			if ((n1 / osn[cnt]) == 1) {
				n1 %= osn[cnt];
				--cnt;
				cile = n1 / osn[cnt];
				n1 %= osn[cnt];
				result += dec[cile];
				--cnt;
				if (!(cnt % 3))
					result += " " + termination[0][cnt] + " ";
			}
			if (!cnt) break;
		}
		cile = n1 / osn[cnt];
		n1 %= osn[cnt];
		result += basis[cnt][cile] + " ";
		--cnt;
		if (!(cnt % 3))
			result += termination[cile][cnt] + " ";
	}
	cout << "�� ������ ������� " << result << "������� " << fixed << setprecision(0) << frac * 100 << " ������";
	cout << endl;
}