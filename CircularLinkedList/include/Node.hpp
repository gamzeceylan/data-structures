// herhangi türden bir veri eklenecek bir liste oluşturuyoruz
// generic yapı olması, sablon olması ve bütün kodun baslık dosyasında bulunması gerekir

#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
using namespace std;

template <typename Object>
class Node{
/* Node alt alanlarını private yapmak gerekir ama liste,
düğümün alt alanlarını sürekli kullanacak ama bunları privata yapmamak
listeyi senin kontolünden çıkartmaz. çünkü listebaşı pointer'ını açamaıdğın
sürece hiçbir düğüme gidemezler ve listene müdahele edemezler. fazladan kod yazmaya gerek yok
private, bağıl listenin içinde olacak.
*/

	public:
		Object item; //item veridir. türü oluşturunca belli olacak.
		// pointer da gösterdiği düğümün türünde olmalı. o yüzden o da object
		// next : bir sonraki düğümü gösteren düğümün adresi
		
		Node<Object> *next; //burayı anlamadım
		
		// kurucu fonk
		Node(const Object& item=Object(), Node<Object> *next=NULL){
			this->item = item;
			this->next = next;
		}
};

#endif
