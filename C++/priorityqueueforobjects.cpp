/*important*/
#include <bits/stdc++.h>
using namespace std;	

class node{
public:
	int age;
	string name;
	node(int a, string b){
		age = a;
		name = b;
	}
};

bool operator<(const node& a, const node& b) {
	
	node temp1=a,temp2=b;
	if(a.age != b.age)
		return a.age > b.age;
	else{
		return temp1.name.append(temp2.name) > temp2.name.append(temp1.name);
	}
}

int main(){
	priority_queue<node> pq;
	node b(23,"prashantandsoon..");
	node a(22,"prashant");
	node c(22,"prashantonly");
	pq.push(b);
	pq.push(a);
	pq.push(c);

	int size = pq.size();
	for (int i = 0; i < size; ++i)
	{
		cout<<pq.top().age<<" "<<pq.top().name<<"\n";
		pq.pop();
	}
}
