#include <string>
#include <vector>
#include <stack>
#include <queue>
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
	
	void SerializeCore(TreeNode* root,string& s)
	{
		if(root == NULL)
		{
			s+= '#';
			return ;
		}

		s+=to_string(root->val);//
		s+=',';
		SerializeCore(root->left,s);
		SerializeCore(root->right,s);
	}

	char* Serialize(TreeNode *root) 
	{    
		if(root == NULL)
		{
			return NULL;
		}
		string s;
		SerializeCore(root,s);

		char* ret = new char[s.length()+1];//
		int i=0;
		for(;i<s.length(); ++i)
		{
			ret[i] = s[i];
		}
		ret[i] = '\0';
		
		return ret;
	}

	TreeNode* DeserializeCore(char** str)
	{
		if(**str == '#')
		{
			++(*str);
			return NULL;
		}

		int num = 0;
		while(**str != '\0' && **str != ',')
		{
			num = num*10+((**str)-'0');
			++(*str);
		}

		TreeNode* root = new TreeNode(num);
		if(**str == '\0')
		{
			return root;
		}
		else
		{
			++(*str);
		}
		root->left = DeserializeCore(str);
		root->right = DeserializeCore(str);

		return root;
	}

	TreeNode* Deserialize(char *str) 
	{
		if(str == NULL)
		{
			return NULL;
		}

		return DeserializeCore(&str);
	}
}

void TestSerialize()
{
	TreeNode* root = new TreeNode(1);
	TreeNode* left = new TreeNode(2);
	TreeNode* right = new TreeNode(3);
	TreeNode* lleft = new TreeNode(4);
	root->left = left;
	root->right = right;
	left->left = lleft;

	Solution s;
	char* c = s.Serialize(root);
	cout<<c<<endl;
	TreeNode* ret = s.Deserialize(c);
}

int main()
{
	TestSerialize();
	return 0;
}

