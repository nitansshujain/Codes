// https://www.codingninjas.com/codestudio/problems/create-a-graph-and-print-it_1214551?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define ll long long int
#define ld long double
#define endd '\n'
#define pi 3.1415926535897932384626433832795028841971
#define MOD 1000000007

template<typename T>
class Graph {
public:
	unordered_map<T, list<T>>mp;

	void addEdges(T u, T v, bool dir) {
		// dir == 0 -> undirected
		mp[u].push_back(v);
		if (dir == 0) {
			mp[v].push_back(u);
		}
	}
	void printGraph() {
		for (auto m : mp) {
			cout << m.first << " -> ";
			for (int x : m.second) {
				cout << x << " ";
			}
			cout << endd;
		}
	}
};
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fast;

	int n;
	// cout << "Enter the number of nodes: ";
	cin >> n;


	int e;
	// cout << "Enter the number of edges: ";
	cin >> e;

	Graph<int> g;
	for (int i = 0; i < e; i++) {
		int u, v;
		cin >> u >> v;
		g.addEdges(u, v, 0);
	}

	g.printGraph();
}

/*
4
3
1 2
0 3
2 3
*/