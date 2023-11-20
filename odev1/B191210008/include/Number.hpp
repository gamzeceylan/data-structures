 /** 
* @file Number.cpp
* @description Number sınıfı olutşurduğum ve gerekli fonksiyonların prototiplerini yazdığım başlık dosyası.
Bu sınıfta dosyadan char olarak okunan her 3 sayıyı alıyorum ve üç basamaklı bir sayıya çevirip
kullanıcıya döndürüyorum.
* @course 1/B
* @assignment 1. Ödev
* @date 05.08.2021
* @author Gamze Ceylan - gamze.ceylan3@ogr.sakarya.edu.tr 
*/
#ifndef NUMBER_HPP
#define NUMBER_HPP
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Number{
	private:
		int units; 
		int tens; 
		int hundreds; 		
	public:
		Number(char, char, char);		
		int getNumber()const;
};

#endif