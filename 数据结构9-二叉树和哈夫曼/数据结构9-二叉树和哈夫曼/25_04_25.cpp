//#include<iostream>
//using namespace std;
//#include<vector>
//#include<queue>
//
//struct TreeNode 
//{
//	int val;
//	TreeNode* left;
//	TreeNode* right;
//
//	TreeNode(const int& x)
//		:val(x)
//		,left(nullptr)
//		,right(nullptr)
//	{ }
//};
//
//TreeNode* SeqBuildTree(const vector<int>& v1)								// 层序遍历构建二叉树
//{
//	if (v1.empty())
//		return nullptr;
//
//	TreeNode* root = new TreeNode(v1[0]);
//	queue<TreeNode*>q1;
//	q1.push(root);
//	
//	int i = 1;
//	while (!q1.empty() && i < v1.size())
//	{
//		TreeNode* _root = q1.front();
//		q1.pop();
//
//		if (v1[i] != -1)
//		{
//			_root->left = new TreeNode(v1[i]);
//			q1.push(_root->left);
//		}
//		i++;
//
//		if (i < v1.size() && v1[i] != -1)
//		{
//			_root->right = new TreeNode(v1[i]);
//			q1.push(_root->right);
//		}
//		i++;
//	}
//
//	return root;
//}
//
//
//bool sym(TreeNode* left, TreeNode* right)
//{
//	if (left == nullptr && right == nullptr)
//		return true;
//	if (left == nullptr || right == nullptr)
//		return false;
//
//	return (left->val == right->val) && sym(left->left, right->right) && sym(left->right, right->left);
//}
//
//
//bool symTree(TreeNode* root)
//{
//	if (!root)
//		return true;
//	
//	return sym(root->left, root->right);
//}
//
//
//int main()
//{
//
//	int t;
//	cin >> t;
//	
//
//	while (t--)
//	{
//		int n;
//		cin >> n;
//		vector<int> v1(n);
//
//		for (int i = 0; i < n; i++)
//			cin >> v1[i];
//
//		TreeNode* root = SeqBuildTree(v1);
//
//		bool k = symTree(root);
//		if (k)
//			cout << "true" << endl;
//		else
//			cout << "false" << endl;
//	}
//
//
//
//
//}



//#include<iostream>
//using namespace std;
//#include<vector>
//
//struct TreeNode
//{
//	char val;
//	TreeNode* left;
//	TreeNode* right;
//
//	TreeNode(const char& x)
//		:val(x)
//		,left(nullptr)
//		,right(nullptr)
//	{}
//};
//
//TreeNode* BuildTree(const string& str, int& p)
//{
//	if (p >= str.size() || str[p] == '0')
//	{
//		p++;
//		return nullptr;
//	}
//
//	TreeNode* newNode = new TreeNode(str[p++]);
//	newNode->left = BuildTree(str, p);
//	newNode->right = BuildTree(str, p);
//
//	return newNode;
//}
//
//int PosOrdir(TreeNode* root, const vector<int>& v1,int& i,int e)
//{
//	if (!root)
//		return 0;
//
//	if (!root->left && !root->right)
//		return e * v1[i++];
//
//	return PosOrdir(root->left, v1, i, e + 1)+PosOrdir(root->right, v1, i, e + 1);
//
//}
//
//int main()
//{
//	int t;
//	cin >> t;
//	string str;
//
//	while (t--)
//	{
//		cin >> str;
//		int n,p;
//		p = 0;
//		cin >> n;
//		vector<int> v1(n);
//
//		for (int i = 0; i < n; i++)
//			cin >> v1[i];
//
//		TreeNode* root = BuildTree(str, p);
//		int i = 0;
//		int e = 0;
//		cout << PosOrdir(root, v1, i,e) << endl;;
//	}
//
//
//
//	return 0;
//}



//#include<iostream>
//using namespace std;
//#include<vector>
//#include<queue>
//
//struct TreeNode
//{
//	int val;
//	TreeNode* left;
//	TreeNode* right;
//
//	TreeNode(const int& x)
//		:val(x)
//		, left(nullptr)
//		, right(nullptr)
//	{ }
//};
//
//TreeNode* seqBuildTree(const vector<int>& v1)
//{
//	if (v1.empty())
//		return nullptr;
//
//	queue<TreeNode*> q1;
//
//	TreeNode* root = new TreeNode(v1[0]);
//	q1.push(root);
//
//	int i = 1;
//	while (!q1.empty() && i < v1.size())
//	{
//		TreeNode* _root = q1.front();
//		q1.pop();
//
//		
//		_root->left = new TreeNode(v1[i]);
//		q1.push(_root->left);
//		i++;
//
//		if (i < v1.size())
//		{
//			_root->right = new TreeNode(v1[i]);
//			q1.push(_root->right);
//		}
//		i++;
//	}
//
//
//	return root;
//
//}
//
//bool IsSameTree(TreeNode* root1, TreeNode* root2)
//{
//	if (!root1 && !root2)
//		return true;
//
//	if (!root1 || !root2)
//		return false;
//
//	return (root1->val == root2->val) && IsSameTree(root1->left, root2->left) && IsSameTree(root1->right, root2->right);
//}
//
//
//bool IsSubTree(TreeNode* root1, TreeNode* root2)
//{
//	if (!root1)
//		return false;
//
//	bool k = IsSameTree(root1, root2);
//	if (k)
//		return true;
//
//	return IsSubTree(root1->left, root2) || IsSubTree(root1->right, root2);
//}
//
//
//int main()
//{
//	int t;
//	cin >> t;
//
//	while (t--)
//	{
//		int n1,n2;
//
//		cin >> n1;
//		vector<int> v1(n1);
//		for (int i = 0; i < n1; i++)
//			cin >> v1[i];
//
//		cin >> n2;
//		vector<int> v2(n2);
//		for (int i = 0; i < n2; i++)
//			cin >> v2[i];
//
//		TreeNode* root1 = seqBuildTree(v1);
//		TreeNode* root2 = seqBuildTree(v2);
//		bool k = IsSubTree(root1, root2);
//
//		if (k)
//			cout << "true" << endl;
//		else
//			cout << "false" << endl;
//	}
//
//
//	return 0;
//}

#include<iostream>
using namespace std;
#include<vector>

struct HFNode
{
	int weight;
	HFNode* parent;
	HFNode* Lchild;
	HFNode* Rchild;

	HFNode(const int& x)
		:weight(x)
		,parent(nullptr)
		,Lchild(nullptr)
		,Rchild(nullptr)
	{ }
};


HFNode* BuildTree(const vector<int>& v1)
{

}

int main()
{
	int t;
	cin >> t;
	
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> v1(n);

		for (int i = 0; i < n; i++)
			cin >> v1[i];

		BuildTree(v1);
	}



	return 0;
}