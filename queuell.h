#include "lab3.h"

template <typename T>
class Queue{
	DList<T> theQueue_;
public:
	Queue(){		
	}
	void enqueue (const T& data){
		theQueue_.push_back(data);
	}
	void dequeue(){
		theQueue_.pop_front();
	}
	T front()const {
		return *(theQueue_.begin());
	}
	bool isEmpty(){
		return theQueue_.isEmpty();
	}
};