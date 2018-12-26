//11. Спроектировать класс «Fraction», который содержит: дробь в формате «±m/n», 
//правильную или неправильную. Для класса определить: операцию сложения «+»,
//операцию вычитания «-», операцию умножения «*», операцию деления «/». 
//При возможности, обязательно сокращать дроби. Для нахождения наибольшего 
//общего делителя использовать бинарный алгоритм. При необходимости разрешается определять 
//другие операции (например «=»). Продемонстрировать каждую операцию. 
//Ільницький Ростислав Олександрович
//ІП-72
//Лаб №2, рівень Б
#include "pch.h"
#include <iostream>

using namespace std;

class Fraction
{
private:
	int sign; //знак
	int m; //знаменник
	int n; // чисельник
	int FullPart;
	void GetFullPart();  // якщо у нас неправильний дріб, то виділяємо цілу частину
	void MixedView();	// і перетворюємо в змішаний вигляд 
	void Cancellation(); //ф-ція скорочення дробу

public:
	Fraction() :m(1), n(0), sign(1), FullPart(0)
	{

	};
	Fraction(int n, int m, int FullPart, int sign)
	{
		this->FullPart = FullPart;
		this->m = m;
		this->n = n;
		this->sign = sign;

	};
	Fraction(int n, int m) :sign(1), FullPart(0)
	{
		this->m = m;
		this->n = n;
	};
	Fraction operator + (Fraction);
	Fraction operator + (int);
	Fraction operator - (Fraction);
	Fraction operator - (int);
	Fraction operator * (Fraction);
	Fraction operator * (int);
	Fraction operator / (Fraction);
	Fraction operator / (int);
	friend Fraction operator + (int, Fraction);
	friend Fraction operator - (int, Fraction);
	friend Fraction operator * (int, Fraction);
	friend Fraction operator / (int, Fraction);

	void print() {
		if (FullPart == 0 && sign < 0 && n != 0)
		{
			printf(" -%i/%i  ", n, m);
		}
		else if (FullPart > 0 && sign < 0 && n != 0)
		{
			printf(" -%i * %i/%i  ", FullPart, n, m && n != 0);
		}
		else if (FullPart == 0 && sign > 0 && n != 0) {
			printf(" %i/%i  ", n, m);
		}
		else if (FullPart > 0 && sign > 0 && n != 0)
		{
			printf(" %i * %i/%i  ", FullPart, n, m);
		}
		else if (n == 0){
			printf("%i  ", FullPart);
		}
	}




};

void Fraction::MixedView()
{
	GetFullPart();
	 Cancellation();
}

void Fraction::GetFullPart()
{
	if (n >= m)
	{
		FullPart = n / m;
		n = n % m;
	}
}

void Fraction::Cancellation()
{
	int nod, a = n, b = m;
	while (b > 0 && a > 0) //  алгоритм Евкліда(бінарний алгоритм) 
	{
		int tmp = a;
		a = b;
		b = tmp % b;
	}
	nod = a;
	if (nod > 0)
	{//сокращение
		m /= nod;
		n /= nod;
	}
}

Fraction Fraction::operator + (Fraction a)
{
	Fraction res;
	res.n = sign * (FullPart * m + n) * a.m + a.sign *(a.FullPart * a.m + a.n) * m;
	res.m = m * a.m;
	if (res.n < 0)
	{
		res.n *= -1; res.sign = -1;
	}
	res.MixedView();
	return res;
}

Fraction Fraction::operator + (int a)
{
	Fraction res;
	Fraction b(0, 1, abs(a), a / abs(a));    // b = a
	res = (*this) + b; //додавання двох дробів
	return res;
}

Fraction operator + (int a, Fraction c)
{
	Fraction res;
	Fraction b(0, 1, abs(a), a / abs(a));     // b = a
	res = b + c;        //додавання двох дробів
	return res;
}


Fraction Fraction::operator - (Fraction a)
{
	Fraction res;
	res.n = sign * (FullPart * m + n) * a.m - a.sign *(a.FullPart * a.m + a.n) * m;
	res.m = m * a.m;
	if (res.n < 0)
	{
		res.n *= -1; res.sign = -1;
	}
	res.MixedView();
	return res;
}


Fraction Fraction::operator - (int a)
{
	Fraction res;
	Fraction b(0, 1, abs(a), a / abs(a));    // b = a
	res = (*this) - b; //віднімання двох дробів
	return res;
}
Fraction operator - (int a, Fraction c)
{
	Fraction res;
	Fraction b(0, 1, abs(a), a / abs(a));     // b = a
	res = b - c;        //віднімання двох дробів
	return res;
}

Fraction Fraction::operator * (Fraction a)
{
	Fraction res;
	res.n = sign * (FullPart * m + n) * a.sign *(a.FullPart * a.m + a.n);
	res.m = m * a.m;
	if (res.n < 0)
	{
		res.n *= -1; res.sign = -1;
	}
	res.MixedView();
	return res;
}

Fraction Fraction::operator * (int a)
{
	Fraction res;
	Fraction b(0, 1, abs(a), a / abs(a));    // b = a
	res = (*this) * b; 
	return res;
}

Fraction operator * (int a, Fraction c)
{
	Fraction res;
	Fraction b(0, 1, abs(a), a / abs(a));     // b = a
	res = b * c;        
	return res;
}

Fraction Fraction::operator / (Fraction a)
{
	Fraction res;
	res.n = sign * (FullPart * m + n) * a.sign * a.m;
	res.m = m * (a.FullPart * a.m + a.n);
	if (res.n < 0)
	{
		res.n *= -1; res.sign = -1;
	}
	res.MixedView();
	return res;
}

Fraction Fraction::operator / (int a)
{
	Fraction res;
	Fraction b(0, 1, abs(a), a / abs(a));    // b = a
	res = (*this) / (b); 
	return res;
}

Fraction operator / (int a, Fraction c)
{
	Fraction res;
	Fraction b(0, 1, abs(a), a / abs(a));     // b = a
	res = b / (c);        
	return res;
}
int main()
{
	Fraction a(2, 3); // 2/3
	Fraction g(1, 4, 2, -1); // -2 * 1/4
	Fraction l(4, 5, 1, 1); // 1 * 4/5
	Fraction k(5, 8);
	//a.print();
	Fraction b(1,4);   // 1/6
	//b.print();
	Fraction c = a + b; // 5/6
	Fraction h = a - b;// 1/2
	Fraction z = k - b; // 11/24
	Fraction d = 2 + g; // -1/4
	Fraction x =  l-2; // -1/5
	Fraction j = a * k; // 5/12
	Fraction m = l * 3; // (k*3) =  1 * 7/8      (l*3) = 5 * 2/5
	Fraction n = 2 * a; // 1* 1/3
	Fraction w = a / b; // 4 
	Fraction s = b / 2;
	Fraction v = 5 / k; // 8
	v.print();

	cin.get();
}
