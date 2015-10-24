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
node *merge(node*, node*);
void halfsplit(node*, node**, node**);

void display(node *head){
	node* start = head;
	while(start){
		cout<<start->data<<" ";
		start = start->next;
	}
	cout<<endl;
}

void mergeSort(node **head){
	if(*head == NULL || (*head)->next == NULL)
		return;
	node *headref = *head;
	node *a, *b;
	halfsplit(headref, &a, &b);
	mergeSort(&a);
	mergeSort(&b);
	*head = merge(a, b);
}

node *merge(node *a, node *b){
	
	node *result = NULL;
	if(a == NULL)
		return b;
	else if(b == NULL)
		return a;
	if(a->data > b->data){
		result = b;
		result->next = merge(a, b->next);
	}
	else{
		result = a;
		result->next = merge(a->next, b);	
	}
	return result;
}

void halfsplit(node *head, node **a, node **b){
	if(head == NULL || head->next == NULL){
		*a = head;
		*b = NULL;
		return;
	}
	node *slow = head, *fast = head->next;
	while(fast != NULL){
		fast = fast->next;
		if(fast)
			fast = fast->next;
		else
			break;
		slow = slow->next;
	}
	*a = head;
	*b = slow->next;
	slow->next = NULL;

}

int main(){
	linkedlist l1;
	l1.addNode(5);
	l1.addNode(6);
	l1.addNode(4);
	l1.addNode(2);
	l1.addNode(7);
	l1.addNode(1);
	l1.display();
	mergeSort(&l1.head);
	l1.display();
}