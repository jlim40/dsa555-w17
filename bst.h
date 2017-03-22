#include "queuearr.h"
template <typename T>
class BST{
	struct Node{
		T data_;
		Node* left_;
		Node* right_;
		Node(const T& data=T{},Node* left=nullptr, Node* right=nullptr){
			left_=left;
			right_=right;
			data_=data;
		}
	};
	Node* root_;
	void remove(const T& data,Node*& rt){
		if(rt){
			if(rt->data_ == data){
				Node* rm =rt;
				if(rt->left_==nullptr && rt->right_==nullptr){
					//If the node is a leaf
					//make link from parent a nullptr		
					rt=nullptr;
				}
				else if(rt->left_!= nullptr && rt->right_!=nullptr){
						//if the node has two children
		    			//find the node's inorder successor (next biggest decsendent node)
		    			//detach the inorder successor
				    //the inorder successor will take the place of the node being deleted
				    //ie parent points to this node, this node points to the two children

				}
				else{
					if(rt->right_){
						//right child only
					}
					else
						//left child only
				}

				delete rm;
		//if the node has one child
		    //make link from parent point to only child
				//found it!  yay!  unlink and remove
			}
			else if(data < rt->data_){
				remove(data,rt->left_);
			}
			else{
				remove(data,rt->right_);
			}
		}
	}
	void insert(const T& data,Node*& rt){
		if(rt == nullptr){
			rt=new Node(data);
		}
		else{
			if(data < rt->data_){
				insert(data,rt->left_);
			}
			else{
				insert(data,rt->right_);
			}
		}
	}
	Node* insert2(const T& data, Node* rt){
		Node* rc=rt;
		if(rt == nullptr){
			rc=new Node(data);
		}
		else{
			if(data < rt->data_){
				rt->left_=insert(data,rt->left_);
			}
			else{
				rt->right_=insert(data,rt->right_);
			}
		}
		return rc;

	}
	void preOrderPrint(const Node* rt)const{
		if(rt!= nullptr){
			cout << rt->data_  << endl;
			preOrderPrint(rt->left_);
			preOrderPrint(rt->right_);
		}
	}
	void postOrderPrint(const Node* rt)const{
		if(rt!= nullptr){
			postOrderPrint(rt->left_);
			postOrderPrint(rt->right_);
			cout << rt->data_  << endl;
		}
	}
	void inOrderPrint(const Node* rt)const{
		if(rt!= nullptr){
			inOrderPrint(rt->left_);
			cout << rt->data_  << endl;
			inOrderPrint(rt->right_);
		}
	}
	void reverseOrderPrint(const Node* rt)const{
		if(rt!= nullptr){
			reverseOrderPrint(rt->right_);
			cout << rt->data_  << endl;
			reverseOrderPrint(rt->left_);
		}
	}
	void breadthfirstPrint() const{
		Queue<Node*> q;
		q.enqueue(root_);
		while(!q.isEmpty()){
			Node* curr=q.front();
			cout << curr->data_ << endl;
			q.dequeue();  //removes front item
			if(curr->left_)
				q.enqueue(curr->left_);
			if(curr->right_)
				q.enqueue(curr->right_);
		}
	}

public:
	BST(){
		root_=nullptr;
	}
	void insertRecursive(const T& data){
		insert(data,root_);
	}
	void insertRecursive2(const T& data){
		root_=insert2(data,root_);
	}
	void insertIterative(const T& data){
		if(root_==nullptr){
			root_=new Node(data);
		}
		else{
			Node* curr=root_;
			while(curr){
				if(data < curr->data_){
					if(curr->left_==nullptr){
						curr->left_=new Node(data);
						curr=nullptr;
					}
					else{
						curr=curr->left_;
					}
				}
				else{
					if(curr->right_==nullptr){
						curr->right_=new Node(data);
						curr=nullptr;
					}
					else{
						curr=curr->right_;
					}

				}
			}
		}
	}
	void remove(const T& data){
		remove(data,root_);
		//find the node containing data
		
	}
	void print(const int order=1) const{
		switch(order){
			case 1: preOrderPrint(root_); break;
			case 2: inOrderPrint(root_); break;
			case 3: postOrderPrint(root_); break;
			case 4: reverseOrderPrint(root_); break;
			case 5: breadthfirstPrint(); break;
			default: preOrderPrint(root_);
		}
	}
};