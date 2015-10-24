/*binary search modified finding element lesser than the given one*/

#include <bits/stdc++.h>
using namespace std;

int NextLargestBinSearch( int key, int data[], const int len )
{
    int low  = 0;
    int high = len-1;

    while( low <= high)
    {

        int mid = low + ((high - low) / 2);

		if (data[mid] < key) low  = mid + 1;
        else if (data[mid] > key) high = mid - 1;
        else return                      mid + 1;
    }

    if( high < 0 )
        return 0;
    else
    if( low > (len-1))
        return len; 
    else
        return (low < high)
            ? low  + 1
            : high + 1;
}

int modifiedbinarysearch(int arr[], int low, int high, int number){
	// cout<<low<<" " <<high<<endl;
	if(arr[low] > number)
		return low - 1;

	if(low>=high)
		return low-1;
	
	int mid = (low+high)/2;
	
	if(arr[mid]>=number){
		if(mid!= 0 && arr[mid-1] < number)
			return mid-1;
		return modifiedbinarysearch(arr,low,mid-1,number);
	}else 
		return modifiedbinarysearch(arr,mid+1,high,number);

}

int main(){
	int arr[] = {1,2,4,7,7,7,7,10,15,16,25};

	// int res = modifiedbinarysearch(arr,0,10,5);
	// // cout<<i<<" ";
	// cout<<res<<" ";
	// cout<<arr[res]<<endl;
	for(int i = 0; i < 10; ++i){
	int res = NextLargestBinSearch(i,arr,10);
		cout<<i<<" ";
		cout<<arr[res]<<endl;	
	}
	
}

