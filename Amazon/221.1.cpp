/*sparse*/

#include <iostream>
using namespace std;

int findnextsparse(int n){
    bool curr = false;
    bool done = false;

    while(!done){
        n++;
        int k = n;

        while(k!=0){
            if(k%2 == 1){
                if(curr == true)
                    break;
                else
                    curr = true;
            }else
                curr = false;
            k/=2;

            if(k == 0){
                done = true;
                break;
            }
        }
    }

    return n;
}
 
int main()
{
    int n;
    cin>>n;
    cout<<findnextsparse(n); 
}