/** 
* @file DoubleLinkedList.hpp
* @description DoubleLinkedList sınıfı olutşurduğum ve gerekli fonksiyonların prototiplerini oluşturduğum başlık dosyası
* @course 1/B
* @assignment 1. Ödev
* @date 05.08.2021
* @author Gamze Ceylan - gamze.ceylan3@ogr.sakarya.edu.tr 
*/

#ifndef DOUBLELINKEDLIST_HPP
#define DOUBLELINKEDLIST_HPP
#include<iostream>
#include<fstream>
#include<string>
#include"Node.hpp"
using namespace std;

class DoubleLinkedList{
	private:
		Node *head;
		int size;		
		
		Node* FindByPosition(int index);
		
	public:
		DoubleLinkedList();
		int Count()const;
		bool isEmpty()const;
		void add(const int& data);
		void insert(int index, const int data);
		const int& elementAt(int index);
		void reverse();
		void removeAt(int index);
		void clear();		
		static void swap(int index, DoubleLinkedList*& list1, DoubleLinkedList*& list2);
		~DoubleLinkedList();
		friend ostream& operator <<(ostream& screen, DoubleLinkedList& right);
};

#endif