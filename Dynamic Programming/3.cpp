#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long int numberofwaysdp(long long int arr[], long long int coins, long long int sum){
    long long int table[coins+1][sum+1];
    for(long long int i = 0; i <= coins; ++i){
        for(long long int k = 0; k <= sum; ++k){
            table[i][k] = 0;
            if(k == 0)
                table[i][k] = 1; // no coins is the number of ways
            else if(i == 0 && k > 0)
                table[i][k] = 0;
            else{
                if(k >= arr[i-1]){
                    table[i][k] = table[i-1][k] + table[i][k-arr[i-1]];
                }else{
                    table[i][k] = table[i-1][k];
                }
                    
            }
        }
    }
    
    return table[coins][sum];
}

int main() {
    long long int sum, coins;
    cin>>sum>>coins;
    long long int arr[coins];
    for(long long int i = 0; i < coins; ++i)
        cin>>arr[i];
    // arr has coin values
    cout<<numberofwaysdp(arr, coins, sum);
    
    
    return 0;
}
