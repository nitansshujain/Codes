#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &v, int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;

    vector<int> A(n1), B(n2);

    for (int i = 0; i < n1; i++)
    {
        A[i] = v[low + i];
    }

    for (int i = 0; i < n2; i++)
    {
        B[i] = v[mid + 1 + i];
    }

    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2)
    {
        if (A[i] <= B[j])
        {
            v[k++] = A[i++];
        }
        else
        {
            v[k++] = B[j++];
        }
    }

    while (i < n1)
    {
        v[k++] = A[i++];
    }
    while (j < n2)
    {
        v[k++] = B[j++];
    }
}
void mergesort(vector<int> &v, int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        mergesort(v, low, mid);
        mergesort(v, mid + 1, high);
        merge(v, low, mid, high);
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
    mergesort(v, 0, v.size() - 1);
    print(v);
    return 0;
}