​
// Author :: Gaurav Ahirwar
#include<bits/stdc++.h>
using namespace std;
 
struct node 
{   
    int data;
    int pathlen;
    struct node* left, *right;
};
typedef struct node node;
 
node *newNode(int data)
{
    node *temp = (node *)malloc(sizeof(struct node));
    temp->data  = data;
    temp->pathlen = 0;
    temp->left  = temp->right = NULL;
    return(temp);
}
 
void getmaxval(node *root, int &res) {
    if(!root) return;   
    res = max(res, root->pathlen);
    getmaxval(root->left, res);
    getmaxval(root->right,res);
}
 
int getlength(node *root, char bend, bool flag) {
    if(!root) return 0; 
    int ans1 = 0, ans2 = 0;
     
    if(flag) ans1 = bend == 'r' ? 1 + getlength(root->right, bend, flag) : 1 + getlength(root->left, bend, flag);
    else {
        if(bend == 'r') ans1 = 1 + max(getlength(root->right, bend, flag), getlength(root->left, 'l', !flag));
        if(bend == 'l') ans1 = 1 + max(getlength(root->left, bend, flag), getlength(root->right, 'r', !flag));        
    }
     
    root->pathlen = 1 + max(getlength(root->left, 'l', false), getlength(root->right, 'r', false));
    return ans1;
}
 
int solve(node *root) {
    if(root == NULL) return 0;
    root->pathlen = 1 + max(getlength(root->left, 'l', false), getlength(root->right, 'r', false));
}
   
 
int main() {
 
// Let us construct the BT shown in the below figure
    node *root        = newNode(4);
    root->left        = newNode(2);
    root->right       = newNode(6);
    root->left->left  = newNode(1);
    root->left->right = newNode(3);
    root->right->left  = newNode(5);
    root->right->right = newNode(7);
    root->right->right->left = newNode(9);
    root->right->right->left->left = newNode(12);
    root->right->right->left->right = newNode(10);
    root->right->right->left->right->right = newNode(11);
    root->right->right->left->right->right->right = newNode(13);
    root->right->right->left->right->right->right->right = newNode(14);    
    /* Constructed binary tree is 
            4
          /   \
        2      6
      /  \    / \
    1     3  5  7
               /
              9
            / \
           12 10
                \
                 11
                  \
                  13
                   \
                   14
   
  */
     
    solve(root);
    int res = 0;
    getmaxval(root, res);
    cout << res << endl;
    return 0;
}
​