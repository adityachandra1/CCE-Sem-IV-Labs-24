
#include<iostream>
using namespace std;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int pos[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
                swap(&pos[j], &pos[j+1]);
            }
}

int main()
{
    int n, c;
    cout << "Enter number of containers: " << endl;
    cin >> n;
    cout << "Enter total Capacity: " << endl;
    cin >> c;

    int W[n];
    int X[n] = {0};
    int pos[n];

    cout << "Enter the weights:" << endl;
    for(int i = 0; i < n; i++)
    {
        cin >> W[i];
        pos[i] = i;
    }

    bubbleSort(W, pos, n);

    for(int i = 0; i < n && W[i] <= c; i++){
        X[pos[i]] = 1;
        c -= W[i];
    }

    cout << "Selected Items: ";
    for(int i = 0; i < n; i++){
        cout << X[i] << " ";
    }
}
