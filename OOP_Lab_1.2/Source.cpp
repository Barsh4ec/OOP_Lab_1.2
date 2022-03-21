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
	a.setSecondname("Петренко");
	a.setNo(1);
	a.setPercent(6.4);
	a.setSumma(592.76);

	int no;
	do {
		a.Display();
		cout << "Виберіть дію" << endl;
		cout << "[1] - змінити власника рахунку" << endl;
		cout << "[2] - зняти деяку суму грошей з рахунку" << endl;
		cout << "[3] - покласти гроші на рахунок" << endl;
		cout << "[4] - нарахувати відсотки" << endl;
		cout << "[5] - перевести суму в долари" << endl;
		cout << "[6] - перевести суму в євро" << endl;
		cout << "[7] - отримати суму прописом" << endl;
		cout << "[0] - завершити виведення" << endl;
		cout << "Введіть значення: "; cin >> no;
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