#pragma once

#include "RefCounter.h"

class MySmartPointer {
private:
	RefCounter* counter;
	int* data;

public:
	MySmartPointer(int* data);
	MySmartPointer(const MySmartPointer& otherPointer);
	~MySmartPointer();

	int& operator *();
	int* operator ->();
};