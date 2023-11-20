/**
* @file Stack.hpp
* @description Stack sınıfı agaca eklenen kisi nesnelerinin yükseklik ve derinliklerini tutmak için
yazılmıştır.
* @course 1/B
* @assignment 2. Ödev
* @date Kodu 24/08/2021
* @author Gamze Ceylan gamze.ceylan3@ogr.sakarya.edu.tr
*/


#ifndef STACK_HPP
#define STACK_HPP

#include "NodeStack.hpp"
#include <iostream>
using namespace std;

class Stack{
	private:
		NodeStack *topOfStack;
		NodeStack *head;
		int size;
	
	public:
		Stack();
		bool isEmpty()const;
		void push(const int &);
		void YazdirYukseklik(Stack *);
		void YazdirDerinlik(Stack *);
		void pop();
		void makeEmty();
		int top()const;
		~Stack();
	
};



#endif