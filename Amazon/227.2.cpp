#include <bits/stdc++.h>
using namespace std;


class node{
public:
	int data;
	node *left;
	node *right;
	node(){
		data = -1;
		left = NULL;
		right = NULL;
	}
};

class BST
{
public:
	node *root;
	BST(){
		root = NULL;
	}

	void insert(int num){
		if(root == NULL){
			root = new node();
			root->data = num;
		}else{
			node *start = root;
			node *prev = NULL;
			while(start != NULL){
				prev = start;
				if(start->data > num)
					start = start->left;
				else if(start->data < num)
					start = start->right;
				else if(start->data == num){
					printf("already present\n");
					return;
				}
			}
			if(num > prev->data){
				prev->right = new node();
				prev->right->data = num;
			}else{
				prev->left = new node();
				prev->left->data = num;
			}
		}
	}

	void inorder(node *root){
		if(root == NULL)
			return;
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}	
};


int height(node *root){
	if(root == NULL)
		return 0;

	return 1+max(height(root->left),height(root->right));
}

int getdiameter(node *root){
	if(root == NULL)
		return 0;

	int l = getdiameter(root->left);
	int r =getdiameter(root->right);
	int leftheight = height(root->left);
	int rightheight = height(root->right);

	return max(max(l,r),leftheight+rightheight+1);
}

int main(int argc, char const *argv[])
{
	BST b;
	b.insert(7);b.insert(4);b.insert(5);b.insert(10);b.insert(6);b.insert(8);b.insert(11);b.insert(3);b.insert(12);
	b.inorder(b.root);

	int diameter = getdiameter(b.root);
	cout<<diameter<<endl;
	return 0;
}