/**
* @file Stack.cpp
* @description Stack sınıfının fonksiyon gövdelerinin yazılı olduğu dosya
* @course 1/B
* @assignment 2. Ödev
* @date Kodu 24/08/2021
* @author Gamze Ceylan gamze.ceylan3@ogr.sakarya.edu.tr
*/


#include "Stack.hpp"

Stack::Stack(){
			topOfStack = NULL;
			head = NULL;
			size = 0;
		}

		bool Stack::isEmpty()const{
			return topOfStack == NULL;
		}

		// anlamadım
		void Stack::push(const int &item){
			if(size == 0){
				head =  new NodeStack(item, topOfStack);
			}

			topOfStack = new NodeStack(item, topOfStack);
			size ++;
		}
		
		void Stack::YazdirYukseklik(Stack *stack){
			cout << "Y(";

			for(int i=0; i<size; i++){
				if(i==size-1)
					cout << stack->top() << "),";
				else
					cout << stack->top() << ",";
				stack->pop();
			}
		}

		void Stack::YazdirDerinlik(Stack *stack){
			cout << "D(";
			for(int i=0; i<size; i++){
				if(i==size-1)
					cout << stack->top() << ") ";
				else
					cout << stack->top() << ",";
		
				stack->pop();
			}
		}


		void Stack::pop(){
			// if(isEmpty())  throw hata

			NodeStack *tmp = topOfStack;
			topOfStack = topOfStack->next;
			delete tmp; /// çöp oluşmasın
		}

		void Stack::makeEmty(){
			while(!isEmpty()) pop();

		}

		int Stack::top()const{
			//  if(isEmpty())  throw hata
			return topOfStack->item;
		}

		Stack::~Stack(){
			makeEmty();
		}