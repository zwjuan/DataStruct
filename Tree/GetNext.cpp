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

//����������һ�����
class Solution1 {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		TreeLinkNode* cur = pNode;
		if(cur == NULL)
		{
			return NULL;
		}

		//�ж��Һ����Ƿ�ΪNULL
		if(cur->right != NULL)//����������
		{
			cur = cur->right;
			while(cur->left)
			{
				cur = cur->left;
			}
			return cur;
		}

		//�жϴ˽���Ƿ�Ϊ����
		if(cur->next == NULL)
		{
			return NULL;
		}

		if(cur == cur->next->left)
		{
			return cur->next;
		}

		//�˽ڵ�Ϊ���ڵ���ҽڵ㣬���ϻ���, ֱ���ҵ����ڵ��Ǹ��ڵ������
		while(cur->next)
		{
			if(cur == cur->next->left)
			{
				return cur->next;
			}
			//�������ϻ���
			cur = cur->next;
		}

		return NULL;
	}
};