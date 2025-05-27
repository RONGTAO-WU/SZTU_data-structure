//#include<iostream>
//using namespace std;
//#include<vector>
//
//
//void printmatrix(vector<vector<int>> vv1, vector<string> v1, int n)
//{
//
//	for (int i = 0; i < n; i++)
//	{
//		if (i != n - 1)
//			cout << v1[i] << " ";
//		else
//			cout << v1[i] << endl;
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (j != n - 1)
//				cout << vv1[i][j] << " ";
//			else
//				cout << vv1[i][j] << endl;
//		}
//	}
//}
//
//void _DFS(int i, vector<bool>& v, vector<vector<int>> v1)
//{
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
//	int count = 0;
//
//	for (int i = 0; i < v1.size(); i++)	
//	{
//		if(v[i] != true)
//		{
//			_DFS(i, v, v1);
//			count++;
//		}
//		
//	}
//	cout << count << endl;
//	
//}
//
//int main()
//{
//
//	int t;
//	cin >> t;
//
//	while (t--)
//	{
//		int n;
//		cin >> n;
//
//		vector<string> v1(n);
//		for (int i = 0; i < n; i++)
//		{
//			cin >> v1[i];
//		}
//		
//
//		vector<vector<int>> vv1(n, vector<int>(n));
//		int k;
//		cin >> k;
//
//		for (int i = 0; i < k; i++)
//		{
//			string s1, s2;
//			cin >> s1 >> s2;
//			int x = 0, y = 0;
//			for (int j = 0; j < n; j++)
//			{
//				if(v1[j] == s1)
//					x = j;
//				if (v1[j] == s2)
//					y = j;
//			}
//			vv1[x][y] = 1;
//			vv1[y][x] = 1;
//		}
//
//
//		printmatrix(vv1,v1, n);
//		DFS(vv1);
//		cout << endl;
//	}
//
//
//
//	return 0;
//}



//#include<iostream>
//using namespace std;
//
//void TraverseDiagram(int **matrix,int *deg,bool *visit,int n)
//{
//	int flag = -1;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (visit[j] == false && deg[j] == 0)						// δ���������Ϊ0
//			{
//				flag = j;
//				break;
//			}
//		}
//
//		cout << flag << " ";
//		visit[flag] = true;
//
//		for (int j = 0; j < n; j++)
//		{
//			if (matrix[flag][j] == 1)
//				deg[j]--;												// ��һ��ȫ������
//		}
//		
//	}
//	cout << endl;
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
//		int n;
//		cin >> n;
//
//		int** matrix = new int *[n];
//		for (int i = 0; i < n; i++)
//		{
//			matrix[i] = new int[n];
//		}
//
//		int* deg = new int[n];
//		for (int i = 0; i < n; i++)
//			deg[i] = 0;
//
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < n; j++)
//			{
//				cin >> matrix[i][j];
//				if (matrix[i][j] == 1)							// ����ÿ���ڵ����ȴ洢��һ��������
//					deg[j]++;
//			}
//		}
//
//		bool* visit = new bool[n];
//		for (int i = 0; i < n; i++)
//			visit[i] = false;
//
//
//		TraverseDiagram(matrix,deg,visit,n);
//	}
//
//
//	return 0;
//}





//#include<iostream>
//using namespace std;
//#include<vector>
//#include<queue>
//
//void TraverseDiagram(vector<vector<int>> vv1, int n)
//{
//	vector<vector<int>> vv2(n);										// �ڽӱ�
//	vector<int> v3(n,0);											// �ڽӱ����Ӹ�����ǰ�ÿγ�����
//
//	for (int i = 0; i < vv1.size(); i++)
//	{
//		int x = vv1[i][0];
//		int y = vv1[i][1];											// y��x��ǰ�ÿγ�
//		vv2[y].push_back(x);										// x���ӵ�y����
//		v3[x]++;													// x�����++
//	}
//
//	int count = 0;
//	queue<int> q1;
//
//	for (int i = 0; i < n; i++)
//	{
//		if (v3[i] == 0)
//			q1.push(i);												// �������Ӹ������飬�����ĸ��γ�û��ǰ�ÿγ̣���Ϊ0
//	}
//
//	while (!q1.empty())
//	{
//		int x = q1.front();
//		q1.pop();
//		count++;					
//
//		for (int i = 0; i < vv2[x].size(); i++)									// �����ڽӱ�����޳�
//		{
//			int y = vv2[x][i];
//			v3[y]--;
//			if (v3[y] == 0)
//				q1.push(y);											// ����γ̵�ǰ�ÿγ��Ѵ���
//		}
//
//	}
//
//	if (count == n)
//		cout << "true" << endl;
//	else
//		cout << "false" << endl;
//}
//
//int main()
//{
//	int t;
//	cin >> t;
//
//	while (t--)
//	{
//		int n,len;
//		cin >> n >>len;
//
//		vector<vector<int>> vv1(len, vector<int>(2));
//		for (int i = 0; i < len; i++)
//		{
//			cin >> vv1[i][0] >> vv1[i][1];
//		}
//
//
//		TraverseDiagram(vv1, n);
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
//class UnionFind
//{
//public:
//	UnionFind(int n)
//	{
//		parent.resize(n+1);
//		rank.resize(n+1, 1);
//		for (int i = 1; i < n+1; i++)
//		{
//			parent[i] = i;
//		}
//	}
//
//	int find(int x)
//	{
//		if (parent[x] != x)
//			parent[x] = find(parent[x]);
//
//		return parent[x];
//	}
//
//	bool Unoin(int x,int y)
//	{
//		int rootx = find(x);
//		int rooty = find(y);
//		if (rootx == rooty)
//			return false;
//
//		if (rank[rootx] < rank[rooty])
//			parent[rootx] = rooty;				// �ȴ��Ϊ�µĸ��ڵ�
//		else
//		{
//			parent[rooty] = rootx;
//			if (rank[rootx] == rank[rooty])
//				rank[rootx]++;
//		}
//
//		return true;
//	}
//
//private:
//
//	vector<int> parent;
//	vector<int> rank;
//};
//
//int Union_Find(vector<vector<int>>& edges)
//{
//	int n = edges.size();
//	UnionFind u(n);
//	for (int i = 0; i < n; i++)
//	{
//		if (!u.Unoin(edges[i][0], edges[i][1]))
//			return i;
//	}
//	return -1;
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
//		vector<vector<int>> edges(n);
//		for (int i = 0; i < n; i++)
//		{
//			int x1, x2;
//			cin >> x1 >> x2;
//
//			edges[i] = { x1,x2 };
//		}
//
//		int i = Union_Find(edges);
//		cout << edges[i][0] << " " << edges[i][1] << endl;
//	}
//
//
//	return 0;
//}



