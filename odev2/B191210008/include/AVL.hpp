/**
* @file AVL.hpp
* @description AVL, agacın oluşturulduğu sınıftır. Aynı zamanda Agac burada leveorder yazdırılıyor
ve stack'e düğümün yükseklik ve derinliği değiştikçe derinliği ekleniyor.
* @course 1/B
* @assignment 2. Ödev
* @date Kodu 24/08/2021
* @author Gamze Ceylan gamze.ceylan3@ogr.sakarya.edu.tr
*/

#ifndef AVL_HPP
#define AVL_HPP

#include "NodeAVL.hpp"
#include "Stack.hpp"

class AVL{
	private:
		NodeAVL *kok;
		NodeAVL *AraveEkle(NodeAVL *, Kisi *);
		NodeAVL *SolCocukIleDegistir(NodeAVL *);
		NodeAVL *SagCocukIleDegistir(NodeAVL *);
		void SeviyeyiYazdir(NodeAVL* , int) const;
		int Yukseklik(NodeAVL *) const;
		bool DugumSil(NodeAVL *&);
	public:
		AVL();
		bool Bosmu() const;
		void Ekle(Kisi *);
		void Temizle();
		int Yukseklik() const;
		void LevelOrder() const;
		~AVL();
};

#endif