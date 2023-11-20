/**
* @file Test.cpp
* @description Test dosyasının yazılı olduğu dosya
* @course 1/B
* @assignment 2. Ödev
* @date Kodu 24/08/2021
* @author Gamze Ceylan gamze.ceylan3@ogr.sakarya.edu.tr
*/


#include "Kisi.hpp"
#include "AVL.hpp"

#include <fstream>
#include <cstring>  
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

int main(){

	AVL *agac = new AVL();
	
	string isim="";
	string yas="";
	string boy="";
	string satir = "";
	ifstream dosyaOku1("./doc/Kisiler.txt");
	ifstream dosyaOku2("./doc/Kisiler.txt");
	
	int sayac=0;
	if(dosyaOku1.is_open()){
	
		while (getline(dosyaOku1, satir))
		{
			sayac++;
		}
	}
	dosyaOku1.close();
	
	
	Kisi *kisiler[sayac];
	int i=0;
	if(dosyaOku2.is_open()){
	
		while (getline(dosyaOku2, satir))
		{
			// dosyadan okunan satırlar isim, yas, boy olarak ayrılıyor
			stringstream ss(satir);
			getline(ss, isim, '#');
			getline(ss, yas, '#');
			getline(ss, boy, '#');
			
			// kisi nesneleri oluşturuluyor
			Kisi *kisi = new Kisi(isim, stoi(yas), stoi(boy));
			agac->Ekle(kisi); // kisiler agaca ekleniyor
			
			kisiler[i] = kisi; // kisi nesneleri dizi içine atılıyor
			
			i++;
		}
	}
	agac->LevelOrder();
	dosyaOku2.close();
	
	// kisiler bellekten siliniyor
	for (int i=0; i<sayac; i++){
		delete kisiler[i];
	}
	
	delete agac;
	return 0;
}