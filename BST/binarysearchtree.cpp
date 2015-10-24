#include <iostream>
#include <stdio.h>
#include <queue>
#include <limits.h>
using namespace std;

class node{
public:
	int data;
	node *left;
	node *right;
	node *parent;
	node(){
		data = -1;
		left = NULL;
		right = NULL;
		parent = NULL;
	}
};

class Tree{
public:
	node *root;
	Tree(){
		root = NULL;
	}

	void insert(int num){
		if(root == NULL){
			root = new node();
			root->data = num;
			return;
		}
		node *curr = root;
		node *previous = NULL;
		while(curr != NULL){
			if(curr->data > num){
				previous = curr;
				curr = curr->left;
			}else if(curr->data < num){
				previous = curr;
				curr = curr->right;
			}else{
				printf("Key already present.\n");
			}
		}
		if(num > previous->data){
			previous->right = new node();
			previous->right->data = num;
			previous->right->parent = previous;
		}else if(num < previous->data){
			previous->left = new node();
			previous->left->data = num;
			previous->left->parent = previous;
		}else{
			printf("Key already present.\n");
		}
		return;
	}

	node *find(int num){
		node *curr = root;
		while(curr != NULL){
			if(num > curr->data){
				curr = curr->right;
			}else if(num == curr->data){
				curr = curr->right;
			}else{
				if(curr->parent->data > num)
					return curr->parent->left;
				else
					return curr->parent->right;
			}			
		}
	}

	void deleteNode(int num){
		node *curr = root;
		while(curr != NULL){
			if(curr->data > num)
				curr = curr->left;
			else if(curr->data < num)
				curr = curr->right;
			else if(curr->data == num){
				if(curr->left == NULL && curr->right == NULL){
					if(curr->parent->left->data == num)
						curr->parent->left = NULL;
					else if(curr->parent->right->data == num)
						curr->parent->right = NULL;
				}else if(curr->left == NULL && curr->right != NULL){
					if(curr->parent->left->data == num)
						curr->parent->left = curr->right;
					else
						curr->parent->right = curr->right;
				}else if(curr->right == NULL && curr->left != NULL){
					if(curr->parent->left->data == num)
						curr->parent->left = curr->left;
					else
						curr->parent->right = curr->left;
				}else if(curr->left != NULL && curr->right != NULL){
					node *temp = curr;
					temp = temp->left;
					while(temp->right != NULL)
						temp = temp->right;
					curr->data = temp->data;
					if(temp->parent->left == temp){
						delete(temp->parent->left);
						temp->parent->left = NULL;
					}
					else if(temp->parent->right == temp){
						delete(temp->parent->right);
						temp->parent->right = NULL;
					}
				}
				break;
			}			
		}
	}

	void inorder(node *curr){
		if(curr == NULL)
			return;
		inorder(curr->left);
		cout<<curr->data<<" ";
		inorder(curr->right);
	}

	void postorder(node *curr){
		if(curr == NULL)
			return;
		postorder(curr->left);
		postorder(curr->right);
		cout<<curr->data<<" ";
	}

