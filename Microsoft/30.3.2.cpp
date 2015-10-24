#include <iostream>
using namespace std;

class node{
public:
	int data;
	node *next;
};

class linkedlist{
public:
	node *head, *start;
	linkedlist(){
		head = NULL;
		start = head; // start pointer points to the last node in the list
	}

	void addNode(int num){ // node value to be added
		if(head == NULL){
			head = new node();
			head->data = num;
			head->next = NULL;
			start = head;
		}else{
			start->next = new node();
			start->next->data = num;
			start->next->next = NULL;
			start = start->next;
		}
	}

	void display(){
		node* start = head;
		while(start){
			cout<<start->data<<" ";
			start = start->next;
		}
		cout<<endl;
	}
};

void deletenafterm(linkedlist l1, int p, int q)
{
	node *start = l1.head;
	
	for (int i = 0; i < p-1; ++i)
		start = start->next;
	
	node *qs = start->next;
	node *temp;
	
	start->next = NULL;
	
	for (int i = 0; i < q; ++i){
		
		if(qs == NULL)
			return;
		else
			temp = qs->next;

		delete(qs);
		qs = temp;
	
	}
	
	if(qs){
		start->next = qs;
	}
}

int main(){
	linkedlist l1;
	for(int i = 0; i < 25; ++i){
		l1.addNode(i+1);
	}
	deletenafterm(l1,5,50);
	l1.display();
}
