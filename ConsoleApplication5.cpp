//11.Задана последовательность разных натуральных чисел. 
//Построить список, элементами которого являются натуральные числа. 
//Конец списка – число 0. Напечатать в обратной последовательности все числа последовательности. 
//Ільницький Ростислав Олександрович
// ІП-72, лаба №5, Варіант 11, рівень А

#include "stdafx.h"
#include<iostream>
#include<list>
#include<vector>


using namespace std;

list<int> generatelist(){
	list<int> sequence;
	for(int i = 0; i < 15 ; i++){
		sequence.push_back(i*2 +3);
	}
	sequence.push_back(0);
	    
	return sequence;
};
void print(list<int> List){
    list<int>::reverse_iterator iterator; // реверсивний ітератор
    for (iterator = List.rbegin(); iterator != List.rend(); ++iterator) { // rbegin() ~ end(); rend() ~ begin()

        cout << *iterator << "  ";
    }
}
void main()
{
	
	list<int> MyInt = generatelist();
	print(MyInt);
	cin.get();
}

