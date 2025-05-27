//#include<iostream>
//using namespace std;
//
//
//void printmatrix(int matrix[10][10], int Gvertix)
//{
//	for (int i = 0; i < Gvertix; i++)
//	{
//		for (int j = 0; j < Gvertix; j++)
//		{
//			cout << matrix[i][j];
//			if (j != Gvertix - 1)
//				cout << " ";
//		}
//		cout << endl;
//	}
//}
//
//void printdegree(char Gtype, string vertixInfo[], int matrix[10][10], int Gvertix)
//{
//	for (int i = 0; i < Gvertix; i++)
//	{
//		int der = 0, inder = 0, outder = 0, flag = 0;
//		for (int j = 0; j < Gvertix; j++)
//		{
//			if (matrix[i][j] == 1)
//				outder++;
//			if (matrix[j][i] == 1)
//				inder++;
//
//			if (matrix[i][j] == 0 && matrix[j][i] == 0)
//				flag++;
//
//		}
//		der = outder + inder;
//
//		if (flag == Gvertix)
//		{
//			cout << vertixInfo[i] << endl;
//			continue;
//		}
//		if (Gtype == 'D')
//			cout << vertixInfo[i] << ':' << " " << outder << " " << inder << " " << der << endl;
//		if (Gtype == 'U')
//			cout << vertixInfo[i] << ':' << " " << inder << endl;
//
//	}
//}
//
//int main()
//{
//	int t;
//	cin >> t;
//
//	while (t--)
//	{
//		char Gtype;
//		int Gvertix;
//		cin >> Gtype >> Gvertix;
//
//		string* VertixInfo = new string[Gvertix];
//		for (int i = 0; i < Gvertix; i++)
//			cin >> VertixInfo[i];
//
//		int Gside;
//		cin >> Gside;
//
//		int matrix[10][10] = { 0 };
//		for (int i = 0; i < Gside; i++)
//		{
//			string v1, v2;
//			cin >> v1 >> v2;
//			int index1 = 0, index2 = 0;
//			for (int j = 0; j < Gvertix; j++)
//			{
//				if (VertixInfo[j] == v1)
//					index1 = j;
//				if (VertixInfo[j] == v2)
//					index2 = j;
//			}
//
//			matrix[index1][index2] = 1;
//			if (Gtype == 'U')
//				matrix[index2][index1] = 1;
//
//		}
//
//		printmatrix(matrix, Gvertix);
//		printdegree(Gtype, VertixInfo, matrix, Gvertix);
//	}
//
//
//
//
//	return 0;
//}



//#include<iostream>
//using namespace std;
//#include<vector>
//
//struct SideInfo
//{
//	int adj;
//	SideInfo* next;
//
//	SideInfo(int x)
//		:adj(x)
//		,next(nullptr)
//	{ }
//};
//
//struct VertixNode
//{
//	char x;
//	SideInfo* Side;
//};
//
//
//void AddSide(char src, char det, vector<VertixNode>& v1)
//{
//	int _src = 0;
//	int _det = 0;
//	for (int i = 0; i < v1.size(); i++)
//	{
//		if (src == v1[i].x)
//			_src = i;
//		if (det == v1[i].x)
//			_det = i;
//	}
//
//	SideInfo* NewNode = new SideInfo(_det);
//	SideInfo* tail = v1[_src].Side;
//
//	if (v1[_src].Side == nullptr) 
//	{
//		v1[_src].Side = NewNode;
//		return;
//	}
//	
//	while (tail->next != nullptr)
//		tail = tail->next;
//
//	tail->next = NewNode;
//}
//
//void prinflinktable(vector<VertixNode>& v1)
//{
//	for (int i = 0; i < v1.size(); i++) {
//		cout << i << " " << v1[i].x;
//
//		SideInfo* p = v1[i].Side;
//		while (p) 
//		{
//			cout << "-" << p->adj;
//			p = p->next;
//		}
//		cout << "-^" << endl;
//	}
//}
//
//int main()
//{
//	int t;
//	cin >> t;
//
//	while (t--)
//	{
//		int n, k;
//		cin >> n >> k;
//		vector<VertixNode> v1(n);
//		for (int i = 0; i < n; i++)
//			cin >> v1[i].x;
//
//		while (k--)
//		{
//			char src, det;
//			cin >> src >> det;
//
//			AddSide(src, det, v1);
//		}
//
//		prinflinktable(v1);
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
//
//void BFS(vector<vector<int>> v1)
//{
//	queue<int> Q;
//	vector<bool> Visit(v1.size(), false);
//
//	Visit[0] = true;
//	Q.push(0);
//	while (!Q.empty())
//	{
//		int i = Q.front();
//
//		for (int j = 0; j < v1.size(); j++)
//		{
//			if (v1[i][j] == 1 && Visit[j] != true)
//			{
//				Q.push(j);
//				Visit[j] = true;
//			}
//		}
//		cout << Q.front() << " ";
//		Q.pop();
//	}
//	cout << endl;
//
//
//
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
//
//		vector<vector<int>> v1(n,vector<int>(n));
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < n; j++)
//			{
//				cin >> v1[i][j];
//			}
//		}
//
//		BFS(v1);
//	}
//
//
//
//}


