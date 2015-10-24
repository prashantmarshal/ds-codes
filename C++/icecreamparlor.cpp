#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(s) ((ll)(s.size()))
#define bg begin()
#define en end()
#define Y second
#define X first
typedef long long ll;
#define fi freopen("input.txt","r",stdin)
#define fo freopen("output.txt","w",stdout)
const double pi     =   acos(-1.0);
const double eps    =   1e-8;
#define print(a) cout<<(#a)<<" = "<<a<<"\n";
#define fill(a,val) memset(a ,val, sizeof(a) );
/*Solution code starts here */
const ll MAXN = 205;

//#define BRUTECHECK

#define maxn (500009)

void solve()
{
    map< pair<int,int> ,bool> graf;

    int dist[maxn];
    queue<int> Q;
    int N,a,b,start,edge;

     cin>>N>>edge;

     graf.clear();

     for(int i=1;i<=edge;i++)
     {
        scanf("%d%d",&a,&b);
        graf[ mp(min(a,b) ,max(a,b) ) ]=true;
     }

     scanf("%d",&start);

//     while(!Q.empty())
//      {
//          Q.pop();
//      }

     fill(dist,-1);
     dist[start]=0;
     Q.push(start);

     int done=1;

     while(!Q.empty())
     {
             int curr= Q.front() ; Q.pop();

             int d= dist[curr];

             if(done==N)
                break;

             for(int i=1;i<=N;i++)
             {
                 if(i==curr)
                    continue;

                 if( dist[i]!=-1)
                    continue;

                 int a = min( i, curr);
                 int b =  max( i , curr);

                 if( graf.count( mp(a,b)) > 0)
                    continue;

                  Q.push(i);
                  dist[i]=d+1;
                  done++;
              }
     }

     for(int i=1;i<=N;i++)
        if( dist[i]!=0)
         printf("%d ",dist[i]);

      printf("\n");
}

int main()
{

 int test;

 scanf("%d",&test);

 while( test--)
 {
     solve();
 }


 return 0;

}
