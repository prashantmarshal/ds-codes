#include <iostream>
using namespace std;

int multiply(int p, int res[], int size){
	int carry=0,prod;
	for(int i=0; i<size; ++i){
		prod = res[i]*p+carry;
		res[i] = prod%10;
		carry = prod/10;
	}

	while(carry){
		res[size] = carry%10;
		carry /= 10;
		size++;
	}

	return size;
}

void factorial(int n){
	int res[500];
	res[0]=1;
	int size=1;


	for(int i=2; i<=n; ++i){
		size = multiply(i,res,size);
	}

	for(int i=size-1; i>=0; --i){
		cout<<res[i];
	}
}


int main(){
		int n;
	while(cin>>n)
{	factorial(n);
cout<<endl;

}
}