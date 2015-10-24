#include<stdio.h>
#include<limits.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

bool printPath (struct node *root, struct node *target_leaf)
{
	// base case
	if (root == NULL)
		return false;

	if (root == target_leaf || printPath(root->left, target_leaf) ||
			printPath(root->right, target_leaf) )
	{
		printf("%d ", root->data);
		return true;
	}

	return false;
}

void getTargetLeaf (struct node *node, int *max_sum_ref, int curr_sum,
				struct node **target_leaf_ref)
{
	if (node == NULL)
		return;

	curr_sum = curr_sum + node->data;

	if (node->left == NULL && node->right == NULL)
	{
		if (curr_sum > *max_sum_ref)
		{
			*max_sum_ref = curr_sum;
			*target_leaf_ref = node;
		}
	}

	// If this is not a leaf node, then recur down to find the target_leaf
	getTargetLeaf (node->left, max_sum_ref, curr_sum, target_leaf_ref);
	getTargetLeaf (node->right, max_sum_ref, curr_sum, target_leaf_ref);
}

int maxSumPath (struct node *node)
{
	// base case
	if (node == NULL)
		return 0;

	struct node *target_leaf;
	int max_sum = INT_MIN;

	getTargetLeaf (node, &max_sum, 0, &target_leaf);

	printPath (node, target_leaf);

	return max_sum; // return maximum sum
}

struct node* newNode (int data)
{
	struct node *temp = new struct node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

int maxSumPath2(node *root, int &ref_var, int curr_sum, node* &leafnode){
	if(root == NULL)
		return 0;
	if(root->left == NULL && root->right == NULL){
		curr_sum += root->data;
		if(ref_var < curr_sum){
			ref_var = curr_sum;
			leafnode = root;
		}
	}

	maxSumPath2(root->left, ref_var, curr_sum+root->data, leafnode);
	maxSumPath2(root->right, ref_var, curr_sum+root->data, leafnode);

}

int main()
{
	struct node *root = NULL;

	root = newNode(10);
	root->left = newNode(-2);
	root->right = newNode(7);
	root->left->left = newNode(8);
	root->left->right = newNode(-4);

	printf ("Following are the nodes on the maximum sum path \n");
	int ref_var = INT_MIN;
	node *leafnode = NULL;
	maxSumPath2(root, ref_var, 0, leafnode);
	printf("%d\n", ref_var);
	printPath(root, leafnode);
	return 0;
}
