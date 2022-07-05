// #include <bits/stdc++.h>
// using namespace std;

// #define nitro ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
// #define vi vector<int>
// #define lli long long int
// #define vlli vector<long long int>
// #define loop0(i, n) for (int i = 0; i < n; i++)
// #define loop1(i, n) for (int i = 1; i <= n; i++)
// #define endl '\n'
// #define vpi vector<pair<int, int>>
// #define vplli vector<pair<long long int, long long int>>
// #define mod 1000000007

// int main()
// {
//     // string s;
//     // cin >> s;

//     // char c;
//     // cin >> c;
//     // cout << count(s.begin(), s.end(), c);

//     string s;
//     getline(cin, s);

//     int n = s.size();
//     int cnt = 0;
//     for (int i = 0; i < s.size(); i++)
//     {
//         if (!(s[i] == ' ') || (s[i] >= 48 and s[i] <= 57) || (s[i] > 65 and s[i] <= 90) || (s[i] > 97 and s[i] <= 122))
//         {
//             cnt++;
//         }
//     }
//     cout << n - cnt;
// }
// // bool isPrime(lli n)
// // {
// //     if (n == 1)
// //         return false;

// //     for (int i = 2; i * i <= n; i++)
// //     {
// //         if (n % i == 0)
// //             return false;
// //     }
// //     return true;
// // }
// // int main()
// // {
// //     int t = 1;
// //     cin >> t;
// //     while (t--)
// //     {
// //         lli n;
// //         cin >> n;

// //         bool res = false;
// //         if ((n + 1) % 2 == 0)
// //             res = true;
// //         else
// //         {
// //             if (isPrime(n + 1))
// //                 res = false;
// //             else
// //                 res = true;
// //         }
// //         if (res)
// //             cout << "YES" << endl;
// //         else
// //             cout << "NO" << endl;
// //     }
// // }

// #include <iostream>
// using namespace std;

// int main()
// {
//     char str[81];
//     int nletter, ndigit, nspace, nother; /* char counts */
//     int i;

//     // printf("Enter a line of text:\n");
//     gets(str);
//     /* count characters in string str */
//     nletter = ndigit = nspace = nother = 0; /* init counts */
//     i = 0;
//     while (str[i] != '\0')
//     {
//         char ch = str[i];
//         if (ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z')
//             nletter++;
//         else if (ch >= '0' && ch <= '9')
//             ndigit++;
//         else if (ch == ' ' || ch == '\n' || ch == '\t')
//             nspace++;
//         else
//             nother++;
//         i++;
//     }
//     /* print counts */
//     // printf("Letters: %d \tWhite spaces : %d", nletter, nspace);
//     // printf(" Digits : %d \tOther chars : %d\n", ndigit, nother);

//     cout << nother << endl;
// }

// int n=A.size();
// int ones=0,zero=0;
// for(i=0;i<n;i++){
//     if(A[i]==1){
//         ones++;
//     }
//     else{
//         zero++;
//     }
// }
// return (abs(ones-zero))/2;

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
}