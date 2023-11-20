/**
* @file NodeStack.cpp
* @description NodeStack sınıfının fonksiyon gövdelerinin yazılı olduğu dosya
* @course 1/B
* @assignment 2. Ödev
* @date Kodu 24/08/2021
* @author Gamze Ceylan gamze.ceylan3@ogr.sakarya.edu.tr
*/

#include "NodeStack.hpp"

		NodeStack::NodeStack(const int &item, NodeStack *next){
			this->item = item;
			this->next = next;
		}