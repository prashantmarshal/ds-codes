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


void evennodesatend(node *head, node **last, int number){
	if(head == NULL)
		return;

	if(head->next == NULL){
		*last = head;
		return;
	}

	evennodesatend(head->next, last, number + 1);

	if(number%2 == 0 && *last != head->next){
		node *temp = head->next->next;
		(*last)->next = head->next;
		head->next->next = NULL;
		head->next = temp;
		*last = (*last)->next;
		return;
	}	

}	
int main(){
	linkedlist l1;
	for(int i = 1; i < 6; ++i){
		l1.addNode(i);
	}
	node *temp = new node();
	evennodesatend(l1.head, &temp, 0);
	l1.display();
}