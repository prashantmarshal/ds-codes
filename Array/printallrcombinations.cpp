/*printallrcombinations print all combinations of numbers*/

#include <bits/stdc++.h>
using namespace std;

#define For(i,s,l) for (int i = s; i < l; ++i)
#define si(i) scanf("%d", &i)
#define sl(i) scanf("%ld", &i)
#define pi(i) printf("%d", i)
#define pl(i) printf("%ld", i);
#define scan(arr,l) for(int i = 0; i < l; ++i) si(arr[i])
#define SIZE(arr) sizeof(arr)/sizeof(arr[0])


void solverecur(int arr[], int data[], int curr, int start, int size, int k)
{
	if (curr == k)
	{
		for (int j=0; j<3; j++)
			printf("%d ", data[j]);
		printf("\n");
		return;
	}

	for(int i=start; i<=size+curr-k && i<size; ++i){
		data[curr] = arr[i];
		solverecur(arr,data,curr+1,start+1,size,k);
	}
}

void combinationUtil(int arr[], int data[], int start, int end, int index, int r)
{
    cout<<start<<" "<<end<<"  "<<index<<endl;
	if (index == r)
	{
		for (int j=0; j<r; j++)
			printf("%d ", data[j]);
		printf("\n");
		return;
	}

    	for (int i=start; i<=end && end-i+1 >= r-index; i++)
	{
		data[index] = arr[i];
		combinationUtil(arr, data, i+1, end, index+1, r);
	}
}



void solve(int arr[], int size){
	int k=3;
	int data[k];
	int pos=0,count=0;
	solverecur(arr,data,pos,count,size,k);
}

int main(int argc, char const *argv[])
{
	int arr[] = {1,2,3,4};
	int size=SIZE(arr);
	solve(arr,size);
	return 0;
}