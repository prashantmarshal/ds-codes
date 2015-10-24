#include <iostream>
#include <stack>
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
	
	bool checkIfPalindrome(linkedlist l){ // by stack
		node *head = l.head;
		if(head == NULL)
			return true;
		stack<int> myStack;
		node *start = head;
		int lengthOfLinkedList = 0;
		while(start != NULL){
			myStack.push(start->data);
			start = start->next;
			++lengthOfLinkedList;
		}

		// check for proper insertion into stack
		if(lengthOfLinkedList != myStack.size())
			return false;
		start = l.head;
		while (!myStack.empty() && start != NULL){
     		if(myStack.top() != start->data)
     			return false;
     		myStack.pop();
     		start = start->next;
  		}
  		return true;
	}

	/*bool checkIfPalindrome(node **left, node *right){ // by recursion, again left pointer passed by reference trick
														// so that whenever left is changed the real left gets changed
		if(*left == NULL)
			return true;
		if(right == NULL)
			return true;
		if(!checkIfPalindrome(left, right->next))
			return false;
		if((*left)->data == right->data){
			*left = (*left)->next;
			return true;
		}else
		return false;
	}*/

	bool checkIfPalindrome(node **left, node right){
		if(*left == NULL || right == NULL)
			return true;

		checkIfPalindrome(left, right->next);
		if((*left)->data == right->data){
			*left = (*left)->next;
			return true;
		}else
			return false;
	}


};

int main(){
	linkedlist l1;
	for(int i = 1; i < 11; ++i)	l1.addNode(i);
	for(int i = 9; i > 0; --i)	l1.addNode(i);
	if(l1.checkIfPalindrome(&l1.head, l1.head))
		cout<<"Yes\n";
	else
		cout<<"No\n";
}