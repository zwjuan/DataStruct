#include <iostream>
using namespace std;

struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

	}
};

//二叉树的下一个结点
class Solution1 {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		TreeLinkNode* cur = pNode;
		if(cur == NULL)
		{
			return NULL;
		}

		//判断右孩子是否为NULL
		if(cur->right != NULL)//返回最左结点
		{
			cur = cur->right;
			while(cur->left)
			{
				cur = cur->left;
			}
			return cur;
		}

		//判断此结点是否为左结点
		if(cur->next == NULL)
		{
			return NULL;
		}

		if(cur == cur->next->left)
		{
			return cur->next;
		}

		//此节点为父节点的右节点，向上回溯, 直到找到父节点是父节点的左结点
		while(cur->next)
		{
			if(cur == cur->next->left)
			{
				return cur->next;
			}
			//继续向上回溯
			cur = cur->next;
		}

		return NULL;
	}
};