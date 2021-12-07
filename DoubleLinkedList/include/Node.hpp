
#ifndef NODE_HPP
#define NODER_HPP

#include <iostream>
using namespace std;

template <typename Object>
class Node{
	public:
		Object data; 
		Node<Object> *next; // ileri. çünkü ilerisi de içinde data olan bir düğüm
		Node<Object> *prev; // geri
		
		// kurucu fonk
		Node(const Object& data=Object(), Node<Object> *next=NULL, Node<Object> *prev=NULL){
			this->data = data;
			this->next = next;
			this->prev = prev;
		}
};

#endif
