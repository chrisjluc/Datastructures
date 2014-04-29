#include "CircularQueue.hpp"
#include <iostream>

using namespace std;
typedef CircularQueue::QueueItem QueueItem;  // for simplicity
const QueueItem CircularQueue::EMPTY_QUEUE = -999;

CircularQueue::CircularQueue()
{
	items_ = new QueueItem[16];
	capacity_ = 16;
	size_ = 0;
	head_ = 0;
	tail_ = 0;
}

CircularQueue::~CircularQueue()
{
	delete [] items_;
	items_ = NULL;
	size_ = 0;
	head_ = 0;
	tail_ = 0;
}

bool CircularQueue::empty() const
{   
	if(size_ == 0)
		return true;
	return false;
}

bool CircularQueue::full() const
{ 
	if(size_ == capacity_)
		return true;
	return false;
}

int CircularQueue::size() const
{ 
	return size_;
}

bool CircularQueue::enqueue(QueueItem value)
{
	if(full())
		return false;

	items_[tail_] = value;
	tail_ = (tail_ + 1) % capacity_;
	size_++;
	return true;
}

QueueItem CircularQueue::dequeue()
{
	if(empty())
		return EMPTY_QUEUE;
	QueueItem qi = items_[head_];
	head_ = (head_ + 1) % capacity_;
	size_--;
	return qi;
}

QueueItem CircularQueue::peek() const
{
	if(empty())
		return EMPTY_QUEUE;
	return items_[head_];
}

void CircularQueue::print() const
{
	if(empty())
		return;

	int size = size_;
	int i = head_;
	while(size > 0){
		cout << items_[i] << " ";
		i++;
		if(i == 16)
			i = 0;
		size--;
	}
	cout << endl;
}
