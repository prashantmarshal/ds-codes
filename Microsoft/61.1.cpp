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