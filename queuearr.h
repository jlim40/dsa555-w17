#include "lab3.h"

template <typename T>
class Queue{
	T* theQueue_;
	int max_;
	int size_;
	int front_;
	int back_;
	void grow(){
		T* tmp=new T[max_*2];
		int j=front_;
		for(int i=0;i<size_;i++){
			tmp[i]=theQueue_[j];
			j=(j+1)%max_;
		}
		max_=max_*2;
		delete [] theQueue_;
		theQueue_=tmp;
		front_=0;
		back_=size_-1;
	}
public:
	Queue(){		
		theStack_=new T[50];
		max_=50;
		size_=0;
		front_=0;
		back_=0;
	}
	void enqueue (const T& data){
		if(size_ == max_){
			grow();
		}
		theQueue_[back_]=data;
		//back_=(back_+1)%max_
		back_=back_+1;
		if(back_==max_){
			back_=0;
		}
		size_++;
	}
	void dequeue(){
		if(!isEmpty()){
			front_=front_+1;
			if(front_==max_){
				front_=0;
			}
			size_--;
		}
	}
	T front()const {
		return theQueue_[front_];
	}
	bool isEmpty(){
		return size_==0;
	}
};