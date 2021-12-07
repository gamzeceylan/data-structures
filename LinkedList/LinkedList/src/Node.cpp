#include "Node.hpp"


Node::Node(const int& data, Node* next){
    this->data = data;
    this->next = next;
}
Node::Node(){
    this->data=int();
    this->next=NULL;
}

