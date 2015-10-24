#include <iostream>
#include <stdio.h>
#include <queue>
#include <limits.h>
#include <cmath>
#include <stack>
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
				return;
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
					while(temp->right != NULL)		// finding inorder predecessor
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


int max(int a, int b){
	return (a>b)?a:b;
}

int maximumdepth(node *root){

	if(root == NULL)
		return 0;
	return max(1+maximumdepth(root->left), 1+maximumdepth(root->right));

}

void deleteatree(node **root){
	if(*root == NULL)
		return;
	node *temp = *root;
	deleteatree(&(temp->left));
	deleteatree(&(temp->right));
	delete(temp);
	*root = NULL;
}

void mirrortree(node **curr){
	if(*curr == NULL)
		return;
	node *first = *curr;

	mirrortree(&(first->left));
	mirrortree(&(first->right));
	node *temp = first->left;
	first->left = first->right;
	first->right = temp;
}



void printroottoleafpaths(node *curr, int *arr, int i){
	if(curr == NULL){
		return;
	}
	arr[i++] = curr->data;
	if(curr->left == NULL && curr->right == NULL){
		for(int k = 0; k < i; ++k)
			cout<<arr[k]<<" ";
		cout<<endl;
		return;
	}
	printroottoleafpaths(curr->left, arr, i);
	printroottoleafpaths(curr->right, arr, i);


}

void printroottoleafpathspre(node *curr){
	if(curr == NULL)
		return;
	int *arr =  new int[100];
	int i = 0;
	printroottoleafpaths(curr, arr, i);

}

int countleafnodes(node *curr){
	if(curr == NULL)
		return 0;
	if(curr->left == NULL && curr->right == NULL){
		return 1;
	}else 
		return countleafnodes(curr->left) + countleafnodes(curr->right);
}


void printgivenlevel(node *curr, int level, int current, int ltr){ // levelordertraversalspiral(node *curr)
	if(curr == NULL)
		return;
	if(current == level)
		cout<<curr->data<<" ";
	else if(ltr == 0){
		printgivenlevel(curr->left, level, current+1, ltr);
		printgivenlevel(curr->right, level, current+1, ltr);
	}else if(ltr == 1){
		printgivenlevel(curr->right, level, current+1, ltr); // curr->right prints from the right side
		printgivenlevel(curr->left, level, current+1, ltr);
	}

}

