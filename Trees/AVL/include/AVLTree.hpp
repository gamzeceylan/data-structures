#ifndef AVLTREE_HPP
#define AVLTREE_HPP

#include <cmath>
#include "ElemanYok.hpp"

template <typename Nesne>
struct Dugum
{
	Nesne veri;
	Dugum<Nesne> *sol;
	Dugum<Nesne> *sag;
	int yukseklik; // düğümlerin yüksekliklerine bakıyoruz
	Dugum(const Nesne &vr, Dugum<Nesne> *sl = NULL, Dugum<Nesne> *sg = NULL)
	{
		veri = vr;
		sol = sl;
		sag = sg;
		yukseklik = 0; // eklenen her yeni düğüm ilk önce yaprak olarak eklenir.
	}
};

template <typename Nesne>
class AVLTree
{
private:
	Dugum<Nesne> *root;
	
	// silme için bu derste sorumlu değiliz ama sen yine de çalış 
	
	// bize bir düğüm adresi döndürmeli 
	Dugum<Nesne> *AraveEkle(Dugum<Nesne> *alt_Dugum, const Nesne &yeni)
	{
		// alt_Dugum = z, alt_Dugum->sol = y, yeni = x,w
		if (alt_Dugum == NULL)
		{
			alt_Dugum = new Dugum<Nesne>(yeni);
		}
		else if (yeni < alt_Dugum->veri) // y, z'nin sol çocuğu ise
		{
			alt_Dugum->sol = AraveEkle(alt_Dugum->sol, yeni);
	
			// sola eklersen solda denge bozulur sağda denge bozulmaz o yüzden sadece onu kontrol ediyourz
			if (Yukseklik(alt_Dugum->sol) - Yukseklik(alt_Dugum->sag) == 2)
			{
				// Sol Sol Durumu -> düz bir çigi mi?
				if (yeni < alt_Dugum->sol->veri) // x, y'nin sol çocuğu ise
					alt_Dugum = SolCocukIleDegistir(alt_Dugum); //sağa dönüş z
				else // Sol Sağ Durumu -> zinzak mo
				{														  
					alt_Dugum->sol = SagCocukIleDegistir(alt_Dugum->sol); // sola dönüş y
					alt_Dugum = SolCocukIleDegistir(alt_Dugum); // sağa dönüş z
				}
			}
		}
		
		else if (yeni > alt_Dugum->veri) // sağ tarafa eklendiyse
		{
			alt_Dugum->sag = AraveEkle(alt_Dugum->sag, yeni);

			if (Yukseklik(alt_Dugum->sag) - Yukseklik(alt_Dugum->sol) == 2)
			{
				// Sağ Sağ Durumu
				if (yeni > alt_Dugum->sag->veri)
					alt_Dugum = SagCocukIleDegistir(alt_Dugum);
				else
				{ // Sağ Sol Durumu
					alt_Dugum->sag = SolCocukIleDegistir(alt_Dugum->sag);
					alt_Dugum = SagCocukIleDegistir(alt_Dugum);
				}
			}
		}
		else
			 // Aynı eleman var.

		//Yüksekliği güncelle
		alt_Dugum->yukseklik = Yukseklik(alt_Dugum);
		return alt_Dugum;
	}
	
	// referanslı değil dikkat et. Ama nedennnn??. neyse o yüzden tmp var
	Dugum<Nesne> *SolCocukIleDegistir(Dugum<Nesne> *alt_Dugum) // Sağa dönüş
	{
		//swap
		Dugum<Nesne> *tmp = alt_Dugum->sol;
		alt_Dugum->sol = tmp->sag;
		tmp->sag = alt_Dugum;

		// Yükseklikleri Güncelle
		alt_Dugum->yukseklik = Yukseklik(alt_Dugum);
		tmp->yukseklik = max(Yukseklik(tmp->sol), alt_Dugum->yukseklik) + 1; // Bir düğümün yüksekliği en yüksek çocuğunun bir fazlasıdır

		return tmp;
	}
	
	// alt düğümün sağına 
	Dugum<Nesne> *SagCocukIleDegistir(Dugum<Nesne> *alt_Dugum) // Sola dönüş
	{
		//swap
		Dugum<Nesne> *tmp = alt_Dugum->sag;
		alt_Dugum->sag = tmp->sol;
		tmp->sol = alt_Dugum;

		// Yükseklikleri Güncelle
		alt_Dugum->yukseklik = Yukseklik(alt_Dugum);
		tmp->yukseklik = max(Yukseklik(tmp->sag), alt_Dugum->yukseklik) + 1;

		return tmp;
	}
	void Inorder(Dugum<Nesne> *alt_Dugum) const
	{
		if (alt_Dugum != NULL)
		{
			Inorder(alt_Dugum->sol);
			cout << alt_Dugum->veri << " ";
			Inorder(alt_Dugum->sag);
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
	int Yukseklik(Dugum<Nesne> *alt_Dugum) const
	{
		if (alt_Dugum == NULL)
			return -1; // Ortada düğüm yoksa yükseklik anlamsızdır. Kodun çalışması adına -1 verilmektedir.
		return 1 + max(Yukseklik(alt_Dugum->sol), Yukseklik(alt_Dugum->sag));
	}
	bool DugumSil(Dugum<Nesne> *&alt_Dugum)
	{
		Dugum<Nesne> *silinecekDugum = alt_Dugum;

		if (alt_Dugum->sag == NULL)
			alt_Dugum = alt_Dugum->sol;
		else if (alt_Dugum->sol == NULL)
			alt_Dugum = alt_Dugum->sag;
		else
		{
			silinecekDugum = alt_Dugum->sol;
			Dugum<Nesne> *ebeveynDugum = alt_Dugum;
			while (silinecekDugum->sag != NULL)
			{
				ebeveynDugum = silinecekDugum;
				silinecekDugum = silinecekDugum->sag;
			}
			alt_Dugum->veri = silinecekDugum->veri;
			if (ebeveynDugum == alt_Dugum)
				alt_Dugum->sol = silinecekDugum->sol;
			else
				ebeveynDugum->sag = silinecekDugum->sol;
		}
		delete silinecekDugum;
		return true;
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
	AVLTree()
	{
		root = NULL;
	}
	bool Bosmu() const
	{
		return root == NULL;
	}
	void Ekle(const Nesne &yeni)
	{
		root = AraveEkle(root, yeni);
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
	~AVLTree()
	{
		Temizle();
	}
};

#endif