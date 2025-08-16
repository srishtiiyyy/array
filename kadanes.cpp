#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Kadane’s Algorithm
    int maxi = INT_MIN;  // maximum subarray sum so far
    int sum = 0;         // current subarray sum

    for (int i = 0; i < n; i++) {
        sum += nums[i];                 // include current element
        maxi = max(maxi, sum);          // update maximum
        if (sum < 0) sum = 0;           // reset if sum goes negative
    }

    cout << "Maximum Subarray Sum: " << maxi << endl;

    return 0;
}
