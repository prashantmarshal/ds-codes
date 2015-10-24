/*Program for Fibonacci numbers*/

#include <iostream>
using namespace std;


int fibonacci(int n){
	if(n == 0)
		return 0;
	if(n == 1 || n ==2)
		return 1;

	int fib[n+1];
	fib[0] = 0; fib[1] = 1; fib[2] = 1;

	for(int i = 3; i <= n; ++i){
		fib[i] = fib[i-1] + fib[i-2];
	}
	return fib[n];
}

int main(){
	int n;
	cout<<"Enter n:\n";
	cin>>n;
	cout<<fibonacci(n);
}