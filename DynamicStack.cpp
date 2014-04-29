#include "DynamicStack.hpp"
#include <iostream>

using namespace std;
typedef DynamicStack::StackItem StackItem;  // for simplicity
const StackItem DynamicStack::EMPTY_STACK = -999;

DynamicStack::DynamicStack()
{
	items_ = new StackItem[16];
	capacity_ = 16;
	size_ = 0;
	init_size_ = 16;

}

DynamicStack::DynamicStack(unsigned int size_)
{
	if(size_ <= 0)
		size_ = 16;
	items_ = new StackItem[size_];
	capacity_ = size_; 
	DynamicStack::size_ = 0;
	init_size_ = size_;
}

DynamicStack::~DynamicStack()
{
	delete [] items_;
	items_ = NULL;
	capacity_ = 0;
	size_ = 0;
	init_size_ = 0;
}

bool DynamicStack::empty() const
{
	if(size_ == 0)
		return true;
	return false;
}

int DynamicStack::size() const
{
	return size_;
}

void DynamicStack::push(StackItem value)
{
	if(size_ == capacity_){
		//Copy data to double-sized array
		int newItems[16384];
		for(int i = 0; i < size_; i++)
			newItems[i] = items_[i];
		//Delete old array and move copied data now.
		capacity_ *= 2;
		delete [] items_;
		items_ = new StackItem[capacity_];
		for(int i = 0; i < size_; i++)
			items_[i] = newItems[i];
	}
	//Add to stack
	items_[size_] = value;
	size_++;
}

StackItem DynamicStack::pop()
{
	if(empty())
		return EMPTY_STACK;
	//Check if number of items remaining is less than 1/4 size of array
	if(size_ - 1<= capacity_ / 4)
		if(capacity_/2 >= init_size_){
			//Copy data to double-sized array
			int newItems[16384];
			for(int i = 0; i < size_; i++)
				newItems[i] = items_[i];
			//Delete old array and move copied data now.
			capacity_ /= 2;
			delete [] items_;
			items_ = new StackItem[capacity_];
			for(int i = 0; i < size_; i++)
				items_[i] = newItems[i];
		}
		size_ --;
		return items_[size_];
}

StackItem DynamicStack::peek() const
{
    if(empty())
        return EMPTY_STACK;
	return items_[size_ - 1];
}

void DynamicStack::print() const
{
	if(empty())
		return;
	for(int i = size_ - 1; i >= 0; i--)
		cout << items_[i] << " ";
	cout << endl;
}
