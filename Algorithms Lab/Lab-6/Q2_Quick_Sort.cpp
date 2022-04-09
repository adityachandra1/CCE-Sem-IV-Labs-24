#include <iostream>

using namespace std;
void quicksort(int a[], int low, int high)
{
    int i,j,pivot,temp;
    if(high>low)
    {
        i=low;
        j=high+1;
        pivot=a[high];
        cout<<pivot;
        do
        {
            do
            {
                i++;
            }
            while(pivot>a[i]);
            do
            {
                j--;
            }
            while (pivot<a[j]);
            if(j>i)
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
        while (j>i);
        temp=a[low];
        a[low]=a[j];
        a[j]=temp;
        quicksort(a,low,j-1);
        quicksort(a,j+1,high);
    }
}
int main()
{
    cout << "Enter Size of Array: ";
    int n ;
    cin >> n;
    int arr[n];
    cout << "Enter Array Elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    quicksort(arr,0,n);
    cout<<"The sorted array is "<<endl;
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
}
