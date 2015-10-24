#include <iostream>
using namespace std;
class node{
public:
	int data;
	node *next;
	node *previous;
};

class DLL{
public:
	node *head;
	node *start;
	DLL(){
		head = NULL;
	}
	void add(int num){
		if(head == NULL){
			head = new node();
			head->data = num;
			head->previous = NULL;
			start = head;
		}else {
			node *temp = new node();
			temp->data = num;
			temp->next = NULL;
			start->next = temp;
			temp->previous = start;
			start = start->next;
		}
	}

	void display(){
		node *first = head;
		while(first != NULL){
			cout<<first->data<< " ";
			first = first->next;
		}
	}

	void deleteNode(int num){
		if(head->data == num){
			head = head->next;
			head->previous = NULL;
			return;
		}

		node *first = head;
		while(first != NULL){
			if(first->data == num)
				break;
			first = first->next;
		}

		first->previous->next = first->next;
		if(first->next != NULL)
			first->next->previous = first->previous;
	}

	void swapKths(int k){
		node *temp = head;
		for(int i = 0; i < k; ++i){
			temp = temp->next;
		}
		node *last = head;
		node *first = head;
		while(temp != NULL){
			temp = temp->next;
			last = last->next;
		}
		for(int i = 0; i < k-1; ++i)
			first = first->next;

		node *p, *q, *pdash, *qdash;
		p = first->next;
		q = last->next;
		pdash = first->previous;
		qdash = last->previous;
		first->next = q;
		last->next = p;
		first->previous = qdash;
		last->previous = pdash;
		qdash->next = first;
		p->previous = last;
		if(pdash != NULL)
			pdash->next = last;
		if(q != NULL)
			q->previous = first;
		if(k == 1)
			head = last;

	}
	
};

int main(int argc, char const *argv[]){
	DLL dll;
	int n;
	while(n--){
		cin>>n;
		dll.add(n);
	}
	dll.swapKths(1);
	dll.display();
	return 0;
}