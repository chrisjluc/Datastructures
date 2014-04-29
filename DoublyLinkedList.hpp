#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP

class DoublyLinkedList{
	friend class DoublyLinkedListTest;
public:
	typedef int DataType;
	static const unsigned int CAPACITY = 65536;
private:
	struct Node{
		Node(DataType value);
		DataType value;
		Node* next;
		Node* prev;
	};
	Node* getNode(unsigned int pos) const;
public:
	DoublyLinkedList();
	~DoublyLinkedList();

	unsigned int size() const;
	unsigned int capacity() const;
	bool empty() const;
	bool full() const;
	DataType select(unsigned int pos) const;
	unsigned int search(DataType val) const;
	void print() const;

	bool insert(DataType val, unsigned int pos);
	bool insert_front(DataType val);
	bool insert_back(DataType val);
	bool remove(unsigned int pos);
	bool remove_front();
	bool remove_back();
	bool replace(unsigned int pos, DataType val);

private:
	Node* head_;
	Node* tail_;
	unsigned int size_;
};
#endif
