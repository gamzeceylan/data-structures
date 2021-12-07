#ifndef BTS_HPP
#define BTS_HPP

#include <cmath>
#include <iostream>
#define SIZE 5000
using namespace std;

template <typename Object>
class BST{
	private:
		Object *items; // dizi 
		
		// C++ dizi oluşturudupu zaman içine rastgele değerler atar.
		// peki bu değerler C++ ın mı atadığı mı yoksa biizm yazdığımı değerler mi ?
		// işte bunu tespit etmek için aynı uzunlukta bir dizi daha oluşturuz. 1-> dolu 0->boş
		int IndexFill[SIZE]; // index doluluğu dizisi
		
		// elaman indexi döndürme
		int FindIndex(const Object & item, int currentIndex = 0){
			// ekleme ile arama aynı işlemdir
		//	int currentIndex = 0;
			while(true){
				// bulamazsa
				if(IndexFill[currentIndex] == 0 || currentIndex == SIZE){ 
				// 0 sa veya agacın dışına taştıysak eleman yok
					return -1;
				}
				// bulursa
				// ayrıca index doluluğuna da bakmamız gerekir
				// belki elemanı buldu ama biizm yazdığımız eleman değil
				if(items[currentIndex] == item && IndexFill[currentIndex] == 1) return currentIndex;
				
				else if(item < items[currentIndex]) currentIndex = 2*currentIndex+1;
				else if(item > items[currentIndex]) currentIndex = 2*currentIndex+2;

			}
		}
		
		bool ikininKuvvetiMi(int x){
			while(((x%2) == 0) && x>1) x/=2;
			return  (x==1);
		}
		int EnKucukDeger(int i=0)
		{
			if(2*i+1 > SIZE) return i;
			else if(IndexFill[2*i+1] == 0) return i;
			else return EnKucukDeger(2*i+1);
		}
		
	public:
		BST(){
			items = new Object[SIZE];
			clear();
		}
		
		void clear(){ // index doluluğu dizisini 0 lıyoruz çünkü ilk oluşturunda eleman yok
			for(int i=0; i<SIZE; i++){
				IndexFill[i] = 0;
			}
		}
		
		// ekleme işlemi
		void add(const Object & item){
			// küçükse sol çocukta büyükse sağ çocukta ilerleyecek şekilde gitmeliyiz.
			// kökten başlanır
			int currentIndex = 0;
			while(true){
				
				// durum 1 : hiç düğüm yok boş gördüğün yere ekle
				if(IndexFill[currentIndex] == 0){ // eğer 0 da yani boşsa ekleyeceğimiz yere gelmişizdir
					items[currentIndex] = item;
					IndexFill[currentIndex] = 1;
					break;
				}
				
				// düğüm var karşılaştırma yapıcaz
				
				// ekleyeceğimiz eleman şuanki düğümden daha küçük değerde
				// currentIndexi sol cocuğa gidecek şekilde düzenlicez
				else if(item < items[currentIndex]) currentIndex = 2*currentIndex+1;
				
				// ekleyeceğimiz eleman şuanki düğümden daha büyük değerde
				// currentIndexi sağ cocuğa gidecek şekilde düzenlicez
				else if(item > items[currentIndex]) currentIndex = 2*currentIndex+2;
				
				else return; // eşitse eklemiyoruz
			}
		}

		// arama işlemi. böyle bir eleman var mo yok mu
		bool find(const Object& item){
			// boşluk gelirse false döner
			if(FindIndex(item) == -1) return false;
			return true;
		}
		
		// agacın yüksekliği
		// eğer index verilirse verilen düğüm yüksekliği
		// verilmezse ağacın yüksekliği isteniyor demekdir
		int Height(int index=0){
			if(IndexFill[index] == 0) return -1; // durma kuralı. boş bir yere gelmişizdir
			
			// yükseklik önyineleme ile bulunur
			// her düğümün üzerine geldiğimizde solun ve sağın yüksekliğini alırız hangisi büyükse üzerine 1 koyup düğüm yüksekliğini buluruz
			
			// önce kökten en aşağı kadar gideriz ve son düğümde -1 döner. -1 in üzeirne 1 koyarsan da 0 yani enn alttaki düğümün yüksekliği
			// sonra 1 daha koy üste çık, böyle böyle gider
			
			return 1+max(Height(2*index+1), Height(2*index+2));
			// max sag mı sol mu büyük onu getirir
		}
		
		// dolaşımlar
		
