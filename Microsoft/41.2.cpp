#include <bits/stdc++.h>
using namespace std;

#define for(i,s,l) for (int i = s; i < l; ++i)
#define si(i) scanf("%d", &i)
#define pi(i) printf("%d", i)
#define scan(arr,l) for(int i = 0; i < l; ++i) si(arr[i])
#define size(arr) sizeof(arr)/sizeof(arr[0])

class node
{
public:
	int data;
	node *left;
	node *right;
	node(){
		left = NULL;
		right = NULL;
		data = -1;
	}		
};


node* converttobst(int *arr, int low,int high){

	if(low>high)
		return NULL;
	int mid = (low+high)/2;
	node *root = new node();
	root->data = arr[mid];
	root->left = converttobst(arr,low,mid-1);
	root->right = converttobst(arr, mid+1, high);
	return root;

}

void displaytree(node *root){
	if(root == NULL)
		return;
	displaytree(root->left);
	cout<<root->data<<" ";
	displaytree(root->right);

}

void levelorder(node *root){
	queue <node*> myqueue;
	node *curr = root;
	if(curr == NULL)
		return; 

	myqueue.push(curr);
	while(!myqueue.empty()){
		node *top = myqueue.front();
		cout<<top->data<<" ";
		myqueue.pop();
		if(top->left)
			myqueue.push(top->left);
		if(top->right)
			myqueue.push(top->right);
	}
}

void preorder(node *root){
	if(root == NULL)
		return;
	cout<<root->data<<" " ;
	preorder(root->left);
	preorder(root->right);
}

int main(int argc, char const *argv[])
{
	int arr[] = {1,2,3,4,5,6,7,8,9};
	int size = size(arr);
	node *root = converttobst(arr, 0,size-1);
	levelorder(root);
	return 0;
}