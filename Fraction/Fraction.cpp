#include "Fraction.h"
#include "FracException.h"
using namespace std;

Fraction::Fraction(long value_numerator, long value_denominator) {
	Set_Numerator(value_numerator, false);
	Set_Denominator(value_denominator);
	fractionshort();
}

long long Fraction::nod(long long a, long long b) {
	if (!b)
		return a;
	if (nod(b, a % b) < 0) {
		return -(nod(b, a % b));
	}
	else
		return(nod(b, a % b));
}

void Fraction::fractionshort() {
	if (Get_Denominator() < 0) {
		Set_Denominator(-Get_Denominator());
		Set_Numerator(-Get_Numerator());
	}
	long nodx = nod(Get_Numerator(), Get_Denominator());
	Set_Numerator(Get_Numerator() / nodx);
	Set_Denominator(Get_Denominator() / nodx);
}

Fraction::~Fraction() {};

long long Fraction::Get_Numerator() const {
	return numerator;
}
void Fraction::Set_Numerator(long long value_numerator) {
	if (value_numerator == 0) {
		numerator = value_numerator;
		denominator = 1;
	}
	numerator = value_numerator / nod(value_numerator,denominator);
	denominator = denominator / nod(value_numerator, denominator);
}
long long Fraction::Get_Denominator() const {
	return denominator;
}
void Fraction::Set_Denominator(long long value_denominator) {
	if (value_denominator == 0) {
		throw FracException();
	}
	denominator = value_denominator / nod(numerator, value_denominator);
	numerator = numerator / nod(numerator, value_denominator);
}

void Fraction::Set_Numerator(long long value_numerator, bool is_short) {
	if (value_numerator == 0) {
		numerator = value_numerator;
		denominator = 1;
	}
	if (is_short) {
		numerator = value_numerator / nod(value_numerator, denominator);
		denominator = denominator / nod(value_numerator, denominator);
		if (denominator < 0) {
			numerator = (-numerator);
			denominator = (-denominator);
		}
	}
	else {
		numerator = value_numerator;
	}
}

double Fraction::value_fraction() const {
	if (numerator == 0 && denominator < 0) {
		return -((double)numerator / denominator);
	}
	return (double)numerator / denominator;
}

Fraction Fraction::operator+(const Fraction& f) const {
	return Fraction(numerator * f.denominator + f.numerator * denominator, denominator * f.denominator);
}

Fraction Fraction::operator-(const Fraction& f) const {
	return Fraction(numerator * f.denominator - f.numerator * denominator, denominator * f.denominator);
}

Fraction Fraction::operator*(const Fraction& f) const {
	return Fraction(numerator * f.numerator, denominator * f.denominator);
}

Fraction Fraction::operator/ (const Fraction& f) const {
	if (f.numerator == 0) {
		throw FracException();
	}
	return Fraction(numerator * f.denominator, denominator * f.numerator);
}
Fraction Fraction::operator-() const {
	if (numerator == 0) {
		return Fraction(numerator, -denominator);
	}
	else
		return Fraction(-numerator, denominator);
}

bool Fraction::operator==(const Fraction& f) const {
	return ((numerator == f.numerator) && (denominator == f.denominator));
}

bool Fraction::operator!=(const Fraction& f) const {
	return ((numerator != f.numerator) || (denominator != f.denominator));
}

bool Fraction::operator>(const Fraction& f) const {
	return ((numerator * f.denominator - denominator * f.numerator) > 0);
}

bool Fraction::operator<(const Fraction& f) const {
	return ((numerator * f.denominator - denominator * f.numerator) < 0);
}

bool Fraction::operator>=(const Fraction& f) const {
	return ((numerator * f.denominator - denominator * f.numerator) >= 0);
}

bool Fraction::operator<=(const Fraction& f) const {
	return ((numerator * f.denominator - denominator * f.numerator) <= 0);
}


