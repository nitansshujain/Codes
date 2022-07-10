#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

vector<int>parent;
vector<int>jump;
vector<bool>occupied;
vector<vector<int>>table;
int MAX;

void buildTable(int n) {
	MAX = ceil(log2(n));
	table.resize(MAX + 1, vector<int>(n + 1, -1));
	table[0] = parent;

	for (int i = 1; i <= MAX; i++) {
		for (int node = 0; node <= n; node++) {
			int pnode = table[i - 1][node];
			if (pnode != -1) table[i][node] = table[i - 1][pnode];
		}
	}
}
int find(int cat) {
	int curr = jump[cat];
	if (occupied[curr]) return 0;

	int jumps = 1;
	// while (true) {
	// 	int par = parent[curr];
	// 	if (occupied[par]) break;
	// 	jumps++;
	// 	curr = par;
	// }

	// Optimisation - Binary Lifting
	for (int i = MAX; i >= 0; i--) {
		int par = table[i][curr];
		if (occupied[par]) continue;
		else {
			jumps += (1 << i);
			curr = par;
			// break; nhi hoga
		}
	}
	occupied[curr] = true;
	return jumps;

}
void solve() {
	int n; cin >> n;
	parent.resize(n + 1);
	jump.resize(n + 1);
	occupied.resize(n + 1);

	for (int i = 0; i < n; i++) {
		int p; cin >> p;
		parent[i + 1] = p;
	}

	occupied[0] = true;
	for (int i = 0; i < n; i++) {
		int j; cin >> j;
		jump[i + 1] = j;
	}

	buildTable(n);
	for (int cat = 1; cat <= n; cat++) {
		int jumps = find(cat);
		cout << jumps << "\n";
	}

}

int code_for_log2_n(int n) {
	int MAXBITS = 0;
	while ((1 << MAXBITS) & n) MAXBITS++;

	MAXBITS--;
	return MAXBITS;
}
int main()
{
	fast;
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);

// #endif
	int t = 1;
	// cin >> t;

	for (int i = 1; i <= t; i++) {
		parent.clear();
		jump.clear();
		solve();
	}
	return 0;
}