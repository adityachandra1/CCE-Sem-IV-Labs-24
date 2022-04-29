#include <bits/stdc++.h>
using namespace std;

int findMinVertex(int *distance, bool *visited, int v) {
    int minVal = INT_MAX, minIndex;

    for (int i = 0; i < v; i++)
        if (!visited[i] && distance[i] < minVal) {
            minIndex = i;
            minVal = distance[i];
        }

    return minIndex;
}

int main() {
    int v, e;
    cin >> v >> e;
    cout << endl;

    int **adj = new int *[v];

    for (int i = 0; i < v; i++)
        adj[i] = new int[v];

    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++)
            adj[i][j] = 0;

    for (int i = 0; i < e; i++) {
        int l, r, w;
        cin >> l >> r >> w;
        adj[l][r] = w;
        adj[r][l] = w;
    }

    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
        visited[i] = false;

    int *distance = new int[v];
    int *parent = new int[v];

    for (int i = 1; i < v; i++)
        distance[i] = INT_MAX;

    distance[0] = 0;

    for (int i = 0; i < v - 1; i++) {
        int curr = findMinVertex(distance, visited, v);
        visited[curr] = true;

        for (int j = 0; j < v; j++)
            if (!visited[j] && adj[curr][j] != 0)
                if (distance[j] > adj[curr][j]) {
                    distance[j] = adj[curr][j];
                    parent[j] = curr;
                }
    }

    for (int i = 1; i < v; i++)
        cout << min(parent[i], i) << " -> " << max(parent[i], i) << " : " << distance[i] << "\n";

    return 0;
}
