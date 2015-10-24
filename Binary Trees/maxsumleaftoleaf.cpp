#include <iostream>
#include <climits>
#include <math.h>
#include <stdio.h>
using namespace std;

struct Node
{
	int data;
	struct Node* left, *right;
};

struct Node* newNode(int data)
{
	struct Node* node = new(struct Node);
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}

int max(int a, int b)
{ return (a >= b)? a: b; }

int maxPathSumUtil(struct Node *root, int &res)
{
	if (root==NULL) return 0;
	if (!root->left && !root->right) return root->data;

	int ls = maxPathSumUtil(root->left, res);
	int rs = maxPathSumUtil(root->right, res);

	int curr_sum = ls + rs + root->data;

	if (res < curr_sum)
		res = curr_sum;


	if (!ls || !rs) return (!ls)? rs + root->data: ls + root->data;
	else return max(ls, rs) + root->data;

	return max(ls, rs)+root->data;
}

int maxPathSum(struct Node *root)
{
	int res = INT_MIN;
	maxPathSumUtil(root, res);
	return res;
}

int maxPathSum2(Node *root, int &ref_var){
	if(root == NULL)
		return 0;

	if(!root->left && !root->right)
		return root->data;

	int l = maxPathSum2(root->left, ref_var);
	int r = maxPathSum2(root->right, ref_var);

	int curr_sum = max(max(l,r),root->data+l+r);
	if(curr_sum > ref_var)
		ref_var = curr_sum;
	
	return max(l, r)+root->data; // max of l and r because only one leaf path to be returned to the parent node

}

int main()
{
	struct Node *root = newNode(-15);
	root->left = newNode(5);
	root->right = newNode(6);
	root->left->left = newNode(-8);
	root->left->right = newNode(1);
	root->left->left->left = newNode(2);
	root->left->left->right = newNode(6);
	root->right->left = newNode(3);
	root->right->right = newNode(9);
	root->right->right->right= newNode(0);
	root->right->right->right->left= newNode(4);
	root->right->right->right->right= newNode(-1);
	root->right->right->right->right->left= newNode(10);
	int ref_var = INT_MIN;
	maxPathSum2(root, ref_var);
	printf("%d\n", ref_var);
	return 0;
}
