#pragma once

#include "RefCounter.h"

template <typename T> class MySmartPointer {
private:
	RefCounter* counter;
	T* data;

public:
	MySmartPointer(T* data);
	MySmartPointer(const MySmartPointer& otherPointer);
	~MySmartPointer();

	T& operator *();
	T* operator ->();
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
	if (this->counter->dec == 0) {
		delete this->data;
		delete this->counter;
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