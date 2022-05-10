
#include <bits/stdc++.h>
using namespace std;

string commonPrefix(string s1, string s2) {
    string commonPfix = "";

    int n1 = s1.length();
    int n2 = s2.length();

    for (int i = 0, j = 0; i < n1 && j < n2; i++, j++) {
        if (s1[i] != s2[j]) {
            break;
        }

        commonPfix = commonPfix + s1[i];
    }

    return commonPfix;
}

string longestCommonPrefix(string arr[], int low_idx, int high_idx) {
    string ans;
    if (low_idx == high_idx) {
        return (arr[high_idx]);
    }
    if (high_idx > low_idx) {
        int mid = low_idx + (high_idx - low_idx) / 2;
        string s1 = longestCommonPrefix(arr, low_idx, mid);
        string s2 = longestCommonPrefix(arr, mid + 1, high_idx);
        string ans = commonPrefix(s1, s2);  // longest common prefix
        return ans;
    }
    return "";
}

int main() {
    string arr[100];
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    cout << "Enter all strings: \n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Longest common prefix is : " << longestCommonPrefix(arr, 0, n - 1);
}
