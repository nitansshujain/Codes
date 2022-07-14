bool isPossible(int node, bool graph[101][101], vector<int> &color, int n, int clr)
{
    for (int k = 0; k < n; k++)
    {
        if (k == node)
            continue;
        if (graph[k][node] == 0)
            continue;
        if (color[k] == clr)
            return false;

        // OR
        //  if(k != node && graph[node][k] == 1 && color[k] == clr) return false;
    }
    return true;
}
bool solve(int node, bool graph[101][101], vector<int> &color, int m, int n)
{
    if (node == n)
        return true;

    for (int i = 1; i <= m; i++)
    {
        if (isPossible(node, graph, color, n, i))
        {
            color[node] = i;
            if (solve(node + 1, graph, color, m, n))
                return true;
            color[node] = 0;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int n)
{
    vector<int> color(n);
    if (solve(0, graph, color, m, n))
        return true;
    return false;
}