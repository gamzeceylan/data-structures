// ArrayList generic (şablon) bir yapıda olduğu için bütün kod burada olacak

#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP

#include <iostream>
using namespace std;

// her türden bir nesne kabul etmesi için template yapıya çevirmeliyiz
// C++ da object diye bir şey yok. amaç sadece onu çağrıştırması
// object yerine domates yazarsa domates türünden br dizi olur
template <typename Object>
class ArrayList{
	
	private: // private alabna diziyi arka plana almamız gerek
		
		// dizi türü object 
		// eğer items[] yazsaydık eleman sayısını şimdi vermemiz gerekirdi
		// ama eleman sayısını nereden bilelim. dizi adı da zaten ilk elemanın
		// adresini tutuyor. o zaman *items da yazabiliriz.
		Object *items;
		int length; // eleman sayısı
		int capacity; // max alabileceği eleman sayısı.
		// çünkü dizilerde genişleme olmaz. kendimiz yeni dizi oluşturarak yapıcaz
	
	
		// reserve, capacity dolunca yeni dizi oluşturacak
		// eğer public e yazarsan kontrol senden çıkar
		void reserve(int newCapacity){
			Object *tmp = new Object[newCapacity]; //newCapacity kadar yeni dizi
			
			// eleman eleman eskiyi yeniye kopyalamamız lazım
			for(int i=0; i<length; i++) tmp[i] = items[i];
			
			// eski dizinin heapteki yerini iade et
			delete [] items;
			
			// fonk kapandığında *tmp silineceğinden yeni diziyi elimizde tutamayız
			// *items da global de. yeni diziyi ona atan
			items = tmp;
			capacity = newCapacity;
			
			// 
		}
	
	public:
		// kurucu fonk
		ArrayList(){
			length=0;
			capacity=100; // kafamıza göre başlatabiliriz.
			items = new Object[capacity]; // oluşan dizi heapte olmalı dikkat et.
		}
		
		int size()const{ // get metodu
			return length;
		}
		
		bool isEmpty()const{ // dizi boş mu
			return size() == 0; // size=0 sa true döner, değilse false
		}
		
		// add liste sonuna ekler
		// elemanı sabit olarak alıyoruz çünkü amacımız veriyi değiştirmek değil
		//amacımız veriyi saklamak
		// ve referans üzerinden işlem yapıyoruz ki bellekte boşuna başka değişkenler oluşmasın
		//direkt bizim verimiz üzerinden işlem yapılsın
		void add(const Object& item){
			insert(length, item); // tekrar yazmaya gerek yok doğru indexler gönderirsen insert ekler
		}		
		
		// inset araya ekle metodur.
		// ama index dışarıdan geleceği için her şeyi düşünmemiz gerekir.
		// eğer length=1, index<0, index>length hata vermeli -> bu konumuz dışında am olmalı
		// ve dizi dolma problemi de var onu da kontrol etmelisin
		void insert(int index, const Object& item){
			// if(index<0 || index>length) hata
			
			// capacity dolu ise reserve() metoduyla yer açıcak
			// her zaman varolan capacity nin 2 katı kadar oluştursun
			if (length == capacity) reserve(2*capacity);
			
			// elemanı eklemek için sağa kaydırıcaz (belirtilen konum dahil)
			// en sondaki eleman index sayısı length-1
			// sondan taşımak istene indexe kadar sağa kayacak : i>=index
			for(int i=length-1; i>=index; i--) items[i+1]=items[i];
			
			items[index] = item; // kullanıcının verdiği yere item'ı ekiyoruz
			length++;
		} 
	
		// gönderdiğin elemanın indexini verir
		// indexof çağırıyorsan o elemanın orda olduğunu bilirsin
		// mantık olarak kullanıcı önce olup olmadığına bakmalıdır
		int indexOf(const Object& item){
			for(int i=0; i<length; i++){
				if(items[i]==item) return i;
			}
			// for biterse bulamadı demektir. hata fırlatırsın ama bu konumuz değil
			throw "HATA";
		}
	
		// fist sabit fonksiyondur ilk elemanı döndürür
		// listede eleman yoksa çağrılmaması gerekir
		/* NOT: const fonksiyon çünkü fonksiyon sabit bir değeri döndürüyor : ilk ve son değeri
		fonsiyon bir şey değiştirmiyor öyle bir görevi yok.
		*/
	
		const Object& first() const{
			if(isEmpty()) throw "HATA";
			
			return items[0];
		}
		
		const Object& last() const{
			if(isEmpty()) throw "HATA";
			return items[length-1];
		}
		
		// listenin hepsini temizelemek
		void clear(){
			length = 0;
			/*  - her şeyi uzunluk tan referans alıp yaptık.
				- örneğin insert, size, index metodu length e bakıp işlem yapıyor
				- ve biz kullanıcının arraylist içine ne attığından sorumlu değiliz.
				belki nesne attı bilemeyiz. kendisinin iade etmesi gerek. 
				- C++, dizi oluşturduğunda içine kendi rastgele sayılar atar. biz onları istediğimiz
				gibi değiştiririz. burada da kullanıcının sorumluluğunda
				- sen sadece kendi oluşturduklarını iade et
			*/
			// ama neden kendimi heapte oluşturuğumuz yeri iade etmedik anlamadım
			// acaba şey mi iade edersek bidaha içine eleman ekleyemeyiz. eleman eklemek için nesnenin
			//tekrar oluşturulması lazım. sanırım bu yüzden.
		}
		
		// verilen bir elemanı sil 
		// const Object& item ???? sanırım Object türünden bir item almalı ve bu arraylist in içinde olmalı??
		void remove(const Object& item){
			// hata kontorlunun yapılması lazım
			// zaten removeAt metodumuz var
			int index = indexOf(item); // indexi bul
			removeAt(index); // elemanı sil
		}
		
		// verilen indexten elemanı sil
		// elemanları sola kaydırıcaz
		void removeAt(int index){
			// if(index < 0 || index > length) throw hata
			
			// silecek indexten bir sonraki indexi sola kopyalıcaz
			for(int i=index+1; i<length; i--) items[i-1] = items[i];
			
			length--;
			// elemanlar hep sola kopyalanıcak ama en sonraki eleman fazlalık kalacak
			// ama zaten silme diye bir şey yok. length referansımız onu azaltıyoruz
		}
		
		// listede item elemanı var mı yok mu
		bool find(const Object& item){
			for(int i=0; i<length; i++) if(items[i] == item) return true;
			
			return false ; // elemanı bulamadıysa
		}
		// indexi verilen elemanı bulma
		const Object& elementAt(int index){
			// if(index<0 || index >= length) throw hata
			// eğer dizi ile yapmasaydık tek tek gezip elemanı bulmamız gerekirdi. 
			// ama burada dizi zaten belli [] ile elemana gidebiliyoruz
			return items[index];
		}
		
		// liste elemnalrını ekrana yazan fonksiyon
		friend ostream& operator<<(ostream& screen, ArrayList<Object>& right){
			screen << endl;
			for(int i=0; i<right.length; i++){
				screen << right.items[i] << " ";
			}
			screen << endl;
			return screen;
		}
		
		// yıkıcı fonksiyon. 
		// kendi heapte oluşturduklarını iade etmen lazım
		~ArrayList(){
			delete [] items;
		}
		
};
/*
- şablon yapı olduğu için başlık ve kaynak dosyalarını ayıramadık
- ama ödevde tek bir türden olacağı için bunları ayırman gerekir.

*/
#endif