#include <bits/stdc++.h>
using namespace std;

/*
    Function to merge two halves and count inversions
    Left half: arr[l..mid]
    Right half: arr[mid+1..r]
*/
long long mergeAndCount(vector<int>& arr, int l, int mid, int r) {
    long long invCount = 0;

    // Temp arrays
    vector<int> left(arr.begin() + l, arr.begin() + mid + 1);
    vector<int> right(arr.begin() + mid + 1, arr.begin() + r + 1);

    int i = 0, j = 0, k = l;
    int n1 = left.size(), n2 = right.size();

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            // Inversion found: left[i] > right[j]
            arr[k++] = right[j++];
            invCount += (n1 - i);  
            // All remaining elements in left[] are greater than right[j]
        }
    }

    // Copy remaining elements
    while (i < n1) arr[k++] = left[i++];
    while (j < n2) arr[k++] = right[j++];

    return invCount;
}

/*
    Recursive function to apply merge sort and count inversions
*/
long long mergeSortAndCount(vector<int>& arr, int l, int r) {
    long long invCount = 0;
    if (l < r) {
        int mid = l + (r - l) / 2;

        // Count inversions in left half
        invCount += mergeSortAndCount(arr, l, mid);

        // Count inversions in right half
        invCount += mergeSortAndCount(arr, mid + 1, r);

        // Count cross inversions while merging
        invCount += mergeAndCount(arr, l, mid, r);
    }
    return invCount;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    long long inversions = mergeSortAndCount(arr, 0, n - 1);

    cout << "Number of inversions: " << inversions << endl;
    return 0;
}
