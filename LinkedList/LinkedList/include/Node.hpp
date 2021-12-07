#ifndef _NODE_HPP
#define _NODE_HPP
#include <iostream>

class Node{
/* Node alt alanlarını private yapmak gerekir ama liste,
düğümün alt alanlarını sürekli kullanacak ama bunları privata yapmamak
listeyi senin kontolünden çıkartmaz. çünkü listebaşı pointer'ını açamaıdğın
sürece hiçbir düğüme gidemezler ve listene müdahele edemezler. fazladan kod yazmaya gerek yok
bağıl listenin içinde olacağı için mantık olarak private olur.
*/
    public:
        int data; // verimiz
        Node *next; // bir sonraki düğümü gösteren düğüm adresi
        // pointer da gösterdiği düğümün türünde olmalı. o yüzden o da object

        Node();
        Node(const int& data, Node* next); // kurucu fonksiyonumuz


};

#endif