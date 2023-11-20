/**
* @file Kisi.hpp
* @description Kisi, dosyadan okunan kisi nesnelerinin tutulduğu class
* @course 1/B
* @assignment 2. Ödev
* @date Kodu 24/08/2021
* @author Gamze Ceylan gamze.ceylan3@ogr.sakarya.edu.tr
*/


#ifndef KISI_HPP
#define KISI_HPP

#include <iostream>
#include "Stack.hpp"
using namespace std;
class Kisi{

	public:
	
		Stack *stack_yukseklik;
		Stack *stack_derinlik;
		string isim;
		int yas;
		int boy;
		
		Kisi(string, int, int);
		~Kisi();
};


#endif

