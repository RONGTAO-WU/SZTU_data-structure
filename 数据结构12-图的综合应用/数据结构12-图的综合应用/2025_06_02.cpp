#include<iostream>
using namespace std;

const int MAXN = 100;
int adj[MAXN][MAXN];    // �ڽӾ���洢ͼ
int dist[MAXN];         // �洢��㵽���������̾���
int prev_node[MAXN];    // �洢���·����ÿ�������ǰ���ڵ�
bool visited[MAXN];     // ��Ƕ����Ƿ��ѷ���
char vertex_names[MAXN][10]; // �洢�������ƣ����9���ַ�+��ֹ����
int n;                  // ������
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