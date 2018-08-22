#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:

	//ÅÐ¶ÏÊÇ·ñÊÇ¶þ²æËÑË÷Ê÷
	bool isValidBSTCore(TreeNode *root,TreeNode *&pre)
	{
		if(root == NULL)
		{
			return true;
		}
		if(isValidBSTCore(root->left,pre) == false)
		{
			return false;
		}
		
		if(pre != NULL && pre->val >= root->val)
		{
			return false;
		}
		pre = root;

		if(isValidBSTCore(root->right,pre) == false)
		{
			return false;
		}

		return true;
	}

	bool isValidBST(TreeNode *root) 
	{
		TreeNode* pre = NULL;
		return isValidBSTCore(root,pre);
	}
};