#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

unordered_map< int, list<pair<int, int>> > buildGraph(int n, int e) {
	unordered_map< int, list<pair<int, int>> >G;
	for (int i = 0; i < e; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	return G;
}

void solve(unordered_map< int, list<pair<int, int>> >&G, int src, set<int>&vis, string &res, string orgsrc) {
	vis.insert(src);
	if (vis.size() == G.size()) {
		cout << res;

		bool isHamCycle = false;
		for (auto &neigh : G) {
			if (to_string(neigh.first) == orgsrc) {
				isHamCycle = true;
				break;
			}
		}
		if (isHamCycle) cout << ".";
		else cout << "*";

		cout << "\n";
	}
	for (auto &neigh : G) {
		int v = neigh.first;
		if (vis.find(v) == vis.end()) {
			string temp = res + to_string(v);
			solve(G, v, vis, temp, orgsrc);
		}
	}
	vis.erase(src);
}
int main()
{
	fast;
	int n; cin >> n;
	int e; cin >> e;

	unordered_map< int, list<pair<int, int>> >G = buildGraph(n, e);
	int src; cin >> src;

	set<int>vis;
	string res = to_string(src);
	solve(G, src, vis, res, res);
}