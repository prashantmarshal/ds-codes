#include <iostream>
using namespace std;

int add(int a, int b){

	while(b != 0){
		int carry = a&b;
		a = a^b;
		b = carry<<1;
	}
	return a;
}

int subtract(int a, int b){

	while(b != 0){
		int borrow = (~a)&b;
		a = a^b;
		b = borrow<<1;
	}

	return a;
}

int getkthbit(int a, int k){
	return (a & 1<<(k-1))>>(k-1);
}

bool checkifbinaryispalindrome(int n){
	if(n == 0 || n == 1)
		return true;
	int length = 0, one = 0;
	for(int i = 0; i < 32; ++i){
		if((n & 1<<i)>>i== 1){
			++length;
			one = length;
		}else
			++length;
	}
	length = one;
	for(int i = 0; i < length; ++i){
		if(getkthbit(n, i+1) != getkthbit(n, length-i))
			return false;
		
	}
	return true;

}
int main(){
	/*cout<<subtract(7, 4);*/
	/*for(int i = 8; i >= 1; --i){
		cout<<getkthbit(16, i);
	}*/

	if(checkifbinaryispalindrome(7))
		cout<<"Yes.\n";
	else
		cout<<"No.\n";



}