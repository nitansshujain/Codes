#include<bits/stdc++.h>
using namespace std;

class Parent {
public:
	Parent() {
		cout << "I am parent" << endl;
	}
};

class Child: public Parent {
public:
	Child() {
		cout << "I am child" << endl;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// fast;
	Parent *p = new Child();
	return 0;
}