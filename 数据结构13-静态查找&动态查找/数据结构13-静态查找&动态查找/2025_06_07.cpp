#include<iostream>
using namespace std;
#include<vector>

void Find(vector<int> v1, int k)
{
	int n = v1.size();
	if (n == 0)
	{
		cout << "error" << endl;
		return;
	}
	
	int last = v1[n - 1];
	v1[n - 1] = k;

	int i = 0;
	while (v1[i] != k)
	{
		i++;
	}

	v1[n - 1] = last;

	if (i < n - 1 || last == k)
		cout << i+1 << endl;
	else
		cout << "error" << endl;
}

int main()
{
	int n;
	while(cin >> n)
	{
		
		;

		vector<int> v1(n);
		for (int i = 0; i < n; i++)
		{
			cin >> v1[i];
		}

		int t;
		cin >> t;
		while (t--)
		{
			int k;
			cin >> k;

			Find(v1, k);
		}
	}



	return 0;
}

//#include <iostream>
//using namespace std;
//const int maxn = 1e5 + 10;
//int shuzu[maxn];
//int main()
//{
//    int n;
//    while (cin >> n)
//    {
//        for (int i = 1; i <= n; i++)
//        {
//            cin >> shuzu[i];
//        }
//        int t;
//        cin >> t;
//        while (t--)
//        {
//            int num;
//            cin >> num;
//            shuzu[0] = num;
//            int i = n;
//            for (i = n; shuzu[i] != num; i--);
//            if (i != 0)
//            {
//                cout << i << endl;
//            }
//            else
//            {
//                cout << "error" << endl;
//            }
//        }
//    }
//    return 0;
//}


//#include<iostream>
//using namespace std;
//#include<vector>
//
//void Find(vector<int> v1, int k)
//{
//	int left = 0;
//	int right = v1.size() - 1;
//
//	while (left <= right)
//	{
//		int target = left+(right - left) / 2;
//		if (v1[target] == k)
//		{
//			cout << target+1 << endl;
//			return;
//		}
//
//		if (k <= v1[(right-left) / 2])
//		{
//			right = target - 1;
//		}
//		else
//			left = target + 1;
//	}
//
//	cout << "error" << endl;
//
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//
//	vector<int> v1(n);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> v1[i];
//	}
//
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int k;
//		cin >> k;
//
//		Find(v1, k);
//	}
//
//
//
//	return 0;
//}


//#include <iostream>
//using namespace std;
//#include <cmath>
//
//void Find(int k)
//{
//    double k1 = (double)k;
//    double left = 0.0;
//    double right = 0.0;
//    if (k1 < 1)
//    {
//        left = k1;
//        right = 1.0;
//    }
//    else
//    {
//        left = 0.0;
//        right = k1;
//    }
//
//    double mid = (left + right) / 2;
//    double precision = 0.00001;
//
//    while (fabs(pow(mid,2) - k1) > precision) {
//        if (pow(mid,2) < k1)
//            left = mid;
//        else 
//            right = mid;
//
//        mid = (left + right) / 2;
//    }
//
//    printf("%.3lf\n", mid);
//    
//
//}
//
//int main()
//{
//    int n;
//    cin >> n;
//
//    while (n--) {
//        int k;
//        cin >> k;
//        Find(k);
//    }
//
//    return 0;
//}



//#include<iostream>
//using namespace std;
//#include<vector>
//
//void Find(vector<vector<int>> vv1,int k)
//{
//	int rows = vv1.size();
//	int cols = vv1[0].size();
//
//	int s = 0;
//	vector<int> v1(rows * cols);
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < cols; j++)
//		{
//			v1[s++] = vv1[i][j];
//		}
//	}
//
//	int left = 0;
//	int right = v1.size() - 1;
//
//	while (left <= right)
//	{
//		int mid = left + (right - left)/2;
//		if (k == v1[mid])
//		{
//			cout << "true" << endl;
//			return;
//		}
//		else
//			if (k < v1[mid])
//				right = mid - 1;
//			else
//				left = mid + 1;
//	}
//
//	cout << "false" << endl;
//}
//
//int main()
//{
//	int m, n;
//	cin >> m >> n;
//	vector<vector<int>> vv1(m, vector<int>(n));
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			cin >> vv1[i][j];
//		}
//	}
//
//	int t;
//	cin >> t;
//
//	while (t--)
//	{
//		int k;
//		cin >> k;
//
//		Find(vv1,k);
//	}
//
//
//
//	return 0;
//}


//#include<iostream>
//using namespace std;
//#include<vector>
//
//class TreeNode
//{
//public:
//	int val;
//	TreeNode* left;
//	TreeNode* right;
//
//	TreeNode(int x)
//		:val(x)
//		,left(nullptr)
//		,right(nullptr)
//	{};
//};
//
//TreeNode* insert(TreeNode* root, int x)
//{
//	if (root == nullptr)
//		return new TreeNode(x);
//
//	if (x < root->val)
//		root->left = insert(root->left, x);
//	else
//		root->right = insert(root->right, x);
//
//	return root;
//
//}
//
//TreeNode* BinaryTree(vector<int> v1)
//{
//	TreeNode* root = nullptr;
//	for (int i = 0; i < v1.size(); i++)
//	{
//		root = insert(root, v1[i]);
//	}
//	return root;
//}
//
//void MidOrder(TreeNode* root)
//{
//	if (!root)
//		return ;
//
//	MidOrder(root->left);
//	cout << root->val << " ";
//	MidOrder(root->right);
//
//}
//
//int Find(TreeNode* root, int s)
//{
//	if (!root)
//		return 0;
//
//	int count = 1;
//
//	while (root != nullptr)
//	{
//		if (root->val == s)
//			return count;
//		else
//			if (s < root->val)
//			{
//				root = root->left;
//				count++;
//			}
//			else
//				if (s > root->val)
//				{
//					root = root->right;
//					count++;
//				}
//	}
//
//	return 0;
//}
//
//int main()
//{
//	int t;
//	cin >> t;
//
//	while (t--)
//	{
//		int n;
//		cin >> n;
//		vector<int> v1(n);
//
//		for (int i = 0; i < n; i++)
//		{
//			cin >> v1[i];
//		}
//
//		TreeNode* root = BinaryTree(v1);
//		MidOrder(root);
//		cout << endl;
//
//		int m;
//		cin >> m;
//		for (int i = 0; i < m; i++)
//		{
//			int s;
//			cin >> s;
//			int min = Find(root, s);
//			
//			if (min)
//				cout << min << endl;
//			else
//				cout << "-1" << endl;
//		}
//	}
//
//
//
//	return 0;
//}