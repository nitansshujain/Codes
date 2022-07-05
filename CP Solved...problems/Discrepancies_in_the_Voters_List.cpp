#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int main()
{
    fast;
    int a, b, c;
    cin >> a >> b >> c;

    map<int, int> mp;
    for (int i = 0; i < a + b + c; i++)
    {
        int temp;
        cin >> temp;
        mp[temp]++;
    }

    vector<int> res;

    for (auto &m : mp)
    {
        if (m.second >= 2)
        {
            res.push_back(m.first);
        }
    }
    cout << res.size() << "\n";
    for (auto &n : res)
    {
        cout << n << "\n";
    }
    // vector<int> v_a;
    // vector<int> v_b;
    // vector<int> v_c;

    // for (int i = 0; i < a; i++)
    // {
    //     int temp;
    //     cin >> temp;
    //     v_a.push_back(temp);
    // }

    // for (int i = 0; i < b; i++)
    // {
    //     int temp;
    //     cin >> temp;
    //     v_b.push_back(temp);
    // }
    // for (int i = 0; i < c; i++)
    // {
    //     int temp;
    //     cin >> temp;
    //     v_c.push_back(temp);
    // }

    // vector<int> v_a_b;
    // int i = 0, j = 0;
    // while (i < v_a.size() and j < v_b.size())
    // {
    //     if (v_a[i] <= v_b[j])
    //     {
    //         v_a_b.push_back(v_a[i]);
    //         i++;
    //     }
    //     else
    //     {
    //         v_a_b.push_back(v_b[j]);
    //         j++;
    //     }
    // }
    // while (i < v_a.size())
    // {
    //     v_a_b.push_back(v_a[i]);
    //     i++;
    // }
    // while (j < v_b.size())
    // {
    //     v_a_b.push_back(v_b[j]);
    //     j++;
    // }
    // vector<int> v;

    // i = 0, j = 0;
    // while (i < v_a_b.size() and j < v_c.size())
    // {
    //     if (v_a_b[i] <= v_c[j])
    //     {
    //         v.push_back(v_a_b[i]);
    //         i++;
    //     }
    //     else
    //     {
    //         v.push_back(v_c[j]);
    //         j++;
    //     }
    // }
    // while (i < v_a_b.size())
    // {
    //     v.push_back(v_a_b[i]);
    //     i++;
    // }
    // while (j < v_c.size())
    // {
    //     v.push_back(v_c[j]);
    //     j++;
    // }
    // // sort(v.begin(), v.end());

    // // for (auto &n : v)
    // // {
    // //     cout << n << " ";
    // // }
    // int count_matches = 0;
    // vector<int> res;

    // i = 0;
    // while (i < v.size() - 1)
    // {
    //     if (v[i] == v[i + 1])
    //     {
    //         count_matches++;
    //         res.push_back(v[i]);

    //         if (i + 2 < v.size())
    //         {
    //             if (v[i + 1] == v[i + 2])
    //             {
    //                 i += 3;
    //             }
    //             else
    //             {
    //                 i += 2;
    //             }
    //         }
    //     }
    //     else
    //     {
    //         i++;
    //     }
    // }

    // cout << count_matches << "\n";
    // for (auto &n : res)
    // {
    //     cout << n << "\n";
    // }
    return 0;
}