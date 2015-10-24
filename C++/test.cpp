#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define pi pair<int,int>
#define ll long long
#define all(v) v.begin(),v.end()
#define itr iterator
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
string s;
int ans1=0,ans2=0;
map<string,int>my;
void rec(string s1,stack<char> t,string an,int i,int n)
{
    if(i==n)
    {
        while(!t.empty())
            an+=t.top(),t.pop();
        if(an==s)
            ans1++;
        if(my[an]==0)
        {
            ans2++;
            my[an]=ans2;
        }
        return;
    }
    if(t.empty())
    {
        t.push(s1[i]);
        rec(s1,t,an,i+1,n);
    }
    else
    {
        string a=an;
        char ch=t.top();
        t.pop();
        a=a+ch;
        rec(s1,t,a,i,n);
        t.push(ch);
        t.push(s1[i]);
        i++;
        rec(s1,t,an,i,n);
    }
}
int main()
{
    int n,i,j;
    cin>>s;
    n=s.size();
    stack<char>t;
    while(!t.empty())
        t.pop();
    string an="";
    rec(s,t,an,0,n);
    printf("%d %d\n",ans1,ans2);
    return 0;
}

