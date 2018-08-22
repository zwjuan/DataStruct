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
	//恢复二叉搜索树（二叉搜索树的两个结点被交换）
	void recoverTreeCore(TreeNode* root, TreeNode* &pre, TreeNode* &first,TreeNode* &second)
	{
		//中序遍历
		if(root == NULL)
		{
			return ;
		}
		if(root->left != NULL)
		{
			recoverTreeCore(root->left,pre,first,second);
		}
		
		if(pre != NULL && pre->val > root->val) //不符合二叉搜索树,记录被修改的结点
		{
			if(first == NULL) //first == NULL说明还没找到交换结点
			{
				first = pre;
				second = root;
			}
			else
			{
				second = root;
			}
		}

		pre = root; 

		if(root ->right != NULL)
		{
			recoverTreeCore(root->right,pre,first,second);
		}
	}

	void recoverTree(TreeNode *root) 
	{
		TreeNode* pre = NULL;
		TreeNode* first = NULL;
		TreeNode* second = NULL;

		recoverTreeCore(root,pre,first,second);

		if(first != NULL && second != NULL)
		{
			swap(first->val,second->val);
		}
	}
}