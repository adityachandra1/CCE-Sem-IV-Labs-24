#include <bits/stdc++.h>
using namespace std;
int c = 0;

void merge(int *a, int l, int m, int r) {
    int i, j, k, nl, nr;
    c++;
    nl = m - l + 1;
    c++;
    nr = r - m;
    c++;
    int la[nl], ra[nr];
    c++;

    for (i = 0; i < nl; i++) {
        c++;
        la[i] = a[l + i];
        c++;
    }

    c++;

    for (j = 0; j < nr; j++) {
        c++;
        ra[j] = a[m + 1 + j];
        c++;
    }

    c++;

    i = 0;
    c++;
    j = 0;
    c++;
    k = l;
    c++;
    while (i < nl && j < nr) {
        if (la[i] <= ra[j]) {
            c++;
            a[k] = la[i];
            c++;
            i++;
            c++;
        } else {
            c++;
            a[k] = ra[j];
            c++;
            j++;
            c++;
        }
        k++;
        c++;
    }
    c++;
    while (i < nl) {
        c++;
        a[k] = la[i];
        c++;
        i++;
        k++;
        c++;
        c++;
    }
    c++;
    while (j < nr) {
        c++;
        a[k] = ra[j];
        c++;
        j++;
        k++;
        c++;
        c++;
    }
    c++;
}

void mergeSort(int *a, int l, int r) {
    int m;
    c++;
    if (l < r) {
        c++;
        int m = l + (r - l) / 2;
        c++;
        mergeSort(a, l, m);
        c++;
        mergeSort(a, m + 1, r);
        c++;
        merge(a, l, m, r);
        c++;
    }
}
int main() {
    int n;
    c++;
    cout << "Enter number of elements: ";
    c++;
    cin >> n;
    c++;
    int a[n];
    c++;

    cout << "Enter elements:";
    c++;
    for (int i = 0; i < n; i++) {
        c++;
        cin >> a[i];
        c++;
    }

    mergeSort(a, 0, n - 1);
    c++;
    cout << "Sorted Array: ";
    c++;

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << "\n\nStep count : " << c << endl;
    return 0;
}