#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define ll long long int
#define ld long double
#define endd '\n'
#define pi 3.1415926535897932384626433832795028841971
#define MOD 1000000007

ll add(ll a, ll b)
{
	return ((a % MOD) + (b % MOD)) % MOD;
}
ll subtract(ll a, ll b) { return ((a % MOD) - (b % MOD)) % MOD; }
ll mult(ll a, ll b) { return ((a % MOD) * (b % MOD)) % MOD; }

int expo(int a, int b, int mod)
{
	int res = 1;
	while (b > 0)
	{
		if (b & 1)
			res = (res * a) % mod;
		a = (a * a) % mod;
		b = b >> 1;
	}
	return res;
}
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
int lcm(int a, int b)
{
	return (a / gcd(a, b)) * b;
}
void sieve()
{
	vector<bool> prime(MOD + 1);
	prime[0] = prime[1] = 0;

	for (int i = 2; i * i <= MOD; i++)
	{
		if (prime[i])
		{
			for (int j = i * i; j <= MOD; j += i)
				prime[j] = 0;
		}
	}
}

class DSU
{
private:
	vector<int> root;
	vector<int> rank;

public:
	DSU(int n) : root(n), rank(n)
	{
		for (int i = 0; i < n; i++)
		{
			root[i] = i;
			rank[i] = 1;
		}
	}

	int find(int x)
	{
		if (x == root[x])
			return x;
		return root[x] = find(root[x]);
	}

	void unionFind(int x, int y)
	{
		int rootX = find(x);
		int rootY = find(y);

		if (rootX != rootY)
		{
			if (rank[rootX] < rank[rootY])
			{
				root[rootX] = rootY;
			}
			else if (rank[rootY] < rank[rootX])
			{
				root[rootY] = rootX;
			}
			else
			{
				root[rootY] = rootX;
				rank[rootX]++;
			}
		}
	}

	bool isConnected(int x, int y)
	{
		return find(x) == find(y);
	}
};

// Code for logN base 2
int code_for_log2_n(int n) {
	int MAXBITS = 0;
	while ((1 << MAXBITS) & n) MAXBITS++;

	MAXBITS--;
	return MAXBITS;
}

// Program to calculate C(n, k)
#include <bits/stdc++.h>
using namespace std;

// Returns value of Binomial Coefficient C(n, k)
int binomialCoeff(int n, int r)
{
	int res = 1;

	// Since C(n, r) = C(n, n-r)
	if (n - r < r)
		r = n - r;

	// Calculate value of
	// [n * (n-1) *---* (n-r+1)] / [r * (r-1) *----* 1]
	for (int i = 0; i < r; ++i) {
		res *= (n - i);
		res /= (i + 1);
	}

	return res;

	// --------APPROACH 2----------

	// int solve(int n, int r, vector<vector<int>>&dp, int MOD) {
	// 	if (r > n) return dp[n][r] = 0;
	// 	if (r == 0 || r == n) return dp[n][r] = 1;
	// 	if (dp[n][r] != -1) return dp[n][r];

	// 	return dp[n][r] = (solve(n - 1, r - 1, dp, MOD) % MOD + solve(n - 1, r, dp, MOD) % MOD) % MOD;
	// }

	// int nCr(int n, int r) {
	// 	vector<vector<int>>dp(n + 1, vector<int>(r + 1, -1));
	// 	return solve(n, r, dp, 1e9 + 7);
	// }
}


int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int rotate ( int n )
{

	int r = 0 ;
	map < int , int > mp ;
	mp [ 0 ] = 0 ;
	mp [ 1 ] = 1 ;
	mp [ 6 ] = 9 ;
	mp [ 9 ] = 6 ;
	mp [ 8 ] = 8 ;
	while ( n )
	{
		int rem = n % 10;
		r = r * 10 + mp [ rem ] ;
		n = n  / 10 ;
	}


	return r ;

}
int ConfusingNoII ( int N )
{
	int count = 0 ;
	vector< int > v ( { 0 , 1 , 6 , 8 , 9 } ) ;
	queue < int > q ;
	q.push ( 0 ) ;
	while ( !q.empty() )
	{
		int n = q.front() ;
		if ( rotate ( n ) != n )
			count ++ ;

		q.pop() ;

		for ( auto &i : v )
		{
			if (i == 0 && n == 0) continue;
			if ( n * 10 + i <= N )
				q.push ( n * 10 + i ) ;
		}
	}
	return count ;
}
int ConfusingNoI(int N) {
	string s = to_string(N);
	int n = s.size();
	unordered_map<char, char>mp = {
		{'0', '0'},
		{'1', '1'},
		{'6', '9'},
		{'8', '8'},
		{'9', '6'}
	};
	string check = "";
	for (int i = n - 1; i >= 0; i--) {
		if (mp.find(s[i]) == mp.end()) return false;
		check += mp[s[i]];
	}
	return check != s;
}

struct Node {
	Node* links[26];
	bool flag = false;

	int cnt = 0;
	bool containsKey(char ch) {
		return links[ch - 'a'] != NULL;
	}
	void put(char ch) {
		links[ch - 'a'] = new Node();
	}
	Node* get(char ch) {
		return links[ch - 'a'];
	}
	void setEnd() {
		flag = true;
	}
	bool isEnd() {
		return flag;
	}
};
class Trie {
public:
	Node* root;
	Trie() {
		root = new Node();
	}
	void insert(string word) {
		Node* node = root;
		for (int i = 0; i < word.size(); i++) {
			if (!node->containsKey(word[i])) {
				node->put(word[i]);
			}
			node = node->get(word[i]);
			node->cnt++;
		}
		node->setEnd();
	}

	bool search(string word) {
		Node *node = root;
		for (int i = 0; i < word.size(); i++) {
			if (!node->containsKey(word[i])) {
				return false;
			}
			node = node->get(word[i]);
		}
		return node->isEnd();
	}

	string prefix(string word) {
		Node* node = root;
		string pre = "";
		for (auto w : word) {
			if (node->cnt == 1) break;
			pre += w;
			node = node->get(w);
		}
		return pre;
	}
};
void solve()
{
	// int n;
	// cin >> n;
	// cout << ConfusingNoI(n) << endl;
	// cout << ConfusingNoII(n) << endl;
	int n, k;
	vector<string>v;
	cin >> n >> k;
	Trie trie;
	for (int i = 0; i < n; i++) {
		int s;
		cin >> s;
		v.push_back(s);
		trie.insert(s);
	}


}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fast;
	int t = 1;
	// cin >> t;
	while (t--)
	{
		solve();
	}
}