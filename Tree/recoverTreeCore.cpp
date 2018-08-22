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
	//�ָ�������������������������������㱻������
	void recoverTreeCore(TreeNode* root, TreeNode* &pre, TreeNode* &first,TreeNode* &second)
	{
		//�������
		if(root == NULL)
		{
			return ;
		}
		if(root->left != NULL)
		{
			recoverTreeCore(root->left,pre,first,second);
		}
		
		if(pre != NULL && pre->val > root->val) //�����϶���������,��¼���޸ĵĽ��
		{
			if(first == NULL) //first == NULL˵����û�ҵ��������
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