#include <bits/stdc++.h>
using namespace std;
int c = 0;
void swap(int* a, int* b) {
    int t = *a;
    c++;
    *a = *b;
    c++;
    *b = t;
    c++;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    c++;
    int i = (low - 1);
    c++;

    for (int j = low; j <= high - 1; j++) {
        c++;
        if (arr[j] < pivot) {
            c++;
            i++;
            c++;
            swap(&arr[i], &arr[j]);
            c++;
        }
    }
    c++;
    swap(&arr[i + 1], &arr[high]);
    c++;
    c++;
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        c++;
        int pi = partition(arr, low, high);
        c++;
        quickSort(arr, low, pi - 1);
        c++;
        quickSort(arr, pi + 1, high);
        c++;
    }
}

int main() {
    int n;
    c++;
    cout << "Enter size of array: ";
    c++;
    cin >> n;
    c++;
    int a[n];
    c++;
    cout << "Enter array elements: ";
    c++;
    for (int i = 0; i < n; i++) {
        c++;
        cin >> a[i];
        c++;
    }
    c++;
    quickSort(a, 0, n - 1);
    c++;
    cout << "Sorted array: ";
    c++;
    for (int i = 0; i < n; i++) {
        c++;
        cout << a[i] << " ";
        c++;
    }
    c++;
    cout << endl;
    cout << "Step Count: " << c;

    return 0;
}
