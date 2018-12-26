//11. ������������ �������� �����: ���� ������� �� �������� ������ 
//� ���� ���������: ��� 1 ( x^2 + sqrt(3 * y^3 )), ��� 2 (3 * x^2 * z^(1/3) + e^(sqrt(4y))) . 
//��������� � �������� ���� � ������������� � ���������� ������ ����������
//�������� ������� ��� ������� ������� ����� �. ��������-���� ������������ � �������� ����,
//� �� ������������� � ���������� (�������� ����: �������� ������).
//�������� �������� ���� �, � ������, ������ � ����������� ����� ��'��� �������� ������������ �����.
//���������� � ������� ������ ������ ������� ���� ����� �����������.

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

class Funcs{
protected:
	double x;
	double y;
	double z;
public:
	Funcs(double newX = 0, double newY = 0, double newZ = 0);
	double getX() {
		return x;
	}
	double getY() {
		return y;
	}
	double getZ() {
		return z;
	}

	virtual double calculate() = 0;

};
Funcs::Funcs(double newX, double newY, double newZ) {
	x = newX;
	y = newY;
	z = newZ;
}

class Type1:public Funcs
{
public:
	Type1(double newX = 0, double newY = 0) :Funcs(newX, newY, 0) {}

	double calculate() {
		return pow(x, 2) + sqrt(3 * pow(y, 3));
	}
};

class Type2:public Funcs 
{
public:
	Type2(double newX = 0, double newY = 0,double newZ = 0) :Funcs(newX, newY, newZ) {}

	double calculate() {
		return 3 * pow(x, 2) * pow(z,(double)1/3) + pow(exp(1.0), sqrt(4 * y));
	}

};

int main()
{
	Funcs *func = new Type1(2, 3);
	cout <<"("<< func->getX() <<" ^  2) + sqrt(3 * "<< func->getY()<<"^3) = " ; //13
	cout << func->calculate() << endl;

	func = new Type2(2, 4, 8);
	cout << " 3 * "<<func->getX()<<" ^2) * "<< func->getZ() <<"^(1/3) + e ^ sqrt(4 *" << func->getY()<<")="; //78,5982
	cout << func->calculate() << endl;

	cin.get();
}