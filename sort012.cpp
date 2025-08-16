//DUTCH NATIONAL FLAG ALGORITHM
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements (only 0, 1, 2): ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Dutch National Flag Algorithm (in-place sorting)
    int i = 0, j = 0, k = n - 1;
    while (j <= k) {
        if (nums[j] == 1) {
            j++;
        }
        else if (nums[j] == 2) {
            swap(nums[j], nums[k]);
            k--;
        }
        else { // nums[j] == 0
            swap(nums[i], nums[j]);
            i++;
            j++;
        }
    }

    cout << "Sorted colors: ";
    for (int x : nums) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
