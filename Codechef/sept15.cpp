#include <bits/stdc++.h>
using namespace std;

#define For(i,s,l) for (int i = s; i < l; ++i)
#define si(i) scanf("%d", &i)
#define sl(i) scanf("%ld", &i)
#define pi(i) printf("%d", i)
#define pl(i) printf("%ld", i);
#define scan(arr,l) for(int i = 0; i < l; ++i) si(arr[i])
#define size(arr) sizeof(arr)/sizeof(arr[0])

class point
{
public:
	int x;
	int y;	
};

int subtractpoints(point p1, point p2){
	return (abs(p1.x-p2.x)+abs(p1.y-p2.y));
}

void solve()
{
	int N;
	si(N);
	int *matrix[N];

	std::map<int, point> t;

	For(i,0,N) matrix[i]=new int[N];

	For(i,0,N)
	For(k,0,N){
		si(matrix[i][k]);
		point p;
		p.x = i;p.y = k;
		t[matrix[i][k]] = p;
	}
	
	point prev = t[1];
	long int ans = 0;
	
	For(i,2,N*N+1){
		point p = t[i];
		ans+=subtractpoints(prev,p);
		prev = p;
	}

	pl(ans);printf("\n");
}

int main(int argc, char const *argv[])
{
	int T;
	si(T);
	while(T--)
		solve();
	return 0;
}