#include "Stack.hpp"

int main(){
	
	Stack<int> *yigit = new Stack<int>();
	yigit->push(150);
	yigit->push(120);
	yigit->push(17);
	yigit->pop(); // 17 çıktı. son eklenen ilk çıkar
	
	cout << yigit->top() << endl; // 120 vermeli
	
	delete yigit; // unutmuyoruz
}