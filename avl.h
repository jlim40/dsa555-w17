#include "queuearr.h"
template <typename T>
class AVL{
	struct Node{
		T data_;
		Node* left_;
		Node* right_;
		int height_;
		Node(const T& data=T{}){
			left_=nullptr;
			right_=nullptr;
			data_=data;
			height_=1;
		}
		//returns the height of right subtree - height left subtree
		int balance()const{
			return rightHeight()-leftHeight();
		}
		int leftHeight(){
			return (left_)?left_->height_:0;
		}
		int rightHeight(){
			return (right_)?right_->height_:0;
		}
		void setHeight(){
			int lh=leftHeight();
			int rh=rightHeight();
			height_=(lh>rh)?lh+1:rh+1;
		}	
	};
	Node* root_;
	void leftRotate(Node*& n){
		Node* A=n;
		Node* B=n->right_;
		Node* Y=B->left_;

		A->right_= Y;
		B->left_= A;
		n = B;
	}
	void rightRotate(Node*& n){
		Node* A=n;
		Node* B=A->left_;
		Node* Y=B->right_;

		A->left_=Y;
		B->right_=A;
		n=B;
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
			if(rt->balance() >= 2 ){
				if(rt->right_->balance() >= 1){
					leftRotate(rt);
					rt->right_->setHeight();
					rt->setHeight();
				}
				else{
					rightRotate(rt->right_);
					leftRotate(rt);
					rt->left_->setHeight();
					rt->right_->setHeight();
					rt->setHeight();
				}
			}
			else if(rt->balance() <= -2){
				if(rt->left_->balance() <= -1){
					rightRotate(rt);
					rt->left_->setHeight();
					rt->setHeight();
				}
				else{
					leftRotate(rt->left_);
					rightRotate(rt);
					rt->left_->setHeight();
					rt->right_->setHeight();
					rt->setHeight();				}
			}
			else{
				rt->setHeight();
			}

		}
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
	AVL(){
		root_=nullptr;
	}
	void insert(const T& data){
		insert(data,root_);
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