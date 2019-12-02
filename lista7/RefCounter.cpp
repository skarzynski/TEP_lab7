#include "pch.h"
#include "RefCounter.h"

using namespace std;

RefCounter::RefCounter() {
	this->count = 0;
}

int RefCounter::add() {
	return ++this->count;
}

int RefCounter::dec() {
	return --this->count;
}

int RefCounter::get() {
	return this->count;
}
