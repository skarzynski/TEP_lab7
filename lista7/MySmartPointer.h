#pragma once

#include "RefCounter.h"

#include <iostream>

using namespace std;

template <typename T> class MySmartPointer {
private:
	RefCounter* counter;			//wskaźnik na licznik odwołań
	T* data;						//wskaźnik na dane

public:
	MySmartPointer(T* data);		//konstruktor przyjmujący wskaźnik na dane
	MySmartPointer(const MySmartPointer& otherPointer);		//konstruktor kopiujący
	~MySmartPointer();				//destruktor

	void getStatus();				//wypisuje status wskaźnika

	T& operator *();				//operator *
	T* operator ->();				//operator ->
	MySmartPointer<T>& operator= (const MySmartPointer<T> otherPointer);	//operator =
};

//-----------------------------------------------------------------------------------------------

template <typename T>
MySmartPointer<T>::MySmartPointer(T* data) {
	this->data = data;
	this->counter = new RefCounter();
	this->counter->add();
}

template <typename T>
MySmartPointer<T>::MySmartPointer(const MySmartPointer& otherPointer) {
	this->data = otherPointer.data;
	this->counter = otherPointer.counter;
	this->counter->add();
}

template <typename T>
MySmartPointer<T>::~MySmartPointer() {
	if (this->counter->dec() == 0) {
		delete this->data;
		delete this->counter;
	}
}

template<typename T>
void MySmartPointer<T>::getStatus() {
	if (this->data != nullptr) {
		cout << "Adres przechowywanych danych: " << this->data << endl;
		cout << "Aktualna liczba odwolan: " << this->counter->get() << endl;
		cout << "Maksymalna liczba odwolan: " << this->counter->getMax() << endl;
	}
	else {
		cout << "Wskaznik nic nie przechowuje" << endl;
	}
}

template <typename T>
T& MySmartPointer<T>::operator*() {
	return *this->data;
}

template <typename T>
T* MySmartPointer<T>::operator->() {
	return this->data;
}

template<typename T>
MySmartPointer<T>& MySmartPointer<T>::operator=(const MySmartPointer<T> otherPointer) {
	if (this->data != nullptr) {
		if (this->counter->dec() == 0) {
			delete this->data;
			delete this->counter;
		}
	}
	this->data = otherPointer.data;
	this->counter = otherPointer.counter;
	this->counter->add();

	return *this;
}

