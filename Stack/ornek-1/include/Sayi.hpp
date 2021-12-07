// 10 luk tabanı çevirme

#ifndef SAYI_HPP
#define SAYI_HPP

#include "Stack.hpp"

class Sayi{
	
	private:
		int deger;
		int taban;
		string donusturulen; // 16'lık tabana çevirdiğinde a b vs gelebilir. o yüzden string
	
		string TabanDonustur();
	
	public:
		Sayi();
		int Taban10Deger()const;
		
		friend ostream& operator<<(ostream&, Sayi&); // akrana yazma
		friend istream& operator>>(istream&, Sayi&); // kullanıcıdan nasıl alıcak onu söylicez
};


#endif