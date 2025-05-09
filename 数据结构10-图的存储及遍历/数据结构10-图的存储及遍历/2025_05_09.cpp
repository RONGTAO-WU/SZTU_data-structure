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



#include<iostream>
using namespace std;
#include<vector>

struct SideInfo
{
	int adj;
	SideInfo* next;

	SideInfo(int x)
		:adj(x)
		,next(nullptr)
	{ }
};

struct VertixNode
{
	char x;
	SideInfo* Side;
};


void AddSide(char src, char det, vector<VertixNode>& v1)
{
	int _src = 0;
	int _det = 0;
	for (int i = 0; i < v1.size(); i++)
	{
		if (src == v1[i].x)
			_src = i;
		if (det == v1[i].x)
			_det = i;
	}

	SideInfo* NewNode = new SideInfo(_det);
	SideInfo* tail = v1[_src].Side;

	if (v1[_src].Side == nullptr) 
	{
		v1[_src].Side = NewNode;
		return;
	}
	
	while (tail->next != nullptr)
		tail = tail->next;

	tail->next = NewNode;
}

void prinflinktable(vector<VertixNode>& v1)
{
	for (int i = 0; i < v1.size(); i++) {
		cout << i << " " << v1[i].x;

		SideInfo* p = v1[i].Side;
		while (p) 
		{
			cout << "-" << p->adj;
			p = p->next;
		}
		cout << "-^" << endl;
	}
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, k;
		cin >> n >> k;
		vector<VertixNode> v1(n);
		for (int i = 0; i < n; i++)
			cin >> v1[i].x;

		while (k--)
		{
			char src, det;
			cin >> src >> det;

			AddSide(src, det, v1);
		}

		prinflinktable(v1);
	}

	

	return 0;
}