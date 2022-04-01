#include <iostream>
using namespace std;

int main()
{
    int i,j,k,n,a[10][10] = {0},indeg[10]= {0},flag[10] = {0},count=0;
    int m;

    cout << "Enter the no of vertices:\n";
    cin >> n;

    cout << "Enter the no of edges:\n";
    cin >> m;

    int p,q;
    cout<<"Enter Source and Desitnation vertices in the form  p q" << endl;
    for(int i=0; i<m; i++)
    {
        cin>> p;
        cin>> q;
        a[p][q]=1;
    }

    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++){
            indeg[i]=indeg[i]+a[j][i];
        }

    for(int i = 1; i <= n; i++){
        cout << indeg[i] << " ";
    }
    cout << "\nThe topological order is:";

    while(count<n)
    {
        for(k=1; k<=n; k++)
        {
            if((indeg[k]==0) && (flag[k]==0))
            {
                cout << k << " ";
                flag [k]=1;
            }

            for(i=1; i<=n; i++)
            {
                if(a[i][k]==1)
                    indeg[k]--;
            }
        }
        count++;
    }
}
