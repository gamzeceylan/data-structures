#include "Postfix.hpp"

// infix postfix donusumuyle ilgili kod

int main(){
	
	string infix;
	cout << "infix ifade : ";
	cin >> infix;
	Postfix *postfix = new Postfix(infix);
	cout << "Postfix : " << *postfix << endl;
	cout << "Sonuc : " << postfix->Hesapla()<< endl;
	
	delete postfix;
	return 0;
	
	// (42-2)*3 gibi bir input vermen gerek
	
	
	// hata var nerde var bilmiyorum bulamadım
	// ve postfix-infix dönüşümlerine bak sınavda sorarlarmış
	// dersin son 3 dk sında örnek anlatıyor izlersin
	
	// infixten posfixe yığıta sadece opreator atılır, sayı direkt postfixe eklenir
	// postfix hesaplamada yığıta sadece sayılar atanır operator gelince iki sayıyı çıakrtırsın 
		//ikinci çıkarıdğın 1. sayı olur, işlemi yapıp yığıta atarsın. en son yığıtta kalan sonuçtur
		
	// sol parantez gelince kontrolsüz şekilde yığıta ekliyoruz, sağ p gelirse solu p görene kadar tüm her şeyi çıakrıyoruz postfixe ekliyoruz solu da silmiş oluyoruz
}	// sağ p yığıta ya da postfixe eklenmez. sadece solu çıkartman gerektiğini söyler.

