//Aditya Chandra
//200953032  CCE - A
#include <iostream>
using namespace std;

int STEP_COUNT_I = 0;
int binarySearch_iterative(int arr[], int key, int n)
{
    STEP_COUNT_I++;
    int high = n-1, low = 0;

    STEP_COUNT_I++;
    while(low <= high)
    {
        STEP_COUNT_I++;
        int mid = (high+low)/2;

        STEP_COUNT_I++;
        if(arr[mid] == key)
        {
            STEP_COUNT_I++;
            return mid;
        }

        STEP_COUNT_I++;
        if(arr[mid] < key)
        {
            STEP_COUNT_I++;
            low = mid+1;
        }

        STEP_COUNT_I++;
        if(arr[mid] > key)
        {
            STEP_COUNT_I++;
            high = mid - 1;
        }
    }

    STEP_COUNT_I++;
    return -1;
}

int STEP_COUNT_R = 0;
int binarySearch_recursive(int arr[], int key, int l, int h)
{
    STEP_COUNT_R++;
    if(h >= l)
    {
        STEP_COUNT_R++;
        int mid = (h+l)/2;

        STEP_COUNT_R++;
        if(arr[mid] == key)
        {
            STEP_COUNT_R++;
            return mid;
        }

        STEP_COUNT_R++;
        if(arr[mid] > key)
        {
            STEP_COUNT_R++;
            return binarySearch_recursive(arr, key, l, mid-1);
        }

        STEP_COUNT_R++;
        if(arr[mid] < key)
        {
            STEP_COUNT_R++;
            return binarySearch_recursive(arr, key, mid+1, h);
        }
    }
    STEP_COUNT_R++;
    return -1;
}

int main()
{
    int n;
    cout << "Enter Size of Array: ";
    cin >>  n;

    int k;
    cout << "Enter Element to be searched:";
    cin >> k;

    int arr[n];
    cout << "Enter elements: \n";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int res_i = binarySearch_iterative(arr, k, n);
    int res_r = binarySearch_recursive(arr, k, 0, n-1);

    cout << "Binary Search Iterative: ";
    if(res_i == -1)
    {
        cout << "Element Not Found" << endl;
    }
    else
    {
        cout << "Element Found at " << res_i << endl;
    }
    cout << "Iterative Step Count: " << STEP_COUNT_I << endl;

    cout << endl;
    cout << "Binary Search Recursive: ";
    if(res_r == -1)
    {
        cout << "Element Not Found" << endl;
    }
    else
    {
        cout << "Element Found at " << res_r << endl;
    }
    cout << "Recursive Step Count: " << STEP_COUNT_R << endl;

}












