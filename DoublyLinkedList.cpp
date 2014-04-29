#include "DoublyLinkedList.hpp"
#include <iostream>
using namespace std;

DoublyLinkedList::Node::Node(DoublyLinkedList::DataType val){
	value = val;
	next = NULL;
	prev = NULL;
}

DoublyLinkedList::DoublyLinkedList(){
	head_ = NULL;
	tail_ = NULL;
	size_ = 0;
}

DoublyLinkedList::~DoublyLinkedList(){

    if(head_ == NULL)
        return;     
	Node *n = head_;
	for(int i = 1; i < size_; i++){
        n = n -> next;
        delete n -> prev;
    }
    head_ = NULL;
    delete tail_;
    tail_ = NULL;
	size_ = 0;
}

unsigned int DoublyLinkedList::size() const{
	return size_;
}

unsigned int DoublyLinkedList::capacity() const{
	return CAPACITY;
}

bool DoublyLinkedList::empty() const{
	if(size_ == 0)
		return true;
	return false;
}

bool DoublyLinkedList::full() const{
	if(size_ == CAPACITY)
		return true;
	return false;
}

bool DoublyLinkedList::insert(DataType val, unsigned int pos){
	if(pos >= CAPACITY || pos > size_ || pos < 0 || full())
		return false;
	Node* newNode= new Node(val);

	if(head_ == NULL){
		head_ = newNode;
		tail_ = newNode;
	}else if(pos == 0){

		head_ -> prev = newNode;
		newNode -> next = head_;
		head_ = newNode;
	}else if(pos == size_){
		tail_ -> next = newNode;
		newNode -> prev = tail_;
		tail_ = newNode;

	}else{
		Node *n = head_;
		for(int i = 1; i < pos;i++)
			n = n -> next;
		newNode -> next = n -> next;
		newNode -> prev = n;
		n -> next = newNode;
		newNode -> next -> prev = newNode;

	}
	size_++;
	return true;
}

bool DoublyLinkedList::remove(unsigned int pos) {
	if(pos >= size_ || pos < 0 || empty())
		return false;
	Node *n = head_;
	for(int i = 0; i < pos; i++)
		n = n -> next;
	if(size_ == 1){
		delete head_;
		head_ = NULL;
		tail_ = NULL;
	}else if(pos == 0){
		head_ = head_ -> next;
		delete head_ -> prev;
		head_ -> prev = NULL;
	}else if(pos == (size_ - 1)){
		tail_ = tail_ -> prev;
		delete tail_ -> next;
		tail_ -> next = NULL;
	}else{
		Node *tempNode = n -> prev;
		n -> prev -> next = n -> next;
		n = n -> next;
		delete n -> prev;
		n -> prev = tempNode;
	}
	size_--;
	return true;
}

bool DoublyLinkedList::replace(unsigned int pos,DataType val){
	if(pos >= size_ || pos < 0)
		return false;
	Node *n = head_;
	for(int i = 0; i < pos;i++)
		n = n -> next;
	n -> value = val;
	return true;
}

bool DoublyLinkedList::insert_front(DataType val){
	return insert(val,0);
}

bool DoublyLinkedList::insert_back(DataType val){
	return insert(val,size_);
}

bool DoublyLinkedList::remove_front(){
	return remove(0);
}

bool DoublyLinkedList::remove_back(){
	return remove(size_-1);
}

void DoublyLinkedList::print() const{
	if(head_ != NULL){
		Node *n = head_;
		while(n != NULL){
			cout << n -> value;
			n = n -> next;
			if(n != NULL)
				cout << "->";
		}
		cout << endl;
	}
}

DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int pos) const{
	if(pos >= size_ || pos < 0)
		pos = size_ - 1;
	Node *n = head_;
	for(int i = 0; i < pos; i++)
		n = n -> next;
	return n -> value;
}
unsigned int DoublyLinkedList::search(DataType val) const{
	Node *n = head_;
	for(int i = 0; i < size_; i++){
		if(n -> value == val)
			return i;
		n = n-> next;
	}
	return size_;
}

