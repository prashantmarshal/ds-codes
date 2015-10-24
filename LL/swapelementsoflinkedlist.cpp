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

	void swap(node *first, node *second){
		if(second != NULL){
			int temp = first->data;
			first->data = second->data;
			second->data = temp;			
		}
	}

	void pairwiseSwap(linkedlist l1){ // swapping the data
		node *start = l1.head;

		while(start != NULL){
			node *first = start, *second = start->next;
			swap(first, second);
			start = start->next;
			if(start)
				start = start->next;
		}
	}

	void pairwiseSwapRecursive(node *head){
		if(head == NULL)
			return;
		swap(head, head->next);
		if(head->next == NULL)
			return;
		pairwiseSwapRecursive(head->next->next);
	}

};

node* swapnodes(node *head){

	if(head == NULL)
		return NULL;

	node *one, *two, *temp;
	one = head;
	two = one->next;
	temp = (two)?two->next:NULL;

	if(!two)
		return one;
	two->next = one;
	one->next = swapnodes(temp);

	return two;

}

void display(node *head){
	while(head){
		cout<<head->data<<" ";
		head = head->next;
	}
}

int main(){
	linkedlist l1;
	for(int i = 1; i < 10; ++i){
		l1.addNode(i);
	}
	l1.display();
	// l1.pairwiseSwapRecursive(l1.head);
	// l1.swapnodes(l1.head);
	// l1.display();
	display(swapnodes(l1.head));
}