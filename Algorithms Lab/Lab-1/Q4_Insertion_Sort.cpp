//Aditya Chandra
//200953032  CCE - A
#include <iostream>
using namespace std;

int STEP_COUNT = 0;

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        STEP_COUNT++;

        STEP_COUNT++;
        int j = i - 1;

        STEP_COUNT++;
        int key = arr[i];

        for (; j >= 0 && arr[j] > key; j--)
        {
            STEP_COUNT+= 2;


            STEP_COUNT++;
            arr[j + 1] = arr[j];
        }
        STEP_COUNT++;

        STEP_COUNT++;
        arr[j + 1] = key;
    }
    STEP_COUNT++;
}


int main()
{
    int n;
    cout << "Enter Size of Array: ";
    cin >>  n;


    int arr[n];
    cout << "Enter elements: \n";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Sorting the Array using Insertion Sort" << endl;
    insertionSort(arr, n);
    cout << "Sorted Array: " << endl;

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout <<  endl;
    cout << "Step Count: " << STEP_COUNT << endl;

}
