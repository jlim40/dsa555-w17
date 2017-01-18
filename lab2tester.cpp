#include "timer.h"
unsigned int factorial(unsigned int n);
double power (double base, unsigned int n);
unsigned int fibonacci (unsigned int n);

int main(void){
	Timer t;
	t.start();
	unsigned int rc=fibonacci(35);
	t.stop();
	cout << "fibonacci(35) = " << rc << endl;
	cout << "It took " << t.currtime() << " seconds" << endl;
	return 0;
}
