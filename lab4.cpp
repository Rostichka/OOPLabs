//������� ��������� ������ ������:
//� ������ ���������.
//��� ������ ��������� ������� �������� ������������������� (���������); 
//� ����� ��������� �������; 
//� ����� ������ ������� �������� � �������, �������� ��������; !!!������ 11 - ������ ������ � �������� � ������
//� ����������� ��� �������������� ������������� ����������� ������� ���������, �������� �����.
//� ���������� (��� �������������).
// ������������������ ������ ������� �� ������ ������� ������������� ����� ������. 
// ���������� ��������� �������������
// �� - 72
//���� �4, ����� �

#include"stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename Type>
struct TreeLetter {
	Type data;
	TreeLetter() {
		leftChild = nullptr;
		rightChild = nullptr;
		parent = nullptr;
	};
	TreeLetter* parent;
	TreeLetter* leftChild;
	TreeLetter* rightChild;
};

template <typename Type>
class BinaryTree {
private:
	TreeLetter<Type> * root = nullptr;
public:
	void addLetter(Type data) {
		TreeLetter<Type>* letter = new TreeLetter<Type>();
		letter->data = data;
		TreeLetter<Type>* temp = nullptr;
		TreeLetter<Type>* curr = this->root;

		while (curr != nullptr) {
			temp = curr;
			if (letter->data <= curr->data) curr = curr->leftChild;
			else curr = curr->rightChild;
		}

		letter->parent = temp;
		if (temp == nullptr) {
			this->root = letter;
		}
		else if (letter->data <= temp->data) {
			temp->leftChild = letter;
		}
		else temp->rightChild = letter;
	}

	TreeLetter<Type> * getRoot() {
		return this->root;
	}
};

template <typename Type>
class UserArray{
private:
	int length;
	vector<Type> array;
	void returnIndex(Type* val, TreeLetter<Type> * curr, int*index){
		if (curr != nullptr) {
			if (curr->data == *val) return;
			returnIndex(val, curr->leftChild, index);
			*index += 1;
			returnIndex(val, curr->rightChild, index);
		}
	}
public:
public:

	~UserArray(){}

	UserArray(int size){
		length = size;
		for (int i = 0; i < size; ++i) {
			Type newEl = i;
			array.push_back(newEl);
		}
	}

	UserArray(int size, vector<Type> userArray){
		length = size;
		array = userArray;
	}

	void display(){
		for (int i = 0; i < length; ++i) {
			cout << array[i] << "  ";
		}
	}

	int findIndex(Type val){
		BinaryTree<Type> tree;
		for (int i = 0; i < array.size(); i++) {
			tree.addLetter(array[i]);
		}
		int index = 0;
		returnIndex(&val, tree.getRoot(), &index);
		if (index == length){
			return -1;
		}
		return index;
	}
};

void main() {
	UserArray<int> testInt(5);
	testInt.display();
	cout << endl << "Index of element is: " << testInt.findIndex(3) << endl;
	UserArray<float> testFloat(5);
	testFloat.display();
	cout << endl << "Index of element is: " << testFloat.findIndex(3) << endl;
	UserArray<double> testDouble(5);
	testDouble.display();
	cout << endl << "Index of element is: " << testDouble.findIndex(3) << endl;
	UserArray<long> testLong(5);
	testLong.display();
	cout << endl << "Index of element is: " << testLong.findIndex(3) << endl;
	UserArray<short> testShort(5);
	testShort.display();
	cout << endl << "Index of element is: " << testShort.findIndex(3) << endl;
	cin.get();
}