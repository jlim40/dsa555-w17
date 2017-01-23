#include <iostream>
using namespace std;

template <typename T>
class DList{
	struct Node{
		T data_;
		Node* next_;
		Node* prev_;
		Node(const T& data,Node* next=nullptr,Node* prev=nullptr){
			data_=data;
			next_=next;
			prev_=prev;
		}
	};
	Node* front_;
	Node* back_;
public:
	DList(){
	}
	void push_front(const T& data){
	}
	void push_back(const T& data){
		
	}
	void pop_front(){

	}
	void pop_back(){
	}
};

