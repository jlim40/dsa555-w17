#include "lab3.h"
int main(void){
	DList<int> list;
	DList<int>::const_iterator it;

	list.push_front(30);
	list.push_front(10);
	list.push_back(20);
	it = list.begin();
	while(it != list.end()){
		cout << *it << endl;
		it++;
	}
	DList<int>::iterator it2=list.begin();
	while(it2!= list.end()){
		*it2=*it2+1;
		it2++;
	}
	it = list.begin();
	while(it != list.end()){
		cout << *it << endl;
		it++;
	}

	return 0;
}
