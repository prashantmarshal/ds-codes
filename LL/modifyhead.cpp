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
	void modifyHeadToNext(){
		node *temp = head;
		if(head == NULL)
			return;
		head = head->next;
		delete(temp);
		if(temp == NULL)
			cout<<"Memory freed!!\n";
	}
};

int main(){
	linkedlist l1;
	for(int i = 1; i < 11; ++i)	l1.addNode(i);
	node *temp = l1.head;
	l1.display(); // before modifying the head node
	l1.modifyHeadToNext();
	l1.display(); // after modifying the head node
	cout<<endl;
	cout<<temp->data;
}