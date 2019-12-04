#include <iostream>
#include "FracException.h"
#include "Fraction.h"
using namespace std;

int main() {

	setlocale(LC_ALL, "Russian");

	long numerator;
	long denominator;

	Fraction fraction_1;

	cout << "������� ��������� � ����������� ��� ������ �����: " << endl;

	class MyException :public exception
	{
	private:
		int dataState;
	public:
		MyException(char* msg, int dataState) :exception(msg) {
			this->dataState = dataState;
		}
		int GetDataState() {
			return dataState;
		}
	};

	while (true) {
		cin >> numerator >> denominator;
		try
		{
			fraction_1.Set_Numerator(numerator);
			fraction_1.Set_Denominator(denominator);
			break;
		}
		catch (FracException &ex)
		{
			cout << "������: " << ex.Error("�������� ��� ��������� ������� �� ����!") << endl;
		}
	}

	Fraction fraction_2;

	cout << "������� ��������� � ����������� ��� ������ �����: " << endl;

	while (true) {
		cin >> numerator >> denominator;
		try {
			fraction_2.Set_Numerator(numerator);
			fraction_2.Set_Denominator(denominator);
			break;
		}
		catch (FracException & ex)
		{
			cout << "������: " << ex.Error("�������� ��� ��������� ������� �� ����!") << endl;
		}
	}
	cout << "�������� ������ �����: " << fraction_1.value_fraction() << endl;
	cout << "�������� ������ �����: " << fraction_2.value_fraction() << endl;
	cout << "����� ������: " << (fraction_1 + fraction_2).Get_Numerator() << " " << (fraction_1 + fraction_2).Get_Denominator() << endl;
	cout << "��������: " << (fraction_1 - fraction_2).Get_Numerator() << " " << (fraction_1 - fraction_2).Get_Denominator() << endl;
	cout << "������������: " << (fraction_1 * fraction_2).Get_Numerator() << " " << (fraction_1 * fraction_2).Get_Denominator() << endl;
	try { cout << "�������: " << (fraction_1 / fraction_2).Get_Numerator() << " " << (fraction_1 / fraction_2).Get_Denominator() << endl; }
	catch (FracException & ex)
	{
		cout << "������: " << ex.Error("�������� ��� ��������� ������� �� ����!") << endl;
	}
	cout << "��������� ����� ������ �����: " << (-fraction_1).Get_Numerator() << " " << (-fraction_1).Get_Denominator() << endl;
	cout << "��������� ����� ������ �����: " << (-fraction_2).Get_Numerator() << " " << (-fraction_2).Get_Denominator() << endl;
	cout << "��������� ==: " << (fraction_1 == fraction_2) << endl;
	cout << "��������� !=: " << (fraction_1 != fraction_2) << endl;
	cout << "��������� >: " << (fraction_1 > fraction_2) << endl;
	cout << "��������� <: " << (fraction_1 < fraction_2) << endl;
	cout << "��������� >=: " << (fraction_1 >= fraction_2) << endl;
	cout << "��������� <=: " << (fraction_1 <= fraction_2) << endl;

	system("pause");
	return 0;
}