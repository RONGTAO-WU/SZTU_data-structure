#include<iostream>
using namespace std;

struct TreeNode
{
	char val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(const char& x)
		:val(x)
		,left(nullptr)
		,right(nullptr)
	{ }

};

TreeNode* BuildTree(const string& str, int& i) 
{
	if (i >= str.size() || str[i] == '#') 
	{
		i++;
		return nullptr;
	}

	TreeNode* newnode = new TreeNode(str[i++]);
	newnode->left = BuildTree(str, i);
	newnode->right = BuildTree(str, i);

	return newnode;
}

void ProOrder(TreeNode* root)
{
	if (root == nullptr)
		return;

	cout << root->val;
	ProOrder(root->left);
	ProOrder(root->right);

}

void InOrder(TreeNode* root)
{

	if (root == nullptr)
		return;

	InOrder(root->left);
	cout << root->val;
	InOrder(root->right);
}

void PosOrder(TreeNode* root)
{
	if (root == nullptr)
		return;

	PosOrder(root->left);
	PosOrder(root->right);
	cout << root->val;
}

int main()
{

	int t;
	cin >> t;
	string str;
	int i = 0;

	while (t--)
	{
		cin >> str;
		TreeNode* root = BuildTree(str,i);
		i = 0;
		ProOrder(root);
		cout << endl;
		InOrder(root);
		cout << endl;
		PosOrder(root);
		cout << endl;
		
	}

	return 0;
}


//#include<iostream>
//using namespace std;
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
//	{ }
//
//};
//
//TreeNode* BuildTree(const string& str, int& i) 
//{
//	if (i >= str.size() || str[i] == '0') 
//	{
//		i++;
//		return nullptr;
//	}
//
//	TreeNode* newnode = new TreeNode(str[i++]);
//	newnode->left = BuildTree(str, i);
//	newnode->right = BuildTree(str, i);
//
//	return newnode;
//}
//
//int ProOrder(TreeNode* root,int& j)
//{
//	if (root == nullptr)
//		return 0;
//
//	if (root->left == nullptr && root->right == nullptr)
//		j++;
//	ProOrder(root->left,j);
//	ProOrder(root->right,j);
//
//	return j;
//
//}
//
//int main()
//{
//	int t;
//	cin >> t;
//	string str;
//	
//
//	while (t--)
//	{
//		cin >> str;
//		int i = 0;
//		int j = 0;
//		TreeNode* Node = BuildTree(str, i);
//		cout << ProOrder(Node, j) << endl;
//	}
//
//
//
//	return 0;
//}


//#include<iostream>
//using namespace std;
//
//struct TreeNode
//{
//	char val;
//	TreeNode* left;
//	TreeNode* right;
//
//	TreeNode(const char& x)
//		:val(x)
//		, left(nullptr)
//		, right(nullptr)
//	{}
//
//};
//
//TreeNode* BuildTree(const string& str, int& i)
//{
//	if (i >= str.size() || str[i] == '0')
//	{
//		i++;
//		return nullptr;
//	}
//
//	TreeNode* newnode = new TreeNode(str[i++]);
//	newnode->left = BuildTree(str, i);
//	newnode->right = BuildTree(str, i);
//
//	return newnode;
//}
//
//int ProOrder(TreeNode* root, int& j)
//{
//	
//	if (root == nullptr)
//		return 0;
//
//	if (root->left)
//	{
//		if (root->left->left == nullptr && root->left->right == nullptr)
//			j++;
//	}
//
//	ProOrder(root->left, j);
//	ProOrder(root->right, j);
//
//	return  j;
//
//}
//
//int main()
//{
//	int t;
//	cin >> t;
//	string str;
//
//
//	while (t--)
//	{
//		cin >> str;
//		int i = 0;
//		int j = 0;
//		TreeNode* Node = BuildTree(str, i);
//		cout << ProOrder(Node,j) << endl;
//	}
//
//
//
//	return 0;
//}




//#include<iostream>
//using namespace std;
//#include<queue>
//
//struct TreeNode
//{
//	char val;
//	TreeNode* left;
//	TreeNode* right;
//
//
//	TreeNode(const char& x)
//		:val(x)
//		, left(nullptr)
//		, right(nullptr)
//	{}
//
//};
//
//TreeNode* BuildTree(const string& str, int& i)
//{
//	if (i >= str.size() || str[i] == '0')
//	{
//		i++;
//		return nullptr;
//	}
//
//	TreeNode* newnode = new TreeNode(str[i++]);
//	newnode->left = BuildTree(str, i);
//	newnode->right = BuildTree(str, i);
//
//	return newnode;
//}
//
//void ProOrder(TreeNode* root, queue<char>& q)
//{
//
//	if (root == nullptr)
//		return;
//
//	if (root->left)
//	{
//		if (root->left->left == nullptr && root->left->right == nullptr)
//		{
//			q.push(root->val);
//			cout << root->left->val << " ";
//		}
//		
//	}	
//	ProOrder(root->left,q);
//
//	if (root->right)
//	{
//		if (root->right->left == nullptr && root->right->right == nullptr)
//		{
//			q.push(root->val);
//			cout << root->right->val << " ";
//		}
//
//	}
//
//	ProOrder(root->right,q);
//	
//}
//
//int main()
//{
//	int t;
//	cin >> t;
//	string str;
//	queue<char> q;
//
//	while (t--)
//	{
//		cin >> str;
//		int i = 0;
//		TreeNode* Node = BuildTree(str, i);
//		ProOrder(Node, q);
//		
//		
//		if (q.empty())									// A00
//			cout << Node->val << " " << endl;			// " " ?
//		else
//			cout << endl;
//	
//		while (!q.empty()) 
//		{
//			cout << q.front() << " ";
//			q.pop();
//		}
//		cout << endl;
//		
//	}
//
//
//	return 0;
//}


//#include<iostream>
//using namespace std;
//#include<vector>
//
//struct TreeNode
//{
//	int val;
//	TreeNode* left;
//	TreeNode* right;
//
//
//	TreeNode(const int& x)
//		: val(x)
//		, left(nullptr)
//		, right(nullptr)
//	{}
//
//};
//
//TreeNode* BuildTree(const vector<int>& v1, int i)
//{
//	if (i >= v1.size() || v1[i] == 0)
//		return nullptr;
//
//	TreeNode* newnode = new TreeNode(v1[i]);
//	newnode->left = BuildTree(v1,i*2 + 1);
//	newnode->right = BuildTree(v1,i*2 +2);
//
//	return newnode;
//}
//
//void ProOrder(TreeNode* root)
//{
//	if (root == nullptr)
//		return;
//
//	cout << root->val << " ";
//	ProOrder(root->left);
//	ProOrder(root->right);
//	
//
//}
//
//int main()
//{
//	int t;
//	cin >> t;
//	int n,i,j;
//
//	while (t--)
//	{
//		cin >> n;
//		vector<int> v1(n);
//		for (int j = 0; j < n; j++)
//			cin >> v1[j];
//		
//		i = 0;
//		TreeNode* root = BuildTree(v1, i);
//		ProOrder(root);
//		cout << endl;
//
//	}
//
//
//	return 0;
//}

