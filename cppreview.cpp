#include <iostream>
using namespace std;

class MyClass{
	int val_;
public:
	MyClass(int val=0){
		val_=val;
	}
	int val() const{return val_;}
	int val2() {return val_;}
	void set(int v){
		val_=v;
	}
};
void swap(MyClass& a,MyClass& b){
	MyClass tmp=a;
	a=b;
	b=tmp;
}
void myFunction(MyClass* a, MyClass* b){
	MyClass* tmp=a;
	a=b;
	b=tmp;
}

void myFunction2(MyClass*& a, MyClass*& b){
	MyClass* tmp=a;
	a=b;
	b=tmp;
}

int main(void){
	MyClass A;
	MyClass* B=&A; //B points to A, B holds address of A
	MyClass& C=A;  //C is another name for A
	MyClass D(10);
	MyClass* E=&D;
	myFunction2(B,E);
	cout << B->val() << endl;
	cout << E->val() << endl;


	myFunction(B,E);
	cout << B->val() << endl;
	cout << E->val() << endl;


	myFunction(&A, & D);
	cout << A.val() << endl;
	cout << D.val() << endl;


	swap(A,D);
	cout << C.val() << endl;

	cout << B->val() << endl;
	cout << (*B).val() << endl;
	//cout << B.val() << endl;
	//cout << *B.val() << endl;
}







