#include<bits/stdc++.h>
#define maxn 25

using namespace std;
bool gr[maxn][maxn];
bool isCover(int V, int k, int E)
{
    int set = (1 << k) - 1;

    int limit = (1 << V);
    bool vis[maxn][maxn];

    while (set < limit)
    {
        memset(vis, 0, sizeof vis);
        int cnt = 0;
        for (int j = 1, v = 1 ; j < limit ; j = j << 1, v++)
        {
            if (set & j)
            {
                for (int k = 1 ; k <= V ; k++)
                {
                    if (gr[v][k] && !vis[v][k])
                    {
                        vis[v][k] = 1;
                        vis[k][v] = 1;
                        cnt++;
                    }
                }
            }
        }

        if (cnt == E)
            return true;
        int c = set & -set;
        int r = set + c;
        set = (((r^set) >> 2) / c) | r;
    }
    return false;
}

// Returns answer to graph stored in gr[][]
int findMinCover(int n, int m)
{
    // Binary search the answer
    int left = 1, right = n;
    while (right > left)
    {
        int mid = (left + right) >> 1;
        if (isCover(n, mid, m) == false)
            left = mid + 1;
        else
            right = mid;
    }


    return left;
}

void insertEdge(int u, int v)
{
    gr[u][v] = 1;
    gr[v][u] = 1;  // Undirected graph
}

// Driver code
int main()
{
    int V = 6, E = 6;
    insertEdge(1, 2);
    insertEdge(2, 3);
    insertEdge(1, 3);
    insertEdge(1, 4);
    insertEdge(1, 5);
    insertEdge(1, 6);
    cout << "Minimum size of a vertex cover = "
         << findMinCover(V, E) << endl;


    memset(gr, 0, sizeof gr);

    V = 6, E = 7;
    insertEdge(1, 2);
    insertEdge(1, 3);
    insertEdge(2, 3);
    insertEdge(2, 4);
    insertEdge(3, 5);
    insertEdge(4, 5);
    insertEdge(4, 6);
    cout << "Minimum size of a vertex cover = "
         << findMinCover(V, E) << endl;

    return 0;
}
