#pragma once

class RefCounter {

private:
	int count;			//przechowuje aktualn� liczb� jednoczesnych odwo�a� do pami�ci

public:
	RefCounter();		//konstruktor bezparametrowy

	int add();			//inkrementuje licznik o 1 i zwraca warto�� licznika
	int dec();			//dekrementuje licznik o 1 i zwraca warto�� licznika
	int get();			//zwraca warto�� licznika
};
