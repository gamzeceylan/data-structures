// liste üzerinde öncelikli kuyruk

#include <iostream>
using namespace std;

template <typename T>
class Node{
    public:
        T item;
        Node<T> *next;

        Node(T item = T(), Node<T> *next=NULL){
            this->item = item;
            this->next = next;
        }

};

template <typename T>
class Queue{
    private:
        Node<T> *front; // ilk düğüm
        Node<T> *back; // son düğüm
        int length; // eleman sayısı kuyrukta sorulabilir
        // artık sınırlanan bir kapasitemiz yok

        // verisi büyük olanı bulup öncesine yerleşmek için
        Node<T>* previousMaxNode(){ 
            Node<T> *prev=NULL;
            Node<T> *tmp = front;
            T max= front->item;

            while(tmp->next !=NULL){
                if(tmp->next->item > max){
                    max = tmp->next->item;
                    prev = tmp;
                }
                tmp = tmp->next;
            }
            return prev;
        }
    public:
        Queue(){
                front = back = NULL;
                length = 0;

        }
            
        int Count()const{
                return length;
        }
            
        bool isEmpty()const{
                return length==0;
        }
        void enqueue(const T&item){
			Node<T> *last = new Node<T>(item);
			// eğer ilk düğümse front ta o düğümü gösterir
			if(isEmpty()) front = back = last;
			else{
				// frontun hareket etmesine gerek yok zaten front onu göteriyor
				back->next = last;
				back = back->next;
			}
			length++;
		}

        // silme işlemi (baştan)
		void dequeue(){
			// if(isEmpty()) throw hata
			
			// front silinecek
			Node<T> *tmp = front;
			front = front->next;
			delete tmp;
			length--;
			
			// eğer son düğüm çıkarılırsa front ve back aynı düğümü gösteriyor.
			// eğer son düğüm çıkarılırsa front nullı göstericek ama back iade edilmiş bir düğümü göstericek
			// peki bu sorun mu? eklerken zaten isEmpty ise back değiştirilicek. hayır sorun değil. tm.
			
		}
        void dequeueMax(){
			// aradan, sonran çıkma ihitmali var
			// o zaman bir önceki düğüme yerleşicek fonksiyonu yazmamız gerek -> previousMaxNode
			Node<T> *prev = previousMaxNode();
			Node<T> *tmp;
			if(prev == NULL) dequeue(); // eğer prev==NULL sa ilk düğümdür ve normal çıkartma işlmei yaparız
			else{ // aradan veya sondan
				if(prev->next==back) back = prev; // son eleman siliniyor, back i de güncelliyoruz
				tmp=prev->next;
				prev->next = prev->next->next;
				delete tmp;
				length--;
				
			}
		
		} 
        void clear(){
			// tüm düğümler silinmeli
			while(!isEmpty()) dequeue();
		}
		
		// çıkmak üzere olan elemanı getirir
		T& peek()const{
			// if(isEmpty()) throw hata
			return front->item;
		}
		
		// çıkmak üzera olan max elemanı getirir
		T& peekMax(){
			Node<T> *prev = previousMaxNode();
			if(prev==NULL) return peek();
			return prev->next->item;
		}
		
		~Queue(){
			clear();
		}
};



class Kisi{
	public:
		string isim;
		double kilo;
		Kisi(){
			isim="";
			kilo=0;
		}
		Kisi(string isim, double kilo){
			this->isim = isim;
			this->kilo = kilo;
		}
		friend ostream& operator <<(ostream& ekran, Kisi& sag){
			ekran<< sag.isim << " " << sag.kilo << endl;
			return ekran;
		}
		
		bool operator> (Kisi& sag){
			return this->kilo > sag.kilo;
		}
		
};

int main(){
	// normal kuyruk testi
	// normal kuyruk ve öncelikli kuyruk farkı 2 tane max fonksiyonu
	/*
	Queue<Kisi*> *kisiler = new Queue<Kisi*>(); // bunu kuyruk iade etmez. kuyruk diziyi iade eder. ama dizidede her biri heap te oluşmuş nesneler var
	kisiler->enqueue(new Kisi("Mehmet", 85));
	kisiler->enqueue(new Kisi("Ceren", 35));
	kisiler->enqueue(new Kisi("Hamza", 70));
	
	delete kisiler->peek();
	kisiler->dequeue(); // eğer burdan önce bir delete işlemi yapmazsan çöp oluşur
	// çünkü içine hep new ile oluşturduğumuz adresleri atıyoruz
	
	cout << *kisiler->peek()<< endl;
	
	// kalan 2 kişi çöp olmasın diye
	while(!kisiler->isEmpty()){
		delete kisiler->peek();
		kisiler->dequeue();
	}
	
	
	
	delete kisiler;
	*/
	
	
	// öncelikli kuyruk testi
	// farkı anlamadım
	Queue<Kisi> *kisiler = new Queue<Kisi>();
	Kisi *k1 = new Kisi("Mahmet", 85);
	Kisi *k2 = new Kisi("Ceren", 35);
	Kisi *k3 = new Kisi("Hamza", 90);
	
	kisiler->enqueue(*k1);
	kisiler->enqueue(*k2);
	kisiler->enqueue(*k3);
	
	kisiler->dequeue();
	cout << kisiler->peek()<< endl; // içerisinde diretk nesne olduğundan * koymaya gerek yok
	// cout << *kisiler->peekMax()<< endl;
	/* peekMax > operatoru ile direkt kisi nesnelerini karşılaştırıyor ama şuan
	ne karşılaştıracağını bilmiyor. Kisi sınıfına > operatorunu yazalım*/
	
	cout << kisiler->peekMax()<< endl;
	
	// elimizde adresler olduğu için direkt çıkarabiliriz
	delete k1;
	delete k2;
	delete k3;
	delete kisiler;
	
	return 0;
}