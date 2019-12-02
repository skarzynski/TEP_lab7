#pragma once

#include "NodeDynamic.h"

template <typename T> class TreeDynamic {

private:
	NodeDynamic<T>* root;			//korzeñ drzewa

public:
	TreeDynamic();				//konstruktor bezparametrowy
	~TreeDynamic();				//destruktor

	NodeDynamic<T>* getRoot();		//zwraca korzeñ drzewa

	bool moveSubtree(NodeDynamic<T>* parentNode, NodeDynamic<T>* newChildNode); //przenosi poddrzewo z obcego drzewa do swojego

	void printTree();			//wypisuje wartoœci wszystkich wêz³ów
	int count(T val);			//zlicza ilość wystąpień argumentu w drzewie
};

//------------------------------------------------------------------------------------------------------------------------------------------

template <typename T>
TreeDynamic<T>::TreeDynamic() {
	this->root = new NodeDynamic<T>();
}

template <typename T>
TreeDynamic<T>::~TreeDynamic() {
	delete this->root;
}

template <typename T>
NodeDynamic<T>* TreeDynamic<T>::getRoot() {
	return this->root;
}

template <typename T>
bool TreeDynamic<T>::moveSubtree(NodeDynamic<T>* parentNode, NodeDynamic<T>* newChildNode) {
	if (parentNode == nullptr || newChildNode == nullptr) {
		return false;
	}
	newChildNode->getParent()->removeChild(newChildNode);
	parentNode->addNewChild(newChildNode);
	return true;
}

template <typename T>
void TreeDynamic<T>::printTree() {
	this->root->printAllBelow();
}

template <typename T>
int TreeDynamic<T>::count(T val) {
	return this->root->countAllBelow(val);
}
