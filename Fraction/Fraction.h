#pragma once
class Fraction
{
private:
	long long numerator;
	long long denominator;
	void fractionshort();
	static long long nod(long long, long long);
	void Set_Numerator(long long, bool);
public:
	Fraction(long = 0, long = 1);
	virtual ~Fraction();
	long long Get_Numerator() const;
	void Set_Numerator(long long);
	long long Get_Denominator() const;
	void Set_Denominator(long long);
	double value_fraction() const;
	Fraction operator-() const;
	Fraction operator+ (const Fraction&) const;
	Fraction operator- (const Fraction&) const;
	Fraction operator* (const Fraction&) const;
	Fraction operator/ (const Fraction&) const;
	bool operator== (const Fraction&) const;
	bool operator!= (const Fraction&) const;
	bool operator> (const Fraction&) const;
	bool operator< (const Fraction&) const;
	bool operator>= (const Fraction&) const;
	bool operator<= (const Fraction&) const;

};


