/** 
* @file Node.hpp
* @description Node sınıfı oluşturduğum ve gerekli fonksiyonların prototiplerini yazdığım başlık dosyası.
Node sınıfı programda düğümleri oluşturmak için kullanılır.
* @course 1/B
* @assignment 1. Ödev
* @date 05.08.2021
* @author Gamze Ceylan - gamze.ceylan3@ogr.sakarya.edu.tr 
*/

#ifndef NODE_HPP
#define NODE_HPP
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Node{
	public:
		int data;
		Node *prev;
		Node *next;		
		Node(const int&, Node*, Node*);
};

#endif