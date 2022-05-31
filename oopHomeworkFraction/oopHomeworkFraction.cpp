#include <iostream>
#include<cassert>
#include<string>
using namespace std;
#include"Fraction.h"

int main()
{
	Fraction f1, f2;
	cin >> f1;
	cin >> f2;
	Fraction result = f1 + f2;
	cout << result << endl;
}
