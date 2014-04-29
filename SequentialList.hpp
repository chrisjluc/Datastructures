#ifndef SEQUENTIAL_LIST_HPP
#define SEQUENTIAL_LIST_HPP

class SequentialList
{
	friend class SequentialListTest;
public:
	typedef int DataType;
public:
	SequentialList(unsigned int cap);
	~SequentialList();

	unsigned int size() const;
	unsigned int capacity() const;
	bool empty() const;
	bool full() const;
	DataType select(unsigned int pos) const;
	unsigned int search(DataType val) const;
	unsigned int length() const;
	void print() const;

	bool insert(DataType val, unsigned int pos);
	bool insert_front(DataType val);
	bool insert_back(DataType val);
	bool remove(unsigned int post);
	bool remove_front();
	bool remove_back();
	bool replace(unsigned int pos, DataType val);

private:
	DataType *data_;
	unsigned int capacity_;
	unsigned int size_;
private:
	SequentialList(const SequentialList& rhs){}
	SequentialList& operator=(const SequentialList& rhs){}
};
#endif
