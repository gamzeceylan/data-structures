/**
* @file NodeAVL.cpp
* @description NodeAVL sınıfının fonksiyon gövdelerinin yazılı olduğu dosya
* @course 1/B
* @assignment 2. Ödev
* @date Kodu 24/08/2021
* @author Gamze Ceylan gamze.ceylan3@ogr.sakarya.edu.tr
*/


#include "NodeAVL.hpp"

		NodeAVL::NodeAVL(Kisi* kisi, NodeAVL* sol, NodeAVL* sag){
			this->kisi = kisi;
			this->sol = sol;
			this->sag = sag;
			yukseklik = 0;
			derinlik = 0;
		}