void printspiral(node *curr){
	int height = maximumdepth(curr);
	int ltr = 0;
	for(int i = 0; i < height; ++i){
		printgivenlevel(curr, i+1, 1, ltr);
		ltr = 1-ltr;
	}

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

int diameter(node *curr){
	if(curr == NULL)
		return 0;
	return max((height(curr->left)+height(curr->right)+1), max(diameter(curr->left), diameter(curr->right)));
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

	if(left && right)
		return true;
	else 
		return false;

}

bool ancestorsofagivennode(node *root, int num){
	if(root == NULL)
		return false;
	if(root->data == num){
		return true;
	}
	if(ancestorsofagivennode(root->left, num) || ancestorsofagivennode(root->right, num)){
		cout<<root->data<<endl;
		return false; // prints only the just ancestor
		return true; // prints all the ancestors
	}

	return false;
}

void inorderwithoutrecursion(node *curr){
	if(curr == NULL)
		return;

	stack <node*> mystack;
	mystack.push(curr);

	while(!mystack.empty() || curr != NULL){ // hold on
		while(curr != NULL){
			mystack.push(curr);
			curr = curr->left;
		}


		if(!mystack.empty()){
			node *temp = mystack.top();
			if(temp != NULL){
				mystack.pop();
				cout<<temp->data<<" ";
				mystack.push(temp->right);
				curr = temp->right;
			}else
				curr = NULL;		
		}

	}
	

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

/*void calllevelorder(node *root, node **arr, int &i){
	queue <node*> myqueue;
	myqueue.push(root);
	while(!myqueue.empty()){
		node *temp = myqueue.front();
		if(temp->left == NULL && temp->right == NULL){ // temp is a leaf node
			arr[i++] = temp;
		}
		if(temp->left)
			myqueue.push(temp->left);
		if(temp->right)
			myqueue.push(temp->right);
		myqueue.pop();
	}

	for(int k = 0; k < i; ++k){
		node *t = arr[k];
		cout<<t->data<<" ";
	}

}*/

void callinorder(node *root, node **arr, int &i){
	if(root == NULL)
		return;
	callinorder(root->left, arr, i);
	if(root->left == NULL && root->right == NULL)
		arr[i++] = root;
	callinorder(root->right, arr, i);
}	


void displaylinkedlist(node *head){
	while(head != NULL){
		cout<<head->data<<" ";
		head = head->right;
	}
}
node* leavestolinkedlist(node *root){
	int h = height(root);
	node *arr[2^h];
	int i = 0;
	callinorder(root, arr, i);
	node *linkedlisthead = NULL, *temp = NULL;
	linkedlisthead = arr[0];
	if(linkedlisthead == NULL)
		return NULL;
	for(int k = 0; k < i-1; ++k){
		temp = arr[k];
		temp->right = arr[k+1];
		temp = temp->right;
	}
	temp->right = NULL;
	displaylinkedlist(linkedlisthead);
}

int getwidth(node *root, int curr, int level){
	if(root == NULL)
		return 0;
	if(curr == level)
		return 1;
	else
		return getwidth(root->left, curr+1, level) + getwidth(root->right, curr+1, level);

}


int maximumwidth(node *root){
	int h = height(root);
	int maxwidth = 0, width = 0;

	for(int i = 0; i < h; ++i){
		width = getwidth(root, 1, i+1);
		if(width > maxwidth)
			maxwidth = width;
	}

	return maxwidth;
}

int heightofbinarytree(node* root);
int widthofabinarytreeiterative(node *root){
	return heightofbinarytree(root);
}

int heightofbinarytree(node *root){ // height of a bianry tree iterative
	if(root == NULL)
		return 0;

	int var_used_for_max_width = 0;

	queue <node*> q;

	q.push(root);
	int qsize;
	int height = 0;

	while(1){
		qsize = q.size();
		if(qsize > var_used_for_max_width)
			var_used_for_max_width = qsize;
		if(qsize == 0) // there are no more nodes in the queue
			// return height;
			break;
		// ++height;

		while(qsize > 0){
			node *temp = q.front();
			q.pop();
			if(temp->left)	
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
			--qsize;
		}
	}
	return var_used_for_max_width;
}

void findminmaxwidth(node *root, int &min, int &max, int val){
	if(root == NULL)
		return;
	if(val < min)
		min = val;
	if(val > max)
		max = val;

	findminmaxwidth(root->left, min, max, val-1);
	findminmaxwidth(root->right, min, max, val+1);
}

void printvertical(node *root, int i, int curr){
	if(root == NULL)
		return;
	if(curr == i)
		cout<<root->data<<" ";
	
	printvertical(root->left, i, curr-1);
	printvertical(root->right, i, curr+1);
	
}

void printbinarytreeinverticalorder(node *root){
	int min = 0, max = 0;
	findminmaxwidth(root, min, max, 0);
	for(int i = min; i <= max; ++i){
		printvertical(root, i, 0);
		cout<<endl;
	}
}


/*connect leaves to linkedlist* microsoft */

node *connectleaves(node *root){
	if(root == NULL)
		return NULL;
	static node *headll = NULL;
	static node *head = NULL;
	connectleaves(root->left);
	if(root->left == NULL && root->right == NULL){
		if(!head){
			head = root;
			headll = head;
		}
		else{
			head->right = root;
			head = head->right;
		}
	}
	connectleaves(root->right);
	return headll;
}

node *connectleaves2(node *root, node **headref){
	if(root == NULL)
		return NULL;
	if(root->left == NULL && root->right == NULL){ // root is a leaf
		root->right = *headref;
		(*headref) = root;
		return *headref;
	}
	connectleaves2(root->right, headref);
	connectleaves2(root->left, headref);
}



int main(){
	
	Tree bst;
	bst.insert(7);
	bst.insert(8);
	bst.insert(4);
	bst.insert(3);
	bst.insert(5);
	bst.insert(6);
	bst.insert(8);
	bst.insert(10);
	bst.insert(9);
	bst.insert(11);
	node *headref = NULL;
	node *head = connectleaves(bst.root);
	displaylinkedlist(head);
	// head = connectleaves2(bst.root, &headref);
	// displaylinkedlist(head);


	// printbinarytreeinverticalorder(bst.root);

	/*cout<<widthofabinarytreeiterative(bst.root);

	cout<<maximumwidth(bst.root);*/


	/*leavestolinkedlist(bst.root);*/

	/*if(checkifsumtree(bst.root))
		cout<<"Yes\n";
	else
		cout<<"No\n";*/

	/*ancestorsofagivennode(bst.root, 3);*/
	/*inorderwithoutrecursion(bst.root);*/

	/*if(isbalanced(bst.root))
		cout<<"Yes.\n";
	else
		cout<<"No.\n";*/

	/*cout<<diameter(bst.root);*/
	

	/*printspiral(bst.root);*/
	/*cout<<countleafnodes(bst.root);*/
	/*printroottoleafpathspre(bst.root);*/
	/*bst.inorder(bst.root);cout<<endl;
	mirrortree(&bst.root);
	bst.inorder(bst.root);*/

	/*deleteatree(&bst.root);
	// cout<<bst.root->data<<endl;
	bst.inorder(bst.root);*/
	/*cout<<maximumdepth(bst.root);*/


	/*if(bst.checktriplettozero(bst.root))
		cout<<"Yes\n";
	else
		cout<<"No\n";*/



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