	void preorder(node *curr){
		if(curr == NULL)
			return;
		cout<<curr->data<<" ";
		preorder(curr->left);
		preorder(curr->right);
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

	void printlevel(node *curr, int l, int level){ // printing nodes at a particular level
		if(curr == NULL)
			return;
		if(l == level)
			cout<<curr->data<<" ";
		else{
			printlevel(curr->left, l+1, level);
			printlevel(curr->right, l+1, level);
		}
	}

	int givelevel(node *curr,int num){
		if(curr == NULL)
			return -2;
		if(curr->data == num){
			return 0;
		}else{
			if(curr->data > num)
				return 1 + givelevel(curr->left, num);
			else
				return 1 + givelevel(curr->right, num);
		}
	}

	int minvalue(node *curr){
		if(curr->left == NULL){
			return curr->data;
		}
		int result = minvalue(curr->left);
		return result;
	}

	void inordersuccessor(node *curr, node **prec, node **succ, int num){
		if(curr == NULL){
			return;
		}

		if(curr->data == num){
			if(curr->left != NULL){
				node *temp = curr->left;
				while(temp->right != NULL){
					temp = temp->right;
				}
				*prec = temp;
			}

			if(curr->right != NULL){
				node *temp = curr->right;
				temp = curr->right;
				while(temp->left != NULL)
					temp = temp->left;
				*succ = temp;
			}
			return;			
		}

		if(curr->data > num){
			*succ = curr;
			inordersuccessor(curr->left, prec, succ, num);
		}else{
			*prec = curr;
			inordersuccessor(curr->right, prec, succ, num);
		}
	}

	bool checkifbst(node *curr, int min, int max){

		if(curr == NULL)
			return true;


		if(curr->data > max || curr->data < min)
			return false;

		return checkifbst(curr->left, min, curr->data-1) && checkifbst(curr->right, curr->data+1, max);

	}

	node *lca(struct node* curr, int n1, int n2){
    	if (curr == NULL) 
    		return NULL;
 
	    if (curr->data > n1 && curr->data > n2)
    	    return lca(curr->left, n1, n2);
 
	    if (curr->data < n1 && curr->data < n2)
    	    return lca(curr->right, n1, n2);
 		if(curr->data != n1 && curr->data != n2)
		    return curr;
		else{
			node *temp = new node();
			temp->data = -1;
			return temp;	
		}
	}

	void printingivenrange(node *curr, int min, int max){
		if(curr == NULL)
			return;
		if(curr->data < min){
			printingivenrange(curr->right, min, max);
			return;
		}else if(curr->data > max){
			printingivenrange(curr->left, min, max);
			return;
		}
		cout<<curr->data;
		printingivenrange(curr->left, min, max);
		printingivenrange(curr->right, min, max);
	}

	node* kthsmallest(node *curr, int &kpre, int k){
		if(curr == NULL){
			return NULL;
		}

		node *ret = kthsmallest(curr->left, kpre, k);
		if(ret)
			return ret;
		++kpre;
		if(kpre == k)
			return curr;
		
		ret = kthsmallest(curr->right, kpre, k);
		if(ret)
			return ret;
		return NULL;
		
		
	}

	void kthsmallestpre(node *curr, int k){
		int kpre = 0;
		node *temp = kthsmallest(curr, kpre, k);
		if(temp)
			cout<<temp->data<<endl;
		else{
			cout<<"Lesser keys in the tree.\n";
		}
	}

	void printsortedbstarray(int *arr, int index, int lim){
		if(index > lim-1)
			return;
		printsortedbstarray(arr, index*2+1, lim);
		cout<<arr[index];
		printsortedbstarray(arr, index*2+2, lim);
	}

	node* sortedarraytobst(int *arr, int start, int end){
		if(start > end){
			return NULL;
		}

		int mid = (start+end+1)/2;
		node *root = new node();
		root->data = arr[mid];
		root->left = sortedarraytobst(arr, start, mid-1);
		root->right = sortedarraytobst(arr, mid+1, end);

		return root;
	}

	void addgreatervalues(node **curr, int &subtract, int sum){
		if(*curr == NULL)
			return;
		node *first = *curr;
		addgreatervalues(&(first->left), subtract, sum);
		subtract += (*curr)->data;
		(*curr)->data = sum - subtract + (*curr)->data;
		addgreatervalues(&(first->right), subtract, sum);
	}
	int addgreatervaluespre(node *curr){
		if(curr == NULL)
			return 0;
		return curr->data + addgreatervaluespre(curr->left) + addgreatervaluespre(curr->right);
	}

	void addgreatervaluesanother(node *curr, int &sum){// reverse inorder
		if(curr == NULL)
			return;
		addgreatervaluesanother(curr->right, sum);
		sum += curr->data;
		curr->data = sum;
		addgreatervaluesanother(curr->left, sum);

	}

	node *removeoutofrange(node *curr, int min, int max){
		if(curr == NULL)
			return NULL;


		curr->left = removeoutofrange(curr->left, min, max);
		curr->right = removeoutofrange(curr->right, min, max);

		if(curr->data > max)
			return curr->left;
		else if(curr->data < min)
			return curr->right;
		
		return curr;		

	}

	bool ifonlyonechild(int *pre, int size){ // preorder traversal of a bst, node's value then left child then right child
		
		for (int i = 0; i < size-1; ++i){
			int current = pre[i];
			if(pre[i+1] > current && pre[size-1] > current)
				continue;
			if(pre[i+1] < current && pre[size-1] < current)
				continue;
			return false;
		}
		return true;
	}

	void triplettozero(node *curr, int *arr, int &i){
		if(curr == NULL)
			return;
		triplettozero(curr->left, arr, i);
		arr[i++] = curr->data;
		triplettozero(curr->right, arr, i);
	}

	bool findforthree(int *arr, int size){
		for (int i = 0; i < size-2; ++i){
			int first = arr[i];
			int second = i+1;
			int third = size-1;
			while(second < third){

				int sum = first+arr[second]+arr[third];
				if(sum == 0)
					return true;
				if(sum > 0)
					--third;
				else if(sum < 0)
					++second;
			}
		}
		return false;
	}

	bool checktriplettozero(node *curr){
		int *arr = new int[100];
		int size= 0;
		triplettozero(curr, arr, size);
		if(size < 3)
			return false;
		else return findforthree(arr, size);
	}


};



int main(){
	Tree bst;
	bst.insert(-16);
	bst.insert(8);
	bst.insert(5);
	bst.insert(4);
	bst.insert(6);
	bst.insert(3);
	bst.insert(9);

	if(bst.checktriplettozero(bst.root))
		cout<<"Yes\n";
	else
		cout<<"No\n";



	/*int pre[] = {8, 3, 5, 7, 6};
	int size = sizeof(pre)/sizeof(int);
	if(bst.ifonlyonechild(pre, size))
		cout<<"Yes\n";
	else
		cout<<"No\n";*/


	/*int sum = 0;
	bst.addgreatervaluesanother(bst.root, sum);
	bst.inorder(bst.root);*/
	// bst.inorder(bst.removeoutofrange(bst.root, 4, 7));
/*	int subtract = 0;
	int sum = bst.addgreatervaluespre(bst.root);
	bst.addgreatervalues(&bst.root, subtract, sum);
	bst.inorder(bst.root);*/
	// cout<<sum<<endl;


	/*int arr[] = {1, 2, 3, 4, 5, 6};
	node *root = bst.sortedarraytobst(arr, 0, sizeof(arr)/sizeof(int)-1);
	bst.levelorder(root);*/

	/*int arr[] = {4, 2, 5, 1, 3};
	bst.printsortedbstarray(arr, 0, 5);*/



	/*int kthsmallest;
	cin>>kthsmallest;
	bst.kthsmallestpre(bst.root, kthsmallest);*/
	/*bst.printingivenrange(bst.root, 5, 9);*/
	/*cout<<(bst.lca(bst.root, 7, 9))->data<<endl;*/
	/*if(bst.checkifbst(bst.root, INT_MIN, INT_MAX))
		cout<<"Yes, BST\n";
	else
		cout<<"Not a BST\n";*/
	/*node *prec = NULL, *succ = NULL;
	bst.inordersuccessor(bst.root, &prec, &succ, 6);
	cout<<prec->data<<" "<<succ->data<<endl;*/
	// bst.deleteNode(9);

	// bst.printlevel(bst.root, 0, 2); // prints nodes at a particular level
	// cout<<endl;

	// int level = bst.givelevel(bst.root, 0);
	// cout<<level<<endl;

	// bst.levelorder();

	// cout<<bst.minvalue(bst.root);
}