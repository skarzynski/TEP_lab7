#include "pch.h"
#include "RefCounter.h"

using namespace std;

RefCounter::RefCounter() {
	this->count = 0;
	this->max = 0;
}

int RefCounter::add() {
	if (++this->count > this->max) {
		this->max = this->count;
	}
	return this->count;
}

int RefCounter::dec() {
	return --this->count;
}

int RefCounter::get() {
	return this->count;
}

int RefCounter::getMax() {
	return this->max;
}
