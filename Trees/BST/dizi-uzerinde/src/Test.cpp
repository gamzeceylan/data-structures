#include "BST.hpp"

int main(){
	BST<int> *agac = new BST<int>();
	agac->add(70);
	agac->add(3);
	agac->add(84);
	agac->add(50);
	agac->add(42);
	agac->add(65);
	agac->add(200);
	agac->add(125);
	agac->add(14);
	cout << "Yukseklik: " << agac->Height()<< endl;
	if(agac->find(65)) cout << "65 var" << endl;
	if(agac->find(500)) cout << "500 var" << endl;
	else cout << "500 yok"<< endl;
	
	agac->postorder();
	cout << endl;
	agac->Sil(70);
	agac->preorder();
	
	
	delete agac;
	return 0;
}
	