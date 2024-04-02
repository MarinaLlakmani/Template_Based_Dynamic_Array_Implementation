#pragma once
#include<iostream>
using namespace std;

template <class elemType>
class listType
{
public:
	bool isEmpty() const;
	bool isFull() const;
	elemType get(int) const;
	int search(const elemType& searchItem) const;
	void insert(const elemType& newElement);
	void remove(const elemType& removeElement);
	void destroyList();
	listType();
	listType(int);
	friend std::ostream& operator<< (std::ostream& os, const listType<elemType>& lt) {
		//TODO: Implement printing of the entire list
		for (int i = 0; i < lt.curLength; i++) {
			os << lt.list[i] <<endl;
		}
		return os;
	}
protected:
	elemType* list;
	int maxLength;
	int curLength;
};

//TODO: Fill in the isEmpty() function
//I'm giving you this function signature as an example

template<class elemType>
bool listType<elemType>::isFull()const {

	return curLength == maxLength;

}

template<class elemType>
bool listType<elemType>::isEmpty() const {
	int newLength = 0;
	curLength = newLength;
	return curLength;
}

//TODO: Write all the remaining functions of the listType<elemType> class



template<class elemType>
elemType listType<elemType> ::get(int placement) const {
	if (placement < curLength && placement >= 0) {
		return list[placement];
	}
	return elemType();
}


template<class elemType>
int listType<elemType>::search(const elemType& searchItem)const {
	for (int i = 0; i < curLength; i++) {
		if (list[i] == searchItem) {
			return i;
		}
	}
	return -1;
}



template<class elemType>
void listType<elemType>::insert(const elemType& newElement){
	if (curLength == maxLength) {
		maxLength *= 2;
		elemType* array = new elemType[maxLength];
		for (int j = 0; j < curLength; j++) {
			array[j] = list[j];
		}
		delete[] list;
		list = array;
	}

	list[curLength] = newElement;
	curLength++;
}

template<class elemType>
void listType<elemType>::remove(const elemType& removeElement) {
	int deletecount = -1;
	for (int i = 0; i < curLength; i++) {
		if (list[i] == removeElement) {
			deletecount = i;
			break;
		}
	}
	if (deletecount != -1) {
		for (int i = deletecount; i < curLength - 1; i++) {
			list[i] = list[i + 1]; 
		}
		curLength--;

	}
}


template<class elemType>
void listType<elemType>::destroyList() {
	delete[] list;
	list = nullptr;
	curLength = 0; 
}

template<class elemType> 
listType<elemType> ::listType() {
	maxLength = 100;
	curLength = 0;
	list = new elemType[maxLength];
}

template<class elemType> 
listType<elemType>::listType(int size){
	maxLength = size;
	curLength = 0;
	list = new elemType[maxLength];
}