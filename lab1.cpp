// 11. ���������� ����� �������������� � �������� ���������� a � b � ������� ��������������. 
//���������� ������ ������, �������������� ������ � ���� ����������.
//������� �����, ������������ ������� ��������������. 
//������ ����� ������������ ��� ������:
//� ����������� ������������� � �������������� ������ ����� ����;
//� ����������� �����������, ��������� ������ �� ������ ����������;
//� ����������� �����������, ����������� � �������� ��������� ������ 
//	�� ������ ������ ��������������, � ��������� ������������� �� ���������,
//	������� ������� ������� ����������� �������. 
//��������� ��������� �������������
//��-72
//���� 1, г���� �


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

