#include <iostream>
#include <list>
using namespace std;

int f(int k){
	int a = 2;
	int b = 3;
	return (a*k+b)%7;
}
class hash{
public:
	list <int> l[7];

	void insert(int k){
		int pos = f(k);
		l[pos].push_back(k);
	}

	void remove(int k){
		int pos = f(k);
		list<int>::iterator it = l[pos].begin();
		while(*it != k){
			it++;
			if(it==l[pos].end())
				break;
		}

		if(it==l[pos].end())
		{
			cout<<"element not found";
			return;
		}
		cout<<*it<<endl;
		l[pos].erase(it);
	}

};
int main(int argc, char const *argv[])
{
	hash h;
	h.insert(1);
	h.insert(2);
	h.insert(3);
	h.insert(4);
	h.remove(3);
	h.remove(3);
	
	return 0;
}