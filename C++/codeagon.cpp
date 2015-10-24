#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<utility>
#include<set>
#include<map>
#include<cstring>
#include<cmath>
#include<string>
#include<cstdlib>
#include<queue>
#include<stack>
#include<cassert>

using namespace std;

vector<string>result;
string s2;
int a1,a2;
  // map<string,int> mp;
void gen_ans(string & s1,int ind,stack<char>st,string cur)
{
    if(ind==s1.length())
    {
        while(!st.empty())
        {

            cur+=st.top();
            st.pop();
       }
        // cout<<cur<<endl;
       //  if(mp[cur]==false)
       // {
       //      mp[cur]=true;
       //      a2++;
       //  }
       cout<<cur<<endl;
        if(cur==s2)
        {
            a1++;
        }
         return;
    }


    st.push(s1[ind]);

    gen_ans(s1,ind+1,st,cur);

    st.pop();

    if(!st.empty())
    {
        char c=st.top();
        st.pop();
        cur+=c;
        gen_ans(s1,ind,st,cur);
    }


}


int main()
{

    string s1;
    cin>>s1;

    assert(s1.length()<=10);

    s2=s1;
    stack<char>st;
    a1=0;
    a2=0;

    gen_ans(s1,0,st,"");
    cout<<a1<<" "<<a2<<endl;
    return 0;
}