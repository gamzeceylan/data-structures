#include "ArrayList.hpp"
#include <cstdlib>

int main(){
	// nesneleri, nesne içerisindeki nesneleri, dizi içindeki her bir nesne
	//mutlaka heapte oluşturmalısın
	
	// isimler sadece string alır.
	//Arraylist sınıfında tüm Object lerin yerine string yazılır.
	ArrayList<string> *isimler = new ArrayList <string>();
	// ArrayList<double> *sayilar = new ArrayList <double>(); -> sayilar sadece double alır
	
	int sec=0;
	string isim;
	int konum=0;
	do{
		system("CLS");
		//system cls cmd ye cls komutunu gönderir. ama bu taşınabilir bir kod değildir
		// windows için böyledir. linuxta başla bir şeydir
		
		cout << "1. isim Ekle" << endl;
		cout << "2. isim Sil" << endl;
		cout << "3. Konumdan isim sil" << endl;
		cout << "4. Konuma isim ekle" << endl;
		cout << "5. Konum bul" << endl;
		cout << "6. isim sayisi" << endl;
		cout << "7. ilk isim" << endl;
		cout << "8. son isim" << endl;
		cout << "9. isimleri Listele" << endl;
		cout << "10. isimleri temizle" << endl;
		cout << "11. konumdaki ismi getir" << endl;
		cout << "12. cikis" << endl;
		cin >> sec;
		
		switch (sec){
			case 1:
				cout << "Isim : ";
				cin.ignore();
				 /*
					direkt cin le alırsan kullanıcı iki isim girerse boşluga kadar olan kısmı alır ikinci kelimeyi almaz.
					tüm satırı almak için getline() kullanman gerek.
					getline(cin, isim) -> cin konsoldan al, isim'e ata 
					cin.igrnore -> görmezden gel. eğer gelemzse otomotik olarak çalıştırabilir ve bir yukarıdaki şeyi alabilir.
					(sanırım) böyle yazınca sa konsola yazılacak şeyi bekliyor.
				 */
				getline(cin, isim);
				isimler->add(isim);
			break;
			case 2:
				cout << "Isim : ";
				cin.ignore();
				getline(cin, isim);
				isimler->remove(isim); //kullanıcının isim giridğini düşünüyoruz yoksa hata fırlatmamız gerkeir
			break;
			case 3:
				cout << "Konum : ";
				cin >> konum;
				isimler->removeAt(konum); // konumun doğru girildiğini varsayıyoruz
			break;
			case 4:
				cout << "Konum : ";
				cin >> konum;
				cout << "Isim : ";
				cin.ignore();
				getline(cin, isim);
				isimler->insert(konum, isim);
			break;
			case 5:
				cout << "Isim : "; // ismin doğru girildiğini varsayıyoruz
				cin.ignore();
				getline(cin, isim);
				cout << "Konumu : " << isimler->indexOf(isim) << endl;	
				
				// ekranda enter'a basana kadar bekletmek için
				cin.ignore();
				cin.get();				
			break;
			case 6:
				cout << "Isim sayisi : " << isimler->size() << endl;	
				cin.ignore();
				cin.get();	
			break;
			case 7:
				cout << "Isim sayisi : " << isimler->first() << endl;	
				cin.ignore();
				cin.get();	
			break;
			case 8:
				cout << "Isim sayisi : " << isimler->last() << endl;	
				cin.ignore();
				cin.get();	
			break;
			case 9:
				cout << "Isimler : "<< endl;
				cout << *isimler;
				cin.ignore();
				cin.get();	
				/*
					NOT : listeye isim yerine nesne de ekleyebilirdin. kullanıcı listeyi göster
					dediğinde bizim yazdığımız kod hata verir. çünkü nesne olursa ne yazacağını bilemez
					bu kütüphaneyi yazanın hatasıdır.
				*/
			break;
			case 10:
				isimler->clear();
			break;
			case 11:
				cout << "Konum : ";
				cin >> konum;
				cout << isimler->elementAt(konum)<< endl;
				cin.ignore();
				cin.get();
			break;
			case 12:
			break;
			default:
			
			// cin.get ve cin.ignore araştır
			
				cout << "Hatali Secim" << endl;
				// cin.get();
				cin.ignore(); // sanırım enter'a bastıktan sonra devam ettirmek için
				cin.get(); // programı sonlandırmak için
			break;
		}
		
	}while(sec != 12);
	
	
	
	delete isimler; // sen oluşturuyorsun sen iade et.
	return 0;
}

/*
- not : yukarıdaki cout cin birbirini çok tekrar etti normalde fonksiyonda yazman lazım
çünkü mesela isimden önce - girsin istersen 11 yerde değiştirmen lazım.

*/

/*
NOT : veri yapılarının amacı hangi problemde hangi çözümü kullanmak daha avatantajlı
olur bunu bilebilmek. ArrayList ve LinkedList ikisinin de ekle, kaldır metodları varıdr
ama probleme göre birini kullanmak daha avantajlıdır. işte ders bunu öğretmek için vardır.
dersi sadeced geçmek için alırsan bitirme projende ya da gerçek hayattaki projende bu farkları 
göremezsen iyi bir programcı olamazsın. kodu yazarsın sonra yavaş çalışıyorsa kullandığın yapılarda 
aradaki farkı bilmiyorsun demektir. 1 milyon verin var ve hep araya ekliyor sen ArrayList kullandıysan
programın aşırı yavaş çalışır ve ortaya büyük sorun çıkar. o noktada bağıl liste kullanman 
gerekir. iyi bir programcı ol 

Her dersin bir amacı vardır. derslerine güzel çalış, kendin üzerine kat ve iyi bir mühendis ol :)

*/