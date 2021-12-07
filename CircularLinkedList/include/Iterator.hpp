// liste uzerinde gezinmeni sağlayacak sınıf.
// şart değil ama bil
// gezici sınıf

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "Node.hpp"

template <typename Object>
class Iterator{
	public:
	// bir adres göndericez ve o da sıradakini getirecek
	// current : şuan bulunduğumuz düğüm
	
	Node <Object> *current;
	Iterator(){
		current = NULL; // adres verilmezse otomatik null alsın
	}
	Iterator(Node<Object> *current){
		this->current = current;
	}
	
	// hasNext : ilerleyebiliyor mu. (ileride düğüm var mı değil)
	// eğer üzerinde bulunduğu düğüm null ise false döndürür
	bool hasNext(){
		return current !=NULL;
	}
	// ilerle
	void next(){
		// ilerleyemiyorsa hatanın fırlatılması lazım
		// if(!hasNext()) throw hata
		
		current = current->next;
	}
	// veriyi getirme fonksiyonu
	const Object& getCurrent()const{
		// null olan bir şeyin verisini getiremez
		// if(!hasNext()) throw hata
		return current->item;
	}
	
	// dışarıdan çağırdığın fonksiyonların hata kontrolunu yapmalısın
};

#endif