/**
* @file AVL.cpp
* @description AVL sınıfının fonksiyon gövdelerinin yazılı olduğu dosya
* @course 1/B
* @assignment 2. Ödev
* @date Kodu 24/08/2021
* @author Gamze Ceylan gamze.ceylan3@ogr.sakarya.edu.tr
*/


#include "AVL.hpp"
#include "NodeAVL.hpp"

		NodeAVL* AVL::AraveEkle(NodeAVL *alt_dugum, Kisi *yeni)
		{
		if (alt_dugum == NULL)
			{
				alt_dugum = new NodeAVL(yeni);
				
				alt_dugum->kisi->stack_derinlik->push(Yukseklik(kok) - alt_dugum->yukseklik);
				alt_dugum->kisi->stack_yukseklik->push(Yukseklik(alt_dugum));
				
			}
			else if (yeni->boy <= alt_dugum->kisi->boy) // y, z'nin sol çocuğu ise /// ben = koydum??
			{
			
				alt_dugum->sol = AraveEkle(alt_dugum->sol, yeni);

				if (Yukseklik(alt_dugum->sol) - Yukseklik(alt_dugum->sag) == 2)
				{
				// Sol Sol Durumu
					if (yeni->boy < alt_dugum->sol->kisi->boy){ // x, y'nin sol çocuğu ise
						alt_dugum = SolCocukIleDegistir(alt_dugum); //sağa dönüş z
						
						alt_dugum->kisi->stack_yukseklik->push(Yukseklik(alt_dugum));
						alt_dugum->kisi->stack_derinlik->push(Yukseklik(kok) - alt_dugum->yukseklik);
						
					}
					else // Sol Sağ Durumu
					{														  
						alt_dugum->sol = SagCocukIleDegistir(alt_dugum->sol); // sola dönüş y
						alt_dugum = SolCocukIleDegistir(alt_dugum); // sağa dönüş z
						
						alt_dugum->kisi->stack_yukseklik->push(Yukseklik(alt_dugum));
						alt_dugum->kisi->stack_derinlik->push(Yukseklik(kok) - alt_dugum->yukseklik);
				
					}
				}

			}
			else if (yeni->boy > alt_dugum->kisi->boy)
			{

				alt_dugum->sag = AraveEkle(alt_dugum->sag, yeni);

				if (Yukseklik(alt_dugum->sag) - Yukseklik(alt_dugum->sol) == 2)
				{
				// Sağ Sağ Durumu
					if (yeni->boy > alt_dugum->sag->kisi->boy){
						alt_dugum = SagCocukIleDegistir(alt_dugum);
						
						alt_dugum->kisi->stack_derinlik->push(Yukseklik(kok) - alt_dugum->yukseklik);
						alt_dugum->kisi->stack_yukseklik->push(Yukseklik(alt_dugum));
						
					}
					else
					{ // Sağ Sol Durumu
						alt_dugum->sag = SolCocukIleDegistir(alt_dugum->sag);
						alt_dugum = SagCocukIleDegistir(alt_dugum);
						
						alt_dugum->kisi->stack_derinlik->push(Yukseklik(kok) - alt_dugum->yukseklik);
						alt_dugum->kisi->stack_yukseklik->push(Yukseklik(alt_dugum));	
					}
				}
			}
		//Yüksekliği güncelle
	
			// alt_dugum->yukseklik = Yukseklik(alt_dugum);
			
			alt_dugum->kisi->stack_yukseklik->push(Yukseklik(alt_dugum));
			alt_dugum->kisi->stack_derinlik->push(Yukseklik(kok) - alt_dugum->yukseklik);
			
			alt_dugum->yukseklik = Yukseklik(alt_dugum);
		
			return alt_dugum;
		}

		NodeAVL* AVL::SolCocukIleDegistir(NodeAVL *alt_dugum) // Sağa dönüş
		{
		//swap
			NodeAVL *tmp = alt_dugum->sol;
			alt_dugum->sol = tmp->sag;
			tmp->sag = alt_dugum;

			// Yükseklikleri Güncelle
			alt_dugum->yukseklik = Yukseklik(alt_dugum);
			tmp->yukseklik = max(Yukseklik(tmp->sol), alt_dugum->yukseklik) + 1; 
			
			return tmp;
		}
		
		NodeAVL* AVL::SagCocukIleDegistir(NodeAVL *alt_dugum) // Sola dönüş
		{
			NodeAVL *tmp = alt_dugum->sag;
			alt_dugum->sag = tmp->sol;
			tmp->sol = alt_dugum;

			tmp->yukseklik = max(Yukseklik(tmp->sag), alt_dugum->yukseklik) + 1;
			return tmp;
		}
			
		void AVL::SeviyeyiYazdir(NodeAVL* alt_dugum, int seviye) const
		{
			if (alt_dugum == NULL)
				return;
			if (seviye == 0){
				cout << alt_dugum->kisi->isim << " " << alt_dugum->kisi->yas<< " " << alt_dugum->kisi->boy << " ";
				alt_dugum->kisi->stack_yukseklik->YazdirYukseklik(alt_dugum->kisi->stack_yukseklik);
				alt_dugum->kisi->stack_derinlik->YazdirDerinlik(alt_dugum->kisi->stack_derinlik);
				cout <<endl;
			}
	
			else
			{
				SeviyeyiYazdir(alt_dugum->sol, seviye - 1);
				SeviyeyiYazdir(alt_dugum->sag, seviye - 1);
			}
		}	

		int AVL::Yukseklik(NodeAVL *alt_dugum) const
		{
			if (alt_dugum == NULL)
				return -1;
			return 1 + max(Yukseklik(alt_dugum->sol), Yukseklik(alt_dugum->sag));
		}
		
		bool AVL::DugumSil(NodeAVL *&alt_Dugum)
		{
			NodeAVL *silinecekDugum = alt_Dugum;

			if (alt_Dugum->sag == NULL)
				alt_Dugum = alt_Dugum->sol;
			else if (alt_Dugum->sol == NULL)
				alt_Dugum = alt_Dugum->sag;
			else
			{
				silinecekDugum = alt_Dugum->sol;
				NodeAVL *ebeveynDugum = alt_Dugum;
				while (silinecekDugum->sag != NULL)
				{
					ebeveynDugum = silinecekDugum;
					silinecekDugum = silinecekDugum->sag;
				}
				alt_Dugum->kisi = silinecekDugum->kisi;
				if (ebeveynDugum == alt_Dugum)
					alt_Dugum->sol = silinecekDugum->sol;
				else
					ebeveynDugum->sag = silinecekDugum->sol;
			}
			delete silinecekDugum;
			return true;
		}
		AVL::AVL(){
			kok = NULL;

		}
		bool AVL::Bosmu() const
		{
			return kok == NULL;
		}
		void AVL::Ekle(Kisi *yeni){
			kok = AraveEkle(kok, yeni);
		}
		void AVL::Temizle()
		{
			while (!Bosmu())
				DugumSil(kok);
		}
		int AVL::Yukseklik() const
		{
			return Yukseklik(kok);
		}
		void AVL::LevelOrder() const
		{
			int h = Yukseklik();
			for (int level = 0; level <= h; level++)
				SeviyeyiYazdir(kok, level);
		}
		
		AVL::~AVL()
		{
			Temizle();
		}