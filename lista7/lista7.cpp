// lista7.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include "MySmartPointer.h"
#include "TreeDynamic.h"

#include <iostream>

using namespace std;


int main() {
    
	TreeDynamic<int>* myTree = new TreeDynamic<int>();
	TreeDynamic<int>* myTree2 = new TreeDynamic<int>();

	MySmartPointer<TreeDynamic<int>> tree(myTree);
	MySmartPointer<TreeDynamic<int>> tree2(myTree2);

	tree->getRoot()->addNewChild();
	tree->getRoot()->addNewChild();

	tree->getRoot()->getChild(0)->setValue(1);
	tree->getRoot()->getChild(1)->setValue(2);

	tree->getRoot()->getChild(0)->addNewChild();
	tree->getRoot()->getChild(0)->addNewChild();

	tree->getRoot()->getChild(0)->getChild(0)->setValue(11);
	tree->getRoot()->getChild(0)->getChild(1)->setValue(12);

	tree->getRoot()->getChild(1)->addNewChild();
	tree->getRoot()->getChild(1)->addNewChild();

	tree->getRoot()->getChild(1)->getChild(0)->setValue(21);
	tree->getRoot()->getChild(1)->getChild(1)->setValue(22);

	tree->printTree();
	cout << endl;

	tree2->getRoot()->addNewChild();
	tree2->getRoot()->getChild(0)->setValue(5);

	tree2->printTree();
	cout << endl;

	cout << endl << endl << "tree status" << endl << endl;
	tree.getStatus();
	cout << endl << endl << "tree2 status" << endl << endl;
	tree2.getStatus();

	tree = tree2;

	cout << endl << endl << "tree status po przypisaniu do niego tree2" << endl << endl;
	tree.getStatus();

	MySmartPointer<TreeDynamic<int>> tree3 = tree;
	MySmartPointer<TreeDynamic<int>> tree4 = tree;
	MySmartPointer<TreeDynamic<int>> tree5 = tree;

	cout << endl << endl << "tree status po stworzeniu kolejnych trzech kopii" << endl << endl;
	tree.getStatus();

	tree2 = NULL;
	tree3 = NULL;
	tree4 = NULL;
	tree5 = NULL;

	cout << endl << endl << "tree status po usunieciu wszystkich kopii" << endl << endl;
	tree.getStatus();

	cout << endl << endl << "tree2 status po usunieciu z niego danych" << endl << endl;
	tree2.getStatus();

	tree->printTree();


}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
