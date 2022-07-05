#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &v, int start, int end)
{
    int pivot = v[end];

    int temp = start;

    for (int i = start; i < end; i++)
    {
        if (v[i] <= pivot)
        {
            swap(v[temp], v[i]);
            temp++;
        }
    }
    swap(v[end], v[temp]);
    return temp;
}
void quicksort(vector<int> &v, int start, int end)
{
    if (start < end)
    {
        int par_index = partition(v, start, end);

        quicksort(v, start, par_index - 1);
        quicksort(v, par_index + 1, end);
    }
}
void print(vector<int> &v)
{
    for (auto &x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> v{1, 3, 2, 5, 10, 5, 16, 8};
    quicksort(v, 0, v.size() - 1);
    print(v);
    return 0;
}