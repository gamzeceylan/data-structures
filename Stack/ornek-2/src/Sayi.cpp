#include "Sayi.hpp"
		
		// yigit kullanılacağı yer
		string Sayi::TabanDonustur(){
			// degeri bölerek küçültücez. ama sınıfın elemanlaırnı parçalamaman laızm
			// o yüzden kendimiz bir sayi tanımlayalım
			int sayi = deger;
			string rakamlar = "0123456789ABCDEF";
			string yeniSayi = "";
			
			// yığıta kalanları->int atıcaz
			Stack<int> *yigit = new Stack<int>();
			
			while(sayi>0){ // bir süre sonra bolüm 0 olacak
				int kalan = sayi%taban;
				yigit->push(kalan);
				sayi = sayi/taban; // işleme girenlerin int olmasına dikkat et. sonuc int olmalı
			}
			while(!yigit->isEmpty()){
				// string birleştirme 
				yeniSayi = yeniSayi + rakamlar[yigit->top()];
				// abcdef de yazabilmesi için rakamları dizide tuttuk
				// çünkü 16 lık tabana çevirmek isterse kalan 15 olabilir. o da F
				yigit->pop();
			}
			
			delete yigit;
			return yeniSayi;
		}
		
		Sayi::Sayi(){
			cin>>*this; // sayi yi ve tabanı aldıktan sonra bana direkt onları dönüştür demek
			// friend >> çağrılacak
			
			donusturulen = TabanDonustur();
			
		}
		int Sayi::Taban10Deger()const{
			return deger; // saten 10 luk tabanda alıyoruz
		}
		
		// aşağıdakiler Sayi sınıfının değil
		ostream& operator<<(ostream& ekran, Sayi& sag){ // akrana yazma
			ekran<< "("<< sag.deger<<")10 = (" << sag.donusturulen <<")"<< sag.taban << endl;
			return ekran;
		
		}
		istream& operator>>(istream& input, Sayi& sag){ // kullanıcıdan nasıl alıcak onu söylicez
			cout << "Sayi : ";
			input >> sag.deger;
			cout << "Donusturulecek taban : ";
			input >> sag.taban;
			return input;
		
		}

// friend ler sadece başlık dosyasında olur