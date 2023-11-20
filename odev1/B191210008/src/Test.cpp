/** 
* @file Test.cpp
* @description Yapılması istenen işlemler doğrultusunda yazdığım test dosyası
* @course 1/B
* @assignment 1. Ödev
* @date 05.08.2021
* @author Gamze Ceylan - gamze.ceylan3@ogr.sakarya.edu.tr 
*/
#include "DoubleLinkedList.hpp"
#include "Number.hpp"
#include "Node.hpp"
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <fstream>
int main(){
	DoubleLinkedList *sayilar1 = new DoubleLinkedList();
	DoubleLinkedList *sayilar2 = new DoubleLinkedList();
	ifstream dosyaOku("./doc/Sayilar.txt");
	char karakter;
	char birlerBasamagi, onlarBasamagi, yuzlerBasamagi;
	
	int sayi;
	
	if(dosyaOku.is_open()){
		dosyaOku.get(karakter);
		while(karakter != '#'){ // # karakterine kadar dosyayı okuyor ve gerekli değişkenlere atıyor.
		
				yuzlerBasamagi = karakter;
			
				dosyaOku.get(karakter);
				onlarBasamagi = karakter;
				
				dosyaOku.get(karakter);
				birlerBasamagi = karakter;
				
				Number number(birlerBasamagi, onlarBasamagi,yuzlerBasamagi); // number sınıfına okunan 3 karakteri gönderiyor
				sayi = number.getNumber(); // daha sonra number sınıfından üç basamaklı sayıyı alıyor
				sayilar1->add(sayi); // sayıyı sayi1 listesine ekliyor
			
				dosyaOku.get(karakter);
				
		}
		dosyaOku.get(karakter);
		while(!dosyaOku.eof()){ // # sonrasını dosya sonuna kadar okuyor
				
				yuzlerBasamagi = karakter;
						
				dosyaOku.get(karakter);
				onlarBasamagi = karakter;
				
				dosyaOku.get(karakter);
				birlerBasamagi = karakter;
				
				Number number(birlerBasamagi, onlarBasamagi,yuzlerBasamagi); // number sınıfına okunan 3 karakteri gönderiyor
				sayi = number.getNumber(); // daha sonra number sınıfından üç basamaklı sayıyı alıyor
				sayilar2->add(sayi); // sayıyı sayi2 listesine ekliyor
				dosyaOku.get(karakter);
		}
		dosyaOku.close();
	}

	if(sayilar1->Count() == sayilar2->Count()){
		for(int i=0; i < sayilar1->Count(); i++){
			if(sayilar1->elementAt(i) > sayilar2->elementAt(i))
				sayilar1->reverse();
			
			else if(sayilar1->elementAt(i) == sayilar2->elementAt(i))
				sayilar2->reverse();
			
			else if(sayilar1->elementAt(i) < sayilar2->elementAt(i))
				DoubleLinkedList::swap(i, sayilar1,sayilar2); 
		}
	
	}
	else{
		// throw hata
	}
	
	cout << "Sayi 1 : " << *sayilar1 << endl;
	cout << "Sayi 2 : " << *sayilar2 << endl;
	
	delete sayilar1;
	delete sayilar2;

	return 0;
}