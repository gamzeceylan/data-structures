/** 
* @file Number.cpp
* @description Number sınıfı olutşurduğum ve gerekli fonksiyonların gövdelerini yazdığım kaynak dosya.
* @course 1/B
* @assignment 1. Ödev
* @date 05.08.2021
* @author Gamze Ceylan - gamze.ceylan3@ogr.sakarya.edu.tr 
*/
#include<iostream>
#include<fstream>
#include<string>
#include "Node.hpp"
#include "DoubleLinkedList.hpp"
#include "Number.hpp"
using namespace std;

	// kurucu fonksion
	// dosyadan char olarak aldığı elemanları üç basamaklı sayıya dönüştürüyor
		Number::Number(char units, char tens, char hundreds){
			this->units = units - 48;
			this->tens = tens - 48;
			this->hundreds = hundreds - 48;
			if(this->hundreds == 0) this->hundreds = 1;
			
		}
		
	// üç basamaklı sayıyı döndürüyor
		int Number::getNumber()const{
			return hundreds*100 + tens*10 + units;
		}