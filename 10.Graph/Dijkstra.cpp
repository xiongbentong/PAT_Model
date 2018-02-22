//邻接矩阵版
//主要是外层循环O(V)(V就是顶点个数n)与内层循环(寻找最小的d[u]需要O(V)，枚举v需要O(V))
//总复杂度为O(V*(V+V))=O(V^2)
const int MAXV = 1000;
const int INF = 1000000000;
int n, G[MAXV][MAXV];
int d[MAXV];//起点到达各点的最短路径长度
bool vis[MAXV] = { false };
void Dijkstra(int s) {//s为起点
	fill(d, d + MAXV, INF);
	d[s] = 0;
	for (int i = 0; i < n; i++) {
		int u = -1, MIN = INF;
		for (int j = 0; j < n; j++) {
			if (vis[j] == false && d[j] < MIN) {
				u = j;
				MIN = d[j];
			}
		}
		if (u == -1) return;
		vis[u] = true;
		for (int v = 0; v < n; v++) {
			if (vis[v] == false && G[u][v] != INF && d[u] + G[u][v] < d[v]) {
				d[v] = d[u] + G[u][v];//优化d[v]
			}
		}
	}
}
//邻接表版
//主要是外层循环O(V)与内层循环(寻找最小的d[u]需要O(V),枚举v需要O(adj[u].size()))产生的。
//对整个程序来说，枚举v的总次数为O(E)，总复杂度为O(V^2+E);
struct Node {
	int v, dis;//v为边的目标顶点,dis为边权
};
vector<Node> Adj[MAXV];
int n;
int d[MAXV];//起点到达各点的最短路径长度
bool vis[MAXV] = { false };
void Dijkstra(int s) {//s为起点
	fill(d, d + MAXV, INF);
	d[s] = 0;
	for (int i = 0; i < n; i++) {
		int u = -1, MIN = INF;
		for (int j = 0; j < n; j++) {
			if (vis[j] == false && d[j] < MIN) {
				u = j;
				MIN = d[j];
			}
		}
		if (u == -1) return;
		vis[u] = true;
		for (int j= 0; j< Adj[u].size(); j++) {
			int v = Adj[u][j].v;
			if (vis[v] == false&& d[u] + Adj[u][j].dis< d[v]) {
				d[v] = d[u] + Adj[u][j].dis;//优化d[v]
			}
		}
	}
}
//记录最短路径
const int MAXV = 1000;
const int INF = 1000000000;
int n, G[MAXV][MAXV];
int d[MAXV];//起点到达各点的最短路径长度
int pre[MAXV];//pre[v]表示从起点到顶点v的最短路径上v的前一个顶点
bool vis[MAXV] = { false };
void Dijkstra(int s) {//s为起点
	fill(d, d + MAXV, INF);
	d[s] = 0;
	for (int i = 0; i < n; i++) {
		int u = -1, MIN = INF;
		for (int j = 0; j < n; j++) {
			if (vis[j] == false && d[j] < MIN) {
				u = j;
				MIN = d[j];
			}
		}
		if (u == -1) return;
		vis[u] = true;
		for (int v = 0; v < n; v++) {
			if (vis[v] == false && G[u][v] != INF && d[u] + G[u][v] < d[v]) {
				d[v] = d[u] + G[u][v];//优化d[v]
				pre[v] = u;
			}
		}
	}
}
//递归输出路径
void DFS(int s, int v) {//s为起点编号,v为当前访问的顶点编号(从终点开始递归)
	if (v == s) {
		printf("%d\n", s);
		return;
	}
	DFS(s, pre[v]);
	printf("%d\n", v);
}