//#include<iostream>
//using namespace std;
//#include<vector>
//
//void _DFS(int i, vector<bool>& v, vector<vector<int>> v1)
//{
//	cout << i << " ";
//	v[i] = true;
//	for (int j = 0; j < v.size(); j++)
//	{
//		if (v1[i][j] == 1 && v[j] != true)
//		{
//			_DFS(j, v, v1);
//		}
//	}
//}
//
//void DFS(vector<vector<int>> v1)
//{
//	vector<bool> v(v1.size(), false);
//
//	for (int i = 0; i < v1.size(); i++)									// 不是联通图，外层在加一层循环
//	{
//		if(v[i] != true)
//			_DFS(i, v, v1);
//	}
//	cout << endl;
//	
//}
//
//int main()
//{
//	int t;
//	cin >> t;
//
//	while (t--)
//	{
//		int n;;
//		cin >> n;
//
//		vector<vector<int>> v1(n, vector<int>(n));
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < n; j++)
//			{
//				cin >> v1[i][j];
//			}
//		}
//	
//		DFS(v1);
//	}
//
//
//	return 0;
//}



// DFS遍历判断是否为联通图

//#include<iostream>
//using namespace std;
//
//void DFS(int** matrix, bool* tagArr,int n,int i)
//{
//	tagArr[i] = true;
//	for (int j = 0; j < n; j++)
//	{
//		if (matrix[i][j] == 1 && tagArr[j] != true)
//		{
//			tagArr[j] = true;
//			DFS(matrix, tagArr, n, j);
//		}
//	}
//}
//
//void DFSUnicom(int** matrix,int n)
//{
//
//	if (n == 0)									// 1.空图
//	{
//		cout << "Yes" << endl;
//		return;
//	}
//	
//	for (int i = 0; i < n; i++)					// 存在单方向联通的情况，对每个顶点都要进行遍历且独立判断
//	{
//		bool* tagArr = new bool[n];
//		DFS(matrix, tagArr, n, i);
//		for (int j = 0; j < n; j++)
//		{
//			if (tagArr[j] != true)
//			{
//				cout << "No" << endl;
//				return;
//			}
//		}
//	}
//	
//	cout << "Yes" << endl;
//
//}
//
//int main()
//{
//	int k;
//	cin >> k;
//
//	while (k--)
//	{
//		int n;
//		cin >> n;
//
//
//		int** matrix = new int*[n];
//		for (int i = 0; i < n; i++)
//		{
//			matrix[i] = new int[n];
//		}
//
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < n; j++)
//			{
//				cin >> matrix[i][j];
//			}
//		}
//		DFSUnicom(matrix,n);
//	}
//
//
//
//	return 0;
//}




#include<iostream>
using namespace std;


void UF(int** matrix, int n)
{

}


int main()
{
	int k;
	cin >> k;

	while (k--)
	{
		int n;
		cin >> n;


		int** matrix = new int*[n];
		for (int i = 0; i < n; i++)
		{
			matrix[i] = new int[n];
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> matrix[i][j];
			}
		}
		UF(matrix,n);
	}



	return 0;
}