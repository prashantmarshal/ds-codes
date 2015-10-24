/*Find the closest pair from two sorted arrays*/

#include <iostream>
#include <cmath>
#include <queue>
#include <climits>
using namespace std;

void findclosest(int *arr1, int *arr2, int size1, int size2, int sum){
	int i = 0;
	int j = size2-1;
	int res = INT_MAX;
	int one = 0, two = size2-1;
	while(i < size1 && j >= 0){
		
		if(arr1[i]+arr2[j] > sum){
			if(res > arr1[i]+arr2[j] - sum){
				res = arr1[i]+arr2[j] - sum;
				one = i;
				two = j;
			}
			--j;
		}
		else if(arr1[i]+arr2[j] < sum){
			if(res > sum - arr1[i]-arr2[j]){
				res = sum - (arr1[i]+arr2[j]);
				one = i;
				two = j;
			}
			++i;
		}else
			break;
	}

	cout<<arr1[one]<<" "<<arr2[two]<<endl;

}
{} how is you
int main(){

    int arr1[] = {1, 4, 5, 7};
    int arr2[] = {10, 20, 30, 40};
    findclosest(arr1, arr2, sizeof(arr1)/sizeof(int), sizeof(arr2)/sizeof(int), 50);
}