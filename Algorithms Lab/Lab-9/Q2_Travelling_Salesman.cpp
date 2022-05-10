#include <bits/stdc++.h>
using namespace std;
#define V 100

void tsp(int graph[][V], bool v[], int currPos, int n, int count, int cost, int& ans, int verts)
{
    if (count == n && graph[currPos][0])
    {
        ans = min(ans, cost + graph[currPos][0]);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!v[i] && graph[currPos][i])
        {
            v[i] = true;
            tsp(graph, v, i, n, count + 1, cost + graph[currPos][i], ans, verts);
            v[i] = false;
        }
    }
};
int main()
{
    int verts;
    cout << "NUMBER OF CITIES" << endl;
    cin >> verts ;
    int graph[V][V];
    cout<<"enter adj matrix of cities"<<endl;
    for(int i=0; i<verts; i++)
    {
        for(int j=0; j<verts; j++)
        {
            cin>>graph[i][j];
        }
    }
    bool v[V];
    for (int i = 0; i < verts; i++)
        v[i] = false;
    v[0] = true;
    int ans = INT_MAX;
    tsp(graph, v, 0, verts, 1, 0, ans, verts);
    cout << ans;
    return 0;
}