#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
using namespace std;

struct Edge {
    int u, v, weight;
    Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
    bool operator<(const Edge& other) const { return weight < other.weight; }
};

class UnionFind {
private:
    vector<int> parent;
public:
    UnionFind(int size) : parent(size) { for (int i = 0; i < size; ++i) parent[i] = i; }
    int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }
    void unite(int x, int y) { parent[find(x)] = find(y); }
    bool connected(int x, int y) { return find(x) == find(y); }
};

int main() {
    int n, m;
    cin >> n;

    vector<string> vertices(n);
    vector<int> vertex_indices(n);  // �洢�������ƶ�Ӧ������

    // ��ȡ�������Ʋ�����ӳ��
    for (int i = 0; i < n; ++i) {
        cin >> vertices[i];
        vertex_indices[i] = i;  // Ĭ�������������
    }

    cin >> m;

    // �����ڽӾ���ͱ��б�
    vector<vector<int>> graph(n, vector<int>(n, INT_MAX));
    vector<Edge> edges;

    for (int i = 0; i < m; ++i) {
        string u_name, v_name;
        int weight;
        cin >> u_name >> v_name >> weight;

        // ���Ҷ�������
        int u = -1, v = -1;
        for (int j = 0; j < n; ++j) {
            if (vertices[j] == u_name) u = j;
            if (vertices[j] == v_name) v = j;
        }

        graph[u][v] = weight;
        graph[v][u] = weight;
        edges.emplace_back(u, v, weight);
    }

    string start_name;
    cin >> start_name;

    // �����������
    int start = -1;
    for (int i = 0; i < n; ++i) {
        if (vertices[i] == start_name) {
            start = i;
            break;
        }
    }

    // Prim�㷨
    vector<bool> visited(n, false);
    vector<int> parent(n, -1), key(n, INT_MAX);
    key[start] = 0;
    vector<Edge> prim_edges;
    int prim_weight = 0;

    for (int i = 0; i < n; ++i) {
        int min_key = INT_MAX, u = -1;
        for (int v = 0; v < n; ++v) {
            if (!visited[v] && key[v] < min_key) {
                min_key = key[v];
                u = v;
            }
        }

        visited[u] = true;
        if (parent[u] != -1) {
            prim_weight += key[u];
            prim_edges.emplace_back(parent[u], u, key[u]);
        }

        for (int v = 0; v < n; ++v) {
            if (!visited[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Kruskal�㷨
    sort(edges.begin(), edges.end());
    UnionFind uf(n);
    vector<Edge> kruskal_edges;
    int kruskal_weight = 0;

    for (const auto& edge : edges) {
        if (!uf.connected(edge.u, edge.v)) {
            uf.unite(edge.u, edge.v);
            kruskal_edges.push_back(edge);
            kruskal_weight += edge.weight;
        }
    }

    // ������
    cout << prim_weight << endl;

    cout << "prim:" << endl;
    for (const auto& e : prim_edges) {
        int u = e.u, v = e.v;
 //       if (u > v) swap(u, v);
        cout << vertices[u] << " " << vertices[v] << " " << e.weight << endl;
    }

    cout << "kruskal:" << endl;
    for (auto& e : kruskal_edges) {
        int u = e.u, v = e.v;
        if (u > v) swap(u, v);
        cout << vertices[u] << " " << vertices[v] << " " << e.weight << endl;
    }

    return 0;
}