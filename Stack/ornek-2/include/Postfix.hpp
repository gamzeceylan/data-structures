#ifndef POSFIX_HPP
#define POSFIX_HPP

#include "Stack.hpp"
#include <cctype>
#include <cstdlib>
#include <sstream>

// sadece parantezler ve dörtişlemi değerlendirioyurz. sınavda da buradan sorumlusun

class Postfix{
	private:
		string ifade; // sağ taraftaki postfix te oluşacak olan ifadeyi temsil ediyor
		
		
	
		bool OncelikDusukmu(char, char);
		void PostfixAktar(Stack<char>*, string&);
		string infixToPostfix(string);
		double StringToDouble(string);
		
	public:
		Postfix(string);
		double Hesapla(); // ifadeyi postfix formatınfa alıcaz
		string postfix()const;
		friend ostream& operator<<(ostream&, Postfix&);
	
	
	
};


#endif