#include<iostream>
using namespace std;

const int MAXN = 100;
int adj[MAXN][MAXN];    // 邻接矩阵存储图
int dist[MAXN];         // 存储起点到各顶点的最短距离
int prev_node[MAXN];    // 存储最短路径中每个顶点的前驱节点
bool visited[MAXN];     // 标记顶点是否已访问
char vertex_names[MAXN][10]; // 存储顶点名称（最多9个字符+终止符）
int n;                  // 顶点数
char v0[MAXN];

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			cin >> vertex_names[i];
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> adj[i][j];
			}
		}

		cin >> v0;


	}


	return 0;
}