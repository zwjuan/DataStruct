#include<vector>
#include <iostream>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution2 {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
		if(pre.empty() || vin.empty())
		{
			return NULL;
		}

		size_t index = 0;
		for(; index < vin.size(); ++index)
		{
			if(vin[index] == pre[0])
			{
				break;
			}
		}
		//找到根节点并构建根节点
		TreeNode* root = new TreeNode(pre[0]);
		//根据中序遍历将根结点左右两侧，一份为二
		vector<int> pre_left, pre_right;
		vector<int> in_left, in_right;

		//记录前序遍历左右子树的根节点
		for(int j=0; j<index; j++)
		{
			pre_left.push_back(pre[j+1]);
			in_left.push_back(vin[j]);
		}

		for(int j=index+1; j<pre.size(); j++)
		{
			pre_right.push_back(pre[j]);
			in_right.push_back(vin[j]);
		}

		//递归构造左右子树
		root->left = reConstructBinaryTree(pre_left,in_left);
		root->right = reConstructBinaryTree(pre_right, in_right);

		return root;

	}
};


void TestReBuild()
{
	Solution2 s2;
	int a[] = {8,6,5,7,10,9,11};
	vector<int> prev(a, a+sizeof(a)/sizeof(a[0]));
	int b[] = {5,6,7,8,9,10,11};
	vector<int> in(b, b+sizeof(b)/sizeof(b[0]));

	TreeNode* root = s2.reConstructBinaryTree(prev, in);
}

int main()
{
	TestReBuild();
	return 0;
}