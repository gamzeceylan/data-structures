///// liste üzerinde gereçekleştirme ////


#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
using namespace std;

template <typename Object>
class Node{
	public:
		Object item;
		Node<Object> *next;
		
		Node(const Object& item, Node<Object> *next=NULL){
			this->item = item;
			this->next = next;
		}
		
	
};

/**	
	Liste ile gerçekleştirimde öncelikle karar vermen gereken push fonk
	nereye ekleyecek? başa mı sona mı? Dizide performans kaybı olmasın ve elemanlar
	sağa sola kaymasın diye en sona ekliyorduk. listede en sona eklediğin zaman çıkar
	fonk çalıştığında en sona kadar gidip çıkarması lazım. bağıl listede düğümün
	sona eklenmesi doğru bir yaklaşım değildir. başa eklemen lazım. ilk düğümün adresi
	elimizde olduğu için direkt eklersin, çıkaracağın zamanda onu çıkartırsın.
	
	
	!!! performans kaybı yaşamamak için ekleme/çıkarma dizide sondan, listede baştan yapılır.

	listede topOfStack ilk düğüm adresidir.
	
	topOfStack, dizide tam sayı türü, listede düğüm adresidir.
**/
template <typename Object>
class Stack{
	private:
		
		Node <Object> *topOfStack;
	
	public:
	// kurucu fonk. ortada bir düğüm olmayacak, çünkü veri yok
		Stack(){
			topOfStack=NULL;
		}
		
		bool isEmpty()const{
			return topOfStack == NULL;
		}
		
	
		
		// eleman ekleme
		void push(const Object& item){
			topOfStack = new Node<Object>(item, topOfStack);
		}
		
		// silme
		void pop(){
			// if(isEmpty())  throw hata
			
			Node<Object> *tmp = topOfStack;
			topOfStack = topOfStack->next;
			delete tmp; /// çöp oluşmasın
		}
		
		// çıkmak üzere olan eleman
		const Object& top()const{
			//  if(isEmpty())  throw hata
			return topOfStack->item;
		}
		

		void makeEmty(){
			while(!isEmpty()) pop();
			// pop tüm düğümleri delete yapar ve çöp kalmaz
		
		}
		
		~Stack(){
			makeEmty();
		}
};


// yıkıcı fonk ve makeEmty farkı nedir?
// makeEmty yığıt yapısını yok etmez, sadece elemanları yok eder.
// yığıt hala var. push diyip eleman ekleyebilirsin
// ama yıkıcı fonk çağrıldığı an yığıt bellekten kalkar. push, pop gibi fonksiyonları artık çağıramazsın

#endif