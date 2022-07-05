#include <iostream>
using namespace std;
bool pal(string s, int i, int j)
{
    if (i >= j)
    {
        return 1;
    }
    if (s[i] == s[j])
    {
        return pal(s, i + 1, j - 1);
    }
}
int main()
{
    cout << pal("abab", 0, 3);
    return 0;
}
