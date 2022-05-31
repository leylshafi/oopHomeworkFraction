#pragma once
class Fraction
{
private:
	int _numerator = 0; // suret
	int _denominator = 0; // mexrec
	friend ostream& operator<<(ostream& output, const Fraction& f);
	friend istream& operator>>(istream& input, Fraction& f);
public:
	Fraction() = default;
	Fraction(int num, int den) {
		setNum(num);
		setDen(den);
	}

	///Accessors
	//Setters
	void setNum(int num) {
		if (num > 0 && num < 100)
			_numerator = num;
		else assert(!"num > 0 && num < 100");
	}
	void setDen(int den) {
		if (den > 0 && den < 100)
			_denominator = den;
		else assert(!"den > 0 && den < 100");
	}

	//Getters
	int getNum() { return _numerator; }
	int getDen() { return _denominator; }

	///Copy
	Fraction(const Fraction& other)
	{
		cout << "Copy Constructor" << endl;
		setNum(other._numerator);
		setDen(other._denominator);
	}
	Fraction& operator=(const Fraction& other)
	{
		cout << "Copy Assignment Operator" << endl;
		setNum(other._numerator);
		setDen(other._denominator);
		return *this;
	}

	///Move
	Fraction(Fraction&& other) noexcept
	{
		cout << "Move Constructor" << endl;
	}

	Fraction& operator=(Fraction&& other) noexcept {
		cout << "Move Assigment operator\n";
		return  *this;
	}

	///Operator overloading

	//Arithmetics
	Fraction operator+(const Fraction& other) {
		return Fraction(_numerator + other._numerator, _denominator + other._denominator);
	}

	Fraction operator-(const Fraction& other) {
		return Fraction(_numerator - other._numerator, _denominator - other._denominator);
	}

	Fraction operator*(const Fraction& other) {
		return Fraction(_numerator * other._numerator, _denominator * other._denominator);
	}

	Fraction operator/(const Fraction& other) {
		return Fraction(_numerator * other._denominator, _denominator * other._numerator);
	}

	//Comparison
	bool operator>(const Fraction& other) {
		if (_numerator > other._numerator && _denominator > other._denominator)
			return true;
		return false;
	}

	bool operator<(const Fraction& other) {
		if (_numerator < other._numerator && _denominator < other._denominator)
			return true;
		return false;
	}

	bool operator<=(const Fraction& other) {
		if (_numerator <= other._numerator && _denominator <= other._denominator)
			return true;
		return false;
	}

	bool operator>=(const Fraction& other) {
		if (_numerator >= other._numerator && _denominator >= other._denominator)
			return true;
		return false;
	}

	bool operator==(const Fraction& other) {
		if (_numerator == other._numerator && _denominator == other._denominator)
			return true;
		return false;
	}

	bool operator!=(const Fraction& other) {
		if (_numerator != other._numerator && _denominator != other._denominator)
			return true;
		return false;
	}

	///Prefic
	Fraction& operator++()
	{
		_numerator += _denominator;
		return *this;
	}
	Fraction& operator--()
	{
		_numerator -= _denominator;
		return *this;
	}


	// Postfix
	Fraction& operator++(int)
	{
		Fraction temp = *this;
		_numerator += _denominator;
		return temp;
	}
	Fraction& operator--(int)
	{
		Fraction temp = *this;
		_numerator -= _denominator;
		return temp;
	}

	///Typecast
	operator int() {
		return int(_numerator / _denominator);
	}

	operator float() {
		return float(_numerator / _denominator);
	}

	operator double() {
		return double(_numerator / _denominator);
	}

	operator bool() {
		return bool(_numerator / _denominator);
	}

	void Simplify() {
		int hcf = 1;
		if (_numerator > _denominator) {
			int temp = _numerator;
			_numerator = _denominator;
			_denominator = temp;
		}

		for (int i = 1; i <= _numerator; ++i) {
			if (_denominator % i == 0 && _numerator % i == 0) {
				hcf = i;
			}
		}

		_numerator /= hcf;
		_denominator /= hcf;
	}
};

ostream& operator<<(ostream& output, const Fraction& f)
{
	output << f._numerator << "/" << f._denominator << endl;

	return output;
}

istream& operator>>(istream& input, Fraction& f)
{
	cout << "Numerator: ";
	input >> f._numerator;

	cout << "Denominator: ";
	input >> f._denominator;

	return input;
}


