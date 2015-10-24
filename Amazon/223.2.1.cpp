/*largest rectanlge are from histogram*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;
#define For(i,s,l) for(unsigned long long int i = s; i < l; ++i)

int givemaxarea(int *arr, int n){

	stack<int> s;
	int area = 0, maxarea = 0;
	For(i,0,n){
		if(s.empty())
			s.push(i);
		else{
			if(arr[i] >= arr[s.top()])
				s.push(i);
			else{
				while(!s.empty() && arr[s.top()] > arr[i]){
					int s_top_1 = s.top();
					int s_top;
					s.pop();
					if(!s.empty()){
						s_top = s.top();
						area = arr[s_top_1]*(i-s_top-1);
					}else if(s.empty())
						area = arr[s_top_1]*i;						
					maxarea = max(maxarea, area);
				}
				s.push(i);
			}
		}
	}
	if(!s.empty()){
		int s_size1 = s.size();
		int s_size = s_size1;
		int s_top_1 = s.top();
		while(s_size1--){
			int curr = s.top();			
			s.pop();
			int s_top;
			if(!s.empty()){
				s_top = s.top();
				area = arr[curr]*(s_top_1-s_top);
			}else if(s.empty())
				area = arr[curr]*(s_top_1);
			maxarea = max(maxarea, area);
		}
	}

	return maxarea;
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	// int arr[] = {4,5,7,8,9,6,3,2,1,4,5,7,8,9,6,3,5,2,2,5,6,6,9,8,7,4,5,1,2,3,6};
	For(i,0,n)
	cin>>arr[i];
	// n = sizeof(arr)/sizeof(arr[0]);
	int res = givemaxarea(arr, n);
	cout<<res;
}
// 4,5,7,8,9,6,3,2,1,4,5,7,8,9,6,3,5,2,2,5,6,6,9,8,7,4,5,1,2,3,6