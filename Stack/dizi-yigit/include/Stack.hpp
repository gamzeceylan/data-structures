///// dizi üzerinde gereçekleştirme ////


#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
using namespace std;

template <typename Object>
class Stack{
	private:
		// diziyi arka plana koyuyoruz ki giriş çıkış sınırlansın. o yüzden private
		// ekle diyince en sona, çıkart diyince en sondan çıkarıcak -> son giren ilk çıkar
		Object *items;
		int  topOfStack; // en son eklenen elemanın indexini tutar
		int length; // uzunluk
		int capacity; // kapasite
		
		// kafalarına göre çağırmamaları için reserve private alanda olmalı
		// dizi boyutunu büyütme
		void reserve(int newCapacity){
			Object *tmp = new Object[newCapacity];
			for(int i=0; i<length; i++) tmp[i] = items[i]; // koypyalama
			
			Object *p = items;
			items=tmp;
			delete[] p;
			capacity = newCapacity;
			
		}
	
	public:
	// kurucu fonk
		Stack(){
			capacity = 100;
			items = new Object[capacity];
			length = 0;
			
			// topOfStack = 0 dersen 1 tane eleman eklenmiş olur ve çıkmak üzere olan eleman 0. indexte olur
			topOfStack = -1; //-1 index olmadığı için -1 den başlayabilir
		}
		
		bool isEmpty()const{
			// topOfStack ya da length e bakarak anlayabilirsin
			return length==0; 
		}
		
		// yığıt problerinde yığıtta kaç eleman olduğu sorulmaz.
		// genellikle eklenmez. ama kendin uygulamana göre ekleyebilirsin
		// mesela kimse sana labirente kaç taş attın demez. çünkü amacımız bu değil
		
		
		// eleman ekleme
		// elimizde bir dizi olduğu için dolma durumunu kontrol etmen lazım
		void push(const Object& item){
			// dolduysa yer açmamız gerek
			if (length == capacity) reserve(2*capacity);
			
			// eleman ekleyecek yer var 
			/** NOT : eleman ekleme/silme olayını diziyi kaydırarak yapabilirsin
			bu maliyeti azaltır. veri yapısını en az maliyetli tasarlaman laızm.
			en sona eklersin, sildiğin zamanda length-- yaparsın. ve topOfStack en son 
			kalan indexi gösterir. referans aldığımız yer length olmalı.
			**/
			
			topOfStack++;
			items[topOfStack] = item;
			length++;
		}
		
		// silme
		void pop(){
			// if(isEmpty())  throw hata
			
			// son indexteki eleman bizi ilgilendirmez.
			topOfStack--;
			length--;
			
			// eleman eklediğinde ise ordaki elemanın üstüne eleman yazılır
		}
		
		// çıkmak üzere olan eleman
		const Object& top()const{
			//  if(isEmpty())  throw hata
			return items[topOfStack];
		}
		
		// yığıtı temizler. yığıtı yok etmez, elemanları siler
		// (dizide eleman silme yok salaklaşma zaten dizi kuralı yok. delete ile silemezsin)
		void makeEmty(){
			topOfStack = -1;
			length = 0;
			// içindeki elemanlar yine bizi ilgilendirmez
			// push yaptığında yine uzunluk 1 artar, topOfStack 0 olur, gönderdiği eleman 0. indexe yerleşir
			
		}
		
		~Stack(){
			delete[] items; // hiç eleman eklemese bile ortada bir dizi var.
		}
};



#endif