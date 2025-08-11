#include <bits/stdc++.h>
using namespace std;

int missing(vector<int> &arr) {
    int n = arr.size();
    int xorall = 0, xorarr = 0;

    for (int i = 0; i <= n; i++) { // XOR from 0 to n
        xorall ^= i;
    }
    for (int i = 0; i < n; i++) {
        xorarr ^= arr[i];
    }

    return xorall ^ xorarr; // Missing number
}

int main() {
    int n;
    cin >> n; // number of elements excluding missing
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Missing number is " << missing(arr);
    return 0;
}
