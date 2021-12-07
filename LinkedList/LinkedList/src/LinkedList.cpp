    #include "LinkedList.hpp"
    #include "Node.hpp"

    LinkedList::LinkedList(){
        head = new Node(); // boş düğüm oluşturuyoruz. parametre girmediğimiz için zaten head->next'i null olur
        size = 0;
    }

    Node *LinkedList::FindPrevPosition(int position){ // ekleme silme işlemlerinde hep bir öncesine yerleşmemiz gerekir
                                                            // aynı döngüyü birden fazla yazmamak için bu fonk tanımladık
        Node *temp=head;
        for(int i=0; i<position; i++){
            if(i == position) return temp;
            temp=temp->next;
        }

    }

    bool LinkedList::isEmpty()const{
        // if(isEmpty()) throw hata;
        return size==0;
        // return head->next == nullptr;
    }
   

    int LinkedList::count()const{
        return size;
    }
     

    void LinkedList::add(const int& data){
        insert(size, data);
    }
    

    void LinkedList::insert(int index, const int& data){
        
        if(index == 0 && size==0){
            Node *node = new Node(data,NULL);
            head->next = node;
        }
        else if(index == 0 && size >0){
            Node *node = new Node(data, head->next);
            head = node;
        }
        Node *temp = FindPrevPosition(index);
        temp->next = new Node(data, temp->next);
        size++;
	}
     

    const int& LinkedList::LinkedList::first()const{
        return head->next->data;
    }
     

    const int& LinkedList::last(){
        Node *temp = FindPrevPosition(size);
        return temp->data;
    }
    

    int LinkedList::indexOf(const int& data){
        Node *temp = head->next;
        for(int index=0; index<size; index++){
            if(temp->data == data)
                return index;
            
            temp = temp->next;
        }
        throw "Element is not current";
    }
     

    const int& LinkedList::elementAt(int index){
        // if(index < 0 || index >= size) throw hata;
        Node *temp = FindPrevPosition(index);
        return temp->next->data;
    }
     

    bool LinkedList::find(const int& data)const{
        Node *temp= head->next;
        for(int i=0; i<size; i++){
            if(temp->data==data)
                return true;
            temp=temp->next;
        }
        return false;
    }
     

    void LinkedList::remove(const int& data){
        int index= indexOf(data);
        removeAt(index);
    }


    void LinkedList::removeAt(int index){ // 0 olmasını kontorl etmedim
        if(index == 0 && size > 0){
            Node* del= head->next;
            head = del->next;
            delete del;
        }

        Node *temp = FindPrevPosition(index);
        Node *del = temp->next;
        temp->next = temp->next->next;
        delete del; // silmemiz gerekn adrestir. isimler zaman stackte. düğümler new ile oluştuğundna ilgili düğüm adresi heapte. o adresi alıyoruz
        size--;
    }


    void LinkedList::clear(){
        while(!isEmpty())
            removeAt(0); // her seferinde 0. indexi silecek
			// removeAt e del var. çöp oluşmaz

    }

    LinkedList::~LinkedList(){
        // çöp işleri
			
			// eğer clear demeden yıkıcı fonksiyon çalışırsa çöp oluşur.
			// burada yıkıcı fonk. düğümleri silmez. linkedlist nesnesini siler
			// nesne içindeki düğümlere dokunmaz.
		clear();
			
			// listeyi silse bile bizim ilk başta bir tane düğümümüz vardı
			// onu da burada silmemiz gerekir
		delete head;


        // yıkıcı fonksiyon senin oluşturduğun new lere dokunmaz. sınıfı bellekten siler kalanıyla ilgilenmez
    }


    std::ostream& operator<<( std::ostream& screen, LinkedList& item){
        for(Node *itr=item.head; itr != NULL; itr++){
           screen << item.head->next << "->";
        }
        return screen;
    }

    /*
        NOT: friend fonksiyonlar hpp dosyaısnda tanımlanmaz. çünkü sınıfa ait değiller
    */

  