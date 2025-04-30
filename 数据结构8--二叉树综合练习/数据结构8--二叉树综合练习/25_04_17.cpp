//#include<iostream>
//using namespace std;
//#include<string>
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
//};
//
//TreeNode* BuildTree(const string& abc, int& x)
//{
//	if (x >= abc.size() || abc[x] == '0')
//	{
//		x++;
//		return nullptr;
//	}
//
//	TreeNode* newNode = new TreeNode(abc[x++]);
//	newNode->left = BuildTree(abc, x);
//	newNode->right = BuildTree(abc, x);
//
//	return newNode;
//}
//
//int Treeheight(TreeNode* root)
//{
//	if (root == nullptr)
//		return 0;
//
//	int leftH = Treeheight(root->left);
//	int rightH = Treeheight(root->right);
//
//	return (leftH > rightH ? leftH : rightH )+ 1;
//
//}
//
//int main()
//{
//	int t,i;
//	cin >> t;
//	string abc;
//
//	while (t--)
//	{
//		cin >> abc;
//		i = 0;
//		TreeNode* root = BuildTree(abc, i);
//		cout << Treeheight(root) << endl;
//	}
//
//
//	return 0;
//}





//#include<iostream>
//using namespace std;
//#include<string>
//#include<queue>
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
//};
//
//TreeNode* BuildTree(const string& abc, int& x)
//{
//	if (x >= abc.size() || abc[x] == '0')
//	{
//		x++;
//		return nullptr;
//	}
//
//	TreeNode* newNode = new TreeNode(abc[x++]);
//	newNode->left = BuildTree(abc, x);
//	newNode->right = BuildTree(abc, x);
//
//	return newNode;
//}
//
//void LevelOrder(TreeNode * root)
//{
//	queue<TreeNode*> q;
//	q.push(root);
//
//	if (root == nullptr)
//		return;
//
//	while (!q.empty()) 
//	{
//		TreeNode* root = q.front();
//		q.pop();
//		cout << root->val;
//
//		if (root->left)
//			q.push(root->left);
//		if (root->right)
//			q.push(root->right);
//	}
//	
//	cout << endl;
//
//}
//
//int main()
//{
//	int t, i;
//	cin >> t;
//	string abc;
//
//
//	while (t--)
//	{
//		cin >> abc;
//		i = 0;
//		TreeNode* root = BuildTree(abc, i);
//		LevelOrder(root);
//	}
//
//
//	return 0;
//}





