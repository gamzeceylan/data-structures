#ifndef _LINKEDLIST_HPP
#define _LINKEDLIST_HPP

#include "Node.hpp"
#include <iostream>


class LinkedList{
    public:
        Node *head; // liste basimizi gosteren dugum
        int size; // eleman sayisi 
        /*
			eleman sayısını tanımlamasan da düğümlerde gezerek bu sayısı bulabilirsin.
			ama her defasında bir sürü düğümü gezip performans kaybı yaşamaya gerek yok.
			eleman her eklendiğinde size'ı bir arttır. 
		*/

        Node* FindPrevPosition(int position); // bir öncesine yerleşiriz çünkü bunu kullanıcaz
    
    public:
        LinkedList();
        bool isEmpty()const; // Is the list empty or full? 
        int count()const; // Return the total number of elements in the list
        void add(const int& data); // Adds an element to the end of the list
        void insert(int index, const int& data); // Adds an element to given index
        const int& first()const; // Returns the first element
        const int& last(); // Returns the last element
        int indexOf(const int& data); // Returns the index of the entered data
        const int& elementAt(int index); // Returns the elemnet at the entered index
        bool find(const int& data)const; // Returns whether the entered data is in the list
        void removeAt(int index); // Deletes an element from the entered index
        void remove(const int& data); // Deletes the entered data from the list
        void clear(); // Deletes the list (deleting the nodes one by one)
        ~LinkedList();

       //friend std::ostream& operator<<(std::ostream& screen, LinkedList<T>& data);




};

#endif