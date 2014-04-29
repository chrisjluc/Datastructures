#include "SequentialList.hpp"
#include <iostream>

using namespace std;

SequentialList::SequentialList(unsigned int cap){
	data_ = new DataType[cap];
	for(int i = 0; i < cap; i++)
		data_[i] = 0;
	size_ = 0;
	capacity_ = cap;
}

SequentialList::~SequentialList(){
	delete [] data_;
	data_ = NULL;
	capacity_ = 0;
	size_ = 0;

}

unsigned int SequentialList::size() const{
	return size_;
}

unsigned int SequentialList::capacity() const{
	return capacity_;
}

bool SequentialList::empty() const{
	if(size_ == 0)
		return true;
	return false;
}

bool SequentialList::full() const{
	if(size_ == capacity_)
		return true;
	return false;
}

bool SequentialList::insert(DataType val, unsigned int pos){
	if(pos >= capacity_ || pos > size_ || pos < 0 || full())
		return false;

	DataType tempVal = data_[pos];
	data_[pos] = val;
	int i = pos;
	while(i < size_){
		i++;
		DataType temp = data_[i];
		data_[i] = tempVal;
		tempVal = temp;	
	}
	size_++;
	return true;

}

bool SequentialList::replace(unsigned int pos, DataType val){
	if(pos < 0 || pos >= size_)
		return false;
	data_[pos] = val;
	return true;

}

bool SequentialList::remove(unsigned int pos){
	if(pos >= capacity_ || pos >= size_ || pos < 0 || empty())
		return false;
	int i = pos;
	while(i < size_){
		data_[i] = data_[i + 1];
		i++;
	}
	size_--;
	return true;

}

bool SequentialList::insert_front(DataType val){
	return insert(val,0);
}

bool SequentialList::insert_back(DataType val){
	return insert(val,size_);
}

bool SequentialList::remove_front(){
	return remove(0);
}

bool SequentialList::remove_back(){
	return remove(size_-1);
}

SequentialList::DataType SequentialList::select(unsigned int pos) const{
	if(pos < 0 || pos >= size_)
		return data_[size_ - 1];
	return data_[pos];
}

unsigned int SequentialList::length() const{
	return size_;
}

void SequentialList::print() const{
	for(int i = 0; i < size_; i++){
		cout << data_[i];
		if(i < size_ - 1)
			cout << "->";
	}
	cout << endl;
}

unsigned int SequentialList::search(DataType val) const{
	for(int i = 0; i < size_; i ++)
		if(data_[i] == val)
			return i;
	return size_;
}
