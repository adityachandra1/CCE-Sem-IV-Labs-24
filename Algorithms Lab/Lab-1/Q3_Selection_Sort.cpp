//Aditya Chandra
//200953032  CCE - A
#include <iostream>
using namespace std;

int STEP_COUNT = 0;

void SelectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        STEP_COUNT++;

        STEP_COUNT++;
        int mini = i;


        for (int j = i+1; j < n; j++) {
            STEP_COUNT++;

            STEP_COUNT++;
            if (arr[j] < arr[mini]) {
                STEP_COUNT++;
                mini = j;
            }
        }
        STEP_COUNT++; //inner for loop

        STEP_COUNT++;
        int temp = arr[mini];

        STEP_COUNT++;
        arr[mini] = arr[i];

        STEP_COUNT++;
        arr[i] = temp;
    }
    STEP_COUNT++; //outer for loop
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

    cout << "Sorting the Array using Selection Sort" << endl;
    SelectionSort(arr, n);
    cout << "Sorted Array: " << endl;

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout <<  endl;
    cout << "Step Count: " << STEP_COUNT << endl;

}
