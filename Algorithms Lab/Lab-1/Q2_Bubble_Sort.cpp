//Aditya Chandra
//200953032  CCE - A
#include <iostream>
using namespace std;

int STEP_COUNT = 0;

void bubbleSort(int arr[], int n){
     for (int i = 0; i < n-1; i++) {
        STEP_COUNT++;

        for (int j = 0; j < n-i-1; j++) {
            STEP_COUNT++;

            STEP_COUNT++;
            if (arr[j] > arr[j+1]) {

                STEP_COUNT++;
                int temp = arr[j];

                STEP_COUNT++;
                arr[j] = arr[j + 1];

                STEP_COUNT++;
                arr[j + 1] = temp;
            }
        }
       STEP_COUNT++; //false
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

    cout << "Sorting the Array using Bubble Sort" << endl;
    bubbleSort(arr, n);
    cout << "Sorted Array: " << endl;

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout <<  endl;
    cout << "Step Count: " << STEP_COUNT << endl;

}












