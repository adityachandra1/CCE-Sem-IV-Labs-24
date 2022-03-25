//Aditya Chandra
//200953032  CCE - A
#include <iostream>
using namespace std;

int STEP_COUNT = 0;

void rank(int a[],int n, int r[])
{

    for(int i = 0; i < n; i++)
    {
        STEP_COUNT++;

        STEP_COUNT++;
        r[i] = 0;
    }
    STEP_COUNT++;

    for(int i = 1; i < n; i++)
    {
        STEP_COUNT++;
        for(int j = 0; j < i; j++)
        {
            STEP_COUNT++;

            STEP_COUNT++;
            if(a[j] <= a[i])
            {
                STEP_COUNT++;
                r[i]++;
            }else{
                STEP_COUNT++;
                r[j]++;
            }
        }
        STEP_COUNT++;
    }
    STEP_COUNT++;
}

void rearrange(int a[], int n, int r[])
{
    STEP_COUNT++;
    int *u = new int [n];

    for(int i = 0; i < n; i++)
    {
        STEP_COUNT++;

        STEP_COUNT++;
        u[r[i]] = a[i];
    }
    STEP_COUNT++;

    for(int i = 0; i < n; i++)
    {
        STEP_COUNT++;

        STEP_COUNT++;
        a[i] = u[i];
    }
    STEP_COUNT++;

    STEP_COUNT++;
    delete [] u;
}

int main()
{
    int n;
    cout << "Enter Size of Array: ";
    cin >>  n;


    int a[n];
    cout << "Enter elements: \n";
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int r[n];
    cout << "Sorting the Array using Rank Sort" << endl;
    rank(a,n,r);
    rearrange(a,n,r);
    cout << "Sorted Array: " << endl;

    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout <<  endl;
    cout << "Step Count: " << STEP_COUNT << endl;

}

