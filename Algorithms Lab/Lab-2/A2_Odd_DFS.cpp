//Aditya Chandra
//200953032  CCE - A
#include <iostream>
using namespace std;
#define MAX_LENGTH 100

void dfs(int i, int adjM[MAX_LENGTH][MAX_LENGTH], int visited[], int n)
{
    int j;
    if(i%2){
        cout << i << " ";
    }
    visited[i]=1;
    for(j = 1; j<n+1; j++)
    {
        if(!visited[j]&&adjM[i][j]==1)
            dfs(j, adjM, visited, n);
    }
}

int main()
{
    int n;
    cout << "Enter the Number of Vertices: ";
    cin >>  n;

    int m;
    cout << "Enter the Number of Edges: ";
    cin >>  m;

    int adjM[MAX_LENGTH][MAX_LENGTH] = {0};

    cout << "Enter all the edges between the nodes, in the format <source> <destination>, for an undirected graph" << endl;
    int p,q;
    for(int i = 0; i < m; i++)
    {
        cin >> p >> q;
        adjM[p][q] = 1;
        adjM[q][p] = 1;
    }

    cout << "Adjaceny Matrix: " << endl;
    for(int i = 1; i < n+1; i++)
    {
        for(int j = 1; j < n+1; j++)
        {
            cout << adjM[i][j] << " ";
        }
        cout << endl;
    }

    int visited[n+1] = {0};

    cout << "Enter Starting vertex: ";
    int k;
    cin >> k;
    dfs(k, adjM, visited, n);
}
