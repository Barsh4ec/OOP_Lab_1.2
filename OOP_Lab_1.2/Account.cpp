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
	cout << "¬вед≥ть пр≥звище власника: "; cin >> prizvysche;
	return prizvysche;
}

int Account::Read(int nomer) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "¬вед≥ть номер банк≥вського рахунку: "; cin >> nomer;
	return nomer;
}

void Account::Display()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "¬ласник рахунку:" << fixed << setprecision(2) << getSecondame() << endl;
	cout << "¬аш баланс:" << getSumma() << endl;

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
		cout << "вкаж≥ть суму зн€тт€:" << endl; cin >> getmoney;
	} while (getmoney > summa);
	summa -= getmoney;
	cout << "¬и усп≥шно зн€ли грош≥!" << endl;
}

void Account::AddMoney()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double addmoney;
	do
	{
		cout << "вкаж≥ть суму поповненн€:" << endl; cin >> addmoney;
	} while (addmoney < 0);
	summa += addmoney;
	cout << "¬и усп≥шно поповнили баланс!" << endl;
}

void Account::MakePercent()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int no;
	do {
		cout << "¬и справд≥ бажаЇте нарахувати " << percent << "% на ваш баланс?" << endl;
		cout << "[1] - “ак" << endl;
		cout << "[2] - Ќ≥" << endl;
		cout << "¬вед≥ть значенн€: "; cin >> no;
		cout << endl;

		switch (no)
		case 1:
		{
			summa += summa * (percent / 100);
			cout << "¬и усп≥шно нарахували в≥дсотки!" << endl;
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
		cout << "¬и справд≥ бажаЇте перевести " << summa << "грн. у доллари?" << endl;
		cout << "[1] - “ак" << endl;
		cout << "[2] - Ќ≥" << endl;
		cout << "¬вед≥ть значенн€: "; cin >> no;
		cout << endl;

		switch (no)
		case 1:
		{
			summa *= 0.033;
		}
		break;
		cout << endl;
	} while (no != 2);
	cout << "¬и усп≥шно перевели грош≥ у доллари!" << endl;
}

void Account::ToEuro()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int no;
	do {
		cout << "¬и справд≥ бажаЇте перевести " << summa << "грн. у Ївро?" << endl;
		cout << "[1] - “ак" << endl;
		cout << "[2] - Ќ≥" << endl;
		cout << "¬вед≥ть значенн€: "; cin >> no;
		cout << endl;

		switch (no)
		case 1:
		{
			summa *= 0.030;
		}
		break;
		cout << endl;
	} while (no != 2);
	cout << "¬и усп≥шно перевели грош≥ у Ївро!" << endl;
}

void Account::Propys()
{

	double x = summa;
	double frac = 0;
	double integral = 0;
	frac = modf(x, &integral);
	int numb = integral;

	//массив, дл€ определени€ разр€да, в котором находимс€(сотни,дес€тки,еденицы...)
	int osn[11] = { 0,1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000 };

	//массив оснований
	string basis[11][10] = {
		{"","","","","","","","","",""},
		{"","один","два","три","чотири","п'€ть","ш≥сть","с≥м","в≥с≥м","дев€ть"},
		{"","дес€ть","двадц€ть","тридц€ть","сорок","п'€тдес€т","ш≥стдес€т","с≥мдес€т","в≥с≥мдес€т","дев'€носто"},
		{"","сто","дв≥ст≥","триста","четириста","п'€тсот","ш≥стсот","с≥мсот","в≥с≥мсот","дев'€тсот"},
		{"","одна","дв≥","три","чотири","п'€ть","ш≥сть","с≥м","в≥с≥м","дев'€ть"},
		{"","дес€ть","двадц€ть","тридц€ть","сорок","п'€тдес€т","ш≥стдес€т","с≥мдес€т","в≥с≥мдес€т","дев'€носто"},
		{"","сто","дв≥ст≥","триста","чотириста","п'€тсот","ш≥стсот","семсот","в≥с≥мсот","дев'€тсот"},
		{"","один","два","три","четире","п'€ть","ш≥сть","с≥м","в≥с≥м","дев'€ть"},
		{"","дес€ть","двадц€ть","тридц€ть","сорок","п'€тдес€т","ш≥стьдес€т","с≥мдес€т","в≥с≥мдес€т","дев'€носто"},
		{"","сто","дв≥ст≥","триста","чотириста","п'€тсот","ш≥стсот","с≥мсот","в≥с≥мсот","дев'€тсот"},
		{"","один","два","три ","чотири","п'€ть","ш≥сть","с≥м","в≥с≥м","дев'€ть"} };

	//массив окончаний
	string termination[10][10] = {
		{"","","","тис€ч","","","м≥льйон≥в","","","м≥ль€рд≥в"},
		{"","","","тис€ча","","","м≥льйон","","","м≥ль€рд"},
		{"","","","тис€ч≥","","","м≥льйона","","","м≥ль€рда"},
		{"","","","тис€ч≥","","","м≥льйона","","","м≥ль€рда"},
		{"","","","тис€ч≥","","","м≥льйона","","","м≥ль€рда"},
		{"","","","тис€ч","","","м≥льйона","","","м≥ль€рд≥в"},
		{"","","","тис€ч","","","м≥льйон≥в","","","м≥ль€рд≥в"},
		{"","","","тис€ч","","","м≥льйон≥в","","","м≥ль€рд≥в"},
		{"","","","тис€ч","","","м≥льйон≥в","","","м≥ль€рд≥в"},
		{"","","","тис€ч","","","м≥льйон≥в","","","м≥ль€рд≥в"} };

	string dec[10] = { "дес€ть","одинадц€ть","дванадц€ть","тринадц€ть","чотирнадц€ть","п'€тнадц€ть","ш≥стнадц€ть","с≥мнадц€ть","в≥с≥мнадц€ть","дев'€тнадц€ть" };
	string result;

	if (!numb) {
		result = "нуль ";
	}
	int n1 = numb;
	int cnt = 0;

	//подсчет количесива цифр в числе
	while (numb) {
		numb /= 10;
		cnt++;
	}
	int cile = 0;

	//перевод
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
	cout << "Ќа вашому рахунку " << result << "гривень " << fixed << setprecision(0) << frac * 100 << " коп≥йок";
	cout << endl;
}