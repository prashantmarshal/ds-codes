/*important*/
/*Sort elements by frequency | Set 1*/

#include <bits/stdc++.h>
using namespace std;

class pairs
{
public:
	int x;
	int y;
	pairs(){
		x = 0;
		y = 0;
	}
};

bool compare(pairs a, pairs b){
	if(a.x != b.x)
		return a.x > b.x;
	else
		return a.y < b.y;
}

void freqsort(int *arr, int size){
	
	map<int, int> it;
	map<int, int> ft;
	
	for (int i = 0; i < size; ++i)
		if(it.count(arr[i]) == 0)
			it[arr[i]] = i;	
	
	for (int i = 0; i < size; ++i)
		ft[it[arr[i]]]++;
	
	list< pairs > l;
	
	for(map<int, int>::iterator it = ft.begin(); it!=ft.end(); ++it){
		pairs p;
		p.x = it->second;
		p.y = it->first;
		l.push_back(p);
	}

	/*cout<<"Count \t Index"<<endl;
	for (std::list<pairs>::iterator it=l.begin(); it != l.end(); ++it){
		pairs p = *it;
		cout<<p.x<< " \t " <<p.y<<endl;
	}*/

	l.sort(compare);

	cout<<"Count \t Index"<<endl;
	for (std::list<pairs>::iterator it=l.begin(); it != l.end(); ++it){
		pairs p = *it;
		cout<<p.x<< " \t " <<arr[p.y]<<endl;
	}

}

int main(){
	int arr[] = {2, 5, 2, 8, 5, 6, 8, 8};
	int size = sizeof(arr)/sizeof(arr[0]);
	freqsort(arr, size);
}