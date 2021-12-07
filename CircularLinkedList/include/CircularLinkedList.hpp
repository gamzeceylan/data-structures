#ifndef CIRCULARLINKEDLIST_HPP
#define CIRCULARLINKEDLIST_HPP

#include "Iterator.hpp"

///////////
// Tek yönlü bağıl listen farkı son düğümün güncellenmesi
// ad ve insert değişicek
// son düğümün silinmesinde sıkıntı yok. 
// sıkıntı ilk düğümün silinmesi. çünkü head onu tutuyor. güncellemezsen ilerisi silinmiş düğümü gösterir
////////////


template <typename Object>
class CircularLinkedList{
	private:
		Node<Object> *head;
		int size; 
		Iterator<Object> FindPrevByPosition(int position){
			// if(position < 0 || position > size) throw hata
			int index = 0;
			Iterator<Object> iterator(head);
			// burda da hasNext e gerek yok. zaten bie şekilde o konuma gelecek
			while(position != index){ 
				iterator.next();
				index++;
			}
			return iterator;
		}
		
		// head'e göre lastNode
		void updateLastNode(){
			Node<Object> *lastNode = FindPrevByPosition(size).current;
			lastNode->next = head->next;
		}
		
	public:
	
		CircularLinkedList(){
			head = new Node<Object>(); 
			size = 0;
		}

		bool isEmpty()const{

			return head->next == NULL;
		}
		
		int Count()const{
			return size;
		}
		

		void add(const Object& item){
			insert(size, item);
		}
		

		void insert(int index, const Object& item){
			Iterator<Object> iterator = FindPrevByPosition(index);
		
			iterator.current->next = new Node<Object>(item, iterator.current->next);
			size++;
			
			// head'e göre son. yoksa son diye bir şey yok.
			if(index == 0) updateLastNode(); // son düğümün güncellenmesi gerek
		}
		

		const Object& first()const{
			// if(isEmpty()) throw hata;
			return head->next->item;
		}
		

		const Object& last(){
	
			return FindPrevByPosition(size).getCurrent();
	
		}

		int indexOf(const Object& item){
			int index=0;
			for(Iterator<Object> iterator(head->next); index<size; iterator.next()){

				if(iterator.getCurrent() == item) return index;
				index++;
			}
			throw "HATA";
		}

		const Object& elementAt(int index){
			// if(index < 0 || index >= size) throw hata;
			Iterator<Object> iterator = FindPrevByPosition(index); 
			return iterator.current->next->item;

		}
		

		bool find(const Object& item)const{
				for(Iterator<Object> iterator(head->next); iterator.hasNext(); iterator.next()){

				if(iterator.getCurrent() == item) return true;
	
			}
			return false;
		}
		

		void remove(const Object& item){
			int index = indexOf(item); 
			removeAt(index);
			
		}

		void removeAt(int index){
			// if(index < 0 || index >= size) throw hata;
			Iterator<Object> iterator = FindPrevByPosition(index);
			Node <Object> *del = iterator.current->next;
			iterator.current->next = iterator.current->next->next;
		
			delete del;
			size--;
			
			// baştaki düğüm 
			if(size !=0 && index == 0) updateLastNode();
		}
		

		friend ostream& operator<<(ostream& screen, CircularLinkedList<Object> &right){
			// artık hasNext() diye bir şey yok. zaten hepsi next. yeni index tanımla
				int index=0;
				for(Iterator<Object> iterator(right.head->next); index<right.size; iterator.next()){
					screen << iterator.getCurrent()<<" -> ";
					index++;
				}
				screen << "NULL" << endl;
				return screen;
		}
		///////////
		// avantaj! geriye doğru gidebildiğin için verilen konumdan tüm listeyi yazdırabilirsin
		//////////
		void printAllFromPosition(int index){
			Iterator<Object> iterator = FindPrevByPosition(index);
			int ind=0;
			for(iterator.next(); ind<size; iterator.next(), int++){
				cout << iterator.getCurrent()<< " -> ";
			}
			cout<< endl;
		}
		

		void clear(){
			while(!isEmpty())
				removeAt(0); 
		}
		~CircularLinkedList(){
			clear();
			
			delete head;
		}
};


#endif