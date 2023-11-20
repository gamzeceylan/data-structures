/**
* @file NodeAVL.hpp
* @description NodeAVL, AVL agacı için düğüm oluşturan sınıf.
* @course 1/B
* @assignment 2. Ödev
* @date Kodu 24/08/2021
* @author Gamze Ceylan gamze.ceylan3@ogr.sakarya.edu.tr
*/

#ifndef NODEAVL_HPP
#define NODEAVL_HPP

#include <iostream>
#include "Kisi.hpp"

using namespace std;

class NodeAVL{
	public:
		Kisi *kisi;
		NodeAVL *sol;
		NodeAVL *sag;
		int yukseklik; 
		int derinlik;
		
		NodeAVL(Kisi* kisi=NULL, NodeAVL* sol = NULL, NodeAVL* sag = NULL);
};


#endif