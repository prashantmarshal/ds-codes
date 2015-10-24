#include <iostream>
#include <stdio.h>
#include <queue>
#include <limits.h>
#include <cmath>
using namespace std;

class node{
public:
	int data;
	node *left;
	node *right;
	node(int num = -1){
		data = num;
		left = NULL;
		right = NULL;
	}
};

int size(node *root){
	if(root == NULL)
		return 0;
	return 1 + size(root->left) + size(root->right);
}

bool twotreesidentical(node *root1, node *root2){
	if(root1 == NULL && root2 == NULL)
		return true;

	if(root1 != NULL && root2 != NULL){
		if(root1->data == root2->data){
			return twotreesidentical(root1->left, root2->left) && twotreesidentical(root1->right, root2->right);
		}else
			return false;
	}

	return false;

}

bool childrensumproperty(node *curr){
	if(curr == NULL)
		return true;

	if(curr->left && curr->right){
		if(curr->data == curr->left->data + curr->right->data)
			return childrensumproperty(curr->left) && childrensumproperty(curr->right);
		else
			return false;
		
	}else if(curr->left && curr->right == NULL){
		if(curr->data == curr->left->data)
			return childrensumproperty(curr->left);
		else
			return false;
	}else if(curr->left == NULL && curr->right != NULL){
		if(curr->data == curr->right->data)
			return childrensumproperty(curr->right);
		else
			return false;
	}
	return true;
}


int height(node *curr){
	if(curr == NULL)
		return 0;
	return 1+max(height(curr->left), height(curr->right));
}

bool isbalanced(node *root){
	if(root == NULL)
		return true;

	int lheight = height(root->left);
	int rheight = height(root->right);
	if(abs(lheight - rheight) > 1)
		return false;
	bool left = isbalanced(root->left);
	bool right = isbalanced(root->right);

	return left&&right;
}

bool checkifsumtree(node *root){
	if(root == NULL)
		return true;

	if(root->left != NULL && root->right != NULL){
		if(root->data == root->left->data + root->right->data)
			return checkifsumtree(root->left) && checkifsumtree(root->right);
		else
			return false;
	}else if(root->left != NULL && root->right == NULL){
		if(root->data == root->left->data)
			return checkifsumtree(root->left);
		else
			return false;
	}else if(root->left == NULL && root->right != NULL){
		if(root->data == root->right->data)
			return checkifsumtree(root->right);
		else
			return false;

	}else if(root->left == NULL && root->right == NULL){
		return true;
	}else
		return false;

}

int sum(node *root){
	if(root == NULL)
		return 0;
	return root->data + sum(root->left) + sum(root->left);
}

bool checkifsumtreewhole(node *root){
	if(root == NULL || (root->left == NULL && root->right == NULL))
		return 1;

	int ls = checkifsumtreewhole(root->left);
	int rs = checkifsumtreewhole(root->right);
	int leftsum = sum(root->left);
	int rightsum = sum(root->right);

	if(root->data == leftsum+rightsum && rs && ls)
		return 1;
	else
		return 0;

}

bool issubtree(node *root1, node* root2){
	if(root1 == NULL && root2 == NULL)
		return true;
	if(root1 == NULL)
		return false;
	if(root2 == NULL)
		return true;
	static bool flag = false;
	if(flag){
		bool samedata = (root1->data == root2->data);
		if(samedata && issubtree(root1->left, root2->left) && issubtree(root1->right, root2->right))
			return true;
		else
			return false;
	}

	if(root1->data == root2->data){
		flag = true;
		return issubtree(root1->left, root2->left) && issubtree(root1->right, root2->right);
	}
	else
		return issubtree(root1->left, root2) || issubtree(root1->right, root2);

}

int maxpathsum(node *root, int &res){
		// incomplete

}




void boundarytraversalleft(node *root){
	if(root == NULL)
		return;
	cout<<root->data<<" ";
	boundarytraversalleft(root->left);
}

void boundarytraversalright(node *root){
	if(root == NULL)
		return;
	cout<<root->data<<" ";
	boundarytraversalright(root->right);
}

void printleaves(node *root){
	if(root == NULL)
		return;
	printleaves(root->left);
	printleaves(root->right);
	if(!root->left && !root->right)
		cout<<root->data<<" ";

}

void boundarytraversal(node *root){
	if(root == NULL)
		return;

	cout<<root->data<<" ";
	boundarytraversalleft(root->left);

	if(root->left)
		printleaves(root->left->right);
	if(root->right)
		printleaves(root->right->left);

	boundarytraversalright(root->right);

}


int converttosumtree(node *root)
{
	if(root == NULL)
		return 0;

	int ls = converttosumtree(root->left);
	int rs = converttosumtree(root->right);
	int temp = root->data;
	root->data = ls+rs;

	return root->data+temp;
}

int main(){

	/*boundary traversal*/
	node *root         = new node(20);
    root->left                = new node(8);
    root->left->left          = new node(4);
    root->left->right         = new node(12);
    root->left->right->left   = new node(10);
    root->left->right->right  = new node(14);
    root->right               = new node(22);
    root->right->right        = new node(25);
 
    // boundarytraversal(root);
    converttosumtree(root);

    return 0;

    

	node *T        = new node(26);
    T->right              = new node(3);
    T->right->right       = new node(3);
    T->left               = new node(10);
    T->left->left         = new node(4);
    T->left->left->right  = new node(30);
    T->left->right        = new node(6);

    /*node *S    = new node(4);
    S->right          = new node(30);
    S->left           = new node(4);
    S->left->right    = new node(30);

    if(issubtree(T, S))
    	cout<<"Yes.\n";
    else
    	cout<<"No.\n";*/


	/*node *root  = new node(26);
    root->left         = new node(20);
    root->right        = new node(6);
    root->left->left   = new node(4);
    root->left->right  = new node(6);
    root->right->right = new node(3);  

	if(checkifsumtreewhole(root))
		cout<<"Yes.\n";
	else
		cout<<"No.\n";*/

	return 0;

	/*if(childrensumproperty(root))
		cout<<"Yes\n";
	else
		cout<<"No\n";*/

	/*node *root2 = new node(1);
	root2->left = new node(2);
	root2->right = new node(3);
	root2->left->left = new node(4);
	root2->left->right = new node(5);
	root2->left->right->left = new node(6);*/ 

	/*if(twotreesidentical(root, root2))
	 	cout<<"Yes\n";
	 else
	 	cout<<"No\n";*/
	return 0;

}

