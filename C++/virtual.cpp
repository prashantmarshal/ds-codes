#include <iostream>
#include <stdio.h>
using namespace std;

class Employee{
public:
	void printPay(){//Employee e){ // reference will only work as then it is not type cast?
		// printf("Calling printPay() -- \n");
		// e.
		pay();
	}

	virtual 
	void pay(){
		printf("Inside Employee -- \n");
	}
};

class Manager : public Employee{
public:
	virtual
	 void pay(){
		printf("Inside Manager -- \n");
	}

};
int main(){
	Manager e;
	e.printPay();
}