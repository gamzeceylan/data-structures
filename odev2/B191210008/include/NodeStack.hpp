/**
* @file NodeStack.hpp
* @description NodeStack, Stack için düğüm oluşturan sınıf. Stack sınıfı düğümün yükseklik
ve derinliğini tutar.
* @course 1/B
* @assignment 2. Ödev
* @date Kodu 24/08/2021
* @author Gamze Ceylan gamze.ceylan3@ogr.sakarya.edu.tr
*/


#ifndef NODESTACK_HPP
#define NODESTACK_HPP

#include <iostream>
using namespace std;

class NodeStack{
	public:
		int item;
		NodeStack *next;
		NodeStack(const int&, NodeStack *next = NULL);
};
#endif
