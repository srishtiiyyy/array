#include <bits/stdc++.h>
using namespace std;

/*
    Function to count reverse pairs during merge step
    arr[l..mid] and arr[mid+1..r] are sorted
*/
int countPairs(vector<int>& arr, int l, int mid, int r) {
    int cnt = 0;
    int j = mid + 1;

    for (int i = l; i <= mid; i++) {
        while (j <= r && (long long)arr[i] > 2LL * arr[j]) {
            j++;
        }
        cnt += (j - (mid + 1));
    }
    return cnt;
}

/*
    Merge two sorted halves
*/
void merge(vector<int>& arr, int l, int mid, int r) {
    vector<int> temp;
    int i = l, j = mid + 1;

    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
        }
    }

    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= r) temp.push_back(arr[j++]);

    for (int k = l; k <= r; k++) {
        arr[k] = temp[k - l];
    }
}

/*
    Modified merge sort that counts reverse pairs
*/
int mergeSort(vector<int>& arr, int l, int r) {
    if (l >= r) return 0;
    int mid = (l + r) / 2;
    int cnt = mergeSort(arr, l, mid);
    cnt += mergeSort(arr, mid + 1, r);
    cnt += countPairs(arr, l, mid, r);
    merge(arr, l, mid, r);
    return cnt;
}

int reversePairs(vector<int>& arr) {
    return mergeSort(arr, 0, arr.size() - 1);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Number of reverse pairs: " << reversePairs(arr) << endl;
    return 0;
}
