#include <bits/stdc++.h>
using namespace std;

#define for(i,s,l) for (int i = s; i < l; ++i)
#define si(i) scanf("%d", &i)
#define pi(i) printf("%d", i)
#define scan(arr,l) for(int i = 0; i < l; ++i) si(arr[i])
#define size(arr) sizeof(arr)/sizeof(arr[0])


class points{
public:
	int x;
	int y;
	points(){
		x = -1;
		y = -1;
	}
	points(int a, int b)
	{
		x = a;
		y = b;
	}
};

class node
{
public:
	points p;
	node *next;
	
};

class linkedlist
{
public:
	node *head;
	node *start;
	linkedlist(){
		head = NULL;
		start = NULL;
	}
	void push(points pint){
		if(head == NULL){
			head = new node();
			head->p = pint;
			start = head;
		}else{
			start->next = new node();
			start->next->p = pint;
			start = start->next;
		}
	}
	
};


void delete2(node *prev, node *currnext){
	delete(prev->next);
	prev->next = currnext;
}

void deleteadjacent(linkedlist l){
	node *head= l.head, *head2 = head;
	node *prev = head, *curr = head->next, *currnext = (head->next)?head->next->next:NULL;
	while(head2){
		cout<<"("<<head2->p.x<<","<<head2->p.y<<") ";
		head2=head2->next;
	}
	printf("\n");
	while(currnext){
		if(prev->p.x == curr->p.x && currnext->p.x == curr->p.x){
			delete2(prev, currnext);
			curr = currnext;
			currnext = currnext->next;
		}else if(prev->p.y == curr->p.y && currnext->p.y == curr->p.y){
			delete2(prev, currnext);
			curr = currnext;
			currnext = currnext->next;
		}else{
			prev = curr;
			curr = currnext;
			currnext = currnext->next;
		}
	}

	while(head){
		cout<<"("<<head->p.x<<","<<head->p.y<<") ";
		head=head->next;
	}

}	

int main(int argc, char const *argv[])
{
	points p(0,10);
	points p1(1,10);
	points p2(5,10);
	points p3(10,10);
	points p4(10,5);
	points p5(20,5);
	points p6(40,5);

	linkedlist l;
	l.push(p);l.push(p1);l.push(p2);l.push(p3);l.push(p4);l.push(p5);l.push(p6);

	deleteadjacent(l);
	
	return 0;
}