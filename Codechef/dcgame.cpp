#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;


int searchbybinary(std::vector<int> v, int low, int high, int number){
	if(low > high)
		return -1;
	if(low == high && v[low] == number)
		return low;

	int mid = (low+high)/2;
	if(v[mid] > number)
		return searchbybinary(v, low, mid-1, number);
	else if(v[mid] < number)
		return searchbybinary(v, mid+1, high, number);
	else if(v[mid] == number)
		return mid;

	return -1;
}

int getcount(std::vector<int> v, int number, char sign){

	int mid = searchbybinary(v, 0, v.size()-1, number);
	
	int left, right, i, j;
	switch(sign){
		case '=':
			if(mid == -1)
				return 0;
			left = 0; i = mid-1;
			while(v[i] == number && i >= 0){
				++left;
				--i;
			}
			right = 0; j = mid+1;
			while(v[j] == number && j <= v.size()-1){
				++right;
				++j;
			}

			return left+right+1;
			break;
		case '>':
			if(number > v[v.size()-1])
				return 0;
			else if(number < v[0])
				return v.size();
			if(mid == -1){
				for(int start = 0; start < v.size()-1; ++start){
					if(v[start] < number)
						continue;
					else if(v[start] > number)
						return v.size()-start;
				}
			}

			right = 0; j = mid+1;
			while(v[j] == number && j <= v.size()-1){
				++right;
				++j;
			}
			return v.size()-1-(mid+right);
			break;
		case '<':
			if(number > v[v.size()-1])
				return v.size();
			else if(number < v[0])
				return 0;
			if(mid == -1){
				for(int start = 0; start < v.size()-1; ++start){
					if(v[start] < number)
						continue;
					else if(v[start] > number)
						return start;
				}
			}
			left = 0; i = mid-1;
			while(v[i] == number && j <= v.size()-1){
				++left;
				--i;
			}
			return mid-left;
			break;
		default:
			break;

	}

}

int main(){
	int n, games;
	cin>>n>>games;

	int *arr = new int[n];
	for(int i = 0; i < n; ++i)
		cin>>arr[i];
	char sign; int number; char player;

	vector<int> v;
	for(int i = 0; i < n; ++i){
		int max = INT_MIN;
		for(int j = i; j < n; ++j){
			if(arr[j] > max)
				max = arr[j];
			v.push_back(max);
			
		}	
	}

	sort(v.begin(), v.end());

	for(int i = 0; i < games; ++i){
		cin>>sign>>number>>player;
		int count;
		count = getcount(v, number, sign);
		cout<<count<<endl;
		if(count%2 == 0){
			if(player == 'D')
				cout<<"C";
			else
				cout<<"D";
		}else{
			cout<<player;
		}

	}

}
