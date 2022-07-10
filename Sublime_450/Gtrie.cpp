#include <bits/stdc++.h>
using namespace std;
class Trie
{
private:
    Trie *next[26] = {};
    bool isWord = false;
    int count = 0;

public:
    Trie()
    {
    }

    void insert(string word)
    {
        Trie *node = this;
        for (char ch : word)
        {
            ch -= 'a';
            if (!node->next[ch])
            {
                node->next[ch] = new Trie();
            }

            node = node->next[ch];
            node->count++;
        }
    }

    int search(string word)
    {
        int count = 0;
        Trie *node = this;
        for (char ch : word)
        {
            ch -= 'a';

            node = node->next[ch];
            count += node->count;
        }
        return count;
    }
};
void solve()
{
    int n, k;
    cin >> n >> k;

    Trie *root = new Trie();
    vector<string> v(n);
    for (auto &x : v)
    {
        cin >> x;
        root->insert(x);
    }
    vector<int> res;
    for (auto x : v)
    {
        res.push_back(root->search(x));
    }
    for (auto x : res)
    {
        cout << x << " ";
    }
    cout << endl;
}
int main()
{
#ifndef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

#endif
    solve();
    return 0;
}