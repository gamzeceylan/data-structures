// özyineleme çalış

#ifndef BST_HPP
#define BST_HPP

#include <iostream>
#include <cmath>
using namespace std;

// C++ da struct ile class'ın tek farkı struct belirtilmediği sürece içine yazılan her şey public,
// class belirtilmediği sürece içine yazılan her şey private tır.

template <typename Nesne>
struct Dugum{
	Nesne veri;
	
	// bir düğüm aşağıda olan hem sağ hem sol çocuğu gösterir. bağıl listedeki next pre gibi
	Dugum<Nesne> *sol; //sol çocuk
	Dugum<Nesne> *sag; //sağ çocuk
	
	// her düğüm 3 bölümden oluşur. veri, sol cocuk, sağ çocuk
	Dugum(const Nesne &vr, Dugum<Nesne> *sl = NULL, Dugum<Nesne> *sg = NULL)
	{
		veri = vr;
		sol = sl;
		sag = sg;
	}
};

template <typename Nesne>
class BST
{
private:
	Dugum<Nesne> *root; // kök düğüm. bütün düğümlere bu düğümden erişebiliriz
	
	// dışarıdan çağrılmaması gerekir.
	// *& kullanmalıyız. root dediğimiz şey bir pointerdir. 
	// sadece *alt_Dugum yazarsak da çalışır ama biz sürekli bir düğüm adresi göndericez
	// ve sürekli bir büyük küçük kontrolü olucak. alt_Dugum bir formal parametre. parantezler kapandıktan
	// sonra yok eidlir. yani & yazarsak düğüm fonk bitince yok edilicek ve eklenmemiş olacak
	// bu yüzden referans ile gönderiyoruz. alt_Dugum sadece bir takma isimdir
	void AraveEkle(Dugum<Nesne> *&alt_Dugum, const Nesne &yeni)
	{ //alt_Dugum ne verilirse o düğümün kök olduğu ağaç üzerinde işlem yapılır
	// alt_Dugum = üzerinde bulunduğumuz düğüm 
	
		// boş bir noktaya geldik
		if (alt_Dugum == NULL)
			alt_Dugum = new Dugum<Nesne>(yeni);
		
		//  üzerirnde bulunduğumuz düğüm büyük olabilir. sağa yönlendiririz
		else if (yeni < alt_Dugum->veri)
			AraveEkle(alt_Dugum->sol, yeni);
		
		// küçük olabilir. sola yönlendirirz
		else if (yeni > alt_Dugum->veri)
			AraveEkle(alt_Dugum->sag, yeni);
		
		// eşit olabilir
		else
			return; // Aynı eleman var.
	}
	
	// 3 durum var. hiç çocuk yok, 1 çocuk var, 2 çocuk var
	// hiç çocuk yoksa direkt sil
	// tek çocuk varsa silinenin ebeveyni silinenin çocuğuna bağlanır
	// 2 çocuklu düğümü silmiyoruz. çünkü hangi çocuk yukarı çıkacak sıkıntısı vardır.
	// ya solun en sağına ya da sağın en soluna gideriz. ve düğümü alır silmek istediğimiz verinin yerine yazarz
	// düğümü silmeyiz veriyi değiştirirz. en alttan getiridğimiz düğümü sileriz 
	// yine referans ile yapılır
	bool AraveSil(Dugum<Nesne> *&alt_Dugum, const Nesne &yeni)
	{
		if (alt_Dugum == NULL)
			return false; //Eleman yok
		if (alt_Dugum->veri == yeni)
			return DugumSil(alt_Dugum);
		else if (yeni < alt_Dugum->veri)
			return AraveSil(alt_Dugum->sol, yeni);
		else
			return AraveSil(alt_Dugum->sag, yeni);
	}
	
