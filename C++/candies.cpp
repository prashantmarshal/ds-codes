#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;
#define For(i,s,l) for(int i = s; i < l; ++i)
#define scanint(n) scanf("%d", &n)
#define printint(n) printf("%d", n);


int main(){
    int T;
    scanint(T);
    int curr, prev = 0;
    int arr[T], arr2[T];
    scanint(arr[0]);
    arr2[0] = 1;
    For(i,1,T){
        scanint(arr[i]);
        if(arr[i] > arr[i-1])
            arr2[i] = arr2[i-1]+1;
        else if(arr[i] <= arr[i-1])
            arr2[i] = 1;
        
    }
    // int sum = 0;
    // for (int i = 0; i < T; ++i)
    // {   sum += arr2[i];

    // }
    // cout<<sum<<endl;

    // for (int i = 0; i < T; ++i)
    // {
    //     cout<<arr2[i]<<" ";
    // }
    // cout<<endl;
    // checking from last again
    int total=arr2[T-1];
    for (int i = T-2; i >= 0; --i)
    {
        if(arr[i] > arr[i+1] && arr2[i] <= arr2[i+1])
            arr2[i] = arr2[i+1]+1;
        total += arr2[i];
    }

    printint(total);printf("\n");
    
}


// 4 8 6 9 5 7 8 9 4 5 6 3 6 5 4

// 1 2 1 2 1 2 3 4 1 2 3 1 2 2 1