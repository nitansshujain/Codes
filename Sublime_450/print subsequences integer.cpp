#include<bits/stdc++.h>
using namespace std;

void printSub(int idx, vector<int>&v, vector<int>&res) {
	if (idx >= v.size()) {
		for (int i = 0; i < res.size(); i++) {
			cout << res[i] << " ";
		}
		cout << endl;
		return;
	}

	// take
	res.push_back(v[idx]);
	printSub(idx + 1, v, res);
	//when take vector as reference, we need to popout during backtrack
	res.pop_back();

	// not take
	printSub(idx + 1, v, res);

}
int main() {
	vector<int>v = {1, 2, 3};
	vector<int>res;
	printSub(0, v, res);
	return 0;
}