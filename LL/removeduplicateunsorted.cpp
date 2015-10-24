#include <iostream>
#include <map>
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

	void removeDuplicateUnsorted(linkedlist l1){
		map<int, int> myMap;
		node *start = l1.head;
		if(start == NULL)
			return;
		node *previous = start;
		

		if(start == NULL)
			return;
		while(start != NULL){
			if(myMap[start->data] == 0){
				myMap[start->data] = 1;
				previous = start;
				start = start->next;
			}
			else{
				previous->next = start->next;
				delete(start);
				start = previous->next;
			}
		}
	}



};

int main(){
	linkedlist l1;
	for(int i = 0; i < 10; ++i){
		l1.addNode(i);
	}
	for(int i = 0; i < 10; ++i){
		l1.addNode(i);
	}
	l1.display();
	l1.removeDuplicateUnsorted(l1);
	cout<<endl;
	l1.display();
}