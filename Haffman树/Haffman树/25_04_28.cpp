//#include<iostream>
//using namespace std;
//#include<vector>
//#include<queue>
//#include<map>
//
//struct HaffmanNode
//{
//	int val;
//	HaffmanNode* left;
//	HaffmanNode* right;
//
//	HaffmanNode(const int&x)
//		:val(x)
//		,left(nullptr)
//		,right(nullptr)
//	{ }
//
//
//};
//
//struct compare 
//{
//
//	bool operator()(HaffmanNode* left, HaffmanNode* right)
//	{
//		return left->val > right->val;
//	}
//
//};
//
//HaffmanNode* BuildHaffmanTree(const vector<int>& v1)
//{
//	priority_queue<HaffmanNode*, vector<HaffmanNode*>, compare> minHeap;
//
//	for (int e : v1)
//		minHeap.push(new HaffmanNode(e));
//
//	while (minHeap.size() > 1)
//	{
//		HaffmanNode* left = minHeap.top();
//		minHeap.pop();
//
//		HaffmanNode* right = minHeap.top();
//		minHeap.pop();
//
//		HaffmanNode* newNode = new HaffmanNode(left->val + right->val);
//		newNode->left = left;
//		newNode->right = right;
//
//		minHeap.push(newNode);
//	}
//
//	return minHeap.top();
//}
//
//void PerOrder(HaffmanNode* root,string str ,vector<int>& v1, map<int,vector<string>>& m1)
//{
//
//	if (!root)
//		return;
//
//	if (!root->left && !root->right)
//		m1[root->val].push_back(str);
//
//	PerOrder(root->left, str + '0', v1,m1);
//	PerOrder(root->right, str + '1', v1,m1);
//}
//
//
//int main()
//{
//	int t;
//	cin >> t;
//	
//
//	while (t--)
//	{
//		int n;
//		cin >> n;
//		
//
//		vector<int> v1(n);
//		for (int i = 0; i < n; i++)
//			cin >> v1[i];
//
//		HaffmanNode* root = BuildHaffmanTree(v1);
//
//		string str;
//		map<int, vector<string>> m1;
//		PerOrder(root, str, v1,m1);
//
//		map<int, int> m2;
//		for (int i = 0; i < n; i++) 
//		{
//			int e = v1[i];
//			
//			cout << e << '-' << m1[e][m2[e]] << endl;
//			m2[e]++;
//		}
//
//	}
//
//	return 0;
//}



#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<map>

struct HaffmanNode
{
	char val;
	int weight;
	HaffmanNode* left;
	HaffmanNode* right;

	HaffmanNode(char x,int y)
		:val(x)
		,weight(y)
		,left(nullptr)
		,right(nullptr)
	{ }
};

struct compare
{
	bool operator()(HaffmanNode* left, HaffmanNode* right)
	{
		if (left->weight == right->weight) {
			return left->val > right->val;									// 权值相同比较对应的字符大小 ！！！
		}
		return left->weight > right->weight;
	}
};

HaffmanNode* BuildHaffmanTree(const map<char,int>& m1)							
{
	priority_queue<HaffmanNode*, vector<HaffmanNode*>, compare> minHeap;						

	for (const auto& e : m1)
		minHeap.push(new HaffmanNode(e.first, e.second));

	while (minHeap.size() > 1)
	{
		HaffmanNode* left = minHeap.top();
		minHeap.pop();
		HaffmanNode* right = minHeap.top();
		minHeap.pop();

		HaffmanNode* newNode = new HaffmanNode('#',left->weight + right->weight);
		newNode->left = left;
		newNode->right = right;

		minHeap.push(newNode);
	}


	return minHeap.top();

}


void HaffmanTreedecode(HaffmanNode* root, const vector<string>& v3)
{
	for (const string& str : v3)
	{
		string abc;
		HaffmanNode* tempNode = root;
		bool valid = true;
		for (char j : str)
		{
			if (j == '0')
			{
				if (tempNode->left != nullptr)
					tempNode = tempNode->left;
				else
				{
					valid = false;
					break;
				}
			}
			else if (j == '1')
			{
				if (tempNode->right != nullptr)
					tempNode = tempNode->right;
				else
				{
					valid = false;
					break;
				}
			}
			if (!tempNode->left && !tempNode->right)
			{
				abc += tempNode->val;
				tempNode = root;
			}
		}
		if (valid && tempNode == root)
		{
			cout << abc << endl;
		}
		else
		{
			cout << "error" << endl;
		}
	}
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;
		vector<char> v1(n);						
		vector<int> v2(n);
		for (int i = 0; i < n; i++)
			cin >> v2[i];
		for (int i = 0; i < n; i++)
			cin >> v1[i];

		map<char, int>m1;
		for (int i = 0; i < v1.size(); i++)
			m1[v1[i]] =  v2[i];


		// 编码字符串
		int k;
		cin >> k;
		vector<string> v3;
		string str;

		for (int i = 0; i < k; i++)
		{	
			cin >> str;
			v3.push_back(str);
		}

		//for (string e : v3)
		//	cout << e << endl;


		HaffmanNode* root = BuildHaffmanTree(m1);
		HaffmanTreedecode(root,v3);
	}




	return 0;
}


