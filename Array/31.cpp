#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool ispalindrome(string str){
	int l = str.length();
	int i = 0, k = l - 1;
	while(i < k){
		if(str[i] == str[k]){
			++i; --k;
		}
		else
			return false;
	}
	return true;
}

int checkpalindrome(string str, int first, int second, int n){
    string first_check = str.substr(first, second-first);
	string second_check = str.substr(first+1, second-first);
    
    if(ispalindrome(first_check))
    	return second;
    else if(ispalindrome(second_check))
    	return first;
    return -1;
}
int main() {
    int T;
    cin>>T;
    while(T--){
        string str;
        cin>>str;
        
        
        int index = -1;
        int n = str.length();
        int i = 0, k = n-1;
        while(i < k){
            if(str[i] == str[k]){
            	++i; --k;
            }
            else{
                index = checkpalindrome(str, i, k, n);
                break;
            }
        }
        cout<<index<<endl;
    }
    return 0;
}
