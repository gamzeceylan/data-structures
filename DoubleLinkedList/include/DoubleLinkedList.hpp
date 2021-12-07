#ifndef DOUBLELINKEDLIST_HPP
#define DOUBLELINKEDLIST_HPP

#include "Node.hpp"


template <typename Object>
class DoubleLinkedList{
	private:
		Node<Object> *head; //ilk düğümün adresini tutar
		int size; 
		
		Node<Object> *FindPrevByPosition(int index){
			Node<Object> *prv = head; //head den başladık. headın öncesi yok.
			int i=1; // bu fonk çağrıldığı yerde 0 kontrolu yaptık o yüzden 1 den başlasın.
			for(Node<Object> *itr = head; itr->next != NULL && i != index; itr=itr->next, i++){
				prv = prv ->next;
			}
			return prv;
		}
		
	public:
	
		DoubleLinkedList(){
			//head = new Node<Object>(); 
			// boşta düğüm oluşturmuyoruz. ortada veri yoksa head null'ı gösterir
			head=NULL;
			size = 0;
		}

		bool isEmpty()const{
		// aşağıdaki de olur
			// return head->next == NULL;
			return size == 0;
		}
		
		int Count()const{
			return size;
		}
		

		void add(const Object& item){
			insert(size, item);
		}
		

		void insert(int index, const Object& item){
			// if(index < 0 || index > size) throw hata
				
			/*
				- araya ya da sona eklemeyi kontrol etmemize gerek yok
				- ama başa eklemeyi kontrol etmeliyiz. çünkü head gerçek veriyi tutuyor
			
			*/
			if(index == 0){ // ilk başsa
				head = new Node<Object>(item, head); // varsayılan olarak head in prev i nulla a atanır
				
				// head->next == NULL ilk düğüm eklenmiş
				if(head->next != NULL) head->next->prev=head;
			}
			else{ // en son ya da orta
				// bir önceye yerleşmemiz gerek
				
				//en sona eleman eklenirse çalışır aşağısı çalışır
				Node<Object> *prv = FindPrevByPosition(index);
				prv->next = new Node<Object> (item, prv->next, prv); // daha düğüm oluşurken ilerisi ve gerisi atanmış şekilde oluşuyor
				
				// araya eleman eklenirse çalışır
				if(prv->next->next != NULL)
					prv->next->next->prev = prv->next;
				
			}
			size++;
		}
		

		const Object& first()const{
			// if(isEmpty()) throw hata;
			return head->data;
		}
		

		const Object& last(){
	
			return FindPrevByPosition(size)->data;
	
		}

		int indexOf(const Object& item){
			int index=0;
			for(Node<Object> *itr=head; itr!=NULL; itr=itr->next){

				if(itr->data == item) return index;
				index++;
			}
			throw "HATA";
		}

		const Object& elementAt(int index){
			if(index==0) return head->data;
			return FindPrevByPosition(index)->next->data;

		}
		

		bool find(const Object& item)const{
			for(Node<Object> *itr=head; itr!=NULL; itr=itr->next){

				if(itr->data == item) return true;
			}
			return false;
		}
		

		void remove(const Object& item){
			int index = indexOf(item); 
			removeAt(index);
			
		}

		void removeAt(int index){
			// if(index < 0 || index >= size) throw hata;
			Node<Object> *del; 
			if(index == 0){
				del = head;
				head = head->next;
				delete del;
				if(head != NULL) head->prev =NULL;
			}
			else{ // aradan veya sondan
				Node<Object> *prv = FindPrevByPosition(index);
				del = prv->next;
				prv->next = del ->next;
				
				//aradan siliniyorsa aşağını çalışır
				if(del->next != NULL)
						del->next->prev = prv;
			}
			size--;
			delete del;
		}
		

		friend ostream& operator<<(ostream& screen, DoubleLinkedList<Object> &right){
			for(Node<Object> *itr=right.head; itr!=NULL; itr=itr->next){
				screen << itr->data << " -> ";
			}
			screen <<endl;
			return screen;
		}
		///////////
		// avantaj! geriye doğru gidebildiğin için verilen konumdan tüm listeyi tersine yazdırabilirsin
		//////////
		void printNodesFromPositionInReverseOrder(int index){
			// if(index < 0 || index >= size) throw hata;
			for(Node<Object> *itr = FindPrevByPosition(index+1); itr!=NULL; itr=itr->prev){
				cout << itr->data << " <-> ";
			}
			cout << endl;
		}
		/////
		// avantaj! tersine de yazdırabilirsin
		/////
		void printReverseOrder(){
			// if(index < 0 || index >= size) throw hata;
			printNodesFromPositionInReverseOrder(size-1);
		}

		void clear(){
			while(!isEmpty())
				removeAt(0); 
		}
		
		~DoubleLinkedList(){
			clear();
			
			// delete head; zaten boşta düğüm yok
		}
};


#endif