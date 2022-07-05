#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int main()
{
    fast;
    int r, o, c;
    cin >> r >> o >> c;
    int rem_balls = (20 - o) * 6;
    int max_possible_runs_to_be_scored = 6 * rem_balls;
    int max_runs_teamB = c + max_possible_runs_to_be_scored;
    // cout << max_runs_teamB << " ";
    if (max_runs_teamB > r)
    {
        cout << "YES"
             << "\n";
    }
    else
    {
        cout << "NO"
             << "\n";
    }

    return 0;
}