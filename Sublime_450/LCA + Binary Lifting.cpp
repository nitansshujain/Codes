#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

/*
It will get accepted when n & q <=10^3, otherwise TLE
Solution : Binary Lifting

https://leetcode.com/problems/kth-ancestor-of-a-tree-node/
https://www.youtube.com/watch?v=PE-kQVZxvWA&list=PL-Jc9J83PIiGC6uQ2CjMhSaWAcmjbAQfp&index=1&ab_channel=Pepcoding

*/
unordered_map<int, list<int>>child;
vector<int>level;
vector<int>parent;
vector<vector<int>>table;
int MAX;
void dfs(int node, int lvl) {
	level[node] = lvl;
	for (int c : child[node]) {
		parent[c] = node;
		dfs(c, lvl + 1);
	}
}

void buildTable(int n) {
	MAX = ceil(log2(n));
	table.resize(MAX + 1, vector<int>(n + 1, -1));
	table[0] = parent;

	for (int i = 1; i <= MAX; i++) {
		for (int node = 1; node <= n; node++) {
			int pnode = table[i - 1][node];
			if (pnode != -1) table[i][node] = table[i - 1][pnode];
		}
	}
}
int lca(int u, int v) {
	if (level[u] > level[v]) swap(u, v);

	// level[v] > level[u]
	// Optimisation - 1
	int jumps = level[v] - level[u];
	for (int i = MAX; i >= 0; i--) {
		if (jumps & (1 << i)) v = table[i][v];
	}


	// while (level[u] != level[v]) {
	// 	v = parent[v];
	// }

	if (u == v) return u;

	// Optimisation - 2 - We don't know how much to jump, so we start with max jump, if we have not reached the same ancestor, then we jump again.
	for (int i = MAX; i >= 0; i--) {
		int pu = table[i][u];
		int pv = table[i][v];

		if (pu != pv) {
			u = pu;
			v = pv;
		}
	}
	// After the jumps, we have reached where parent of u/v is lca
	u = parent[u];

	// while (u != v) {
	// 	u = parent[u];
	// 	v = parent[v];
	// }
	return u;
}
void solve() {
	int n; cin >> n;

	for (int i = 1; i <= n; i++) {
		int count; cin >> count;
		for (int j = 0; j < count; j++) {
			int u; cin >> u;
			child[i].push_back(u);
		}
	}

	level.resize(n + 1);
	parent.resize(n + 1);

	dfs(1, 1);

	buildTable(n);
	// querying
	int q; cin >> q;
	for (int i = 1; i <= q; i++) {
		int u, v;
		cin >> u >> v;
		int res = lca(u, v);
		cout << res << "\n";
	}

}
int main()
{
	fast;
#ifndef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

#endif
	int t;
	cin >> t;

	for (int i = 1; i <= t; i++) {
		level.clear();
		parent.clear();
		child.clear();
		table.clear();
		cout << "Case " << i << ":" << "\n";
		solve();
	}
	return 0;
}