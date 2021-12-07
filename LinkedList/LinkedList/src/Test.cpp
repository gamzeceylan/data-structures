#include "LinkedList.hpp"
#include <iostream>
#include <string>

using namespace std;

int main(){
    LinkedList *list = new LinkedList();
/*
    int choice=0;
	std::string line;
    int number;
	int location=0;
 
	do{
		system("CLS");

		cout << "1. Add number" << endl;
		cout << "2. Remove number" << endl;
		cout << "3. Remove number at location" << endl;
		cout << "4. Add number at location" <<endl;
		cout << "5. Find location" << endl;
        cout << "6. Total number of elements" << endl;
		cout << "7. First number" << endl;
		cout << "8. Last number" << endl;
		cout << "9. List of numbers" << endl;
		cout << "10. Clear numbers" << endl;
		cout << "11. Find the number in the position" << endl;
		cout << "12. Exit" << endl;
		cin >> choice;
		
		switch (choice){
			case 1:
				cout << "Number : ";
				cin.ignore();
		
				getline(std::cin, line);
                number = stoi(line);
				list->add(number);
			break;
			case 2:
				cout << "Number : ";
				cin.ignore();
				getline(std::cin, line);
                number = stoi(line);
				list->remove(number); 
			break;
			case 3:
				cout << "Location : ";
				cin >> location;
				list->removeAt(location);
			break;
			case 4:
				cout << "Location : ";
				cin >> location;
				cout << "Number : ";
				cin.ignore();
				getline(std::cin, line);
                number = stoi(line);
				list->insert(location, number);
			break;
			case 5:
				cout << "Number : "; 
				cin.ignore();
				getline(std::cin, line);
                number = stoi(line);
				cout << "Location : " << list->indexOf(number) << endl;	
				
	
				cin.ignore();
				cin.get();				
			break;
			case 6:
				cout << "Total number of elements: " << list->count() << endl;	
				cin.ignore();
				cin.get();	
			break;
			case 7:
				cout << "Total number of elements: " << list->first() << endl;	
				cin.ignore();
				cin.get();	
			break;
			case 8:
				cout << "Total number of elements: " << list->last() << endl;	
				cin.ignore();
				cin.get();	
			break;
			case 9:
				cout << "Numbers: "<< endl;
			//	cout << *list;
				cin.ignore();
				cin.get();	

			break;
			case 10:
				list->clear();
			break;
			case 11:
				cout << "Location: ";
				cin >> location;
				cout << list->elementAt(location)<< endl;
				cin.ignore();
				cin.get();
			break;
			case 12:
			break;
			default:
				cout << "Wrong choice!" << endl;
				// cin.get();
				cin.ignore();
				cin.get(); 
			break;
		}
		
	}while(choice != 12);
*/
    return 0;
}