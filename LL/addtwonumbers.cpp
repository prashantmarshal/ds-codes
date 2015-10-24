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

void display(node *head){
	node* start = head;
	while(start){
		cout<<start->data<<" ";
		start = start->next;
	}
	cout<<endl;
}

node* addTwolists(node *head1, node *head2){
	linkedlist add;
	int sum, carry = 0;
	while(head1 && head2){
		sum = carry + head1->data + head2->data;
		carry = (sum >= 10)? 1 : 0;
		sum = sum % 10;
		add.addNode(sum);
		head1 = head1->next;
		head2 = head2->next;
	}
	while(head1){
		sum = carry + head1->data;
		carry = (sum >= 10)? 1 : 0;
		sum = sum % 10;
		add.addNode(sum);
		head1 = head1->next;
	}
	while(head2){
		sum = carry + head2->data;
		carry = (sum >= 10)? 1 : 0;
		sum = sum % 10;
		add.addNode(sum);
		head2 = head2->next;
	}

	return add.head;

}

int main(){
	linkedlist l1, l2;
	for(int i = 1; i < 2; ++i)
		l1.addNode(i);
	for(int i = 1; i < 5; ++i)
		l2.addNode(i);
	l1.display();
	l2.display();
	display(addTwolists(l1.head, l2.head));
}