//#include<iostream>
//using namespace std;
//#include<stack>
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
//	{ }
//};
//
//TreeNode* BuildTree(const string& abc, int& x)
//{
//	if (x >= abc.size() || abc[x] == '0')
//	{
//		x++;
//		return nullptr;
//	}
//
//	TreeNode* newNode = new TreeNode(abc[x++]);
//	newNode->left = BuildTree(abc, x);
//	newNode->right = BuildTree(abc, x);
//
//	return newNode;
//}
//
//void posOrder(TreeNode* root)
//{
//	if (root == nullptr)
//		return;
//
//	stack<int> s1;
//	stack<TreeNode*>s2;
//
//	do
//	{
//		while (root)
//		{
//			s2.push(root);
//			s1.push(0);
//
//			root = root->left;
//		}
//
//		int tag = s1.top();
//		if (tag == 0)
//		{
//			s1.pop();
//			s1.push(1);
//			root = s2.top()->right;
//		}
//		else
//		{
//			TreeNode* p = s2.top();
//			s1.pop();
//			s2.pop();
//
//			cout << p->val;
//
//		}
//
//
//	} while (!s2.empty());
//
//	cout << endl;
//
//
//}
//
//int main()
//{
//	int t,i;
//	cin >> t;
//	string abc;
//
//	while (t--)
//	{
//		cin >> abc;
//		i = 0;
//		TreeNode* root = BuildTree(abc, i);
//		posOrder(root);
//	}
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
//		,left(nullptr)
//		,right(nullptr)
//	{ }
//		
//};
//
//
//TreeNode* BuildTree(const string& str,int& i)
//{
//	if (i >= str.size() || str[i] == '#')
//	{
//		i++;
//		return nullptr;
//	}
//
//	TreeNode* newNode = new TreeNode(str[i++]);
//	newNode->left = BuildTree(str, i);
//	newNode->right = BuildTree(str, i);
//
//	return newNode;
//
//}
//
//
//TreeNode* mirrorTree(TreeNode* root)
//{
//	if (!root)
//		return nullptr;
//
//	swap(root->left, root->right);
//	mirrorTree(root->left);
//	mirrorTree(root->right);
//
//	return root;
//}
//
//
//void ProOrder(TreeNode* root)
//{
//	if (!root)
//		return;
//
//	cout << root->val << " ";
//	ProOrder(root->left);
//	ProOrder(root->right);
//
//}
//
//void InOrder(TreeNode* root)
//{
//	if (!root)
//		return;
//
//	InOrder(root->left);
//	cout << root->val << " ";
//	InOrder(root->right);
//
//}
//
//void PosOrder(TreeNode* root)
//{
//	if (!root)
//		return;
//
//	PosOrder(root->left);
//	PosOrder(root->right);
//	cout << root->val << " ";
//
//}
//
//int TreeHeight(TreeNode* root)
//{
//	if (!root)
//		return 0;
//
//	int leftH = TreeHeight(root ->left);
//	int rightH = TreeHeight(root->right);
//
//	return (leftH > rightH ? leftH  : rightH)+1;
//
//}
//
//void LevelOrderPrint(TreeNode* root, int i)
//{
//	if (!root)
//		return;
//		
//
//	if (i == 1)
//		cout << root->val << " ";
//	else
//	{
//		LevelOrderPrint(root->left, i-1);
//		LevelOrderPrint(root->right, i-1);
//	}
//}
//
//void LevelOrder(TreeNode* root)
//{
//	int H = TreeHeight(root);
//	for (int i = 1; i <= H; i++)
//		LevelOrderPrint(root, i);
//
//}
//
//int main()
//{
//
//	int t;
//	cin >> t;
//	string str;
//
//	while (t--)
//	{
//		cin >> str;
//		int i = 0;
//		TreeNode* root = BuildTree(str, i);
//
//		if (!root) 
//		{
//			cout << "NULL" << endl;
//			cout << "NULL" << endl;
//			cout << "NULL" << endl;
//			cout << "NULL" << endl;
//			continue;
//		}
//		root = mirrorTree(root);
//		ProOrder(root);
//		cout << endl;
//		InOrder(root);
//		cout << endl;
//		PosOrder(root);
//		cout << endl;
//		LevelOrder(root);
//		cout << endl;
//	}
//
//	return 0;
//}





#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// 定义二叉树节点结构
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 根据中序和后序遍历构建二叉树
TreeNode* buildTree(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd) {
    if (inStart > inEnd || postStart > postEnd) {
        return nullptr;
    }
    // 后序遍历的最后一个元素是根节点
    int rootVal = postorder[postEnd];
    TreeNode* root = new TreeNode(rootVal);

    // 在中序遍历中找到根节点的位置
    int rootIndexInorder = 0;
    for (int i = inStart; i <= inEnd; i++) {
        if (inorder[i] == rootVal) {
            rootIndexInorder = i;
            break;
        }
    }

    // 计算左子树的节点数量
    int leftSubtreeSize = rootIndexInorder - inStart;

    // 递归构建左子树和右子树
    root->left = buildTree(inorder, inStart, rootIndexInorder - 1, postorder, postStart, postStart + leftSubtreeSize - 1);
    root->right = buildTree(inorder, rootIndexInorder + 1, inEnd, postorder, postStart + leftSubtreeSize, postEnd - 1);

    return root;
}

// 辅助函数：释放二叉树内存
void freeTree(TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

// 求叶子节点权值的最小值
int findMinLeafValue(TreeNode* root) {
    if (!root) return INT_MAX;
    if (!root->left && !root->right) return root->val;
    int leftMin = findMinLeafValue(root->left);
    int rightMin = findMinLeafValue(root->right);
    return min(leftMin, rightMin);
}

int main() {
    int N;
    while (cin >> N) {
        vector<int> inorder(N);
        vector<int> postorder(N);

        // 读取中序遍历结果
        for (int i = 0; i < N; i++) {
            cin >> inorder[i];
        }
        // 读取后序遍历结果
        for (int i = 0; i < N; i++) {
            cin >> postorder[i];
        }

        // 构建二叉树
        TreeNode* root = buildTree(inorder, 0, N - 1, postorder, 0, N - 1);

        // 求叶子节点权值的最小值
        int minLeafValue = findMinLeafValue(root);
        cout << minLeafValue << endl;

        // 释放二叉树内存
        freeTree(root);
    }

    return 0;
}