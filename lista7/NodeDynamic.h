#pragma once

#include <vector>
#include <iostream>
#include <string>

using namespace std;

template <typename T> class NodeDynamic {

private:
	vector<NodeDynamic*> children;			//wektor dzieci
	NodeDynamic* parentNode;				//wskaŸnik na rodzica
	T value;								//wartoœæ

public:
	NodeDynamic();							//kontruktor bezparametrowy
	~NodeDynamic();							//destruktor

	void setValue(T newValue);				//ustawia wartoœæ
	T getValue();							//pobiera wartość węzła

	int getChildrenNumber();				//pobiera liczbê dzieci
	void addNewChild();						//dodaje nowe dziecko
	void addNewChild(NodeDynamic* newChild);//dodaje nowe dziecko podane w parametrze
	bool removeChild(NodeDynamic* child);	//usuwa zadane dziecko (ca³e poddrzewo)
	NodeDynamic* getChild(int childOffset);	//pobiera wskaŸnik na dziecko o zadanym offsecie
	NodeDynamic* getParent();				//pobiera rodzica
	int getOffset(NodeDynamic* child);		//pobiera offset dziecka w wektorze
	int count(T val);						//zlicza ilość wystąpień argumentu w swoim wektorze dzieci
	int countAllBelow(T val);				//zlicza ilość wystąpień argumentu w swoim poddrzewie

	void print();							//wypisuje wartoœæ wêz³a
	void printAllBelow();					//wypisuje wartoœci wszystkich wêz³ów pocz¹wszy od danego w dó³
};

//------------------------------------------------------------------------------------------------------------------------------------------

template <typename T>
NodeDynamic<T>::NodeDynamic() {
	this->value = 0;
	this->parentNode = NULL;
}

template <>
NodeDynamic<string>::NodeDynamic() {
	this->value = "0";
	this->parentNode = NULL;
}

template <typename T>
NodeDynamic<T>::~NodeDynamic() {
	for (int i = 0; i < this->children.size(); i++) {
		delete this->children.at(i);
	}
}

template <typename T>
void NodeDynamic<T>::setValue(T newValue) {
	this->value = newValue;
}

template <typename T>
T NodeDynamic<T>::getValue() {
	return this->value;
}

template <typename T>
int NodeDynamic<T>::getChildrenNumber() {
	return this->children.size();
}

template <typename T>
void NodeDynamic<T>::addNewChild() {
	NodeDynamic<T>* newChild = new NodeDynamic<T>();
	newChild->parentNode = this;
	this->children.push_back(newChild);
}

template <typename T>
void NodeDynamic<T>::addNewChild(NodeDynamic<T>* newChild) {
	if (newChild != nullptr) {
		this->children.push_back(newChild);
		newChild->parentNode = this;
	}
}

template <typename T>
bool NodeDynamic<T>::removeChild(NodeDynamic<T>* child) {
	int offset = child->getParent()->getOffset(child);
	if (child == nullptr || offset == -1) {
		return false;
	}
	child->getParent()->children.erase(child->getParent()->children.begin() + offset);
	child->parentNode = NULL;
	return true;
}

template <typename T>
NodeDynamic<T>* NodeDynamic<T>::getChild(int childOffset) {
	if (childOffset < 0 || childOffset >= this->children.size()) {
		return nullptr;
	}
	return this->children.at(childOffset);
}

template <typename T>
NodeDynamic<T>* NodeDynamic<T>::getParent() {
	return this->parentNode;
}

template <typename T>
int NodeDynamic<T>::getOffset(NodeDynamic<T>* child) {
	int offset = -1;

	for (int i = 0; i < this->getChildrenNumber(); i++) {
		if (this->children.at(i) == child) {
			offset = i;
		}
	}

	return offset;
}

template <typename T>
int NodeDynamic<T>::count(T val) {
	int counter = 0;
	for (int i = 0; i < this->getChildrenNumber(); i++) {
		if (this->children.at(i)->value == val) {
			counter++;
		}
	}
	return counter;
}

template <typename T>
int NodeDynamic<T>::countAllBelow(T val) {
	int counter = this->count(val);
	for (int i = 0; i < this->getChildrenNumber(); i++) {
		counter += this->children.at(i)->countAllBelow(val);
	}
	return counter;
}

template <typename T>
void NodeDynamic<T>::print() {
	cout << " " << this->value;
}

template <typename T>
void NodeDynamic<T>::printAllBelow() {
	this->print();
	for (int i = 0; i < this->children.size(); i++) {
		this->children.at(i)->printAllBelow();
	}
}