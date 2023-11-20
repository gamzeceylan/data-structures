/** 
* @file Node.cpp
* @description Node sınıfı olutşurduğum ve gerekli fonksiyonları yazdığım kaynak dosya.
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
		
		// düğüm sınıfının kurucu fonskiyonu
		Node::Node(const int& data=int(), Node *next=NULL, Node *prev=NULL){
			this->data = data;
			this->next = next;
			this->prev = prev;
		}