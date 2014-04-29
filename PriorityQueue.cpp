#include "PriorityQueue.hpp"
#include <iostream>
#include <math.h>

using namespace std;
typedef PriorityQueue::DataType DataType;
void enqueuesort(int,DataType*);
void swap(DataType*,DataType*);
void dequeuesort(int,int,DataType*);

PriorityQueue::PriorityQueue(unsigned int capacity){
	heap_ = new DataType[capacity + 1];
	capacity_ = capacity;
	size_ = 0;
}

PriorityQueue::~PriorityQueue(){
	delete [] heap_;
	heap_ = NULL;
	capacity_ = 0;
	size_ = 0;
}
unsigned int PriorityQueue::size() const{
    return size_; 
 }

bool PriorityQueue::enqueue(DataType val){
	if(full())
		return false;
	heap_[++size_] = val;
	enqueuesort(size_,heap_);
	return true;
}

void enqueuesort(int size, DataType* a){
	if(size == 1)
		return;
	int temp = size/2;
	//child is bigger than parent swap
	if(a[size] > a[temp]){
		swap(a[size],a[temp]);
		enqueuesort(temp,a);
	}
}
void swap(DataType* a,DataType* b){
	DataType temp = *a;
	*a = *b;
	*b = temp;
}
bool PriorityQueue::dequeue(){
	if(empty())
		return false;
	heap_[1] = heap_[size_];
	size_--;
	dequeuesort(1,size_,heap_);
	return true;
}
void dequeuesort(int pos, int size, DataType* a){
	//Check we don't go past the maximum level and if a child exists for the node
	if(pos / 2 == size / 2 || pos * 2 > size)
		return;
	int temp = 0;
	//If right child doesn't exist or right child is smaller than left
	if(pos * 2 + 1 > size || a[pos * 2 + 1] < a[pos * 2])
		temp = pos * 2;
	else
		temp = pos * 2 + 1;
	if(a[pos] < a[temp]){
		swap(a[pos],a[temp]);
		dequeuesort(temp,size,a);
	}
}

DataType PriorityQueue::max() const{
	if(empty())
		return -1;
	return heap_[1];
}

bool PriorityQueue::empty() const{
	if(size_ == 0)
		return true;
	return false;
}

bool PriorityQueue::full() const{
	if(size_ == capacity_)
		return true;
	return false;
}

void PriorityQueue::print() const{
	if(empty())
		return;
	int level = size_/2 + 1;
	int size = 1;
	//Traverse level by level
	for(int i = 0; i < level; i++){
		//Print all the nodes at that level
		for(int j = 0; j < pow(2,i);j++){
			if(size == size_ + 1){
				cout << endl;
				return;
			}
			cout << heap_[size] << " ";
			size++;
		}
		cout << endl;
	}

}
