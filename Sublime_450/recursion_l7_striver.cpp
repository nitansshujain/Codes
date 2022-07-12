#include<bits/stdc++.h>
using namespace std;

void printAllSub(int idx, vector<int>&v, int sum, int &target, vector<int>&ds) {
	if (idx == v.size()) {
		if (sum == target) {
			for (int &it : ds) cout << it << " ";
			cout << endl;
		}
		return;
	}

	// ds.push_back(v[idx]);
	// printAllSub(idx + 1, v, sum + v[idx], target, ds);
	// ds.pop_back();

	// printAllSub(idx + 1, v, sum, target, ds);

	// OR - does't matter we pass "sum" by reference or not.
	ds.push_back(v[idx]);
	sum += v[idx];
	printAllSub(idx + 1, v, sum, target, ds);

	sum -= v[idx];
	ds.pop_back();

	printAllSub(idx + 1, v, sum, target, ds);
}

// To print only one subsequence, we can make a bool flag which is initially false, and when we get the first sub, we mark flag=true.
// But it is an inefficcient approach. Better is to return bool
bool printOneSub(int idx, vector<int>&v, int sum, int &target, vector<int>&ds) {
	if (idx == v.size()) {
		if (sum == target) {
			for (int &it : ds) cout << it << " ";
			cout << endl;
			return true;
		}
		else return false;
	}

	// ds.push_back(v[idx]);
	// printAllSub(idx + 1, v, sum + v[idx], target, ds);
	// ds.pop_back();

	// printAllSub(idx + 1, v, sum, target, ds);

	// OR - does't matter we pass "sum" by reference or not.
	ds.push_back(v[idx]);
	sum += v[idx];
	if (printOneSub(idx + 1, v, sum, target, ds)) return true;

	sum -= v[idx];
	ds.pop_back();

	if (printOneSub(idx + 1, v, sum, target, ds)) return true;
	return false;
}

// Here we can pass a reference variable count, and increment it whenever sum==target.
// But we can also do it, like way of returning from the fn itself.
int countAllSub(int idx, vector<int>&v, int sum, int &target) {
	if (idx == v.size()) {
		if (sum == target) {
			return 1;
		}
		else return 0;
	}

	// ds.push_back(v[idx]);
	// printAllSub(idx + 1, v, sum + v[idx], target, ds);
	// ds.pop_back();

	// printAllSub(idx + 1, v, sum, target, ds);

	// OR - does't matter we pass "sum" by reference or not.
	// sum += v[idx];
	int l = countAllSub(idx + 1, v, sum + v[idx], target);

	// sum -= v[idx];

	int r = countAllSub(idx + 1, v, sum, target);
	return l + r;
}
int main() {
	vector<int>v = {1, 2, 1};
	vector<int>ds;
	int target = 2;
	printAllSub(0, v, 0, target, ds);
	cout << "\n\n";

	printOneSub(0, v, 0, target, ds);
	cout << "\n\n";

	cout << countAllSub(0, v, 0, target) << "\n"; // Here we don't need ds to store
	return 0;
}