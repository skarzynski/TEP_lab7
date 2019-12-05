#pragma once

class RefCounter {

private:
	int count;			//przechowuje aktualn¹ liczbê jednoczesnych odwo³añ do pamiêci
	int max;			//przechowuje maksymalną liczbę jednoczesnych odwołań do pamięci

public:
	RefCounter();		//konstruktor bezparametrowy

	int add();			//inkrementuje licznik o 1 i zwraca wartoœæ licznika
	int dec();			//dekrementuje licznik o 1 i zwraca wartoœæ licznika
	int get();			//zwraca wartoœæ licznika
	int getMax();		//zwraca wartość max
};
