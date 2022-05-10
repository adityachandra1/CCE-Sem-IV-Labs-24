
#include <bits/stdc++.h>
using namespace std;
void merge_and_sort(
	vector<int> &output, vector<vector<int>> arr,
	int n, int k)
{
	// Put the elements in sorted array.
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			output[(i * n) + j] = arr[i][j];
		}
	}
	sort(output.begin(), output.end());
}
int main()
{
	vector<vector<int>> arr;
    int k;
    cout << "enter no of arrays (k): " << endl;
    cin >> k;
	cout << "enter size of arrays(n): " << endl;
	int n;
	cin >> n;

	for(int i = 0 ; i < k ; i++){
        vector<int> temp(n);
        cout << "Enter elements in array " << i+1 << endl;
        for(int j = 0 ; j < n ; j++){
            cin >> temp[j];
        }
        arr.push_back(temp);
	}

	vector<int> output(n*k);
    cout << "Merged Arrays" << endl;
	merge_and_sort(output, arr, n, k);
	for (int i = 0; i < n * k; i++)
		cout << output[i] << " ";

	return 0;
}


