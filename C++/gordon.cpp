#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;
#define For(i,s,l) for(int i = s; i < l; ++i)
#define si(n) scanf("%d", &n)
#define pi(n) printf("%d", n)
#define sa(arr,a) for(int i=0; i<a; ++i) si(arr[i])


struct lund
{
	int a[3];
	int b[3];
};
int main(int argc, char const *argv[])
{
	int lunds;
	cin>>lunds;
	lund ls[lunds];
	int a,b,c;
	For(i,0,lunds){
		cin>>a>>b>>c;
		ls[i].a[0] = a-4; ls[i].a[1] = b-4; ls[i].a[2] = c-4;
		ls[i].b[0] = a; ls[i].b[1] = b; ls[i].b[2] = c;
	}

	int mahalund;
	cin>>mahalund;
	For(i,0,mahalund){
		int setf[3];int setl[3];
		sa(setf, 3); sa(setl, 3);
		int cnt=0;
		For(j,0,lunds){
			bool dir1,dir2,dir3;
			if(setf[0]<=ls[j].a[0])
				dir1=false;
			else
				dir1=true;

			if(setf[1]<=ls[j].a[1])
				dir2=false;
			else
				dir2=true;

			if(setf[2]<=ls[j].a[2])
				dir3=false;
			else
				dir3=true;

			dir1 = !dir1;
			dir2 = !dir2;
			dir3 = !dir3;

			// cout<<dir1<<dir2<<dir3<<endl;
			if(dir1 && (setl[0]>=ls[j].b[0])){
				if(dir2 && (setl[1]>=ls[j].b[1]))
					if(dir3 && (setl[2]>=ls[j].b[2]))
						++cnt;
			}
		}
		pi(cnt);printf("\n");
	}
	return 0;
}