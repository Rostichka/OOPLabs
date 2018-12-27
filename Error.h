#include "pch.h"
#include<iostream>
#include<string>

using namespace std;
class Error
{
public:
	virtual void printError() = 0;
};

class DevbyZero :virtual public Error {
public:
	void printError() {
		cout << "We can`t devide by 0";
	}
};

class ZeroDenominator :virtual public Error {
public:
	void printError() {
		cout << "Denominator can`t be 0";
	}
};