		// sol çocuk düğümün kendisi sağ çocuk
		void inorder(int index = 0){
			// durma noktası boş düğüm 
			if(index < SIZE && IndexFill[index] != 0 ){
				inorder(2*index+1); // sol
				cout << items[index]<< " "; // kendisi
				inorder(2*index+2); // sağ
			}
		}
		void preorder(int index = 0){
			if(index < SIZE && IndexFill[index] != 0 ){
				cout << items[index]<< " "; // kendisi
				preorder(2*index+1); // sol
				preorder(2*index+2); // sağ
			}
			
		}
		void postorder(int index = 0){
			if(index < SIZE && IndexFill[index] != 0 ){
				postorder(2*index+1); // sol
				postorder(2*index+2); // sağ
				cout << items[index]<< " "; // kendisi
			}
		}
		void levelorder(int index = 0){
			// levelorder yaparsan en doğrusu dizi üzerinde gerçekleştirmek
			// çünkü zaten ağac dizite levelorder olarak yerleştirilir
			// diziyi dolaşsan yeter
			for(int i=0; i<SIZE; i++){
				if(IndexFill[i] == 1){
					cout << items[i] << " ";
				}
			}
		}
		
		// silme işlemi. sürekli silme yapılıyorsa bağıl liste tercih edilmeli, dizi tercih edilmemeli
		void Sil(const Object& eleman, int ind=0) throw(){
			int i = FindIndex(eleman, ind);
			if(i == -1) throw "HATA";
			else{
				IndexFill[i] = 0;//hiç çocuğu yoksa aşağıdaki hiçbir kod bloğu çalışmayacaktır. Sadece indis doluluğunu sıfır yapıp çıkacaktır.
				if(IndexFill[2*i+2] == 0)
				{
					if(IndexFill[2*i+1] == 1) //Sadece sol çocuğu varsa
					{
						int k = 2*i+1; int yedek[SIZE];
						for(int iter = 0; iter < SIZE ; iter++) yedek[iter] = 0;
						yedek[0] = k; int index = 0;
						
						// BFS algoritması kullanılarak sol alt ağaçtaki düğümler silinen düğümün yerine getiriliyor. yukarı taşınıyor
						for(int iter = 0; iter < SIZE && yedek[iter] != 0; iter++) 
						{
							for(int x = 0; x < SIZE; x++)
							{
								if(ikininKuvvetiMi(yedek[iter]+1-x))
								{
									items[(yedek[iter]+x-1)/2] = items[yedek[iter]];
									IndexFill[(yedek[iter]+x-1)/2] = 1;
									IndexFill[yedek[iter]] = 0;
									break;
								}
							}
							if(IndexFill[2*yedek[iter] + 1] != 0)
							{
									yedek[++index] = 2*yedek[iter] + 1;
							}
							if(IndexFill[2*yedek[iter] + 2] != 0)
							{
									yedek[++index] = 2*yedek[iter] + 2;
							}
						}
					}
				}
				else
				{
					if(IndexFill[2*i+1] == 0) //Sadece sağ çocuğu varsa
					{
						int k = 2*i+2; int yedek[SIZE];
						for(int iter = 0; iter < SIZE ; iter++) yedek[iter] = 0;
						yedek[0] = k; int index = 0;
						
						// BFS algoritması kullanılarak sağ alt ağaçtaki düğümler silinen düğümün yerine getiriliyor.
						for(int iter = 0; iter < SIZE && yedek[iter] != 0; iter++){
							for(int x = 0; x < SIZE; x++){
								if(ikininKuvvetiMi((yedek[iter]+x)/2+1)){
									items[(yedek[iter]-2-x)/2] = items[yedek[iter]];
									IndexFill[(yedek[iter]-2-x)/2] = 1;
									break;
								}
							}
							IndexFill[yedek[iter]] = 0;
							if(IndexFill[2*yedek[iter] + 1] != 0)
							{
									yedek[++index] = 2*yedek[iter] + 1;
							}
							if(IndexFill[2*yedek[iter] + 2] != 0)
							{
									yedek[++index] = 2*yedek[iter] + 2;
							}
						}
					}
					else //İki çocuğu varsa
					{
						int x = EnKucukDeger(2*i+2);
						Object kopyalanacak = items[x];
						IndexFill[i] = IndexFill[x];
						items[i] = items[x];
						Sil(kopyalanacak, x);
					}
				}
			}
		}
		
		~BST(){
			delete[] items;
		}
		
};

#endif