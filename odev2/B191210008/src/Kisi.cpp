/**
* @file Kisi.cpp
* @description Kisi sınıfının fonksiyon gövdelerinin yazılı olduğu dosya
* @course 1/B
* @assignment 2. Ödev
* @date Kodu 24/08/2021
* @author Gamze Ceylan gamze.ceylan3@ogr.sakarya.edu.tr
*/


#include "Kisi.hpp"
#include "Stack.hpp"

		Kisi::Kisi(string isim, int yas, int boy){
			this->isim = isim;
			this->yas = yas;
			this->boy = boy;
			stack_yukseklik = new Stack();
			stack_derinlik = new Stack();
		}
		
		Kisi::~Kisi(){
			delete stack_yukseklik;
			delete stack_derinlik;
		}
