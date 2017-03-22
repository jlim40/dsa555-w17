template <typename T>
class BST{
	struct Node{
		T data_;
		Node* left_;
		Node* right_;
		Node(const T& data=T{},Node* left, Node* right){
			left_=left;
			right_=right;
			data_=data;
		}
	};
	Node* root_;
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
	void remove(const T& data);
	void print(const int order=1) const{
		switch(order){
			case 1: preOrderPrint(root_); break;
			case 2: inOrderPrint(root_); break;
			case 3: postOrderPrint(root_); break;
			case 4: reversePrint(root_); break;
			case 5: breadthfirstPrint(); break;
			default: preOrderPrint(root_);
		}
	}
};