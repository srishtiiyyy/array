#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cout << "Enter size of first array: ";
    cin >> n;
    vector<int> nums1(n);
    cout << "Enter elements of first array (sorted): ";
    for (int i = 0; i < n; i++) cin >> nums1[i];

    cout << "Enter size of second array: ";
    cin >> m;
    vector<int> nums2(m);
    cout << "Enter elements of second array (sorted): ";
    for (int i = 0; i < m; i++) cin >> nums2[i];

    vector<int> Union;
    int i = 0, j = 0;

    // Merge while avoiding duplicates
    while (i < n && j < m) {
        if (nums1[i] <= nums2[j]) {
            if (Union.empty() || Union.back() != nums1[i])
                Union.push_back(nums1[i]);
            i++;
        } else {
            if (Union.empty() || Union.back() != nums2[j])
                Union.push_back(nums2[j]);
            j++;
        }
    }

    // Remaining elements of nums1
    while (i < n) {
        if (Union.empty() || Union.back() != nums1[i])
            Union.push_back(nums1[i]);
        i++;
    }

    // Remaining elements of nums2
    while (j < m) {
        if (Union.empty() || Union.back() != nums2[j])
            Union.push_back(nums2[j]);
        j++;
    }

    cout << "Union of the arrays: ";
    for (int val : Union) cout << val << " ";
    cout << endl;

    return 0;
}
