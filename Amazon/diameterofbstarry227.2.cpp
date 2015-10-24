/*diamtere of a bst elements given in array*/

#include <bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node *left;
	node *right;
	node(){
		left = NULL;
		right = NULL;
	}
};

class BST{
public:
	node *root;
	BST(){
		root = NULL;
	}

	void insert(int key){
		if(root == NULL){
			root = new node();
			root->data = key;
		}else{
			node *start = root;
			node *prev=NULL;
			while(start!=NULL){
				if(start->data < key){
					prev = start;
					start = start->right;
				}else if(start->data > key){
					prev = start;
					start = start->left;
				}else{
					printf("givenkeyalreadyfound\n");
					return;
				}
			}

			if(prev->data > key){
				prev->left = new node();
				prev->left->data = key;
			}else if(prev->data < key){
				prev->right = new node();
				prev->right->data = key;
			}
		}
	}

	void inorder(node *root){
		if(root == NULL)
			return;
		inorder(root->left);
		cout<<root->data;
		inorder(root->right);
	}

};


int height(node *root){

	if(root == NULL)
		return 0;

	return max(1+height(root->left), 1+height(root->right));
}

int getdiameter(node *root){
	if(root == NULL)
		return 0;

	int ls = getdiameter(root->left);
	int rs = getdiameter(root->right);

	int lh = height(root->left);
	int rh = height(root->right);

	return max(max(ls,rs), lh+rh+1);
}

void solve(int arr[], int size){
	BST tree;
	for(int i=0;i<size;++i)
		tree.insert(arr[i]);
	tree.inorder(tree.root);
	cout<<getdiameter(tree.root);

}

int main(){
	int arr[] = {5,6,4,2,1,3,7,9,8,10};
	int size = sizeof(arr)/sizeof(arr[0]);
	solve(arr,size);
}