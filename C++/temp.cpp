#include <cstdio>
#include <cmath>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;

#define For(i,s,l) for(int i = s; i < l; ++i)
#define scanint(n) scanf("%d", &n)
#define printint(n) printf("%d", n)

void solve(){
    string s;
    cin>>s;

    int length = s.length();
    int count=0;
    For(l,1,length+1){
        int ft[length-l+1][26];
        For(i,0,length-l+1)
            For(j,0,26)
                ft[i][j] = 0;
        For(i,0,length-l+1){
            For(j,i,i+l){
                ft[i][s[j]-'a']++;
            }
        }

        For(i,0,length-l+1){
            For(j,i+1,length-l+1){
                bool flag  = true;
                For(k,0,26){
                    if(ft[i][k] == ft[j][k])
                        continue;
                    else{
                        flag = false;
                        break;
                    }
                }
                if(flag)
                    ++count;
            }
        }
    }
    printint(count);printf("\n");
}


int main(int argc, char const *argv[])
{
    int T;
    scanint(T);
    while(T--)
        solve();
    return 0;
}