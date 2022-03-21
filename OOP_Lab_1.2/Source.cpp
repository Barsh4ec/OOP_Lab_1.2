#include <iostream>
#include <Windows.h>
#include <cmath>
#include <iomanip>
#include "Account.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Account a;
	a.setSecondname("��������");
	a.setNo(1);
	a.setPercent(6.4);
	a.setSumma(592.76);

	int no;
	do {
		a.Display();
		cout << "������� ��" << endl;
		cout << "[1] - ������ �������� �������" << endl;
		cout << "[2] - ����� ����� ���� ������ � �������" << endl;
		cout << "[3] - �������� ����� �� �������" << endl;
		cout << "[4] - ���������� �������" << endl;
		cout << "[5] - ��������� ���� � ������" << endl;
		cout << "[6] - ��������� ���� � ����" << endl;
		cout << "[7] - �������� ���� ��������" << endl;
		cout << "[0] - ��������� ���������" << endl;
		cout << "������ ��������: "; cin >> no;
		cout << endl;

		switch (no)
		{
		case 1:
			a.ChangeOwner();
			break;
		case 2:
			a.GetMoney();
			break;
		case 3:
			a.AddMoney();
			break;
		case 4:
			a.MakePercent();
			break;
		case 5:
			a.ToDollar();
			break;
		case 6:
			a.ToEuro();
			break;
		case 7:
			a.Propys();
			break;
		}
		cout << endl;
	} while (no != 0);
	
	return 0;
}