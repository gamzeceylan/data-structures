#include "Postfix.hpp"
		
		// op2-> infix ten okuduğun şey, op1-> yığıttan? okuduğun şey 
		bool Postfix::OncelikDusukmu(char op1, char op2){ // true yığıttan gelirse eleman çıkar
			if(op1 == '(') return false;
			else if(op2 == '(') return false;
			else if(op2 == ')') return true; // yığıtta sol parantezi görene kadar her şey çıkabileceği için true döndürmemiz lazım
			// yani ) ise yığıttan bir şey çıkacak 
			
			// postfix parantezsizdir. sadece işlem önceliğine göre yapılır
			
			else if(op1 == '*' || op1 == '/') return true;
			else if(op2 == '*' || op2 == '/') return false;
		
			return true;
		}
		
		void Postfix::PostfixAktar(Stack<char>* stack, string& postfix){
			// postfix'e yığıttan okuduğu elemanı ekliyor
			postfix += stack->top();
			postfix += " ";
			stack->pop();
		}
		
		
		// yığıtı kullanarak postfixe dönüştürür
		string Postfix::infixToPostfix(string infix){
			// soldaki infixin uzunlu
			int uzunluk = infix.length();
			
			// ikili operatorleri dekteklemediğini varsayıyoruz
			// her operator bir karakter
			Stack<char>* stack = new Stack<char>();
			string postfix = "";
			
			// soldan rakam, operator, parantez gelebilir.
			for(int i=0; i<uzunluk; i++){ // ihtimalleri değerlendiriyoruz
				if(isdigit(infix[i])){
					while(isdigit(infix[i])){ // operator ya da paranteze kadal olan sayının tamamını almaya çalışıyoruz
						postfix += infix[i];
					}
					postfix += " "; //postfix aralrında boşluk vardır 85 10 2 gibi
					i--; // anlamadım 1:09
				}
				
				else if(infix[i] == '('){ // sol parantezse direkt yığıta atarız
					stack->push(infix[i]);
				}
				
				// operatorlerden biriyle
				else if(infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/'){
					// öncelik kontrolü. öncelik yüksekse çıkacak
					while(!stack->isEmpty() && stack->top() != '('){
						if(OncelikDusukmu(stack->top(), infix[i])){
							// true dönerse yığıttan eleman çıkıcak
							
							/////////// beynim durdu ya almıyor yeter valla sıkıldım bezdim allahım yardım gönder
							// lütfen allahım teşekkür ederim
							
							PostfixAktar(stack, postfix);
						}
						else break; 
					}
					stack->push(infix[i]);
				}
				
				else if(infix[i] == ')'){ // desteklenmeyen eleman
				// sağ parantezi kesinlikle yığıta atmıyorsun.
				// sol parantezi görene kadar her şeyi çıkartıyoruz. sol parantezi de çıkarıyoruz ama yığıta eklemiyoruz
						while(!stack->isEmpty() && stack->top() != '('){
							// sol parantezi görene kadar her şeyi postfix e aktarıcaz
							PostfixAktar(stack, postfix);
						}
						if(!stack->isEmpty()) stack->pop(); // sol parantezi çıkar çünkü eklenmiyor
				}
			}
			
			// infix tamamlandı ama hala yığıtta elemanlar var. o da bu kısma düşer
			// bütün operatörleri postfixe ekler
			while(!stack->isEmpty()){
				PostfixAktar(stack, postfix);
			}
			
			delete stack;
			return postfix;
		}
		
		double Postfix::StringToDouble(string str){
			stringstream ss(str);
			double num;
			ss>>num;
			return num;
		}
		
		Postfix::Postfix(string infix){ // infix kısmı alır
			ifade = infixToPostfix(infix);
		}
		
		// postfix hesaplıcaz. cevabı sayı, operator yok
		double Postfix::Hesapla(){
			double sonuc;
			int uzunluk = ifade.length();
			Stack<double> *stack = new Stack<double>();
			
			// şuan elimizde operator, sayı bulunan bir ifade var.
			for(int i=0; i<uzunluk; i++){
				// boşluk var mı?
				if(isspace(ifade[i])) continue;
				if(isdigit(ifade[i])){
					string sayi = "";
					while(isdigit(ifade[i])){
						sayi+= ifade[i];
						i++;
					}
					double s;
					s = StringToDouble(sayi);
					stack->push(s);
					i--; // i yi nerde fazladan arttırdı da azaltıyoruz ya abi 
					continue;
				}
				else{ // operator gelmiştir, yapacağımız şey sayı çekmek
					double sayi2 = stack->top();  // ilk çektiğimiz sayi
					stack->pop();
					double sayi1 = stack->top();
					stack->pop();
					
					// 10 ve 2 10/2 şeklinde olmalı
					
					//operatore göre işlem yapıcaz
					switch(ifade[i]){
						case '+':
							stack->push(sayi1+sayi2);
						break;
						
						case '-':
							stack->push(sayi1-sayi2);
						break;
						
						case '*':
							stack->push(sayi1*sayi2);
						break;
						
						case '/':
							stack->push(sayi1/sayi2);
						break;
					}
				}
				
			}
			
			if(!stack->isEmpty()){
				sonuc = stack->top();
				stack->pop();
			}
			delete stack;
			return sonuc;
			
		}
		
		// get fonk
		string Postfix::postfix()const{
			return ifade;
		}
		
		ostream& operator<<(ostream& ekran, Postfix& sag){
			ekran<< sag.ifade<< endl;
			return ekran;
		}
		
		
		

// yukarıda nerede yazıdm bilmioyrum ama sağ parantezi gördüğün zaman yığıttaki 
//her şeyi sol parantezi göreen kadar postfize ekliyorsun