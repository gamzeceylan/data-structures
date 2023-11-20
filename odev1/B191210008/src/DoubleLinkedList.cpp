/**
* @file DoubleLinkedList.cpp
* @description DoubleLinkedList sınıfının fonksiyon gövdelerini yazdığım kaynak dosya.
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

	// istenen indexteki düğümü bulan fonksiyon
		Node* DoubleLinkedList :: FindByPosition(int index){	
			Node *tmp = head;
			int i=0;
			for(Node *itr = head; itr->next != NULL && i != index; itr=itr->next, i++){
				tmp = tmp ->next;
			}
			return tmp;
			
		}
		
	// sınıfın kurucu fonksiyonu
		DoubleLinkedList :: DoubleLinkedList(){
			head=NULL;
			size = 0;
		}

	// listeeki toplam eleman sayısını döndürüyor
		int DoubleLinkedList :: Count()const{
			return size;
		}
		
	// listede eleman olup olmadığın kontrol ediyor
		bool DoubleLinkedList :: isEmpty()const{
			return size==0;
		}
		
	// liste sonuna eleman ekliyor
		void DoubleLinkedList :: add(const int& data){
			insert(size, data);
		}
		
	// gönderilen datayı istenen indexe ekliyor
		void DoubleLinkedList :: insert(int index, const int data){
			if(index == 0){
				head = new Node(data, head, NULL);
				if(head->next != NULL){
					head->next->prev = head;
				}
			}
			else{
				Node *tmp = FindByPosition(index);
				if(tmp->next != NULL){
					tmp->prev = new Node(data, tmp, tmp->prev);
					tmp->prev->next = tmp->prev;
				}
				else{
					tmp->next = new Node(data, NULL, tmp);
					
				}
				
			}
			size++;
			
		}

	// istenen indexteki datayı döndürüyor
		const int& DoubleLinkedList :: elementAt(int index){
			if(index == 0)
				return head->data;
			return FindByPosition(index)->data;
		}
		
		
	// listeyi ters çeviren fonksiyon
		void DoubleLinkedList :: reverse(){ 

			Node *itr = head; 
			Node *temp;
			Node *tmpL = FindByPosition(size);
			for(int i=0; i<size; i++){
				temp = itr->next;
				itr->next = itr->prev;
				itr->prev = temp;
				itr = temp;
			}
			head=tmpL;
		}
		
	// verilen konumdan eleman siliyor
		void DoubleLinkedList :: removeAt(int index){
			Node *del;
			if(index == 0){
				del = head;
				head = head->next;
			
				if(head != NULL) head->prev = NULL;
			}
			else{
				Node *tmp = FindByPosition(index);
				del = tmp;
				tmp->prev->next = tmp->next;
				if(tmp->next != NULL)
					tmp->next->prev = tmp->prev;
			}
			delete del;
			size--;
		}
		
	// listeyi temizliyor
		void DoubleLinkedList :: clear(){
			while(!isEmpty())
				removeAt(0);
		}
		
	// gönderilen indexe göre iki listenin karşılıklı elemanlarını değiştiriyor
		void  DoubleLinkedList :: swap(int index, DoubleLinkedList*& list1, DoubleLinkedList*& list2){
			Node *temp1 = list1->FindByPosition(index);
			Node *temp2 = list2->FindByPosition(index);
			
			if(index == 0){
				Node *head11 = list1->FindByPosition(index+1);
				Node *head22 = list2->FindByPosition(index+1);
				temp1->next = head22;
				head22->prev = temp1;
				
				temp2->next = head11;
				head11->prev = temp2;
				list1->head =temp2;
				list2->head = temp1;
			}
			else if (index == list1->Count()-1){
				Node *head1 = list1->FindByPosition(index-1);
				Node *head2 = list2->FindByPosition(index-1);
				
				head1->next = temp2;
				temp2->prev = head1;
				head2->next = temp1;
				temp1->prev = head2;
			}
			else{
				Node *head11 = list1->FindByPosition(index+1);
				Node *head22 = list2->FindByPosition(index+1);
				Node *head1 = list1->FindByPosition(index-1);
				Node *head2 = list2->FindByPosition(index-1);
				
				
				head1->next = temp2;
				temp2->prev = head1;
				
				temp2->next = head11;
				head11->prev= temp2;
				
				head2->next = temp1;
				temp1->prev = head2;
				
				temp1->next = head22;
				head22->prev= temp1;
			}

		}

	// yıkıcı fonksiyon
		DoubleLinkedList ::~DoubleLinkedList(){
			clear();
		}
		
	// listenin elemanlarını ekrana yazdırıyor
		ostream& operator << (ostream& screen, DoubleLinkedList& right){
			for(Node *itr=right.head; itr != NULL; itr = itr->next){
				screen << itr->data;
			}
			return screen;
		}