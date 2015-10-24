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



void addTwolistsDifferentSize(node *head1, node *head2, int &carry, int difference, int diffOrg, node **result){

	if(head1 == NULL || head2 == NULL){
		return;
	}
	if(difference == 0){
		node *first = *result;
		first->next = new node();
		node *second = first->next;
		if(head1->next == NULL)
			first->next = NULL;
		addTwolistsDifferentSize(head1->next, head2->next, carry, 0, diffOrg, &second);
		int sum = carry + head1->data + head2->data;
		carry = (sum >= 10)? 1 : 0;
		sum = sum % 10;
		first->data = sum % 10;

	}else{
		node *first = *result;
		first->next = new node();
		node *second = first->next;
		addTwolistsDifferentSize(head1->next, head2, carry, difference-1, diffOrg, &second);
		int sum = carry + head1->data;
		carry = (sum >= 10)? 1 : 0;
		sum = sum % 10;
		first->data = sum % 10;
		if(carry != 0 && difference == diffOrg){
			sum = carry + (*result)->data;
			node *temp = new node();
			temp->data = sum % 10;
			temp->next = *result;
			*result = temp;
		}
	}

}


int findDifference(node *head1, node *head2){
	int count1 = 0, count2 = 0;
	while(head1 != NULL){
		++count1;
		head1 = head1->next;
	}
	while(head2 != NULL){
		++count2;
		head2 = head2->next;
	}
	return count1-count2;
}


int main(){
	linkedlist l1, l2;

	l1.addNode(9);l1.addNode(6);l1.addNode(6);
	l2.addNode(5);
	l2.addNode(1);

	l1.display();
	l2.display();
	int diff = findDifference(l1.head, l2.head);
	int diffOrg = diff;
	node *result = new node();
	int carry = 0;
	addTwolistsDifferentSize(l1.head, l2.head, carry, diff, diffOrg, &result);
	display(result);
}