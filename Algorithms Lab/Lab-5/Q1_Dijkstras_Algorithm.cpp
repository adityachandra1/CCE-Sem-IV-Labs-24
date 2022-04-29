#include <bits/stdc++.h>
using namespace std;

int findMinVertex(bool *visited, int *distance, int v) {
    int minIndex, minVal = INT_MAX;

    for (int i = 0; i < v; i++) {
        if (!visited[i] && distance[i] < minVal) {
            minVal = distance[i];
            minIndex = i;
        }
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
    }

    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
        visited[i] = false;

    int sv;
    cout << "Enter start vertex: ";
    cin >> sv;

    int *distance = new int[v];
    distance[sv] = 0;
    for (int i = 0; i < v; i++)
        if (i != sv)
            distance[i] = INT_MAX;

    for (int j = 0; j < v; j++) {
        int curr = findMinVertex(visited, distance, v);
        visited[curr] = true;
        for (int i = 0; i < v; i++)
            if (!visited[i] && adj[curr][i] != 0)
                if (distance[i] > distance[curr] + adj[curr][i])
                    distance[i] = distance[curr] + adj[curr][i];
    }

    for (int i = 0; i < v; i++) {
        cout << i << " -> ";
        if (distance[i] == INT_MAX)
            cout << "unreachable"
                 << "\n";
        else
            cout << distance[i] << "\n";
    }

    return 0;
}