#include "MySmartPointer.h"

MySmartPointer::MySmartPointer(int* data) {
	this->data = data;
	this->counter = new RefCounter();
	this->counter->add();
}

MySmartPointer::MySmartPointer(const MySmartPointer& otherPointer) {
	this->data = otherPointer.data;
	this->counter = otherPointer.counter;
	this->counter->add();
}

MySmartPointer::~MySmartPointer() {
	if (this->counter->dec == 0) {
		delete this->data;
		delete this->counter;
	}
}

int& MySmartPointer::operator*() {
	return *this->data;
}

int* MySmartPointer::operator->() {
	return this->data;
}
