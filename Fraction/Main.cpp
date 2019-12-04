#include <iostream>
#include "FracException.h"
#include "Fraction.h"
using namespace std;

int main() {

	setlocale(LC_ALL, "Russian");

	long numerator;
	long denominator;

	Fraction fraction_1;

	cout << "Введите числитель и знаменатель для первой дроби: " << endl;

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
			cout << "Ошибка: " << ex.Error("возникло или возникнет деление на ноль!") << endl;
		}
	}

	Fraction fraction_2;

	cout << "Введите числитель и знаменатель для второй дроби: " << endl;

	while (true) {
		cin >> numerator >> denominator;
		try {
			fraction_2.Set_Numerator(numerator);
			fraction_2.Set_Denominator(denominator);
			break;
		}
		catch (FracException & ex)
		{
			cout << "Ошибка: " << ex.Error("возникло или возникнет деление на ноль!") << endl;
		}
	}
	cout << "Значение первой дроби: " << fraction_1.value_fraction() << endl;
	cout << "Значение второй дроби: " << fraction_2.value_fraction() << endl;
	cout << "Сумма дробей: " << (fraction_1 + fraction_2).Get_Numerator() << " " << (fraction_1 + fraction_2).Get_Denominator() << endl;
	cout << "Разность: " << (fraction_1 - fraction_2).Get_Numerator() << " " << (fraction_1 - fraction_2).Get_Denominator() << endl;
	cout << "Произведение: " << (fraction_1 * fraction_2).Get_Numerator() << " " << (fraction_1 * fraction_2).Get_Denominator() << endl;
	try { cout << "Частное: " << (fraction_1 / fraction_2).Get_Numerator() << " " << (fraction_1 / fraction_2).Get_Denominator() << endl; }
	catch (FracException & ex)
	{
		cout << "Ошибка: " << ex.Error("возникло или возникнет деление на ноль!") << endl;
	}
	cout << "Изменение знака первой дроби: " << (-fraction_1).Get_Numerator() << " " << (-fraction_1).Get_Denominator() << endl;
	cout << "Изменение знака второй дроби: " << (-fraction_2).Get_Numerator() << " " << (-fraction_2).Get_Denominator() << endl;
	cout << "Сравнение ==: " << (fraction_1 == fraction_2) << endl;
	cout << "Сравнение !=: " << (fraction_1 != fraction_2) << endl;
	cout << "Сравнение >: " << (fraction_1 > fraction_2) << endl;
	cout << "Сравнение <: " << (fraction_1 < fraction_2) << endl;
	cout << "Сравнение >=: " << (fraction_1 >= fraction_2) << endl;
	cout << "Сравнение <=: " << (fraction_1 <= fraction_2) << endl;

	system("pause");
	return 0;
}