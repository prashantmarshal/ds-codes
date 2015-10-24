#include <iostream>
using namespace std;

void ks(int arr[], int n, int sum){
    int t[n+1][sum+1];
    for(int i=0;i<=n;++i){
        for(int j=0;j<=sum;++j){
            if(i==0 || j==0)
                t[i][j] = 0;
            else{
                if(j>=arr[i-1]){
                    t[i][j] = max(t[i-1][j],arr[i-1]+t[i][j-arr[i-1]]);
                }else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
    }
    int i=n,j=sum,ans=0;
    while(i>=0 && j>=0){
    	cout<<i<<" "<<j<<endl;
        if(t[i][j] == t[i-1][j]){
        	cout<<"f";
            i--;
            continue;
        }
        else if(j-arr[i-1] >= 0 && t[i][j] == arr[i-1]+t[i][j-arr[i-1]]){
            cout<<"f2";
            ans += arr[i-1];
            j=j-arr[i-1];
        }else {
        	cout<<"f3";
        	i--;
        }// if(i<=0 ||j<=0)
        // 	break;
    }
    cout<<ans<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,sum;
        cin>>n>>sum;
        int arr[n];
        cout<<n<<" " <<sum<<endl;
        for(int i=0; i<n; ++i){
            cin>>arr[i];       
        }  
        ks(arr,n,sum);
    }
    return 0;
}