	// çağrılırsa bulunmuştur. o yüzden sürekli true döner
	// solun en sağını silme işlemi
	bool DugumSil(Dugum<Nesne> *&alt_Dugum)
	{
		Dugum<Nesne> *silinecekDugum = alt_Dugum;

		if (alt_Dugum->sag == NULL) // ya tek çocuk var ya da hiç çocuk yok
			alt_Dugum = alt_Dugum->sol;
		else if (alt_Dugum->sol == NULL) // en az bir çocupu var. sol çocupu olduğunu belli
			alt_Dugum = alt_Dugum->sag;
		else //iki çocuğunun olması durumu
		{
			// en solun en sağına gidioyuruz
			silinecekDugum = alt_Dugum->sol; 
			Dugum<Nesne> *ebeveynDugum = alt_Dugum; // bir üstteki düğümüde tutup aşağı inmemiz gerekir
			while (silinecekDugum->sag != NULL)
			{
				ebeveynDugum = silinecekDugum;
				silinecekDugum = silinecekDugum->sag;
			}
			alt_Dugum->veri = silinecekDugum->veri;
			if (ebeveynDugum == alt_Dugum) // solun en sağı yoksa. ilk indiğimiz yerde durursak
				alt_Dugum->sol = silinecekDugum->sol;
			else // solun en az bir tane sağ çocuğu var
				ebeveynDugum->sag = silinecekDugum->sol;
		}
		delete silinecekDugum;
		return true;
	}
	void Inorder(Dugum<Nesne> *alt_Dugum) const
	{
		if (alt_Dugum != NULL)
		{
			Inorder(alt_Dugum->sol);		//sol
			cout << alt_Dugum->veri << " "; //kök
			Inorder(alt_Dugum->sag);		//sağ
		}
	}
	void Preorder(Dugum<Nesne> *alt_Dugum) const
	{
		if (alt_Dugum != NULL)
		{
			cout << alt_Dugum->veri << " ";
			Preorder(alt_Dugum->sol);
			Preorder(alt_Dugum->sag);
		}
	}
	void Postorder(Dugum<Nesne> *alt_Dugum) const
	{
		if (alt_Dugum != NULL)
		{
			Postorder(alt_Dugum->sol);
			Postorder(alt_Dugum->sag);
			cout << alt_Dugum->veri << " ";
		}
	}
	
	// index gibi 3. seviye derse 2 yi yazdırıcaz
	void SeviyeyiYazdir(Dugum<Nesne> *alt_Dugum, int seviye) const
	{
		if (alt_Dugum == NULL)
			return;
		if (seviye == 0)
			cout << alt_Dugum->veri << " ";
		else
		{
			SeviyeyiYazdir(alt_Dugum->sol, seviye - 1);
			SeviyeyiYazdir(alt_Dugum->sag, seviye - 1);
		}
	}
	
	// en uzaktaki yaprağa olan sayı
	int Yukseklik(Dugum<Nesne> *alt_Dugum) const
	{
		if (alt_Dugum == NULL)
			return -1; // Düğümsüz ağacın yüksekliği -1'dir.
		return 1 + max(Yukseklik(alt_Dugum->sol), Yukseklik(alt_Dugum->sag));
		// max iki parametreden büyük olanını döndürür
	}
	
	bool Ara(Dugum<Nesne> *alt_Dugum, const Nesne &aranan)
	{
		if (alt_Dugum == NULL)
			return false;
		if (alt_Dugum->veri == aranan)
			return true;
		if (aranan < alt_Dugum->veri)
			return Ara(alt_Dugum->sol, aranan);
		if (aranan > alt_Dugum->veri)
			return Ara(alt_Dugum->sag, aranan);
	}

public:
	BST()
	{
		root = NULL;
	}
	bool Bosmu() const
	{
		return root == NULL;
	}
	void Ekle(const Nesne &yeni)
	{
		AraveEkle(root, yeni);
	}
	void Sil(const Nesne &veri) throw()
	{
		if (AraveSil(root, veri) == false)
			throw "HATA";
	}
	void Inorder() const
	{
		Inorder(root);
	}
	void Preorder() const
	{
		Preorder(root);
	}
	void Postorder() const
	{
		Postorder(root);
	}
	
	// dizide zaten soldan saga doğru okursan levelorder yapmış olursun
	// ama listede böyle kolay değil
	// yükseklik fonk da yazmamız gerek
	// ağacın yüksekliği sorulambilir, derinliği sorulamaz sadece düğümün derinliği sorulabilir
	// agacın yüksekliği = kökün yüksekliği. bir ağacın yüksekliği olur ama derinliği olamaz
	void Levelorder() const 
	{
		int h = Yukseklik();
		for (int level = 0; level <= h; level++)
			SeviyeyiYazdir(root, level);
	}
	bool Arama(const Nesne &aranan)
	{
		return Ara(root, aranan);
	}
	void Temizle()
	{
		while (!Bosmu())
			DugumSil(root);
	}
	int Yukseklik() const
	{
		return Yukseklik(root);
	}
	~BST()
	{
		Temizle();
	}
};


#endif