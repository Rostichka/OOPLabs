// 11. Определить класс «Прямоугольник» с закрытым элементами a и b – стороны прямоугольника. 
//Определить методы класса, обеспечивающие доступ к этим переменным.
//Создать метод, определяющий площадь прямоугольника. 
//Задать такие конструкторы для класса:
//– конструктор инициализации с инициализацией данных через ввод;
//– конструктор перемещения, создающий объект на основе временного;
//– конструктор копирования, принимающий в качестве параметра ссылку 
//	на объект класса «Прямоугольник», и создающий прямоугольник со сторонами,
//	равными большей стороне копируемого объекта. 
//Ільницкий Ростислав Олександрович
//ІП-72
//Лаба 1, Рівень Б


#include "stdafx.h"
#include<iostream>

using namespace std;


class Rectangle
{
private:
	int a;
	int b;

public:
	Rectangle()
	{
		cout << "Input a:" << endl;
		cin >> a;
		cout << "Input b:" << endl;
		cin >> b;
	}

	Rectangle(Rectangle &rect) {
		

		if (a > b){
			a = rect.a;
			b = rect.a;
		} else
		{
			a = rect.b;
			b = rect.b;
		}
	}

	Rectangle(Rectangle&& rect) : a(rect.a), b(rect.b)
	{
	
		

		
	}

	int get_a(int a) {
		return a;
	}

	int get_b(int b) {
		return b;
	}

	void area() const
	{
		int area = a * b;
		cout << "Area = " << area << endl;
	}
};

int main() {
	Rectangle R;
	Rectangle G(R); 
	Rectangle A = move(G);
	
	R.area();
	G.area();
	A.area();




	system("pause");
}

