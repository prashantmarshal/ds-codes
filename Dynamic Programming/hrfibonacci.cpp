/*incomplete*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void multiply(int *arr, int number){ // number is stored reverse in arr1
	
	int n;
	for(int i = 0; i <= curr_length; ++i){
		n = arr[i]*number + carry;
		arr[i] = n%10; 
		carry = n/10;	
	}
	
	while(carry){
		++curr_length;
		arr[curr_length] = carry%10;
		carry = carry/10;
	}
	return curr_length;

}

void addnumbers(int *arr1, int *arr2){
	
	
}

int main() {
	int a, b, N;
	
	cin>>a>>b>>N;
    
    int T[N][500];
    int i = 0;
    while(a){
    	T[0][i] = a%10;
    	++i;
    }
    while(b){
    	T[1][i] = a%10;
    	++i;
    }

    for(int i = 2; i < N; ++i){
    	// T[i] = T[i-1]*T[i-1] + T[i-2];
    	T[i][] = sumof(product(T[i-1], T[i-1]), T[i-2]);

    }
    

    return 0;
}
