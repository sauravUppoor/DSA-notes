/*
BST 
1. Create 
2. Traverse
3. Insert
4. Search
*/

#include <iostream>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left, *right;
};

struct TreeNode* insert(TreeNode *root, int val)
{
	struct TreeNode *temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	temp->val = val;
	temp->left = NULL;
	temp->right = NULL;
	struct TreeNode *cur = root;
	int i = 2;
	if(root == NULL) root = temp;
	else
	{
		while(1)
		{
			// go to left
			if(val <= cur->val)
			{
				if(cur->left == NULL) {cur->left = temp;break;}
				else cur = cur->left;
			}
			else // go to right 
			{
				if(cur->right == NULL) {cur->right = temp; break;}
				else cur = cur->right;
			}
		}
	}
	return root;
}

void inorder(TreeNode *root)
{
	if(root->left != NULL) inorder(root->left);
	cout << root->val << ' ';
	if(root->right != NULL) inorder(root->right);
}

bool search(TreeNode *root, int val)
{
	struct TreeNode *cur = root;
	while(1)	
	{
		if(cur->val == val) return 1;
		if(cur->val >= val)
		{
			if(cur->left == NULL) return 0;
			cur = cur->left;
		}
		else 
		{
			if(cur->right == NULL) return 0;
			cur = cur->right;
		}
	}
}

int main()
{
	int n;
	cin >> n;
	struct TreeNode *T;
	T = NULL;
	T = insert(NULL, 6);
	T = insert(T, 5);
	T = insert(T, 8);
	T = insert(T, 10);
	T = insert(T, 9);
	inorder(T);
	cout << '\n' << search(T, 5) << '\n';
}