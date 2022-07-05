#include<bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// fast;
	int n;
	cin >> n;

	vector<int>v;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	int res_max = INT_MIN;
	int curr_sum = 0;
	for (auto &x : v) {
		curr_sum += x;
		res_max = max(curr_sum, res_max);
		if (curr_sum < 0) curr_sum = 0;
	}

	cout << res_max << endl;
	return 0;
}