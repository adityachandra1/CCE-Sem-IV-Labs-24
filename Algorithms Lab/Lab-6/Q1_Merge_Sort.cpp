#include <iostream>

using namespace std;

void merge(int a[],int l,int m,int r)
{
    int n1=m-l+1;
    int n2= r-m;
    int l1[n1],l2[n2],i,j,k;
    for(i=0; i<n1; i++)
        l1[i]=a[l+i];
    for(j=0; j<n2; j++)
        l2[j]=a[m+j+1];
    i=j=0;
    k=l;
    while(i<n1 && j<n2)
    {
        if(l1[i]>l2[j])
        {
            a[k]=l2[j];
            j++;
        }
        else
        {
            a[k]=l1[i];
            i++;
        }
        k++;
    }
    while(i<n1)
    {
        a[k]=l1[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        a[k]=l2[j];
        j++;
        k++;
    }
}

void mergesort(int a[],int l,int r)
{
    if(r>l)
    {
        int m=(l+r)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,r);
        merge(a,l,m,r);
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
    mergesort(arr,0,n);
    cout<<"The sorted array is "<<endl;
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" , ";
}
