#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;
#define For(i,s,l) for(int i = s; i < l; ++i)

class Interval
{ 
public:
	int strt;
	int end;	
};

bool customsort(Interval a, Interval b){
	return (a.strt < b.strt)?true:false;
}

int main(int argc, char const *argv[])
{
	Interval invl[] = { {1,3},{7,9},{4,6},{10,13} };
	int l = sizeof(invl)/sizeof(invl[0]);
	
	sort(invl, invl+l, customsort);
	
	int s = invl[0].strt, e = invl[0].end;
	For(i,0,l-1)
		if(invl[i].end >= invl[i+1].strt)
			e = max(e, invl[i+1].end);
		else{
			cout<<s<<" "<<e<<endl;
			s = invl[i+1].strt;
			e = invl[i+1].end;
		}
	cout<<s<<" "<<e<<endl;
	
	return 0;
}