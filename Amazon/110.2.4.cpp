/*Maximum sum subarry along with its starting and ending index. important*/

#include <iostream>
using namespace std;

int maximumsumsubarray(int *arr, int n){
	int curr_sum = arr[0], max_sum = arr[0];
	
	int s = 0, e = 0;

	for(int i = 1; i < n; ++i){
		curr_sum = max(curr_sum+arr[i], arr[i]);
		if(arr[i] == curr_sum){
			s = i;
			e = i;
		}
		max_sum = max(curr_sum, max_sum);
		if(max_sum == curr_sum)
			e = i;
	}

	cout<<s<<" "<<e<<endl;
	return max_sum;
}

int main(){
	int arr[] =  {-2, -3, 4, -1, -2, 1, 5, -3};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<maximumsumsubarray(arr, n);
}