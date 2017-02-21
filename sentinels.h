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
	class const_iterator{
		friend class DList;
		const Node* curr_;  //all iterators have a way of looking
		              //at one particular piece of data
		const DList* myList_;  //address of the list that the node
	                 //belongs to.
		const_iterator(const Node* curr,const DList* myList){
			curr_=curr;
			myList_=myList;
		}
	public:
		const_iterator(){
			curr_=nullptr;
			myList_=nullptr;
		}
		const_iterator operator++(){
			//++x
			curr_=curr_->next_;
			return *this;
		}
		const_iterator operator++(int){
			//x++
			const_iterator old=*this;
			curr_=curr_->next_;
			return old;
		}
		const_iterator operator--();
		const_iterator operator--(int);
		T operator*() const{
			return curr_->data_;
		}
		bool operator==(const_iterator rhs) const{
			return (curr_==rhs.curr_ && myList_==rhs.myList_);
		}
		bool operator!=(const_iterator rhs) const{
			//return !(*this==rhs)
			return (curr_!=rhs.curr_ || myList_!=rhs.myList_);
		}
	};
	class iterator:public const_iterator{
		friend class DList;
		iterator(Node* curr,DList* myList):const_iterator(curr,myList){
		}
	public:
		iterator():const_iterator(){
		}
		iterator operator++(){
			//++x
			this->curr_=this->curr_->next_;
			return *this;
		}
		iterator operator++(int){
			//x++
			iterator old=*this;
			this->curr_=this->curr_->next_;
			return old;
		}
		iterator operator--();
		iterator operator--(int);
		T& operator*(){
			return (this->curr_)->data_;
		}
		bool operator==(iterator rhs) const{
			return (this->curr_==rhs.curr_ && this->myList_==rhs.myList_);
		}
		bool operator!=(iterator rhs) const{
			//return !(*this==rhs)
			return (this->curr_!=rhs.curr_ || this->myList_!=rhs.myList_);
		}
	};
	DList(){
		front_=new Node();
		back_=new Node();
		front_->next_=back_;
		back_->prev_=front;
	}
	void push_front(const T& data){
		Node* firstData=front_->next_;
		Node* beforeFirst=firstData->prev_;
		Node* nn=new Node(data,firstData,beforeFirst);
		firstData->prev_=nn;
		beforeFirst->next_=nn;
	}
	void push_back(const T& data){
		
	}
	void pop_front(){
	}
	void pop_back(){
	}
	void print() const{
		Node* curr=front_;
		while(curr){
			cout << curr->data_ << endl;
			curr=curr->next_;			
		}
		
	}
	//returns const_iterator to first node in LL
	const_iterator begin() const{
		return const_iterator( front_->next_,this );
	}
	//returns const_iterator to the node that follows the last node
	const_iterator end() const{
		return const_iterator(back_ , this);
	}
	//returns const_iterator to first node in LL
	iterator begin(){
		return iterator( front_->next_,this );
	}
	//returns const_iterator to the node that follows the last node
	iterator end(){
		return iterator(back_ , this);
	}
};













