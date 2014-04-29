#include "BinarySearchTree.hpp"
#include <iostream>
#define maxInt(a,b)  ((a)>=(b) ? (a) : (b))

using namespace std;
typedef BinarySearchTree::DataType DataType;
void deleteNode(BinarySearchTree::Node*);
BinarySearchTree::Node* findNode(BinarySearchTree::Node*,DataType val);
bool insertNode(BinarySearchTree::Node*, DataType);
bool search(BinarySearchTree::Node*, DataType);
DataType minBST(BinarySearchTree::Node*);
DataType maxBST(BinarySearchTree::Node*);
void printBST(BinarySearchTree::Node*,int);
void removeNode(BinarySearchTree::Node*,DataType);

BinarySearchTree::Node::Node(BinarySearchTree::DataType newval){
	val = newval;
	left = NULL;
	right = NULL;
}

BinarySearchTree::BinarySearchTree(){
	root_ = NULL;
	size_ = 0;
}

BinarySearchTree::~BinarySearchTree(){
	deleteNode(root_);
	root_ = NULL;
	size_ = 0;
}
void deleteNode(BinarySearchTree::Node* n){
	if(n == NULL)
		return;
	if(n->left != NULL)
		deleteNode(n->left);
	if(n->right != NULL)
		deleteNode(n->right);
	n->left = NULL;
	n->right = NULL;
	n->val = -1;
	delete n;


}

bool BinarySearchTree::insert(DataType val){
	if(root_ == NULL){
		root_ = new Node(val);
		size_++;
		return true;
	}
	if(insertNode(root_,val)){
		size_++;
		return true;
	}
	else
		return false;
}

bool insertNode(BinarySearchTree::Node* n, DataType val){
	if( n->val == val)
		return false;
	if(val < n->val){
		if(n->left != NULL)
			return insertNode(n->left,val);
		else{
			BinarySearchTree::Node* newNode = new BinarySearchTree::Node(val);
			n->left = newNode;
			return true;
		}
	}else{
		if(n->right != NULL)
			return insertNode(n->right,val);
		else{
			BinarySearchTree::Node* newNode = new BinarySearchTree::Node(val);
			n->right = newNode;
			return true;
		}
	}
}

bool BinarySearchTree::remove(DataType val){
	Node* n;
	if(root_== NULL)
		return false;
	if(root_->val == val){
		n = root_;
		//No children
		if(root_->left == NULL && root_->right == NULL){
			delete root_;
			root_ = NULL;
		}
		//Has a child on the left
		else if(root_->left != NULL && root_->right == NULL){
			Node* temp = root_->left;
			root_->left= NULL;
			delete root_;
			root_ = temp;
		}
		//Has a child on the right
		else if(root_->left == NULL && root_->right != NULL){
			Node* temp = root_->right;
			root_->right= NULL;
			delete root_;
			root_ = temp;
		}
		//Two children
		else{
			DataType temp = maxBST(root_->left);
			BinarySearchTree::Node* tempNode=findNode(root_,temp);
			root_-> val = temp;
			removeNode(tempNode,temp);
		}
	}
	else{
		n = findNode(root_,val);
		if(n == NULL)
			return false;
		removeNode(n,val);
	}
	size_--;
	return true;
}
void removeNode(BinarySearchTree::Node* n,DataType val){
	//if left child is the one to be removed
	if(n->left != NULL && n->left->val == val){
		//no children
		if(n->left->left == NULL && n->left->right == NULL){
			delete n->left;
			n->left = NULL;
			//child on the right
		}else if(n->left->left == NULL && n->left->right != NULL){
			BinarySearchTree::Node* temp = n->left->right;
			n->left->right = NULL;
			delete n->left;
			n->left = temp;
			//child on the left
		}else if(n->left->right == NULL && n->left->left != NULL){
			BinarySearchTree::Node* temp = n->left->left;
			n->left->left = NULL;
			delete n->left;
			n->left = temp;
			//two children
		}else{
			DataType temp = maxBST(n->left->left);
			BinarySearchTree::Node* tempNode=findNode(n->left,temp);
			n->left->val = temp;
			removeNode(tempNode,temp);

		}

	}
	else if(n->right != NULL &&n->right->val == val){
		//no children
		if(n->right->left == NULL && n->right->right == NULL){
			delete n->right;
			n->right = NULL;
			//child on the right
		}else if(n->right->left == NULL && n->right->right != NULL){
			BinarySearchTree::Node* temp = n->right->right;
			n->right->right = NULL;
			delete n->right;
			n->right = temp;
			//child on the left
		}else if(n->right->right == NULL && n->right->left != NULL){
			BinarySearchTree::Node* temp = n->right->left;
			n->right->left = NULL;
			delete n->right;
			n->right = temp;
			//two child
		}else{
			DataType temp = maxBST(n->right->left);
			BinarySearchTree::Node* tempNode=findNode(n->right,temp);
			n->right->val = temp;
			removeNode(tempNode,temp);
		}
	}
}

BinarySearchTree::Node* findNode(BinarySearchTree::Node* n,DataType val){

	if((n->left != NULL && n->left->val == val) ||(n->right != NULL && n->right->val == val))
		return n;
	if(val < n->val){
		if(n->left != NULL)
			return findNode(n->left,val);
		else{
			return NULL;
		}
	}
	else{
		if(n->right != NULL)
			return findNode(n->right,val);
		else{
			return NULL;
		}
	}
}

bool BinarySearchTree::exists(DataType val) const{
	if(root_ == NULL)
		return false;
	return search(root_,val);
}
bool search(BinarySearchTree::Node* n, DataType val){
	if( n->val == val)
		return true;
	if(val < n->val){
		if(n->left != NULL)
			return search(n->left,val);
		else{
			return false;
		}
	}else{
		if(n->right != NULL)
			return search(n->right,val);
		else{
			return false;
		}
	}
}

DataType BinarySearchTree::min() const{
	if(root_ == NULL)
		return -1;
	return minBST(root_);
}
DataType minBST(BinarySearchTree::Node* n){
	if(n->left == NULL)
		return n -> val;
	return minBST(n->left);
}


DataType BinarySearchTree::max() const{
	if(root_ == NULL)
		return -1;
	return maxBST(root_);
}
DataType maxBST(BinarySearchTree::Node* n){
	if(n->right == NULL)
		return n -> val;
	return maxBST(n->right);
}

unsigned int BinarySearchTree::size() const{
	return size_;
}

unsigned int BinarySearchTree::depth() const{
	return getNodeDepth(root_) - 1;
}

void BinarySearchTree::print() const{
	if(root_ == NULL)
		return;
	printBST(root_,0);
	cout << endl;

}
void printBST(BinarySearchTree::Node* t,int start)
{
	start++;
	if (t->right != NULL)
	{
		printBST(t->right,start);
	}
	for (int i = 0; i <= start; i++)
	{
		cout<<"    ";
	} 
	cout << t->val<<endl;
	if (t->left != NULL)
	{
		printBST(t->left, start);
	}
}

int BinarySearchTree::getNodeDepth(Node* n) const{
	if(!n)
		return 0;
	int height_left =  getNodeDepth(n -> left);
	int height_right = getNodeDepth(n -> right);
	return 1 + maxInt(height_left,height_right);
}
