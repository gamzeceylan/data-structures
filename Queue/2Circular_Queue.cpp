// dizi üzerinde

#include <iostream>
using namespace std;

template <typename T>
class Queue{
    private:
        T *items; // diziyi tutar
        int front; // ilk elemanın indexi
        int rear; // kuyruğun sonundaki elemanın indexi
        int length;
        int capacity;

        void reserve(int newCapacity){		
            T *temp = new T[newCapacity];

            for(int i=front, j=0; j<length; j++){
                temp[j] = items[i];
                i = (i+1)%capacity;
            }
            capacity = newCapacity;
            T *p = items; // bir önceki diziyi kaybetmeyelim, çöp oluşmasın
            items = temp; // dizi adları başlangıç adresini tuttuğundan bu atamayı yapabiliyoruz
            delete[] p;
            front = 0;
            rear = length-1;
        }

    public:
        Queue(){
            capacity = 5; // dizi kapasitesi öndecen belli olmalı
            front = -1;
            rear = -1;
            length = 0;
            items = new T[capacity]; // dizi heapte oluşur
        }

        bool isEmpty()const{
            return length == 0;
        }

        int count()const{
            return length;
        }

        void enqueue(const T& item){
            if(front == -1) front++; // ilk elemanı ekleme
            else if(length == capacity) reserve(2*capacity); // kapasite doldu mu?
        
            rear = (rear+1)%capacity;
            items[rear] = item;
                
            
            length++;
            cout << "Inserted " << item << endl;
        }

        void dequeue(){
            // eleman çıkarttığımızda en baştan çıkarmamız gerekir.
			// yani front'un yeri değişir. ve eleman eklediğimiz zamanda en sona ekleriz
			// örneğin 0. indexteki eleman çıkarsa front = 1 yapmalıyız. yani silmeyiz, indexi değiştirriz (diziyi çalışma zamanında nasıl silicen zaten)
            // bu yüzden front ve back tutarız
            if(isEmpty()) cout << endl << "Queue is empty" << endl;
            else if(front == rear){ // tek eleman varmış o zaman en basa döneriz.
                front = -1;
                rear = -1;
            }
            else if(front < rear) front = (front+1)%capacity; // dizide silme yapamayız. frontu bir öne kaydırıyoruz ve diğer elemanla artık ilgilenmiyoruz
            length--;
        }

        void clear(){ // dizi hafıda kalır onun yerine asagıdaki değisimleri yaaprız
            front = -1;
            rear = -1;
            length = 0;
        }

        void display(){
            if(isEmpty()) cout << "Queue is empty" << endl;
            else{
                for(int i=front; i<=rear; i++)
                    cout << items[i] << " ";
            }
        }

        const T& peek()const{
            if(isEmpty()) throw "Queue is empty";
            return items[front];
        }

        ~Queue(){
            delete[] items;
        }

};

// test 2 için
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
		
};
int main(){
    /* //test 1
    Queue<int> *sayilar = new Queue<int>();

    // kapasitemiz 5
    sayilar->enqueue(5);
    sayilar->enqueue(7);
    sayilar->enqueue(4);
    sayilar->enqueue(3);
    sayilar->enqueue(9);
    sayilar->enqueue(0);

    cout << endl << sayilar->peek() << endl; // 5 dönmeli
    sayilar->dequeue(); // 5 çıkmalı
    cout << sayilar->peek() << endl; // 7 dönmeli
    sayilar->dequeue(); // 7 çıkmalı

    sayilar->enqueue(90);

    cout << endl;

    sayilar->display(); // 90 4 3 9 0

    delete sayilar;
    return 0;
    */


   // test 2
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
	
	
	return 0;

}
